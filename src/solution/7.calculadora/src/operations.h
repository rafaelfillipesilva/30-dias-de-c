#ifndef OPERATIONS_30_DIAS_DE_C_7
#define OPERATIONS_30_DIAS_DE_C_7

#include <stdbool.h>
#include <stdint.h>

/* Operation details: Operands */
#define OP_IN_BINARY 2U
#define OP_IN_UNARY  1U

/* Binary operations */
#define OP_ADD 0U
#define OP_SUB 1U
#define OP_MUL 2U
#define OP_DIV 3U

/* Unary operations */
#define OP_FIB 4U

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
