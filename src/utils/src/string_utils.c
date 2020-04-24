#include "utils/string_utils.h"
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdint.h>

void rtrim_newline(char* line, size_t buffer_size)
{
    assert(line != NULL);

    for (size_t i = 0; i < buffer_size; ++i)
    {
        if ('\n' == line[i])
        {
            line[i] = '\0';

            /* Deals with Windows \r\n special case on non-VC. */
            if ((i >= 1) && ('\r' == line[i - 1]))
            {
                line[i - 1] = '\0';
            }

            break;
        }
    }
}

bool has_trailing_junk(const char* str, const char* endptr, size_t buffer_size)
{
    assert((str != NULL) && (endptr != NULL));
    assert(endptr >= str);

    const size_t offset = (endptr - str);

    for (size_t i = offset; i < buffer_size; ++i)
    {
        if (str[i] == '\0')
        {
            break;
        }
        else if (!isspace(str[i]))
        {
            return true;
        }
    }

    return false;
}

bool can_parse_signed(const char* str, size_t buffer_size)
{
    assert(str != NULL);

    size_t counter = 0;

    for (size_t i = 0; i < buffer_size; ++i)
    {
        if (str[i] != '\0')
        {
            if (!isspace(str[i]))
            {
                ++counter;
            }
        }
        else
        {
            return (counter > 0);
        }
    }

    return false;
}

bool parse_signed(const char* str, size_t buffer_size, intmax_t* out)
{
    assert((str != NULL) && (out != NULL));

    const bool can_parse = can_parse_signed(str, buffer_size);

    if (!can_parse)
    {
        return false;
    }

    errno = 0;

    char* end_ptr = NULL;
    const intmax_t result = strtoimax(str, &end_ptr, 10);

    const bool has_error = ((result == INTMAX_MIN) || (result == INTMAX_MAX))
                           && (errno == ERANGE);

    if (!has_error)
    {
        const bool has_junk = has_trailing_junk(str, end_ptr, buffer_size);

        if (!has_junk)
        {
            *out = result;
            return true;
        }
    }

    return false;
}

bool can_parse_unsigned(const char* str, size_t buffer_size)
{
    assert(str != NULL);

    size_t counter = 0;

    for (size_t i = 0; i < buffer_size; ++i)
    {
        if (str[i] != '\0')
        {
            if (isdigit(str[i]))
            {
                ++counter;
            }
            else if (!isspace(str[i]))
            {
                break;
            }
        }
        else
        {
            return (counter > 0);
        }
    }

    return false;
}

bool parse_unsigned(const char* str, size_t buffer_size, uintmax_t* out)
{
    assert((str != NULL) && (out != NULL));

    const bool can_parse = can_parse_unsigned(str, buffer_size);

    if (!can_parse)
    {
        return false;
    }

    errno = 0;

    char* end_ptr = NULL;
    const uintmax_t result = strtoumax(str, &end_ptr, 10);

    const bool has_error = ((result == 0) || (result == UINTMAX_MAX))
                           && (errno == ERANGE);

    if (!has_error)
    {
        const bool has_junk = has_trailing_junk(str, end_ptr, buffer_size);

        if (!has_junk)
        {
            *out = result;
            return true;
        }
    }

    return false;
}
