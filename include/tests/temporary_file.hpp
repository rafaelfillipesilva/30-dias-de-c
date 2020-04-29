#ifndef TEMPORARY_FILE_30_DIAS_DE_C_I
#define TEMPORARY_FILE_30_DIAS_DE_C_I

#include <cstdio>
#include <memory>
#include <string>
#include <boost/filesystem/exception.hpp>
#include <boost/filesystem/operations.hpp>

namespace tests_30dc {

template<class Deleter>
class temporary_file
{
public:
    explicit temporary_file(std::unique_ptr<std::FILE, Deleter> file)
        : m_file{std::move(file)} { }

    temporary_file(temporary_file&&) = default;
    temporary_file& operator=(temporary_file&&) = default;

    temporary_file(const temporary_file&) = delete;
    temporary_file& operator=(const temporary_file&) = delete;

    bool is_open() const
    {
        return static_cast<bool>(m_file);
    }

    explicit operator bool() const
    {
        return is_open();
    }

    std::FILE* get_fd()
    {
        if (!is_open())
        {
            throw std::runtime_error{"The temporary file is not open."};
        }

        return m_file.get();
    }

    void rewind()
    {
        auto fd = get_fd();
        std::rewind(fd);
    }

    template<class Data = std::string>
    auto read(typename Data::size_type buffer_size = 256) -> Data
    {
        constexpr auto byte_size = sizeof(typename Data::value_type);

        auto fd = get_fd();
        std::rewind(fd);

        Data data;
        auto offset = data.size();

        auto grow_size = (buffer_size * byte_size);

        while (!std::feof(fd))
        {
            data.resize(offset + grow_size);
            auto n = std::fread(data.data()+offset, byte_size, buffer_size, fd);

            // Shrink from grown size to n-read size.
            data.resize(offset + (n * byte_size));
            offset = data.size();

            if (n == 0)
            {
                break;
            }
        }

        return data;
    }

    template<class Data = std::string_view>
    auto write(const Data& data)
    {
        constexpr auto byte_size = sizeof(typename Data::value_type);

        auto fd = get_fd();
        return std::fwrite(data.data(), byte_size, data.size(), fd);
    }

private:
    std::unique_ptr<std::FILE, Deleter> m_file;
};

auto make_temporary_file()
{
    namespace bfs = boost::filesystem;

    constexpr auto pattern = "io-30dc_%%%%-%%%%-%%%%-%%%%";
    auto path = bfs::temp_directory_path() / bfs::unique_path(pattern);

    std::FILE* fd = std::fopen(path.c_str(), "w+x");

    if (!fd)
    {
        throw std::runtime_error{"Failed to open temporary stream."};
    }

    std::string path_str = path.string();

    auto deleter = [path_str](std::FILE* file)
    {
        if (file)
        {
            std::fclose(file);
            std::remove(path_str.c_str());
        }
    };

    return temporary_file{
        std::unique_ptr<std::FILE, decltype(deleter)>{fd, deleter}
    };
}

} // namespace tests_30dc

#endif // TEMPORARY_FILE_30_DIAS_DE_C_I
