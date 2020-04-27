#define BOOST_TEST_MAIN

#include <cmath>
#include <limits>
#include <boost/test/unit_test.hpp>
#include "tests/number_utils.hpp"
#include "operations.h"

namespace operation {
    class result
    {
    public:
        constexpr result(bool ok, double value) : m_ok{ok}, m_value{value} { }

        constexpr bool expect(const double check)
        {
            return (m_ok && epsilon_cmp(check, m_value));
        }

        constexpr static result failure()
        {
            return {false, 0.0};
        }

    private:
        bool m_ok = false;
        double m_value = 0.0;
    };

    template<uintmax_t ID, uintmax_t Operands, auto OperationFn>
    struct operation
    {
        static bool test_operands()
        {
            uintmax_t operand_count = 0;
            const bool ok = query_operation(ID, &operand_count);

            return (ok && (Operands == operand_count));
        }

        template<class... Args>
        static result test(Args&&... args)
        {
            if (!test_operands())
            {
                return result::failure();
            }

            double value = 0.0;
            bool ok = OperationFn(ID, std::forward<Args>(args)..., &value);

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
}

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
