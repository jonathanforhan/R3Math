#pragma once
#include <type_traits>

namespace R3::Math {

template<std::floating_point T, std::size_t S = 3>
struct Vec3
{
    T x, y, z;
    static constexpr auto size() { return S; }

    Vec3() = default;
    Vec3(const Vec3 &v) = default;
    Vec3(Vec3 &&v)  noexcept = default;
    Vec3(T x, T y, T z)
            : x(x),
              y(y),
              z(z)
    {};
    explicit Vec3(T s)
            : x(s),
              y(s),
              z(s)
    {};
    template<std::floating_point U>
    explicit Vec3(const Vec3<U> &v)
            : x(v.x),
              y(v.y),
              z(v.z)
    {};
    Vec3(const Vec1<T> &v, auto y, auto z)
            : x(v.x),
              y(y),
              z(z)
    {};
    Vec3(const Vec2<T> &v, auto z)
            : x(v.x),
              y(v.y),
              z(z)
    {};

    // Unary Constant Operators
    constexpr auto operator+() const {
        return this;
    }
    constexpr auto operator-() const {
        return Vec3 {
            -this->x,
            -this->y,
            -this->z,
        };
    }

    // Unary Arithmetic Operators
    constexpr auto &operator=(const auto &v) {
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator=(const Vec3<U> &v) {
        this->x = static_cast<T>(v.x);
        this->y = static_cast<T>(v.y);
        this->z = static_cast<T>(v.z);
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator+=(const Vec3<U> &v) {
        this->x += static_cast<T>(v.x);
        this->y += static_cast<T>(v.y);
        this->z += static_cast<T>(v.z);
        return *this;
    }
    constexpr auto &operator+=(auto v) {
        this->x += static_cast<T>(v);
        this->y += static_cast<T>(v);
        this->z += static_cast<T>(v);
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator-=(const Vec3<U> &v) {
        this->x -= static_cast<T>(v.x);
        this->y -= static_cast<T>(v.y);
        this->z -= static_cast<T>(v.z);
        return *this;
    }
    constexpr auto &operator-=(auto v) {
        this->x -= static_cast<T>(v);
        this->y -= static_cast<T>(v);
        this->z -= static_cast<T>(v);
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator*=(const Vec3<U> &v) {
        this->x *= static_cast<T>(v.x);
        this->y *= static_cast<T>(v.y);
        this->z *= static_cast<T>(v.z);
        return *this;
    }
    constexpr auto &operator*=(auto v) {
        this->x *= static_cast<T>(v);
        this->y *= static_cast<T>(v);
        this->z *= static_cast<T>(v);
        return *this;
    }
    template<std::floating_point U>
    constexpr auto &operator/=(const Vec3<U> &v) {
        this->x /= static_cast<T>(v.x);
        this->y /= static_cast<T>(v.y);
        this->z /= static_cast<T>(v.z);
        return *this;
    }
    constexpr auto &operator/=(auto v) {
        this->x /= static_cast<T>(v);
        this->y /= static_cast<T>(v);
        this->z /= static_cast<T>(v);
        return *this;
    }

    // Inc and Dec Operations
    constexpr auto &operator++() {
        ++this->x;
        ++this->y;
        ++this->z;
        return *this;
    }
    constexpr auto operator++(auto) {
        const auto copy = Vec3(*this);
        ++*this;
        return copy;
    }
    constexpr auto &operator--() {
        --this->x;
        --this->y;
        --this->z;
        return *this;
    }
    constexpr auto operator--(auto) {
        const auto copy = Vec3(*this);
        --*this;
        return copy;
    }

    // Binary Arithmetic Operators
    constexpr auto operator+(int s) const {
        return Vec3 {
                this->x + s,
                this->y + s,
                this->z + s,
        };
    }
    constexpr auto operator+(const auto &v) const {
        return Vec3 {
                this->x + v.x,
                this->y + v.y,
                this->z + v.z,
        };
    }
    constexpr auto operator-(int s) const {
        return Vec3 {
                this->x - s,
                this->y - s,
                this->z - s,
        };
    }
    constexpr auto operator-(const auto &v) const {
        return Vec3 {
                this->x - v.x,
                this->y - v.y,
                this->z - v.z,
        };
    }
    constexpr auto operator*(int s) const {
        return Vec3 {
                this->x * s,
                this->y * s,
                this->z * s,
        };
    }
    constexpr auto operator*(const auto &v) const {
        return Vec3 {
                this->x * v.x,
                this->y * v.y,
                this->z * v.z,
        };
    }
    constexpr auto operator/(int s) const {
        return Vec3 {
                this->x / s,
                this->y / s,
                this->z / s,
        };
    }
    constexpr auto operator/(const auto &v) const {
        return Vec3 {
                this->x / v.x,
                this->y / v.y,
                this->z / v.z,
        };
    }

    // Boolean Operators
    constexpr bool operator==(const auto &v) const {
        return (
                this->x == v.x &&
                this->y == v.y &&
                this->z == v.z
        );
    }
};

} // R3::Math
