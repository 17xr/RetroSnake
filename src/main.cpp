#include <raylib.h>

#include "class/session.hpp"

#include "constant/constant.hpp"
#include "random/random.hpp"

using namespace Constant;

int main() {
    InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount, Title.data());
    InitAudioDevice();

    Session session{};
    const Texture2D target{LoadTexture("resources/graphics/target.png")};
    const Texture2D logo{LoadTexture("resources/graphics/snake.png")};

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(green);

        DrawRectangleLinesEx(frame, 5, darkGreen);
        DrawText("Retro Snake!", offset - 5, 20, 40, darkGreen);
        DrawTexture(logo, 35 + cellSize * cellCount, 15, white);
        DrawText(TextFormat("%i", session.GetScore()), offset + cellSize * cellCount / 2,
                 offset + cellSize * cellCount + 10, 45, darkGreen);
        DrawTexture(target, 30 + cellSize * cellCount / 2, offset + cellSize * cellCount + 15, white);

        session.Draw();
        session.Update();

        EndDrawing();
    }

    UnloadTexture(logo);
    UnloadTexture(target);
    CloseAudioDevice();
    CloseWindow();

    return EXIT_SUCCESS;
}
