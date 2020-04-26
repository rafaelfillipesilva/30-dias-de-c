#include "velocidade.h"
#include "utils/string_utils.h"
#include <assert.h>
#include <stdio.h>

double mps_to_kmph(double mps)
{
    const double seconds_to_hour = (60.0 * 60.0);
    const double meters_to_kilometers = 1000.0;

    return mps * (seconds_to_hour / meters_to_kilometers);
}

void run_velocidade()
{
    assert(MAX_NUMBER_LENGTH >= 2);

    printf("Digite a velocidade (em m/s): ");

    char buffer[MAX_NUMBER_LENGTH] = { '\0' };
    const char* ms_str = fgets(buffer, MAX_NUMBER_LENGTH, stdin);

    if (ms_str != NULL)
    {
        double mps = 0;
        const bool ok = parse_double(ms_str, MAX_NUMBER_LENGTH, &mps);

        if (ok)
        {
            const double kmph = mps_to_kmph(mps);
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
