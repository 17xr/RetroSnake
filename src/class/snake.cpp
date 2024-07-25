#include "snake.hpp"

void Snake::Draw() const {
    for (size_t i = 0; i < body.size(); ++i) {
        Rectangle rectangle{offset + body[i].x * cellSize, offset + body[i].y * cellSize, cellSize, cellSize};
        DrawRectangleRounded(rectangle, 0.5f, 32, darkGreen);
    }
}

void Snake::Move() {
    body.push_front(Vector2Add(body.front(), direction));
    body.pop_back();
}

void Snake::Reset() {
    body = {GetRandomPosition()};
    direction = GetRandomDirection();
}

bool Snake::WillCollide(Vector2 vector) const {
    for (size_t i = 1; i < body.size(); ++i) {
        if (Vector2Equals(body[i], vector)) {
            return true;
        }
    }

    return false;
}

bool Snake::OutOfBorder() const {
    Vector2 head{GetHead()};

    if (head.x == -1 || head.x == cellCount) {
        return true;
    }

    if (head.y == -1 || head.y == cellCount) {
        return true;
    }

    return false;
}
