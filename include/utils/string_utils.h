#ifndef UTILS_30_DIAS_DE_C_STRING_H
#define UTILS_30_DIAS_DE_C_STRING_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void rtrim_newline(char* line, size_t buffer_size);

bool count_nonspace(char const* str, size_t buffer_size, size_t* count);

bool parse_signed(char const* str, size_t buffer_size, intmax_t* out);
bool parse_unsigned(char const* str, size_t buffer_size, uintmax_t* out);
bool parse_double(char const* str, size_t buffer_size, double* out);

#ifdef __cplusplus
}
#endif

#endif /* UTILS_30_DIAS_DE_C_STRING_H */
