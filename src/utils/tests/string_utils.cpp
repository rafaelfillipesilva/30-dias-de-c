#include <cmath>
#include <limits>
#include <string_view>
#include <boost/test/unit_test.hpp>
#include "tests/result.hpp"
#include "utils/string_utils.h"

namespace tests_30dc {

BOOST_AUTO_TEST_SUITE(string_utils)

BOOST_AUTO_TEST_CASE(rtrim_newline)
{
    auto rtrim_newline = [](std::string str) -> result<std::string>
    {
        ::rtrim_newline(str.data(), str.size());
        return {str.c_str()};
    };

    BOOST_CHECK(rtrim_newline("test\r\n").expect("test"));
}

BOOST_AUTO_TEST_CASE(count_nonspace)
{
    auto count_nonspace = [](std::string_view str) -> result<size_t>
    {
        size_t count = 0u;

        return {ok, count};
    };

    BOOST_CHECK(count_nonspace("test").expect(4u));
    BOOST_CHECK(count_nonspace("  test  \r\n").expect(4u));
    BOOST_CHECK(count_nonspace("te st").expect(4u));
    BOOST_CHECK(count_nonspace("").expect(0u));
    BOOST_CHECK(count_nonspace("  \r\n").expect(0u));
}

BOOST_AUTO_TEST_CASE(parse_signed)
{
    auto parse_signed = [](std::string_view str) -> result<intmax_t>
    {
        intmax_t value = 0;
        const bool ok = ::parse_signed(str.data(), str.size() + 1U, &value);

        return {ok, value};
    };

    BOOST_CHECK(parse_signed("20").expect(20));
    BOOST_CHECK(parse_signed("+20").expect(20));
    BOOST_CHECK(parse_signed("-20").expect(-20));
    BOOST_CHECK(parse_signed("  20  \r\n").expect(20));
    BOOST_CHECK(parse_signed("20 20").fail());
    BOOST_CHECK(parse_signed("").fail());
    BOOST_CHECK(parse_signed("  \r\n").fail());
    BOOST_CHECK(parse_signed("+").fail());
    BOOST_CHECK(parse_signed("-").fail());
    BOOST_CHECK(parse_signed("twenty").fail());
    BOOST_CHECK(parse_signed("twenty20").fail());
    BOOST_CHECK(parse_signed("20twenty").fail());
}

BOOST_AUTO_TEST_CASE(parse_unsigned)
{
    auto parse_unsigned = [](std::string_view str) -> result<uintmax_t>
    {
        uintmax_t value = 0u;

        return {ok, value};
    };

    BOOST_CHECK(parse_unsigned("20").expect(20u));
    BOOST_CHECK(parse_unsigned("  20  \r\n").expect(20u));
    BOOST_CHECK(parse_unsigned("20 20").fail());
    BOOST_CHECK(parse_unsigned("").fail());
    BOOST_CHECK(parse_unsigned("  \r\n").fail());
    BOOST_CHECK(parse_unsigned("+20").fail());
    BOOST_CHECK(parse_unsigned("-20").fail());
    BOOST_CHECK(parse_unsigned("+").fail());
    BOOST_CHECK(parse_unsigned("-").fail());
    BOOST_CHECK(parse_unsigned("twenty").fail());
    BOOST_CHECK(parse_unsigned("twenty20").fail());
    BOOST_CHECK(parse_unsigned("20twenty").fail());
}

BOOST_AUTO_TEST_CASE(parse_double)
{
    auto parse_double = [](std::string_view str) -> result<double>
    {
        double value = 0.0;

        return {ok, value};
    };

    BOOST_CHECK(parse_double("20.123").expect(20.123));
    BOOST_CHECK(parse_double("+20.123").expect(20.123));
    BOOST_CHECK(parse_double("-20.123").expect(-20.123));
    BOOST_CHECK(parse_double("  20.123  \r\n").expect(20.123));
    BOOST_CHECK(parse_double("20.123 20.123").fail());
    BOOST_CHECK(parse_double("").fail());
    BOOST_CHECK(parse_double("  \r\n").fail());
    BOOST_CHECK(parse_double("+").fail());
    BOOST_CHECK(parse_double("-").fail());
    BOOST_CHECK(parse_double(".").fail());
    BOOST_CHECK(parse_double("+.").fail());
    BOOST_CHECK(parse_double("-.").fail());
    BOOST_CHECK(parse_double("twenty.onetwothree").fail());
    BOOST_CHECK(parse_double("twenty20.123").fail());
    BOOST_CHECK(parse_double("20.123twenty").fail());
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace tests_30dc
