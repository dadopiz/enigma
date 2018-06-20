#ifndef ENIGMA_UTILS_H
#define ENIGMA_UTILS_H

#include <array>
#include <enigma/global.h>

namespace enigma {

static const std::array<char, 27> ALPHABET = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

inline constexpr bool ENIGMA_API is_valid(char letter) {
    return (letter >= 'A' && letter <= 'Z');
}

inline constexpr char ENIGMA_API to_char(std::size_t index) {
    return static_cast<char>(index + 'A');
}

inline constexpr std::size_t ENIGMA_API to_index(char letter) {
    return static_cast<std::size_t>(letter - 'A');
}

}

#endif // ENIGMA_UTILS_H
