#include "../constant/constant.hpp"
#include "../random/random.hpp"
#include "additional.hpp"

using namespace Constant;

Vector2 GetRandomPosition() {
    return Vector2{toF(Random::randint(0, cellCount - 1)), toF(Random::randint(0, cellCount - 1))};
}

Vector2 GetRandomDirection() {
    return unitVector[Random::randint(0uz, unitVector.size() - 1)];
}
