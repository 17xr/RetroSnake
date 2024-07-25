#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <deque>

#include "../constant/constant.hpp"
#include "../additional/additional.hpp"

using namespace Constant;

class Snake {
private:
    std::deque<Vector2> body{};
    Vector2 direction{};

public:
    explicit Snake()
        : body{GetRandomPosition()}, direction{GetRandomDirection()} {
    }

    void Draw() const;

    void Move();

    void Reset();

    bool WillCollide(Vector2 vector) const;

    bool OutOfBorder() const;

    Vector2 GetDirection() const { return direction; }
    Vector2 GetHead() const { return body.front(); }

    void IncrementLength() { body.push_front(Vector2Add(body.front(), direction)); }
    void SetDirection(Vector2 vector) { direction = vector; }
};

#endif
