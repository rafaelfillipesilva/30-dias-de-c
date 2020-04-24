#define BOOST_TEST_MAIN

#include <string_view>
#include <boost/test/unit_test.hpp>
#include "pode_beber.h"

inline bool age_expect_success(std::string_view age, uint16_t age_check)
{
    uint16_t age_result = 0;
    const bool success = parse_age(age.data(), age.size() + 1, &age_result);

    return (success && (age_result == age_check));
}

inline bool age_expect_failure(std::string_view age)
{
    uint16_t age_result = 0;
    const bool success = parse_age(age.data(), age.size() + 1, &age_result);

    return !success;
}

BOOST_AUTO_TEST_SUITE(pode_beber)

BOOST_AUTO_TEST_CASE(age_underage)
{
    BOOST_CHECK(!can_drink(17));
}

BOOST_AUTO_TEST_CASE(age_eighteen)
{
    BOOST_CHECK(can_drink(18));
}

BOOST_AUTO_TEST_CASE(age_adult)
{
    BOOST_CHECK(can_drink(21));
}

BOOST_AUTO_TEST_CASE(parse_valid_age)
{
    BOOST_CHECK(age_expect_success("20", 20));
}

BOOST_AUTO_TEST_CASE(parse_empty_age)
{
    BOOST_CHECK(age_expect_failure(""));
}

BOOST_AUTO_TEST_CASE(parse_age_with_spaces)
{
    BOOST_CHECK(age_expect_success("  21   \n", 21));
}

BOOST_AUTO_TEST_CASE(parse_too_high_age)
{
    BOOST_CHECK(age_expect_failure("65536"));
}

BOOST_AUTO_TEST_CASE(parse_negative_age)
{
    BOOST_CHECK(age_expect_failure("-19"));
}

BOOST_AUTO_TEST_CASE(parse_invalid_age)
{
    BOOST_CHECK(age_expect_failure("nineteen19"));
}

BOOST_AUTO_TEST_CASE(parse_age_with_text)
{
    BOOST_CHECK(age_expect_failure("19nineteen"));
}

BOOST_AUTO_TEST_SUITE_END()
