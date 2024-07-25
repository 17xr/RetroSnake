#ifndef SESSION_HPP
#define SESSION_HPP

#include <raylib.h>
#include <raymath.h>

#include "food.hpp"
#include "snake.hpp"

class Session {
private:
    Food m_food{};
    Snake m_snake{};
    Sound m_eatSound{};
    Sound m_hitSound{};
    double m_lastTriggerTime{};
    double m_interval{};
    int m_score{};

    bool eventTriggered() {
        double currentTime{GetTime()};

        if (currentTime - m_lastTriggerTime >= m_interval) {
            m_lastTriggerTime = currentTime;
            return true;
        }

        return false;
    }

public:
    explicit Session()
        : m_food{Food{}}, m_snake{Snake{}}, m_eatSound{LoadSound("resources/sound/eat.mp3")},
          m_hitSound{LoadSound("resources/sound/hit.mp3")}, m_lastTriggerTime{}, m_interval{0.1}, m_score{} {
    }

    ~Session() {
        UnloadSound(m_eatSound);
        UnloadSound(m_hitSound);
    }

    void Draw() const {
        m_food.Draw();
        m_snake.Draw();
    }

    void Update();

    int GetScore() const { return m_score; }
};

#endif
