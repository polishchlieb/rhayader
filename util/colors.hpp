#pragma once
#include <string>

namespace rhayader {
    enum class Color {
        RED,
        RESET
    };

    const char* color(Color color);
}
