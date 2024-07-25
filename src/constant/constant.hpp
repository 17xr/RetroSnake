#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <array>
#include <string_view>

#include <raylib.h>
#include <raymath.h>

namespace Constant {
    inline constexpr Color darkGreen{43, 51, 24, 255};
    inline constexpr Color green{173, 204, 96, 255};
    inline constexpr Color white{255, 255, 255, 255};

    inline constexpr int cellCount{28};
    inline constexpr int cellSize{28};
    inline constexpr int offset{75};

    inline constexpr std::string_view Title{"Retro Snake!"};

    inline constexpr Rectangle frame{offset - 5, offset - 5, cellSize * cellCount + 10, cellSize * cellCount + 10};

    inline constexpr std::array<Vector2, 4> unitVector{Vector2{0, -1}, Vector2{0, 1}, Vector2{-1, 0}, Vector2{1, 0}};
}

#endif
