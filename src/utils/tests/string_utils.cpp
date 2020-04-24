#include <string_view>
#include <boost/test/unit_test.hpp>
#include "utils/string_utils.h"

BOOST_AUTO_TEST_SUITE(string_utils)

BOOST_AUTO_TEST_CASE(test_rtrim_newline)
{
    const std::string_view test_str = "test";

    std::string test{test_str};

    test.append("\r\n");
    rtrim_newline(test.data(), test.size());

    const std::string_view result = test.data();

    BOOST_CHECK(result == test_str);
}

BOOST_AUTO_TEST_CASE(test_parse_unsigned)
{
    auto test_success = [](std::string_view str, const uintmax_t check)
    {
        uintmax_t result = 0;
        const bool success = parse_unsigned(str.data(), str.size()+1, &result);

        return (success && (check == result));
    };

    auto test_failure = [](std::string_view str)
    {
        uintmax_t result = 0;
        const bool success = parse_unsigned(str.data(), str.size()+1, &result);

        return !success;
    };

    BOOST_CHECK(test_success("20", 20));
    BOOST_CHECK(test_success("  20  \r\n", 20));
    BOOST_CHECK(test_failure("20 20"));
    BOOST_CHECK(test_failure(""));
    BOOST_CHECK(test_failure("  \r\n"));
    BOOST_CHECK(test_failure("+20"));
    BOOST_CHECK(test_failure("-20"));
    BOOST_CHECK(test_failure("+"));
    BOOST_CHECK(test_failure("-"));
    BOOST_CHECK(test_failure("twenty"));
    BOOST_CHECK(test_failure("twenty20"));
    BOOST_CHECK(test_failure("20twenty"));
}

BOOST_AUTO_TEST_SUITE_END()
