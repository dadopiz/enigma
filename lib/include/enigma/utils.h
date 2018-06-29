#ifndef ENIGMA_UTILS_H
#define ENIGMA_UTILS_H

#include <cassert>
#include <array>

#define letter_assert(letter) assert(is_valid(letter) && "letter not valid!")

namespace enigma {

using Letters = std::array<char, 27>;

static const Letters ALPHABET = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

inline constexpr bool is_valid(char letter) {
    return (letter >= 'A' && letter <= 'Z');
}

inline constexpr char to_char(std::size_t index) {
    return static_cast<char>(index + 'A');
}

inline constexpr std::size_t to_index(char letter) {
    return static_cast<std::size_t>(letter - 'A');
}

inline std::size_t index_of(const Letters& arr, char letter) {
    std::size_t idx = 0;
    for(auto it = arr.cbegin(); it != arr.cend(); ++it, ++idx)
        if(*it == letter) return idx;
    return idx;
}

}

#endif // ENIGMA_UTILS_H
