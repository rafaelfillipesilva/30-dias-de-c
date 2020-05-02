#ifndef TEMPORARY_FILE_30_DIAS_DE_C_I
#define TEMPORARY_FILE_30_DIAS_DE_C_I

#include <memory>
#include <string>
#include <boost/filesystem/exception.hpp>
#include <boost/filesystem/operations.hpp>

namespace tests_30dc {

template<typename Deleter>
concept FileDeleter = requires(Deleter deleter, std::FILE* fd)
{
    deleter(fd);
};

template<FileDeleter Deleter>
class [[nodiscard]] temporary_file
{
public:
    explicit temporary_file(std::unique_ptr<std::FILE, Deleter> file)
        : m_file{std::move(file)} { }

    temporary_file(temporary_file&&) = default;
    temporary_file& operator=(temporary_file&&) = default;

    temporary_file(const temporary_file&) = delete;
    temporary_file& operator=(const temporary_file&) = delete;

    [[nodiscard]]
    auto get_fd() -> std::FILE*
    {
        if (!m_file)
        {
            throw std::runtime_error{"The temporary file was not created."};
        }

        return m_file.get();
    }

private:
    std::unique_ptr<std::FILE, Deleter> m_file;
};

[[nodiscard]]
auto make_temporary_file()
{
    namespace bfs = boost::filesystem;

    constexpr auto pattern = "io-30dc_%%%%-%%%%-%%%%-%%%%";
    auto const path = bfs::temp_directory_path() / bfs::unique_path(pattern);

    auto fd = std::fopen(path.c_str(), "w+x");

    if (!fd)
    {
        throw std::runtime_error{"Failed to open the temporary file."};
    }

    auto const path_str = std::string(path.string());

    FileDeleter auto deleter = [path_str](std::FILE* file)
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
