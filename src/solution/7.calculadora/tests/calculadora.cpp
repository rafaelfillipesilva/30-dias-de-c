#define BOOST_TEST_MAIN

#include <cmath>
#include <limits>
#include <boost/test/unit_test.hpp>
#include "tests/result.hpp"
#include "operations.h"

namespace tests_30dc {

namespace operation {

template<auto fn>
class operation
{
public:
    auto query_operation() const -> result<uintmax_t>
    {
        uintmax_t operand_count = 0U;
        const bool ok = ::query_operation(m_id, &operand_count);

        return {ok, operand_count};
    }

    template<class... Args>
    auto test(Args&&... args) const -> result<double>
    {
        if (query_operation().expect(m_operands))
        {
            double value = 0.0;
            const bool ok = fn(m_id, std::forward<Args>(args)..., &value);

            return {ok, value};
        }
        else
        {
            return {};
        }
    }

protected:
    constexpr operation(uintmax_t id, uintmax_t operands)
        : m_id{id}, m_operands{operands} { }

private:
    const uintmax_t m_id = 0U;
    const uintmax_t m_operands = 0U;
};

class binary_operation : public operation<run_binary>
{
public:
    constexpr binary_operation(uintmax_t id)
        : operation{id, OP_IN_BINARY} { }
};

class unary_operation : public operation<run_unary>
{
public:
    constexpr unary_operation(uintmax_t id)
        : operation{id, OP_IN_UNARY} { }
};

constexpr auto add = binary_operation{OP_ADD};
constexpr auto sub = binary_operation{OP_SUB};
constexpr auto mul = binary_operation{OP_MUL};
constexpr auto div = binary_operation{OP_DIV};

constexpr auto fib = unary_operation{OP_FIB};

} // namespace operation

BOOST_AUTO_TEST_SUITE(calculadora)

BOOST_AUTO_TEST_CASE(operations)
{
    BOOST_CHECK(operation::add.test(10.0, 10.0).expect( 20.0));
    BOOST_CHECK(operation::sub.test(30.0, 15.0).expect( 15.0));
    BOOST_CHECK(operation::mul.test(20.0, 20.0).expect(400.0));
    BOOST_CHECK(operation::div.test(60.0, 12.0).expect(  5.0));

    BOOST_CHECK(operation::fib.test(9.0).expect(34.0));
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace tests_30dc
