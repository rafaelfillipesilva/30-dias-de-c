#ifndef UTILS_30_DIAS_DE_C_STRING_H
#define UTILS_30_DIAS_DE_C_STRING_H

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void rtrim_newline(char* line, size_t buffer_size);

bool parse_unsigned(const char* str, size_t buffer_size, uintmax_t* out);

#ifdef __cplusplus
}
#endif

#endif /* UTILS_30_DIAS_DE_C_STRING_H */
