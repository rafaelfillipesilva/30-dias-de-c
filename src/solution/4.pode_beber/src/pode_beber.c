#include "pode_beber.h"
#include "utils/string_utils.h"
#include <assert.h>
#include <stdio.h>

bool parse_age(const char* age_str, size_t buffer_size, uint16_t* age_out)
{
    static_assert(MAX_AGE <= UINT16_MAX, "Invalid age range.");
    assert((age_str != NULL) && (age_out != NULL));

    uintmax_t age = 0U;
    const bool parse_success = parse_unsigned(age_str, buffer_size, &age);
    const bool age_in_range  = ((age > 0U) && (age <= MAX_AGE));

    if (parse_success && age_in_range)
    {
        *age_out = age;
        return true;
    }

    return false;
}

bool can_drink(uint16_t age)
{
    return (age >= ADULT_AGE) ? true
                              : false;
}

void run_pode_beber()
{
    static_assert(MAX_AGE_LENGTH >= 2U, "Invalid buffer size.");
    static_assert(MAX_AGE_LENGTH >= MIN_AGE_LENGTH, "Invalid buffer size.");

    printf("Digite sua idade: ");

    char buffer[MAX_AGE_LENGTH] = { '\0' };
    const char* age_str = fgets(buffer, MAX_AGE_LENGTH, stdin);

    if (age_str != NULL)
    {
        uint16_t age = 0U;
        const bool parse_success = parse_age(age_str, MAX_AGE_LENGTH, &age);

        if (parse_success && can_drink(age))
        {
            printf("Pode beber!");
        }
        else if (parse_success && !can_drink(age))
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
