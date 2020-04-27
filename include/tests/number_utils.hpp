#ifndef NUMBER_UTILS_30_DIAS_DE_C_I
#define NUMBER_UTILS_30_DIAS_DE_C_I

#include <cmath>
#include <limits>
#include <type_traits>

template<class T>
inline constexpr bool epsilon_cmp(T left, T right)
{
    static_assert(std::is_floating_point_v<T>, "Requires a floating point.");

    constexpr auto epsilon = std::numeric_limits<T>::epsilon();
    return (std::fabs(left - right) <= epsilon);
}

#endif // NUMBER_UTILS_30_DIAS_DE_C_I
