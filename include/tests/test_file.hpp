#ifndef TEST_FILE_30_DIAS_DE_C_I
#define TEST_FILE_30_DIAS_DE_C_I

#include <cstdio>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>

namespace tests_30dc {

template<typename T>
concept TestContainer = requires(T container)
{
    std::is_trivially_copyable_v<typename T::value_type>;

    container.data();
    std::is_convertible_v<decltype(container.data()), void*>;

    container.size() == typename T::size_type();
};

template<typename T>
concept TestMutableContainer = requires(T container)
{
    TestContainer<T>;

    container.resize(typename T::size_type());
};

class [[nodiscard]] test_file
{
public:
    test_file(std::FILE* fd)
        : m_fd{fd} { }

    [[nodiscard]]
    auto fd() const -> std::FILE*
    {
        return m_fd;
    }

    void rewind()
    {
        if (!m_fd)
        {
            throw std::runtime_error{"Invalid file descriptior."};
        }

        std::rewind(m_fd);
    }

    template<TestMutableContainer T = std::string>
    [[nodiscard]]
    auto read(typename T::size_type buffer_size = 256u) -> T
    {
        if (!m_fd)
        {
            throw std::runtime_error{"Invalid file descriptior."};
        }

        T data;

        using byte_type = typename T::value_type;
        constexpr auto byte_size = sizeof(byte_type);

        while (!std::feof(m_fd))
        {
            auto const offset = data.size();

            data.resize(offset + buffer_size);

            auto const n = std::fread(data.data() + offset,
                                      byte_size, buffer_size,
                                      m_fd);

            if (n < buffer_size)
            {
                // Shrink from grown size to n-read size.
                data.resize(offset + (n * byte_size));

                if (n == 0u)
                {
                    break;
                }
            }
        }

        return data;
    }

    template<TestContainer T = std::string_view>
    auto write(T const& data)
    {
        if (!m_fd)
        {
            throw std::runtime_error{"Invalid file descriptior."};
        }

        using byte_type = typename T::value_type;
        constexpr auto byte_size = sizeof(byte_type);

        return std::fwrite(data.data(), byte_size, data.size(), m_fd);
    }

private:
    std::FILE* m_fd = nullptr;
};

} // namespace tests_30dc

#endif // FILE_30_DIAS_DE_C_I
