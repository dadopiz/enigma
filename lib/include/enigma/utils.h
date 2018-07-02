#ifndef ENIGMA_UTILS_H
#define ENIGMA_UTILS_H

#include <cassert>
#include <string>

#define letter_assert(letter) assert(is_valid(letter) && "letter not valid!")

namespace enigma {

static const std::string ALPHABET = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

inline constexpr bool is_valid(char letter) {
    return (letter >= 'A' && letter <= 'Z');
}

inline constexpr char to_char(std::size_t index) {
    return static_cast<char>(index + 'A');
}

inline constexpr std::size_t to_index(char letter) {
    return static_cast<std::size_t>(letter - 'A');
}

}

#endif // ENIGMA_UTILS_H
