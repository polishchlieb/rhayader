#pragma once
#include "../util/Error.hpp"

namespace rhayader {
    class ParseError : public Error {
    public:
        explicit ParseError(std::string value);

        std::string name() const noexcept;
        std::string message() const noexcept;
    private:
        std::string value;
    };
}
