#include <cmath>
#include <limits>
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

BOOST_AUTO_TEST_CASE(test_count_nonspace)
{
    auto test_case = [](std::string_view str, const size_t check)
    {
        size_t count = 0;
        const bool success = count_nonspace(str.data(), str.size() + 1, &count);

        return (success && (check == count));
    };

    BOOST_CHECK(test_case("test", 4));
    BOOST_CHECK(test_case("  test  \r\n", 4));
    BOOST_CHECK(test_case("te st", 4));
    BOOST_CHECK(test_case("", 0));
    BOOST_CHECK(test_case("  \r\n", 0));
}

BOOST_AUTO_TEST_CASE(test_parse_signed)
{
    auto test_success = [](std::string_view str, const intmax_t check)
    {
        intmax_t result = 0;
        const bool success = parse_signed(str.data(), str.size()+1, &result);

        return (success && (check == result));
    };

    auto test_failure = [](std::string_view str)
    {
        intmax_t result = 0;
        const bool success = parse_signed(str.data(), str.size()+1, &result);

        return !success;
    };

    BOOST_CHECK(test_success("20", 20));
    BOOST_CHECK(test_success("+20", 20));
    BOOST_CHECK(test_success("-20", -20));
    BOOST_CHECK(test_success("  20  \r\n", 20));
    BOOST_CHECK(test_failure("20 20"));
    BOOST_CHECK(test_failure(""));
    BOOST_CHECK(test_failure("  \r\n"));
    BOOST_CHECK(test_failure("+"));
    BOOST_CHECK(test_failure("-"));
    BOOST_CHECK(test_failure("twenty"));
    BOOST_CHECK(test_failure("twenty20"));
    BOOST_CHECK(test_failure("20twenty"));
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

BOOST_AUTO_TEST_CASE(test_parse_double)
{
    auto cmp_d = [](const double left, const double right)
    {
        constexpr auto epsilon = std::numeric_limits<double>::epsilon();
        return (std::fabs(left - right) <= epsilon);
    };

    auto test_success = [&cmp_d](std::string_view str, const double check)
    {
        double result = 0;
        const bool success = parse_double(str.data(), str.size()+1, &result);

        return (success && cmp_d(check, result));
    };

    auto test_failure = [](std::string_view str)
    {
        double result = 0;
        const bool success = parse_double(str.data(), str.size()+1, &result);

        return !success;
    };

    BOOST_CHECK(test_success("20.123", 20.123));
    BOOST_CHECK(test_success("+20.123", 20.123));
    BOOST_CHECK(test_success("-20.123", -20.123));
    BOOST_CHECK(test_success("  20.123  \r\n", 20.123));
    BOOST_CHECK(test_failure("20.123 20.123"));
    BOOST_CHECK(test_failure(""));
    BOOST_CHECK(test_failure("  \r\n"));
    BOOST_CHECK(test_failure("+"));
    BOOST_CHECK(test_failure("-"));
    BOOST_CHECK(test_failure("."));
    BOOST_CHECK(test_failure("+."));
    BOOST_CHECK(test_failure("-."));
    BOOST_CHECK(test_failure("twenty.onetwothree"));
    BOOST_CHECK(test_failure("twenty20.123"));
    BOOST_CHECK(test_failure("20.123twenty"));
}

BOOST_AUTO_TEST_SUITE_END()
