#ifndef PODE_BEBER_30_DIAS_DE_C_4
#define PODE_BEBER_30_DIAS_DE_C_4

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Minimum expected age format size:
// [0-999+]:3 + '\n':4 + '\0':5
#define MIN_AGE_LENGTH 5

// Extra length allows ignoring space (see: isspace()) characters.
#define MAX_AGE_LENGTH 16

#define ADULT_AGE 18

#define MAX_AGE UINT16_MAX

#ifdef __cplusplus
extern "C" {
#endif

bool parse_age(const char* age_str, size_t buffer_size, uint16_t* age_out);
bool can_drink(uint16_t age);

void run_pode_beber();

#ifdef __cplusplus
}
#endif

#endif // PODE_BEBER_30_DIAS_DE_C_4
