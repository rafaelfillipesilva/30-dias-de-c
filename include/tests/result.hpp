#ifndef RESULT_30_DIAS_DE_C_I
#define RESULT_30_DIAS_DE_C_I

#include <cmath>
#include <limits>
#include <type_traits>

namespace tests_30dc {

template<class T>
class result
{
public:
    constexpr result()
        : m_ok{false} { }

    constexpr result(T value)
        : m_ok{true}, m_value{std::move(value)} { }

    constexpr result(bool ok, T value)
        : m_ok{ok}, m_value{std::move(value)} { }

    constexpr bool expect(const T& check) const
    {
        if constexpr (std::is_floating_point_v<T>)
        {
            constexpr auto epsilon = std::numeric_limits<T>::epsilon();
            return (m_ok && (std::fabs(m_value - check) <= epsilon));
        }
        else
        {
            return (m_ok && (m_value == check));
        }
    }

    constexpr bool is_not(const T& check) const
    {
        return !expect(check);
    }

    constexpr bool pass() const
    {
        return m_ok;
    }

    constexpr bool fail() const
    {
        return !m_ok;
    }

private:
    bool m_ok = false;
    T m_value{};
};

} // namespace tests_30dc

#endif // RESULT_30_DIAS_DE_C_I
