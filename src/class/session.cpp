#include "session.hpp"

void Session::Update() {
    Vector2 head{m_snake.GetHead()};

    if (m_snake.WillCollide(head)) {
        PlaySound(m_hitSound);

        m_food.Reset();
        m_snake.Reset();
        m_score = 0;
    }

    if (IsKeyPressed(KEY_UP) && m_snake.GetDirection().y != 1) {
        m_snake.SetDirection(unitVector[0]);
    }

    if (IsKeyPressed(KEY_DOWN) && m_snake.GetDirection().y != -1) {
        m_snake.SetDirection(unitVector[1]);
    }

    if (IsKeyPressed(KEY_LEFT) && m_snake.GetDirection().x != 1) {
        m_snake.SetDirection(unitVector[2]);
    }

    if (IsKeyPressed(KEY_RIGHT) && m_snake.GetDirection().x != -1) {
        m_snake.SetDirection(unitVector[3]);
    }

    if (eventTriggered()) {
        m_snake.Move();
    }

    if (m_snake.OutOfBorder()) {
        PlaySound(m_hitSound);

        m_food.Reset();
        m_snake.Reset();
        m_score = 0;
    }

    if (m_food.WillCollide(head)) {
        PlaySound(m_eatSound);

        m_food.Reset();
        m_snake.IncrementLength();
        ++m_score;
    }
}
