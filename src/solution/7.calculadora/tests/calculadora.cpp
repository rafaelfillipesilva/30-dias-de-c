#define BOOST_TEST_MAIN

#include <cmath>
#include <limits>
#include <boost/test/unit_test.hpp>
#include "tests/result.hpp"
#include "operations.h"

namespace tests_30dc {

namespace operation {

template<uintmax_t ID, uintmax_t Operands, auto OperationFn>
struct operation
{
    static auto query_operation() -> result<uintmax_t>
    {
        uintmax_t operand_count = 0;
        const bool ok = ::query_operation(ID, &operand_count);

        return {ok, operand_count};
    }

    template<class... Args>
    static auto test(Args&&... args) -> result<double>
    {
        if (query_operation().is_not(Operands))
        {
            return {};
        }

        double value = 0.0;
        const bool ok = OperationFn(ID, std::forward<Args>(args)..., &value);

        return {ok, value};
    }
};

template<uintmax_t ID>
using binary_operation = operation<ID, OP_IN_BINARY, run_binary>;

template<uintmax_t ID>
using unary_operation = operation<ID, OP_IN_UNARY, run_unary>;

using add = binary_operation<OP_ADD>;
using sub = binary_operation<OP_SUB>;
using mul = binary_operation<OP_MUL>;
using div = binary_operation<OP_DIV>;

using fib = unary_operation<OP_FIB>;

} // namespace operation

BOOST_AUTO_TEST_SUITE(calculadora)

BOOST_AUTO_TEST_CASE(operations)
{
    BOOST_CHECK(operation::add::test(10.0, 10.0).expect( 20.0));
    BOOST_CHECK(operation::sub::test(30.0, 15.0).expect( 15.0));
    BOOST_CHECK(operation::mul::test(20.0, 20.0).expect(400.0));
    BOOST_CHECK(operation::div::test(60.0, 12.0).expect(  5.0));

    BOOST_CHECK(operation::fib::test(9.0).expect(34.0));
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace tests_30dc
