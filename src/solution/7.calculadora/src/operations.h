#ifndef OPERATIONS_30_DIAS_DE_C_7
#define OPERATIONS_30_DIAS_DE_C_7

#include <stdbool.h>
#include <stdint.h>

/* Operation details: Operands */
#define OP_IN_BINARY 2u
#define OP_IN_UNARY  1u

/* Binary operations */
#define OP_ADD 0u
#define OP_SUB 1u
#define OP_MUL 2u
#define OP_DIV 3u

/* Unary operations */
#define OP_FIB 4u

#ifdef __cplusplus
extern "C" {
#endif

void show_operations();

bool query_operation(uintmax_t operation, uintmax_t* operands);

bool run_binary(uintmax_t op, double left, double right, double* result);
bool run_unary(uintmax_t op, double left, double* result);

#ifdef __cplusplus
}
#endif

#endif /* OPERATIONS_30_DIAS_DE_C_7 */
