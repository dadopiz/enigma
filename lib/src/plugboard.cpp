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

#include <enigma/plugboard.h>

#include <enigma/utils.h>

namespace enigma {

Plugboard::Plugboard()
    : cables_(13)
    , plugboard_(ALPHABET)
{}

char Plugboard::Translate(char letter) const {
    letter_assert(letter);
    return plugboard_[to_index(letter)];
}

void Plugboard::Reset() {
    cables_ = 13;
    plugboard_ = ALPHABET;
}

bool Plugboard::Connect(char lhs, char rhs) {
    letter_assert(lhs);
    letter_assert(rhs);

    if(cables_ <= 0)
        return false;

    if(AreConnected(lhs, rhs))
        return false;

    std::swap(plugboard_[to_index(lhs)], plugboard_[to_index(rhs)]);
    --cables_;

    return true;
}

bool Plugboard::AreConnected(char lhs, char rhs) const {
    return (plugboard_[to_index(lhs)] != lhs) || (plugboard_[to_index(rhs)] != rhs);
}

}
