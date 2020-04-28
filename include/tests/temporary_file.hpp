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
    temporary_file() = delete;

    temporary_file(std::string path, std::unique_ptr<std::FILE, Deleter> file)
        : m_path{std::move(path)}, m_file{std::move(file)} { }

    ~temporary_file() = default;

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
        return static_cast<bool>(m_file);
    }

    std::FILE* get_fd() const
    {
        if (!is_open())
        {
            throw std::runtime_error{"The temporary file is not open."};
        }

        return m_file.get();
    }

    void reopen()
    {
        if (!is_open())
        {
            throw std::runtime_error{"The temporary file is not open."};
        }

        std::FILE* fd = m_file.release();
        fd = std::freopen(m_path.c_str(), "w+", fd);

        if (!fd)
        {
            throw std::runtime_error{"Failed to reopen temporary stream."};
        }

        m_file.reset(fd);
    }

    template<class Data = std::string>
    Data read(typename Data::size_type buffer_size = 256)
    {
        constexpr auto byte_size = sizeof(typename Data::value_type);

        if (!is_open())
        {
            throw std::runtime_error{"The temporary file is not open."};
        }

        std::FILE* fd = m_file.get();
        std::rewind(fd);

        Data data;
        auto offset = data.size();

        auto grow_size = buffer_size * byte_size;

        while (!std::feof(fd))
        {
            data.resize(offset + grow_size);
            auto n = std::fread(data.data()+offset, byte_size, buffer_size, fd);

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
    std::FILE* write(const Data& data)
    {
        constexpr auto byte_size = sizeof(typename Data::value_type);

        if (!is_open())
        {
            throw std::runtime_error{"The temporary file is not open."};
        }

        std::FILE* fd = m_file.get();
        std::rewind(fd);

        std::fwrite(data.data(), byte_size, data.size(), fd);
        std::rewind(fd);

        return fd;
    }

private:
    std::string m_path;
    std::unique_ptr<std::FILE, Deleter> m_file;
};

template<class Deleter>
temporary_file(std::string,
               std::unique_ptr<std::FILE, Deleter>) -> temporary_file<Deleter>;

auto make_tmpfile()
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
        path_str,
        std::unique_ptr<std::FILE, decltype(deleter)>{fd, deleter}
    };
}

} // namespace tests_30dc

#endif // TEMPORARY_FILE_30_DIAS_DE_C_I
