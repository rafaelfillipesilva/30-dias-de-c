#ifndef EXPECTED_OUTPUT_30_DIAS_DE_C_I
#define EXPECTED_OUTPUT_30_DIAS_DE_C_I

#include <cassert>
#include <string>
#include <string_view>
#include "temporary_file.hpp"

class expected_output
{
public:
    expected_output(std::string expected) : m_expected_out{std::move(expected)}
    {
    }

    expected_output(const expected_output&) = delete;
    expected_output(expected_output&&) = delete;

    expected_output& operator=(const expected_output&) = delete;
    expected_output& operator=(expected_output&&) = delete;

    bool is_ready() const
    {
        return m_tmp_out.is_open();
    }

    template<class Function, class... Args>
    decltype(auto) run(Function fn, Args&&... args)
    {
        clear_output();

        assert(m_tmp_out.is_open());

        return fn(m_tmp_out.get_file(), std::forward<Args>(args)...);
    }

    bool validate()
    {
        assert(m_tmp_out.is_open());

        std::FILE* fd = m_tmp_out.get_file();
        std::rewind(fd);

        std::string output(m_expected_out.size(), '\0');
        std::fread(output.data(), output.size(), 1, fd);

        return (output == m_expected_out);
    }

private:
    void clear_output()
    {
        m_tmp_out.reopen();
    }

private:
    temporary_file m_tmp_out;
    std::string m_expected_out;
};

#endif // EXPECTED_OUTPUT_30_DIAS_DE_C_I
