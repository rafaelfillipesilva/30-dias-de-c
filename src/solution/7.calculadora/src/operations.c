#include "operations.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>

bool op_add(double left, double right, double* result)
{
    assert(result != NULL);

    *result = (left + right);
    return true;
}

bool op_sub(double left, double right, double* result)
{
    assert(result != NULL);

    *result = (left - right);
    return true;
}

bool op_mul(double left, double right, double* result)
{
    assert(result != NULL);

    *result = (left * right);
    return true;
}

bool op_div(double left, double right, double* result)
{
    assert(result != NULL);

    *result = (left / right);
    return true;
}

/* Based on:
   https://en.wikipedia.org/wiki/Fibonacci_number */
double calc_fibonacci(const double n)
{
    if (n > 1)
    {
        return (calc_fibonacci(n - 1) + calc_fibonacci(n - 2));
    }
    else
    {
        return n;
    }
}

bool op_fib(double left, double* result)
{
    assert(result != NULL);

    *result = calc_fibonacci(left);
    return true;
}

void show_operations()
{
    printf("- %d: Adicao\n",        OP_ADD);
    printf("- %d: Subtracao\n",     OP_SUB);
    printf("- %d: Multiplicacao\n", OP_MUL);
    printf("- %d: Divisao\n",       OP_DIV);

    printf("- %d: Fibonacci\n",     OP_FIB);
}

void set_operands(uintmax_t* operands, uintmax_t count)
{
    if (operands != NULL)
    {
        *operands = count;
    }
}

bool query_operation(uintmax_t operation, uintmax_t* operands)
{
    switch (operation)
    {
    /* Binary operations */
    case OP_ADD:
        set_operands(operands, OP_IN_BINARY);
        return true;

    case OP_SUB:
        set_operands(operands, OP_IN_BINARY);
        return true;

    case OP_MUL:
        set_operands(operands, OP_IN_BINARY);
        return true;

    case OP_DIV:
        set_operands(operands, OP_IN_BINARY);
        return true;

    /* Unary operations */
    case OP_FIB:
        set_operands(operands, OP_IN_UNARY);
        return true;

    /* Unknown operation */
    default:
        return false;
    }
}

bool run_binary(uintmax_t op, double left, double right, double* result)
{
    assert(result != NULL);

    switch (op)
    {
    case OP_ADD: return op_add(left, right, result);
    case OP_SUB: return op_sub(left, right, result);
    case OP_MUL: return op_mul(left, right, result);
    case OP_DIV: return op_div(left, right, result);

    default: return false;
    }
}

bool run_unary(uintmax_t op, double left, double* result)
{
    assert(result != NULL);

    switch (op)
    {
    case OP_FIB: return op_fib(left, result);

    default: return false;
    }
}
