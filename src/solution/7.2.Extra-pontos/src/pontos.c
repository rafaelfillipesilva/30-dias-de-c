#include "pontos.h"
#include "math.h"
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
            printf("Coordenada invalida.\n");
        }
    }
    else
    {
        printf("\n");
        printf("Nenhuma coordenada digitada.\n");
    }

    return success;
}

bool get_ponto(char* buffer, size_t buffer_size, struct ponto* ponto)
{
    assert((buffer != NULL) && (ponto != NULL));
    assert(buffer_size >= 2);

    bool success = false;

    printf("x: ");
    const bool x_ok = get_number(buffer, buffer_size, &ponto->x);

    if (x_ok)
    {
        printf("y: ");
        const bool y_ok = get_number(buffer, buffer_size, &ponto->y);

        if (y_ok)
        {
            success = true;
        }
    }

    return success;
}

/* Based on:
   https://en.wikipedia.org/wiki/Distance */
double calcular_distancia(struct ponto a, struct ponto b)
{
    const double dx = (b.x - a.x);
    const double dy = (b.y - a.y);

    const double dx_square = (dx * dx);
    const double dy_square = (dy * dy);

    const double square_sum = (dx_square + dy_square);

    const double distance = sqrt(square_sum);

    return distance;
}

void run_pontos()
{
    static_assert(MAX_NUMBER_LENGTH >= 2, "Invalid buffer size.");

    char buffer[MAX_NUMBER_LENGTH] = { '\0' };

    printf("Digite o ponto A:\n");

    struct ponto ponto_a = {.x = 0, .y = 0};
    const bool a_ok = get_ponto(buffer, MAX_NUMBER_LENGTH, &ponto_a);

    if (!a_ok)
    {
        return;
    }

    printf("\n");
    printf("Digite o ponto B:\n");

    struct ponto ponto_b = {.x = 0, .y = 0};
    const bool b_ok = get_ponto(buffer, MAX_NUMBER_LENGTH, &ponto_b);

    if (!b_ok)
    {
        return;
    }

    printf("\n");

    const double distancia = calcular_distancia(ponto_a, ponto_b);

    printf("Distancia: %f", distancia);
    printf("\n");
}
