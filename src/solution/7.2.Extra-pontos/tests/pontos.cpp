#define BOOST_TEST_MAIN

#include <cmath>
#include <boost/test/unit_test.hpp>
#include "tests/result.hpp"
#include "pontos.h"

namespace tests_30dc {

inline auto calcular_distancia(::ponto a, ::ponto b) -> result<double>
{
    const double distance = ::calcular_distancia(a, b);
    return {distance};
}

BOOST_AUTO_TEST_SUITE(pontos)

BOOST_AUTO_TEST_CASE(distancia)
{
// Based on:
// https://brasilescola.uol.com.br/matematica/distancia-entre-dois-pontos.htm
    BOOST_CHECK(calcular_distancia({-3.0, -11.0},
                                   { 2.0,   1.0}).expect(13.0));

    BOOST_CHECK(calcular_distancia({ 1.0, 10.0},
                                   {-1.0,  5.0}).expect(std::sqrt(29.0)));

    BOOST_CHECK(calcular_distancia({-2.0,  1.0},
                                   { 6.0,  7.0}).expect(10.0));

    BOOST_CHECK(calcular_distancia({-2.0, 13.0},
                                   { 6.0,  7.0}).expect(10.0));
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace tests_30dc
