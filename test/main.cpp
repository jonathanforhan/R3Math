#include <immintrin.h>
#include <iostream>
#include <cassert>
#include "types/Vec1.hpp"
#include "types/Vec2.hpp"
#include "types/Vec3.hpp"
#include "types/Vec4.hpp"
#include "operations/dot.hpp"

using namespace R3::Math;

void test_vec1();
void test_vec2();
void test_vec3();
void test_vec4();

int main()
{
    test_vec1();
    test_vec2();
    test_vec3();
    test_vec4();
}

void test_vec1()
{
    Vec1 a(1.0f);
    Vec1<double> b(a++);
    assert(b + 1 == a);

    assert(R3::Math::dot(a, b) == 2);
}

void test_vec2()
{
    Vec2 a = { 4.0, 4.0 };
    Vec2 b(4.0f);
    Vec2 c = { Vec1(1.0), 1.0f };
    assert(a == b && b == c * 4);
}

void test_vec3()
{
    Vec3 a = { 1.0, 1.0, 1.0 };
    Vec3 b = { Vec2(1.0), 1.0 };
    Vec3 c = { Vec1(1.0), 1.0, 1.0 };
    assert(a == b && b == c);
}

void test_vec4()
{
    Vec4 a = { 1.0, 1.0, 1.0, 1.0 };
    Vec4 b = { Vec3(1.0), 1.0 };
    Vec4 c = { Vec2(1.0), 1.0, 1.0 };
    Vec4 d = { Vec1(1.0), 1.0, 1.0, 1.0 };
    assert(a == b && b == c && c == d);
}
