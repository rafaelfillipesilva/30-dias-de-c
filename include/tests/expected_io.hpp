#ifndef EXPECTED_IO_30_DIAS_DE_C_I
#define EXPECTED_IO_30_DIAS_DE_C_I

#include <cassert>
#include <string>
#include <string_view>
#include "temporary_file.hpp"
#include "expected_output.hpp"

class expected_io
{
public:
    expected_io(std::string in, std::string out)
        : m_expected_in{std::move(in)}, m_expected_out{std::move(out)}
    {
    }

    expected_io(const expected_io&) = delete;
    expected_io(expected_io&&) = delete;

    expected_io& operator=(const expected_io&) = delete;
    expected_io& operator=(expected_io&&) = delete;

    bool is_ready() const
    {
        return (m_tmp_in.is_open() && m_expected_out.is_ready());
    }

    template<class Function, class... Args>
    decltype(auto) run(Function fn, Args&&... args)
    {
        refresh_input();

        assert(m_tmp_in.is_open() && m_expected_out.is_ready());

        return m_expected_out.run([this, &fn, &args...](auto&& out)
        {
            return fn(m_tmp_in.get_file(),
                      std::forward<decltype(out)>(out),
                      std::forward<Args>(args)...);
        });
    }

    bool validate()
    {
        return m_expected_out.validate();
    }

private:
    void refresh_input()
    {
        if (m_tmp_in.reopen())
        {
            std::FILE* in = m_tmp_in.get_file();
            std::fwrite(m_expected_in.data(), m_expected_in.size(), 1, in);
            std::rewind(in);
        }
    }

private:
    temporary_file m_tmp_in;
    std::string m_expected_in;

    expected_output m_expected_out;
};

#endif // EXPECTED_OUTPUT_30_DIAS_DE_C_I
