#include "looooping.h"
#include "utils/string_utils.h"
#include <assert.h>
#include <stdio.h>

void run_looooping()
{
    static_assert(MAX_NUMBER_LENGTH >= 2u, "Invalid buffer size.");

    printf("Digite o valor de N: ");

    char buffer[MAX_NUMBER_LENGTH] = { '\0' };
    char* number_str = fgets(buffer, MAX_NUMBER_LENGTH, stdin);

    if (number_str != NULL)
    {
        uintmax_t number = 0u;
        bool const ok = parse_unsigned(number_str, MAX_NUMBER_LENGTH, &number);

        if (ok)
        {
            for (uintmax_t i = 0u; i <= number; ++i)
            {
                uintmax_t const square = (i * i);

                if (square >= i)
                {
                    printf("%lu\n", square);
                }
                else /* Unsigned integer overflow (not a good check). */
                {
                    printf("Impossivel representar resultado.");
                    break;
                }
            }
        }
        else
        {
            printf("Numero invalido.");
        }
    }
    else
    {
        printf("\n");
        printf("Nenhum numero digitado.");
    }

    printf("\n");
}
