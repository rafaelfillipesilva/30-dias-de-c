#ifndef MEDIA_NOTAS_30_DIAS_DE_C_8
#define MEDIA_NOTAS_30_DIAS_DE_C_8

#include <stddef.h>

#define MAX_NUMBER_LENGTH 32u

#define MARK_COUNT 10u

#ifdef __cplusplus
extern "C" {
#endif

double calc_average(double marks[], size_t count);

void run_media_notas();

#ifdef __cplusplus
}
#endif

#endif // MEDIA_NOTAS_30_DIAS_DE_C_8
