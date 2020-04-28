#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "tests/expected_output.hpp"
#include "helloworld.h"

namespace tests_30dc {

BOOST_AUTO_TEST_SUITE(helloworld)

BOOST_AUTO_TEST_CASE(output)
{
    BOOST_CHECK(test_output(run_helloworld).expect("Hello, World!\n"));
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace tests_30dc
