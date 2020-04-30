#ifndef EXPECTED_OUTPUT_30_DIAS_DE_C_I
#define EXPECTED_OUTPUT_30_DIAS_DE_C_I

#include <string>
#include <type_traits>
#include "result.hpp"
#include "test_file.hpp"
#include "temporary_file.hpp"

namespace tests_30dc {

template<class Fn>
auto test_output(Fn fn) -> result<std::string>
{
    static_assert(std::is_invocable_v<Fn, FILE*>,
                  "Requires a function Fn(FILE* out).");

    auto tmp_output = make_temporary_file();

    auto out = test_file{tmp_output.get_fd()};

    fn(out.fd());
    out.rewind();

    return {out.read()};
}

} // namespace tests_30dc

#endif // EXPECTED_OUTPUT_30_DIAS_DE_C_I
