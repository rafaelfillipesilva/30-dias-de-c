#include "looooping.h"
#include "utils/string_utils.h"
#include <assert.h>
#include <stdio.h>

void run_looooping()
{
    static_assert(MAX_NUMBER_LENGTH >= 2, "Invalid buffer size.");

    printf("Digite o valor de N: ");

    char buffer[MAX_NUMBER_LENGTH] = { '\0' };
    char* number_str = fgets(buffer, MAX_NUMBER_LENGTH, stdin);

    if (number_str != NULL)
    {
        uintmax_t number = 0;
        const bool ok = parse_unsigned(number_str, MAX_NUMBER_LENGTH, &number);

        if (ok)
        {
            for (uintmax_t i = 0; i <= number; ++i)
            {
                const uintmax_t square = (i * i);

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
