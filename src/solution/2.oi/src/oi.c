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

        size_t length = 0;
        const bool count_ok = count_nonspace(name, MAX_NAME_LENGTH, &length);

        if (count_ok)
        {
            if (length > 0)
            {
                fprintf(out, "Oi, %s", name);
            }
            else
            {
                fprintf(out, "Oi, ser sem nome.");
            }
        }
        else
        {
            fprintf(out, "Oi, ser com nome invalido.");
        }
    }
    else
    {
        fprintf(out, "\n");
        fprintf(out, "Oi, ser sem nome.");
    }

    fprintf(out, "\n");
}
