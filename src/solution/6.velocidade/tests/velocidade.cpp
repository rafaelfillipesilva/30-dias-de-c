#define BOOST_TEST_MAIN

#include <cmath>
#include <limits>
#include <boost/test/unit_test.hpp>
#include "velocidade.h"

BOOST_AUTO_TEST_SUITE(velocidade)

BOOST_AUTO_TEST_CASE(convert_mps_to_kmph)
{
    auto cmp_d = [](const double left, const double right)
    {
        constexpr auto epsilon = std::numeric_limits<double>::epsilon();
        return (std::fabs(left - right) <= epsilon);
    };

    BOOST_CHECK(cmp_d(mps_to_kmph(+10.0), +36.0));
    BOOST_CHECK(cmp_d(mps_to_kmph(-10.0), -36.0));
    BOOST_CHECK(cmp_d(mps_to_kmph(32.00), 115.2));
    BOOST_CHECK(cmp_d(mps_to_kmph(-0.00), +0.00));
}

BOOST_AUTO_TEST_SUITE_END()
