#include "pontos.h"
#include "utils/string_utils.h"
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool get_number(char* buffer, size_t buffer_size, double* number)
{
    assert((buffer != NULL) && (number != NULL));
    assert(buffer_size >= 2u);

    bool success = false;

    char const* number_str = fgets(buffer, buffer_size, stdin);

    if (number_str != NULL)
    {
        bool const ok = parse_double(number_str, buffer_size, number);

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
        printf("Coordenada nao digitada.\n");
    }

    return success;
}

bool get_ponto(char* buffer, size_t buffer_size, struct ponto* ponto)
{
    assert((buffer != NULL) && (ponto != NULL));
    assert(buffer_size >= 2u);

    bool success = false;

    printf("x: ");
    bool const x_ok = get_number(buffer, buffer_size, &ponto->x);

    if (x_ok)
    {
        printf("y: ");
        bool const y_ok = get_number(buffer, buffer_size, &ponto->y);

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
    double const dx = (b.x - a.x);
    double const dy = (b.y - a.y);

    double const dx_square = (dx * dx);
    double const dy_square = (dy * dy);

    double const square_sum = (dx_square + dy_square);

    double const distance = sqrt(square_sum);

    return distance;
}

void run_pontos()
{
    static_assert(MAX_NUMBER_LENGTH >= 2u, "Invalid buffer size.");

    char buffer[MAX_NUMBER_LENGTH] = { '\0' };

    printf("Digite o ponto A:\n");

    struct ponto ponto_a = {.x = 0.0, .y = 0.0};
    bool const a_ok = get_ponto(buffer, MAX_NUMBER_LENGTH, &ponto_a);

    if (!a_ok)
    {
        return;
    }

    printf("\n");
    printf("Digite o ponto B:\n");

    struct ponto ponto_b = {.x = 0.0, .y = 0.0};
    bool const b_ok = get_ponto(buffer, MAX_NUMBER_LENGTH, &ponto_b);

    if (!b_ok)
    {
        return;
    }

    printf("\n");

    double const distancia = calcular_distancia(ponto_a, ponto_b);

    printf("Distancia: %f", distancia);
    printf("\n");
}
