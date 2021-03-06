#include "velocidade.h"
#include "utils/string_utils.h"
#include <assert.h>
#include <stdio.h>

double mps_to_kmph(double mps)
{
    double const seconds_to_hour = (60.0 * 60.0);
    double const meters_to_kilometers = 1000.0;

    return mps * (seconds_to_hour / meters_to_kilometers);
}

void run_velocidade()
{
    static_assert(MAX_NUMBER_LENGTH >= 2u, "Invalid buffer size.");

    printf("Digite a velocidade (em m/s): ");

    char buffer[MAX_NUMBER_LENGTH] = { '\0' };
    char* const mps_str = fgets(buffer, MAX_NUMBER_LENGTH, stdin);

    if (mps_str != NULL)
    {
        double mps = 0.0;
        bool const ok = parse_double(mps_str, MAX_NUMBER_LENGTH, &mps);

        if (ok)
        {
            double const kmph = mps_to_kmph(mps);
            printf("%f km/h\n", kmph);
        }
        else
        {
            printf("Velocidade invalida.");
        }
    }
    else
    {
        printf("\n");
        printf("Velocidade nao digitada.");
    }

    printf("\n");
}
