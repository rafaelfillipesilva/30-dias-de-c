#ifndef TEST_FILE_30_DIAS_DE_C_I
#define TEST_FILE_30_DIAS_DE_C_I

#include <cstdio>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>

namespace tests_30dc {

class test_file
{
public:
    test_file(std::FILE* fd)
        : m_fd{fd} { }

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

    template<class T = std::string>
    auto read(std::size_t buffer_size = 256U) -> T
    {
        if (!m_fd)
        {
            throw std::runtime_error{"Invalid file descriptior."};
        }

        using byte_type = typename T::value_type;

        static_assert(std::is_trivially_copyable_v<byte_type>,
                      "T::value_type is not trivially copyable.");

        T data;
        constexpr auto byte_size = sizeof(byte_type);

        while (!std::feof(m_fd))
        {
            auto offset = data.size();

            data.resize(offset + buffer_size);

            auto n = std::fread(data.data() + offset,
                                byte_size, buffer_size,
                                m_fd);

            if (n < buffer_size)
            {
                // Shrink from grown size to n-read size.
                data.resize(offset + (n * byte_size));

                if (n == 0U)
                {
                    break;
                }
            }
        }

        return data;
    }

    template<class T = std::string_view>
    auto write(const T& data)
    {
        if (!m_fd)
        {
            throw std::runtime_error{"Invalid file descriptior."};
        }

        using byte_type = typename T::value_type;

        static_assert(std::is_trivially_copyable_v<byte_type>,
                      "T::value_type is not trivially copyable.");

        constexpr auto byte_size = sizeof(byte_type);

        return std::fwrite(data.data(), byte_size, data.size(), m_fd);
    }

private:
    std::FILE* m_fd = nullptr;
};

} // namespace tests_30dc

#endif // FILE_30_DIAS_DE_C_I
