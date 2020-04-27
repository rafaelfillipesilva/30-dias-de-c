#define BOOST_TEST_MAIN

#include <cmath>
#include <limits>
#include <boost/test/unit_test.hpp>
#include "tests/number_utils.hpp"
#include "velocidade.h"

BOOST_AUTO_TEST_SUITE(velocidade)

BOOST_AUTO_TEST_CASE(convert_mps_to_kmph)
{
    BOOST_CHECK(epsilon_cmp(mps_to_kmph(+10.0), +36.0));
    BOOST_CHECK(epsilon_cmp(mps_to_kmph(-10.0), -36.0));
    BOOST_CHECK(epsilon_cmp(mps_to_kmph(32.00), 115.2));
    BOOST_CHECK(epsilon_cmp(mps_to_kmph(-0.00), +0.00));
}

BOOST_AUTO_TEST_SUITE_END()
