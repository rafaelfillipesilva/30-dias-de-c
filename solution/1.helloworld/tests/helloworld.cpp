#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "expected_output.hpp"
#include "helloworld.h"

BOOST_AUTO_TEST_SUITE(helloworld)

BOOST_AUTO_TEST_CASE(output)
{
    expected_output expected("Hello, World!");
    BOOST_REQUIRE_MESSAGE(expected, "Failed to create temporary output.");

    expected.run(run_helloworld);
    BOOST_CHECK(expected.validate());
}

BOOST_AUTO_TEST_SUITE_END()
