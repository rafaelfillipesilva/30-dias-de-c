#ifndef EXPECTED_OUTPUT_30_DIAS_DE_C_I
#define EXPECTED_OUTPUT_30_DIAS_DE_C_I

#include <string>
#include <type_traits>
#include "result.hpp"
#include "test_file.hpp"
#include "temporary_file.hpp"

namespace tests_30dc {

template<typename Fn>
concept OutTestFn = requires(Fn fn, std::FILE* out)
{
    fn(out);
};

[[nodiscard]]
auto test_output(OutTestFn auto fn) -> result<std::string>
{
    auto tmp_output = make_temporary_file();

    auto out = test_file{tmp_output.get_fd()};

    fn(out.fd());
    out.rewind();

    return result{out.read()};
}

} // namespace tests_30dc

#endif // EXPECTED_OUTPUT_30_DIAS_DE_C_I
