#ifndef EXPECTED_IO_30_DIAS_DE_C_I
#define EXPECTED_IO_30_DIAS_DE_C_I

#include <string>
#include <type_traits>
#include "result.hpp"
#include "temporary_file.hpp"

namespace tests_30dc {

template<class Function, class... Args>
auto test_io(std::string_view data,
             Function fn, Args&&... args) -> result<std::string>
{
    static_assert(std::is_invocable_v<Function, FILE*, FILE*, Args&&...>,
                  "Requires a function fn(FILE* in, FILE* out, Args&&...).");

    auto tmp_input = make_temporary_file();
    auto [in, _] = tmp_input.write(data);

    auto tmp_output = make_temporary_file();
    auto out = tmp_output.get_fd();

    fn(in, out, std::forward<Args>(args)...);

    return {tmp_output.read()};
}

struct expect_io
{
    expect_io(std::string in, std::string out)
        : m_in{std::move(in)}, m_out{std::move(out)} { }

    template<class Function, class... Args>
    bool test(Function fn, Args&&... args)
    {
        return test_io(m_in, fn, std::forward<Args>(args)...).expect(m_out);
    }

    template<class Function, class... Args>
    bool fail(Function fn, Args&&... args)
    {
        return !test(fn, std::forward<Args>(args)...);
    }

private:
    std::string m_in;
    std::string m_out;
};

} // namespace tests_30dc

#endif // EXPECTED_OUTPUT_30_DIAS_DE_C_I
