#pragma once
#include <cmath>
#include "types/Vec1.hpp"
#include "types/Vec2.hpp"
#include "types/Vec3.hpp"
#include "types/Vec4.hpp"
#include "dot.hpp"

namespace R3::Math {

template<typename T>
constexpr auto magnitude(const T &v) requires (requires(const T &_v) { dot(_v, _v); })
{
    if constexpr (std::is_same_v<T, Vec1<decltype(v.x)>>) {
        return v.x;
    } else if constexpr (std::is_same_v<decltype(v.x), float>) {
        return sqrtf(dot(v, v));
    } else if constexpr (std::is_same_v<decltype(v.x), double>) {
        return sqrt(dot(v, v));
    }
}

} // R3::Math
