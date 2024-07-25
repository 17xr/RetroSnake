#ifndef FOOD_HPP
#define FOOD_HPP

#include <raylib.h>
#include <raymath.h>

#include "../additional/additional.hpp"
#include "../constant/constant.hpp"

using namespace Constant;

class Food {
private:
    Vector2 position{};
    Texture2D texture{};

public:
    explicit Food()
        : position{GetRandomPosition()}, texture{LoadTexture("resources/graphics/target.png")} {
    }

    ~Food() {
        UnloadTexture(texture);
    }

    void Draw() const {
        DrawTexture(texture, toInt(offset + position.x * cellSize), toInt(offset + position.y * cellSize), white);
    }

    void Reset() { position = GetRandomPosition(); }
    bool WillCollide(Vector2 vector) const { return Vector2Equals(position, vector); }
};

#endif
