#pragma once
#include <type_traits>

namespace R3::Math {

template<std::floating_point T>
struct Vec2
{
    T x, y;

    Vec2() = default;
    Vec2(const Vec2 &v) = default;
    Vec2(Vec2 &&v)  noexcept = default;
    Vec2(T x, T y)
            : x(x),
              y(y)
    {};
    explicit Vec2(T s)
            : x(s),
              y(s)
    {};
    template<std::floating_point U>
    explicit Vec2(const Vec2<U> &v)
            : x(v.x),
              y(v.y)
    {};
    Vec2(const Vec1<T> &v, auto y)
            : x(v.x),
              y(y)
    {};

    // Unary Constant Operators
    constexpr auto operator+() const {
        return this;
    }
    constexpr auto operator-() const {
        return Vec2 {
            -this->x,
            -this->y,
        };
    }

    // Unary Arithmetic Operators
    constexpr auto &operator=(const auto &v) {
        this->x = v.x;
        this->y = v.y;
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator=(const Vec2<U> &v) {
        this->x = static_cast<T>(v.x);
        this->y = static_cast<T>(v.y);
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator+=(const Vec2<U> &v) {
        this->x += static_cast<T>(v.x);
        this->y += static_cast<T>(v.y);
        return *this;
    }
    constexpr auto &operator+=(auto v) {
        this->x += static_cast<T>(v);
        this->y += static_cast<T>(v);
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator-=(const Vec2<U> &v) {
        this->x -= static_cast<T>(v.x);
        this->y -= static_cast<T>(v.y);
        return *this;
    }
    constexpr auto &operator-=(auto v) {
        this->x -= static_cast<T>(v);
        this->y -= static_cast<T>(v);
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator*=(const Vec2<U> &v) {
        this->x *= static_cast<T>(v.x);
        this->y *= static_cast<T>(v.y);
        return *this;
    }
    constexpr auto &operator*=(auto v) {
        this->x *= static_cast<T>(v);
        this->y *= static_cast<T>(v);
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator/=(const Vec2<U> &v) {
        this->x /= static_cast<T>(v.x);
        this->y /= static_cast<T>(v.y);
        return *this;
    }
    constexpr auto &operator/=(auto v) {
        this->x /= static_cast<T>(v);
        this->y /= static_cast<T>(v);
        return *this;
    }

    // Inc and Dec Operations
    constexpr auto &operator++() {
        ++this->x;
        ++this->y;
        return *this;
    }
    constexpr auto operator++(auto) {
        const auto copy = Vec2(*this);
        ++*this;
        return copy;
    }
    constexpr auto &operator--() {
        --this->x;
        --this->y;
        return *this;
    }
    constexpr auto operator--(auto) {
        const auto copy = Vec2(*this);
        --*this;
        return copy;
    }

    // Binary Arithmetic Operators
    constexpr auto operator+(int s) const {
        return Vec2 {
                this->x + s,
                this->y + s,
        };
    }
    constexpr auto operator+(const auto &v) const {
        return Vec2 {
                this->x + v.x,
                this->y + v.y,
        };
    }
    constexpr auto operator-(int s) const {
        return Vec2 {
                this->x - s,
                this->y - s,
        };
    }
    constexpr auto operator-(const auto &v) const {
        return Vec2 {
                this->x - v.x,
                this->y - v.y,
        };
    }
    constexpr auto operator*(int s) const {
        return Vec2 {
                this->x * s,
                this->y * s,
        };
    }
    constexpr auto operator*(const auto &v) const {
        return Vec2 {
                this->x * v.x,
                this->y * v.y,
        };
    }
    constexpr auto operator/(int s) const {
        return Vec2 {
                this->x / s,
                this->y / s,
        };
    }
    constexpr auto operator/(const auto &v) const {
        return Vec2 {
                this->x / v.x,
                this->y / v.y,
        };
    }

    // Boolean Operators
    constexpr bool operator==(const auto &v) const {
        return (
                this->x == v.x &&
                this->y == v.y
        );
    }
};

} // R3::Math
