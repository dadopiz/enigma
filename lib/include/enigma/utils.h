/*
    Copyright (C) 2018 Davide Pizzato.
    Contact: https://github.com/dadopiz/enigma

    This file is part of the Enigma library.

    Enigma library is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Enigma library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Enigma library.  If not, see <http://www.gnu.org/licenses/>.
*/

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
