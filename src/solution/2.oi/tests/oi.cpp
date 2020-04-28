#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "tests/expected_io.hpp"
#include "oi.h"

namespace tests_30dc {

inline constexpr std::size_t max_name_length = MAX_NAME_LENGTH;

BOOST_AUTO_TEST_SUITE(oi)

BOOST_AUTO_TEST_CASE(valid_input)
{
    BOOST_CHECK(expect_io("Test", "Digite seu nome: "
                                  "Oi, Test\n").test(run_oi));
}

BOOST_AUTO_TEST_CASE(blank_input)
{
    BOOST_CHECK(expect_io("\n", "Digite seu nome: "
                                "Oi, ser sem nome.\n").test(run_oi));
}

BOOST_AUTO_TEST_CASE(empty_input)
{
    BOOST_CHECK(expect_io("", "Digite seu nome: "
                              "\n" // run_oi should handle empty stdin (ctrl+d).
                              "Oi, ser sem nome.\n").test(run_oi));
}

// Tests inputs longer than run_oi's buffer size - 1 (null terminator).
// The expected behavior is to truncate the input to the maximum allowed.
BOOST_AUTO_TEST_CASE(very_long_input)
{
    constexpr std::string::size_type buffer_size = max_name_length;
    constexpr std::string::size_type test_length = 2 + (buffer_size - 1);

    std::string long_input(test_length, 'A');

    std::string long_output = "Digite seu nome: "
                              "Oi, " + long_input + "\n";

    auto test = test_io(long_input, run_oi);

    // Expected failure, long_output should contain truncated long_input.
    BOOST_CHECK(expect_io(std::move(long_input),
                          std::move(long_output)).fail(run_oi));
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace tests_30dc
