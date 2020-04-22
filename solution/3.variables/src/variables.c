#include "variables.h"
#include <stdio.h>

void run_variables()
{
    int first_num  = 4;
    int second_num = 2;

    int addition    = first_num + second_num;
    int subtraction = first_num - second_num;
    int product     = first_num * second_num;
    int quotient    = first_num / second_num;

    printf("Numeros: %d e %d\n", first_num, second_num);

    printf("Soma: %d\n", addition);
    printf("Diferenca: %d\n", subtraction);
    printf("Produto: %d\n", product);
    printf("Quociente: %d\n", quotient);
}
