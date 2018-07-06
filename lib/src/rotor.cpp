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

#include <enigma/rotor.h>
#include <enigma/utils.h>

namespace enigma {

Rotor::Rotor(const std::string& rotor, const std::string& notches)
    : rotor_(rotor)
    , notches_(notches)
    , ring_(0)
    , offset_(0)
{}

void Rotor::RingStellung(char ring) {
    letter_assert(ring);
    ring_ = to_index(ring);
}

void Rotor::GrundStellung(char offset) {
    letter_assert(offset);
    offset_ = to_index(offset);
}

void Rotor::Turn() {
    offset_ = (offset_ + 1) % 26;
}

bool Rotor::IsNotch() const {
    return (notches_.find(to_char(offset_)) != std::string::npos);
}

char Rotor::TranslateStraight(char letter) const {
    letter_assert(letter);
    letter = AddOffset(letter, offset_ - ring_);
    letter = rotor_[to_index(letter)];
    return AddOffset(letter, ring_ - offset_);
}

char Rotor::TranslateReverse(char letter) const {
    letter_assert(letter);
    letter = AddOffset(letter, offset_ - ring_);
    letter = ALPHABET[rotor_.find(letter)];
    return AddOffset(letter, ring_ - offset_);
}

char Rotor::AddOffset(char letter, std::size_t offset) const {
    return ALPHABET[(to_index(letter) + offset + 26) % 26];
}

}
