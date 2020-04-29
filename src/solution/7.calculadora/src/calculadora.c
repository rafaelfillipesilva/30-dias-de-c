#include "calculadora.h"
#include "operations.h"
#include "utils/string_utils.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool get_number(char* buffer, size_t buffer_size, double* number)
{
    assert((buffer != NULL) && (number != NULL));
    assert(buffer_size >= 2);

    bool success = false;

    const char* number_str = fgets(buffer, buffer_size, stdin);

    if (number_str != NULL)
    {
        const bool ok = parse_double(number_str, buffer_size, number);

        if (ok)
        {
            success = true;
        }
        else
        {
            printf("Numero invalido.\n");
        }
    }
    else
    {
        printf("\n");
        printf("Numero nao digitado.\n");
    }

    return success;
}

bool get_operation(char* buffer, size_t buffer_size, uintmax_t* operation)
{
    assert((buffer != NULL) && (operation != NULL));
    assert(buffer_size >= 2);

    bool success = false;

    const char* operation_str = fgets(buffer, buffer_size, stdin);

    if (operation_str != NULL)
    {
        const bool ok = parse_unsigned(operation_str, buffer_size, operation);

        if (ok)
        {
            success = true;
        }
        else
        {
            printf("Operacao invalida.\n");
        }
    }
    else
    {
        printf("\n");
        printf("Operacao nao digitada.\n");
    }

    return success;
}

bool get_operands(uintmax_t operation, uintmax_t* operands)
{
    assert(operands != NULL);

    const bool success = query_operation(operation, operands);

    assert(!success || (success
                        && ((OP_IN_BINARY == *operands) ||
                            (OP_IN_UNARY  == *operands))));

    if (!success)
    {
        printf("Operacao invalida.\n");
    }

    return success;
}

void run_calculadora()
{
    static_assert(MAX_NUMBER_LENGTH >= 2, "Invalid buffer size.");

    char buffer[MAX_NUMBER_LENGTH] = { '\0' };

    uintmax_t operation = 0;
    uintmax_t operands  = 0;

    for (;;)
    {
        printf("Digite a operacao: \n");
        show_operations();

        printf("> ");
        const bool op_ok = get_operation(buffer, MAX_NUMBER_LENGTH, &operation);

        if (op_ok)
        {
            const bool query_ok = get_operands(operation, &operands);

            if (query_ok)
            {
                break;
            }
        }

        printf("\n");
    }

    printf("\n");

    double result = 0.0;
    bool success = false;

    if (OP_IN_BINARY == operands)
    {
        double left_number = 0.0;
        printf("Digite o primeiro numero: ");
        const bool n1_ok = get_number(buffer, MAX_NUMBER_LENGTH, &left_number);
        if (!n1_ok) return;

        double right_number = 0.0;
        printf("Digite o segundo numero: ");
        const bool n2_ok = get_number(buffer, MAX_NUMBER_LENGTH, &right_number);
        if (!n2_ok) return;

        success = run_binary(operation, left_number, right_number, &result);
    }
    else if (OP_IN_UNARY == operands)
    {
        double left_number = 0.0;
        printf("Digite o primeiro numero: ");
        const bool n1_ok = get_number(buffer, MAX_NUMBER_LENGTH, &left_number);
        if (!n1_ok) return;

        success = run_unary(operation, left_number, &result);
    }

    printf("\n");

    if (success)
    {
        printf("Resultado: %f", result);
    }
    else
    {
        printf("Erro ao executar operacao.");
    }

    printf("\n");
}
