#ifndef ADDITIONAL_HPP
#define ADDITIONAL_HPP

#include <raymath.h>

template<typename T>
inline float toF(T input) {
    return static_cast<float>(input);
}

template<typename T>
inline int toInt(T input) {
    return static_cast<int>(input);
}

Vector2 GetRandomPosition();

Vector2 GetRandomDirection();

#endif
