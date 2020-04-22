#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "tests/expected_output.hpp"
#include "helloworld.h"

BOOST_AUTO_TEST_SUITE(helloworld)

BOOST_AUTO_TEST_CASE(output)
{
    expected_output expect("Hello, World!");

    BOOST_REQUIRE_MESSAGE(expect.is_ready(), "Open temporary test streams.");

    expect.run(run_helloworld);

    BOOST_CHECK(expect.validate());
}

BOOST_AUTO_TEST_SUITE_END()
