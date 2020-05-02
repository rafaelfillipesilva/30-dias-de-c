#ifndef RESULT_30_DIAS_DE_C_I
#define RESULT_30_DIAS_DE_C_I

#include <cmath>
#include <limits>
#include <type_traits>

namespace tests_30dc {

template<typename T>
class [[nodiscard]] result
{
public:
    constexpr result()
        : m_ok{false} { }

    explicit(!std::is_fundamental_v<T>)
    constexpr result(T value)
        : m_ok{true}, m_value{std::move(value)} { }

    constexpr result(bool ok, T value)
        : m_ok{ok}, m_value{std::move(value)} { }

    template<typename Fn>
    requires std::is_invocable_v<Fn, T const>
    [[nodiscard]]
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

    [[nodiscard]]
    constexpr auto expect(auto const& check) const -> result<T>
    {
        if constexpr (std::is_floating_point_v<T>)
        {
            constexpr auto epsilon = std::numeric_limits<T>::epsilon();
            return {pass() && (std::fabs(m_value - check) <= epsilon), m_value};
        }
        else
        {
            return {pass() && (m_value == check), m_value};
        }
    }

    [[nodiscard]]
    constexpr auto also_is(auto const& check) const -> result<T>
    {
        return expect(check);
    }

    [[nodiscard]]
    constexpr auto is_not(auto const& check) const -> bool
    {
        return !expect(check);
    }

    [[nodiscard]]
    constexpr auto pass() const -> bool
    {
        return m_ok;
    }

    [[nodiscard]]
    constexpr auto fail() const -> bool
    {
        return !pass();
    }

    [[nodiscard]]
    explicit constexpr operator bool() const
    {
        return pass();
    }

private:
    bool m_ok = false;
    T m_value{};
};

} // namespace tests_30dc

#endif // RESULT_30_DIAS_DE_C_I
