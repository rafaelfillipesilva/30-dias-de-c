#define BOOST_TEST_MAIN

#include <string_view>
#include <boost/test/unit_test.hpp>
#include "pode_beber.h"

inline constexpr std::uint16_t adult_age = ADULT_AGE;
inline constexpr std::uint32_t max_age   = MAX_AGE;

inline bool age_expect_success(std::string_view age, const uint16_t age_check)
{
    uint16_t age_result = 0;
    const bool success = parse_age(age.data(), age.size() + 1, &age_result);

    return (success && (age_check == age_result));
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
    BOOST_CHECK(!can_drink(adult_age - 1));
}

BOOST_AUTO_TEST_CASE(age_adult)
{
    BOOST_CHECK(can_drink(adult_age));
    BOOST_CHECK(can_drink(adult_age + 1));
}

BOOST_AUTO_TEST_CASE(parse_valid_age)
{
    BOOST_CHECK(age_expect_success("20", 20));
}

BOOST_AUTO_TEST_CASE(parse_empty_age)
{
    BOOST_CHECK(age_expect_failure(""));
    BOOST_CHECK(age_expect_failure("  \r\n"));
}

BOOST_AUTO_TEST_CASE(parse_age_with_spaces)
{
    BOOST_CHECK(age_expect_success("  20  \r\n", 20));
}

BOOST_AUTO_TEST_CASE(parse_too_high_age)
{
    BOOST_CHECK(age_expect_failure(std::to_string(max_age + 1)));
}

BOOST_AUTO_TEST_CASE(parse_negative_age)
{
    BOOST_CHECK(age_expect_failure("-20"));
}

BOOST_AUTO_TEST_CASE(parse_invalid_age)
{
    BOOST_CHECK(age_expect_failure("20 20"));
    BOOST_CHECK(age_expect_failure("twenty"));
    BOOST_CHECK(age_expect_failure("twenty20"));
}

BOOST_AUTO_TEST_CASE(parse_age_with_text)
{
    BOOST_CHECK(age_expect_failure("20twent"));
}

BOOST_AUTO_TEST_SUITE_END()
