#define BOOST_TEST_MAIN

#include <string_view>
#include <boost/test/unit_test.hpp>
#include "tests/result.hpp"
#include "pode_beber.h"

namespace tests_30dc {

inline constexpr std::uint16_t adult_age = ADULT_AGE;
inline constexpr std::uint32_t max_age   = MAX_AGE;

[[nodiscard]]
inline auto can_drink(uint16_t age) -> result<bool>
{
    return {::can_drink(age)};
}

[[nodiscard]]
inline auto parse_age(std::string_view age) -> result<uint16_t>
{
    uint16_t age_result = 0U;
    const bool ok = ::parse_age(age.data(), age.size() + 1U, &age_result);

    return {ok, age_result};
}

BOOST_AUTO_TEST_SUITE(pode_beber)

BOOST_AUTO_TEST_CASE(age_underage)
{
    BOOST_CHECK(can_drink(adult_age - 1U).expect(false));
}

BOOST_AUTO_TEST_CASE(age_adult)
{
    BOOST_CHECK(can_drink(adult_age).expect(true));
    BOOST_CHECK(can_drink(adult_age + 1U).expect(true));
}

BOOST_AUTO_TEST_CASE(parse_valid_age)
{
    BOOST_CHECK(parse_age("20").expect(20U));
}

BOOST_AUTO_TEST_CASE(parse_empty_age)
{
    BOOST_CHECK(parse_age("").fail());
    BOOST_CHECK(parse_age("  \r\n").fail());
}

BOOST_AUTO_TEST_CASE(parse_age_with_spaces)
{
    BOOST_CHECK(parse_age("  20  \r\n").expect(20U));
}

BOOST_AUTO_TEST_CASE(parse_too_high_age)
{
    BOOST_CHECK(parse_age(std::to_string(max_age + 1U)).fail());
}

BOOST_AUTO_TEST_CASE(parse_negative_age)
{
    BOOST_CHECK(parse_age("-20").fail());
}

BOOST_AUTO_TEST_CASE(parse_invalid_age)
{
    BOOST_CHECK(parse_age("20 20").fail());
    BOOST_CHECK(parse_age("twenty").fail());
    BOOST_CHECK(parse_age("twenty20").fail());
}

BOOST_AUTO_TEST_CASE(parse_age_with_text)
{
    BOOST_CHECK(parse_age("20twenty").fail());
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace tests_30dc
