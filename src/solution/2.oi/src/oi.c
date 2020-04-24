#include "oi.h"
#include "utils/string_utils.h"
#include <assert.h>

void run_oi(FILE* in, FILE* out)
{
    assert(MAX_NAME_LENGTH >= 2);
    assert((in != NULL) && (out != NULL));

    fprintf(out, "Digite seu nome: ");

    char buffer[MAX_NAME_LENGTH] = { '\0' };
    char* name = fgets(buffer, MAX_NAME_LENGTH, in);

    if (name != NULL)
    {
        rtrim_newline(name, MAX_NAME_LENGTH);
        fprintf(out, "Oi, %s", name);
    }
    else
    {
        fprintf(out, "\n");
        fprintf(out, "Oi, ser sem nome.");
    }

    fprintf(out, "\n");
}
