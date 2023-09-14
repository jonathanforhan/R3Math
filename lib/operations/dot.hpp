#pragma once
#include "types/Vec1.hpp"
#include "types/Vec2.hpp"
#include "types/Vec3.hpp"
#include "types/Vec4.hpp"

namespace R3::Math {

template<std::floating_point T, std::floating_point U>
constexpr T dot(const Vec1<T> &v1, const Vec1<U> &v2)
{
    return v1.x * v2.x;
}

template<std::floating_point T, std::floating_point U>
constexpr T dot(const Vec2<T> &v1, const Vec2<U> &v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

template<std::floating_point T, std::floating_point U>
constexpr T dot(const Vec3<T> &v1, const Vec3<U> &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<std::floating_point T, std::floating_point U>
constexpr T dot(const Vec4<T> &v1, const Vec4<U> &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

} // R3::Math
