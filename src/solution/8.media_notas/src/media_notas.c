#include "media_notas.h"
#include "utils/string_utils.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

double calc_average(double marks[], size_t count)
{
    assert(marks != NULL);

    double average = 0.0;

    for (size_t i = 0U; i < count; ++i)
    {
        average += (marks[i] / count);
    }

    return average;
}

bool get_number(char* buffer, size_t buffer_size, double* number)
{
    assert((buffer != NULL) && (number != NULL));
    assert(buffer_size >= 2U);

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
            printf("Nota invalida.\n");
        }
    }
    else
    {
        printf("\n");
        printf("Nota nao digitada.\n");
    }

    return success;
}

void run_media_notas()
{
    static_assert(MAX_NUMBER_LENGTH >= 2U, "Invalid buffer size.");

    char buffer[MAX_NUMBER_LENGTH] = { '\0' };

    double marks[MARK_COUNT] = { 0.0 };

    for (size_t i = 0; i < MARK_COUNT; ++i)
    {
        printf("Digite a %lu nota: ", (i + 1U));
        const bool ok = get_number(buffer, MAX_NUMBER_LENGTH, &marks[i]);

        if (!ok)
        {
            return;
        }
    }

    printf("\n");

    const double average = calc_average(marks, MARK_COUNT);

    printf("Media: %f", average);
    printf("\n");
}
