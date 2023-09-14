#pragma once
#include <type_traits>

namespace R3::Math {

template<std::floating_point T, std::size_t S = 1>
struct Vec1
{
    T x;
    static constexpr auto size() { return S; }

    Vec1() = default;
    Vec1(const Vec1 &v) = default;
    Vec1(Vec1 &&v) noexcept = default;
    explicit Vec1(T x)
            : x(x)
    {};
    template<std::floating_point U>
    explicit Vec1(const Vec1<U> &v)
            : x(v.x)
    {};

    // Unary Constant Operators
    constexpr auto operator+() const {
        return this;
    }
    constexpr auto operator-() const {
        return Vec1 {
            -this->x,
        };
    }

    // Unary Arithmetic Operators
    constexpr auto &operator=(const Vec1 &v) {
        this->x = v.x;
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator=(const Vec1<U> &v) {
        this->x = static_cast<T>(v.x);
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator+=(const Vec1<U> &v) {
        this->x += static_cast<T>(v.x);
        return *this;
    }
    constexpr auto &operator+=(auto v) {
        this->x += static_cast<T>(v);
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator-=(const Vec1<U> &v) {
        this->x -= static_cast<T>(v.x);
        return *this;
    }
    constexpr auto &operator-=(auto v) {
        this->x -= static_cast<T>(v);
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator*=(const Vec1<U> &v) {
        this->x *= static_cast<T>(v.x);
        return *this;
    }
    constexpr auto &operator*=(auto v) {
        this->x *= static_cast<T>(v);
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator/=(const Vec1<U> &v) {
        this->x /= static_cast<T>(v.x);
        return *this;
    }
    constexpr auto &operator/=(auto v) {
        this->x /= static_cast<T>(v);
        return *this;
    }

    // Inc and Dec Operations
    constexpr auto &operator++() {
        ++this->x;
        return *this;
    }
    constexpr auto operator++(int) {
        const auto copy = Vec1(*this);
        ++*this;
        return copy;
    }
    constexpr auto &operator--() {
        --this->x;
        return *this;
    }
    constexpr auto operator--(int) {
        const auto copy = Vec1(*this);
        --*this;
        return copy;
    }

    // Binary Arithmetic Operators
    constexpr auto operator+(int s) const {
        return Vec1 {
                this->x + s,
        };
    }
    constexpr auto operator+(const auto &v) const {
        return Vec1 {
                this->x + v.x,
        };
    }
    constexpr auto operator-(int s) const {
        return Vec1 {
                this->x - s,
        };
    }
    constexpr auto operator-(const auto &v) const {
        return Vec1 {
                this->x - v.x,
        };
    }
    constexpr auto operator*(int s) const {
        return Vec1 {
                this->x * s,
        };
    }
    constexpr auto operator*(const auto &v) const {
        return Vec1 {
                this->x * v.x,
        };
    }
    constexpr auto operator/(int s) const {
        return Vec1 {
                this->x / s,
        };
    }
    constexpr auto operator/(const auto &v) const {
        return Vec1 {
                this->x / v.x,
        };
    }

    // Boolean Operators
    constexpr bool operator==(const auto &v) const {
        return (this->x == v.x);
    }
};

} // R3::Math
