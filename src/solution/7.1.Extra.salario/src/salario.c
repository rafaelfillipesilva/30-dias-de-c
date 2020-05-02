#include "salario.h"
#include "utils/string_utils.h"
#include <assert.h>
#include <stdio.h>

bool calcular_salario(uintmax_t horas_trabalhadas, uintmax_t* salario)
{
    assert(salario != NULL);

    /* Not applicable for the formula, results in uncorrect salary. */
    if (horas_trabalhadas < 2u)
    {
        return false;
    }

    uintmax_t const adjusted_hours = (horas_trabalhadas - 2u);
    uintmax_t const salary = (adjusted_hours * adjusted_hours);

    /* Unsigned integer overflow (not a good check). */
    if (salary < adjusted_hours)
    {
        return false;
    }

    *salario = salary;
    return true;
}

void run_salario()
{
    static_assert(MAX_NUMBER_LENGTH >= 2u, "Invalid buffer size.");

    printf("Digite o numero de horas trabalhadas: ");

    char buffer[MAX_NUMBER_LENGTH] = { '\0' };
    char* const horas_str = fgets(buffer, MAX_NUMBER_LENGTH, stdin);

    if (horas_str != NULL)
    {
        uintmax_t horas = 0u;
        bool const ok = parse_unsigned(horas_str, MAX_NUMBER_LENGTH, &horas);

        if (ok)
        {
            uintmax_t salario = 0u;
            bool const success = calcular_salario(horas, &salario);

            if (success)
            {
                printf("Salario: %lu", salario);
            }
            else
            {
                printf("Impossivel calcular salario.");
            }
        }
        else
        {
            printf("Numero de horas invalido.");
        }
    }
    else
    {
        printf("\n");
        printf("Numero de horas nao digitado.");
    }

    printf("\n");
}
