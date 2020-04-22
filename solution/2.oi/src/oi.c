#include "oi.h"
#include <assert.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

void rtrim_line(char* line, size_t buffer_size)
{
    assert(line != NULL);

    for (size_t i = 0; i < buffer_size; ++i)
    {
        if ('\n' == line[i])
        {
            line[i] = '\0';

            // Deals with Windows \r\n special case on non-VC.
            if ((i >= 1) && ('\r' == line[i - 1]))
            {
                line[i - 1] = '\0';
            }

            break;
        }
    }
}

void run_oi(FILE* in, FILE* out)
{
    assert((in != NULL) && (out != NULL));

    fprintf(out, "Digite seu nome: ");

    char buffer[MAX_NAME_LENGTH] = { '\0' };
    char* name = fgets(buffer, MAX_NAME_LENGTH, in);

    if (name != NULL)
    {
        rtrim_line(name, MAX_NAME_LENGTH);
        fprintf(out, "Oi, %s", name);
    }
    else
    {
        fprintf(out, "\n");
        fprintf(out, "Oi, ser sem nome.");
    }

    fprintf(out, "\n");
}
