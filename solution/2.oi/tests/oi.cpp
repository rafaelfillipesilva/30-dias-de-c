#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "tests/expected_io.hpp"
#include "oi.h"

BOOST_AUTO_TEST_SUITE(oi)

BOOST_AUTO_TEST_CASE(valid_input)
{
    expected_io expect("Test", "Digite seu nome: "
                               "Oi, Test");

    BOOST_REQUIRE_MESSAGE(expect.is_ready(), "Open temporary test streams.");

    expect.run(run_oi);

    BOOST_CHECK(expect.validate());
}

BOOST_AUTO_TEST_CASE(empty_input)
{
    expected_io expect("", "Digite seu nome: "
                           "\n" // should inject new line for empty names.
                           "Oi, ser sem nome.");

    BOOST_REQUIRE_MESSAGE(expect.is_ready(), "Open temporary test streams.");

    expect.run(run_oi);

    BOOST_CHECK(expect.validate());
}

// Tests inputs longer than run_oi's buffer size - 1 (null terminator).
// The expected behavior is to truncate the input to the maximum allowed.
BOOST_AUTO_TEST_CASE(very_long_input)
{
    constexpr std::string::size_type buffer_size = 256;
    constexpr std::string::size_type test_length =   2 + (buffer_size - 1);

    std::string long_input(test_length, 'A');

    std::string long_output = "Digite seu nome: "
                              "Oi, " + long_input;

    expected_io expect(std::move(long_input), std::move(long_output));

    BOOST_REQUIRE_MESSAGE(expect.is_ready(), "Open temporary test streams.");

    expect.run(run_oi);

    // Expected failure, long_output should contain truncated long_input.
    BOOST_CHECK(!expect.validate());
}

BOOST_AUTO_TEST_SUITE_END()
