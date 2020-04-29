#define BOOST_TEST_MAIN

#include <limits>
#include <boost/test/unit_test.hpp>
#include "tests/result.hpp"
#include "salario.h"

namespace tests_30dc {

BOOST_AUTO_TEST_SUITE(salario)

BOOST_AUTO_TEST_CASE(work_hours)
{
    auto calcular_salario = [](uintmax_t hours) -> result<uintmax_t>
    {
        uintmax_t salary = 0;
        const bool ok = ::calcular_salario(hours, &salary);

        return {ok, salary};
    };

    BOOST_CHECK(calcular_salario(0).fail());
    BOOST_CHECK(calcular_salario(1).fail());

    BOOST_CHECK(calcular_salario(2).expect(0));

    BOOST_CHECK(calcular_salario(10).expect(64));

    constexpr auto max = std::numeric_limits<uintmax_t>::max();
    BOOST_CHECK(calcular_salario(max).fail());
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace tests_30dc
