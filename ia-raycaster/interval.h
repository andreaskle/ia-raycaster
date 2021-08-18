// (c) 2021 Andreas Klein
// This code is licensed under MIT license (see LICENSE for details)

#ifndef INTERVAL_H_
#define INTERVAL_H_

#include <cmath>

struct Interval
{
    float a, b;
};

Interval operator*(const Interval &i, float val)
{
    float av = i.a * val;
    float bv = i.b * val;
    return Interval{std::min(av, bv), std::max(av, bv)};
}

Interval operator*(const Interval &i, const Interval &other)
{
    float ac = i.a * other.a;
    float ad = i.a * other.b;
    float bc = i.b * other.a;
    float bd = i.b * other.b;
    return {std::min(ac, std::min(ad, std::min(bc, bd))), std::max(ac, std::max(ad, std::max(bc, bd)))};
}

Interval operator+(const Interval &i, const Interval &other)
{
    return {i.a + other.a, i.b + other.b};
}

Interval operator+(const Interval &i, float val)
{
    return {i.a + val, i.b + val};
}
Interval operator-(const Interval &i, const Interval &other)
{
    return {i.a - other.b, i.b - other.a};
}
Interval operator-(const Interval &i, float val)
{
    return {i.a - val, i.b - val};
}
bool Contains(const Interval &i, float val)
{
    return val >= i.a && val < i.b;
}
#endif
