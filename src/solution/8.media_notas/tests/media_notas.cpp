#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "tests/result.hpp"
#include "media_notas.h"

namespace tests_30dc {

BOOST_AUTO_TEST_SUITE(media_notas)

BOOST_AUTO_TEST_CASE(average)
{
    auto calc_average = []<std::size_t N>(std::array<double, N> marks)
                        -> result<double>
    {
        static_assert(N > 0u, "Requires at least one mark.");
        return {::calc_average(marks.data(), marks.size())};
    };

    BOOST_CHECK(calc_average(std::array{1.0, 2.0, 3.0, 4.0,  5.0,
                                        6.0, 7.0, 8.0, 9.0, 10.0}).expect(5.5));
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace tests_30dc
