#include "pode_beber.h"
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <stdio.h>

// Minimum expected age format size:
// [0-999+]:3 + '\n':4 + '\0':5
#define MIN_AGE_LENGTH 5

// Extra length allows ignoring space (see: isspace()) characters.
#define MAX_AGE_LENGTH 16

bool valid_str_bounds(const char* age_str, size_t buffer_size)
{
    assert(age_str != NULL);

    for (size_t i = 0; i < buffer_size; ++i)
    {
        if (age_str[i] == '\0')
        {
            return true;
        }
    }

    return false;
}

bool has_trailing_text(const char* str, char* end_ptr, size_t buffer_size)
{
    assert((str != NULL) && (end_ptr != NULL) && (end_ptr >= str));

    const size_t age_end = (end_ptr - str);

    for (size_t i = age_end; i < buffer_size; ++i)
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

bool parse_age(const char* age_str, size_t buffer_size, uint16_t* age_out)
{
    assert((age_str != NULL) && (age_out != NULL));

    if (!valid_str_bounds(age_str, buffer_size))
    {
        assert(valid_str_bounds(age_str, buffer_size));
        return false;
    }

    errno = 0;

    char* end_ptr = NULL;
    const uintmax_t age = strtoumax(age_str, &end_ptr, 10);

    const bool age_error = ((age == 0) || (age == UINTMAX_MAX))
                           && (errno == ERANGE);

    const bool age_in_range = ((age > 0) && (age <= UINT16_MAX));

    if (!age_error && age_in_range)
    {
        const bool has_text = has_trailing_text(age_str, end_ptr, buffer_size);

        if (!has_text)
        {
            *age_out = age;
            return true;
        }
    }

    return false;
}

bool can_drink(uint16_t age)
{
    return (age >= 18) ? true
                       : false;
}

void run_pode_beber()
{
    assert(MAX_AGE_LENGTH >= 2);
    assert(MAX_AGE_LENGTH >= MIN_AGE_LENGTH);

    printf("Digite sua idade: ");

    char buffer[MAX_AGE_LENGTH] = { '\0' };
    const char* age_str = fgets(buffer, MAX_AGE_LENGTH, stdin);

    if (age_str != NULL)
    {
        uint16_t age = 0;
        const bool age_parse_success = parse_age(age_str, MAX_AGE_LENGTH, &age);

        if (age_parse_success && can_drink(age))
        {
            printf("Pode beber!");
        }
        else if (age_parse_success && !can_drink(age))
        {
            printf("Nao pode beber!!! vai estudar");
        }
        else
        {
            printf("Idade invalida. Nao pode beber!");
        }
    }
    else
    {
        printf("\n");
        printf("Idade nao informada. Nao pode beber!");
    }

    printf("\n");
}
