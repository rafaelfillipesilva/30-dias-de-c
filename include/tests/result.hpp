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

    template<class Fn>
    constexpr auto transform(Fn fn) const
    {
        using result_type = result<decltype(fn(m_value))>;

        if (pass())
        {
            return result_type{fn(m_value)};
        }
        else
        {
            return result_type{};
        }
    }

    template<class U>
    constexpr auto expect(const U& check) const -> bool
    {
        if constexpr (std::is_floating_point_v<T>)
        {
            constexpr auto epsilon = std::numeric_limits<T>::epsilon();
            return (pass() && (std::fabs(m_value - check) <= epsilon));
        }
        else
        {
            return (pass() && (m_value == check));
        }
    }

    template<class U>
    constexpr auto is_not(const U& check) const -> bool
    {
        return !expect(check);
    }

    constexpr auto pass() const -> bool
    {
        return m_ok;
    }

    constexpr auto fail() const -> bool
    {
        return !pass();
    }

private:
    bool m_ok = false;
    T m_value{};
};

} // namespace tests_30dc

#endif // RESULT_30_DIAS_DE_C_I
