#pragma once
#include <string>

namespace rhayader {
    template<typename First, typename ...T>
    bool isIn(const First& first, const T&... t) {
        return ((first == t) || ...);
    }

	std::string times(const std::string& str, unsigned int num);
}
