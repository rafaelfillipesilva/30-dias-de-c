#ifndef EXPECTED_OUTPUT_30_DIAS_DE_C_I
#define EXPECTED_OUTPUT_30_DIAS_DE_C_I

#include <string>
#include <type_traits>
#include "result.hpp"
#include "temporary_file.hpp"

namespace tests_30dc {

template<class Function, class... Args>
auto test_output(Function fn, Args&&... args) -> result<std::string>
{
    static_assert(std::is_invocable_v<Function, FILE*, Args&&...>,
                  "Requires a function fn(FILE* out, Args&&...).");

    auto tmp_output = make_tmpfile();
    std::FILE* out = tmp_output.get_fd();

    fn(out, std::forward<Args>(args)...);

    return {tmp_output.read()};
}

} // namespace tests_30dc

#endif // EXPECTED_OUTPUT_30_DIAS_DE_C_I
