#ifndef EXPECTED_OUTPUT_30_DIAS_DE_C_I
#define EXPECTED_OUTPUT_30_DIAS_DE_C_I

#include <string>
#include <string_view>
#include "temporary_output.hpp"

class expected_output
{
public:
    expected_output(std::string_view expected) : m_expected{expected}
    {
    }

    expected_output(const expected_output&) = delete;
    expected_output(expected_output&&) = delete;

    expected_output& operator=(const expected_output&) = delete;
    expected_output& operator=(expected_output&&) = delete;

    operator bool() const
    {
        return m_tmp_file.is_open();
    }

    FILE* file() const
    {
        return m_tmp_file.file();
    }

    template<class Function>
    auto run(Function fn)
    {
        return fn(m_tmp_file.file());
    }

    bool validate() const
    {
        FILE* fd = m_tmp_file.file();
        std::rewind(fd);

        const std::size_t length = (m_expected.size() + 1);

        std::string buffer(length, '\0');
        std::fgets(buffer.data(), length, fd);

        std::string_view output(buffer.c_str(), m_expected.size());

        return (output == m_expected);
    }

private:
    temporary_output m_tmp_file;
    std::string_view m_expected;
};

#endif // EXPECTED_OUTPUT_30_DIAS_DE_C_I
