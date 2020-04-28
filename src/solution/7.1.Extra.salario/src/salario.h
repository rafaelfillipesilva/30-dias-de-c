#ifndef SALARIO_30_DIAS_DE_C_7_1
#define SALARIO_30_DIAS_DE_C_7_1

#include <stdbool.h>
#include <stdint.h>

#define MAX_NUMBER_LENGTH 32

#ifdef __cplusplus
extern "C" {
#endif

bool calcular_salario(uintmax_t horas_trabalhadas, uintmax_t* salario);

void run_salario();

#ifdef __cplusplus
}
#endif

#endif // SALARIO_30_DIAS_DE_C_7_1
