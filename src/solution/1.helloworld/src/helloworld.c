#include "helloworld.h"
#include <assert.h>

void run_helloworld(FILE* out)
{
    assert(out != NULL);

    fprintf(out, "Hello, World!\n");
}
