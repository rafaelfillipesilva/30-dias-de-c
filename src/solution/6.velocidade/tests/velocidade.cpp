#define BOOST_TEST_MAIN

#include <cmath>
#include <limits>
#include <boost/test/unit_test.hpp>
#include "tests/result.hpp"
#include "velocidade.h"

namespace tests_30dc {

BOOST_AUTO_TEST_SUITE(velocidade)

BOOST_AUTO_TEST_CASE(convert_mps_to_kmph)
{
    auto mps_to_kmph = [](double mps) -> result<double>
    {
        return {::mps_to_kmph(mps)};
    };

    BOOST_CHECK(mps_to_kmph(+10.0).expect(+36.0));
    BOOST_CHECK(mps_to_kmph(-10.0).expect(-36.0));
    BOOST_CHECK(mps_to_kmph(32.00).expect(115.2));
    BOOST_CHECK(mps_to_kmph(-0.00).expect(+0.00));
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace tests_30dc
