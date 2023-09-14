#pragma once
#include <type_traits>

namespace R3::Math {

template<std::floating_point T>
struct Vec4
{
    T x, y, z, w;

    Vec4() = default;
    Vec4(const Vec4 &v) = default;
    Vec4(Vec4 &&v) noexcept = default;
    Vec4(T x, T y, T z, T w)
            : x(x),
              y(y),
              z(z),
              w(w)
    {};
    explicit Vec4(T s)
            : x(s),
              y(s),
              z(s),
              w(s)
    {};
    template<std::floating_point U>
    explicit Vec4(const Vec4<U> &v)
            : x(v.x),
              y(v.y),
              z(v.z)
    {};
    Vec4(const Vec1<T> &v, auto y, auto z, auto w)
            : x(v.x),
              y(y),
              z(z),
              w(w)
    {};
    Vec4(const Vec2<T> &v, auto z, auto w)
            : x(v.x),
              y(v.y),
              z(z),
              w(w)
    {};
    Vec4(const Vec3<T> &v, auto w)
            : x(v.x),
              y(v.y),
              z(v.z),
              w(w)
    {};

    // Unary Constant Operators
    constexpr auto operator+() const {
        return this;
    }
    constexpr auto operator-() const {
        return Vec4 {
            -this->x,
            -this->y,
            -this->z,
            -this->w,
        };
    }

    // Unary Arithmetic Operators
    constexpr auto &operator=(const auto &v) {
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
        this->w = v.w;
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator=(const auto &v) {
        this->x = static_cast<T>(v.x);
        this->y = static_cast<T>(v.y);
        this->z = static_cast<T>(v.z);
        this->w = static_cast<T>(v.w);
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator+=(const Vec4<U> &v) {
        this->x += static_cast<T>(v.x);
        this->y += static_cast<T>(v.y);
        this->z += static_cast<T>(v.z);
        this->w += static_cast<T>(v.w);
        return *this;
    }
    constexpr auto &operator+=(auto v) {
        this->x += static_cast<T>(v);
        this->y += static_cast<T>(v);
        this->z += static_cast<T>(v);
        this->w += static_cast<T>(v);
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator-=(const Vec4<U> &v) {
        this->x -= static_cast<T>(v.x);
        this->y -= static_cast<T>(v.y);
        this->z -= static_cast<T>(v.z);
        this->w -= static_cast<T>(v.w);
        return *this;
    }
    constexpr auto &operator-=(auto v) {
        this->x -= static_cast<T>(v);
        this->y -= static_cast<T>(v);
        this->z -= static_cast<T>(v);
        this->w -= static_cast<T>(v);
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator*=(const Vec4<U> &v) {
        this->x *= static_cast<T>(v.x);
        this->y *= static_cast<T>(v.y);
        this->z *= static_cast<T>(v.z);
        this->w *= static_cast<T>(v.w);
        return *this;
    }
    constexpr auto &operator*=(auto v) {
        this->x *= static_cast<T>(v);
        this->y *= static_cast<T>(v);
        this->z *= static_cast<T>(v);
        this->w *= static_cast<T>(v);
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator/=(const Vec4<U> &v) {
        this->x /= static_cast<T>(v.x);
        this->y /= static_cast<T>(v.y);
        this->z /= static_cast<T>(v.z);
        this->w /= static_cast<T>(v.w);
        return *this;
    }
    constexpr auto &operator/=(auto v) {
        this->x /= static_cast<T>(v);
        this->y /= static_cast<T>(v);
        this->z /= static_cast<T>(v);
        this->w /= static_cast<T>(v);
        return *this;
    }

    // Inc and Dec Operations
    constexpr auto &operator++() {
        ++this->x;
        ++this->y;
        ++this->z;
        ++this->w;
        return *this;
    }
    constexpr auto operator++(auto) {
        const auto copy = Vec4(*this);
        ++*this;
        return copy;
    }
    constexpr auto &operator--() {
        --this->x;
        --this->y;
        --this->z;
        --this->w;
        return *this;
    }
    constexpr auto operator--(auto) {
        const auto copy = Vec4(*this);
        --*this;
        return copy;
    }

    // Binary Arithmetic Operators
    constexpr auto operator+(int s) const {
        return Vec4 {
                this->x + s,
                this->y + s,
                this->z + s,
                this->w + s,
        };
    }
    constexpr auto operator+(const auto &v) const {
        return Vec4 {
                this->x + v.x,
                this->y + v.y,
                this->z + v.z,
                this->w + v.w,
        };
    }
    constexpr auto operator-(int s) const {
        return Vec4 {
                this->x - s,
                this->y - s,
                this->z - s,
                this->w - s,
        };
    }
    constexpr auto operator-(const auto &v) const {
        return Vec4 {
                this->x - v.x,
                this->y - v.y,
                this->z - v.z,
                this->w - v.w,
        };
    }
    constexpr auto operator*(int s) const {
        return Vec4 {
                this->x * s,
                this->y * s,
                this->z * s,
                this->w * s,
        };
    }
    constexpr auto operator*(const auto &v) const {
        return Vec4 {
                this->x * v.x,
                this->y * v.y,
                this->z * v.z,
                this->w * v.w,
        };
    }
    constexpr auto operator/(int s) const {
        return Vec4 {
                this->x / s,
                this->y / s,
                this->z / s,
                this->w / s,
        };
    }
    constexpr auto operator/(const auto &v) const {
        return Vec4 {
                this->x / v.x,
                this->y / v.y,
                this->z / v.z,
                this->w / v.w,
        };
    }

    // Boolean Operators
    constexpr bool operator==(const auto &v) const {
        return (
                this->x == v.x &&
                this->y == v.y &&
                this->z == v.z &&
                this->w == v.w
        );
    }
};

} // R3::Math
