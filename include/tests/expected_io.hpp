#ifndef EXPECTED_IO_30_DIAS_DE_C_I
#define EXPECTED_IO_30_DIAS_DE_C_I

#include <string>
#include <string_view>
#include <type_traits>
#include "result.hpp"
#include "test_file.hpp"
#include "temporary_file.hpp"

namespace tests_30dc {

template<class Fn>
auto test_io(std::string_view data, Fn fn) -> result<std::string>
{
    static_assert(std::is_invocable_v<Fn, FILE*, FILE*>,
                  "Requires a function Fn(FILE* in, FILE* out).");

    auto tmp_input  = make_temporary_file();
    auto tmp_output = make_temporary_file();

    auto in  = test_file{tmp_input.get_fd()};
    auto out = test_file{tmp_output.get_fd()};

    in.write(data);
    in.rewind();

    fn(in.fd(), out.fd());
    out.rewind();

    return {out.read()};
}

struct expect_io
{
    expect_io(std::string in, std::string out)
        : m_in{std::move(in)}, m_out{std::move(out)} { }

    template<class Fn>
    auto test(Fn fn) -> bool
    {
        return test_io(m_in, fn).expect(m_out);
    }

    template<class Fn>
    auto fail(Fn fn) -> bool
    {
        return !test(fn);
    }

private:
    std::string m_in;
    std::string m_out;
};

} // namespace tests_30dc

#endif // EXPECTED_OUTPUT_30_DIAS_DE_C_I
