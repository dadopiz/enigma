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

#include <enigma/historical.h>

namespace enigma {

namespace historical {

const Reflector reflector::B("YRUHQSLDPXNGOKMIEBFZCWVJAT");
const Reflector reflector::C("FVPJIAOYEDRZXWGCTKUQSBNMHL");
const Reflector reflector::BThin("ENKQAUYWJICOPBLMDXZVFTHRGS");
const Reflector reflector::CThin("RDOBJNTKVEHMLFCWZAXGYIPSUQ");

const Rotor rotor::I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", "Q");
const Rotor rotor::II("AJDKSIRUXBLHWTMCQGZNPYFVOE", "E");
const Rotor rotor::III("BDFHJLCPRTXVZNYEIWGAKMUSQO", "V");
const Rotor rotor::IV("ESOVPZJAYQUIRHXLNFTGKDCMWB", "J");
const Rotor rotor::V("VZBRGITYUPSDNHLXAWMJQOFECK", "Z");
const Rotor rotor::VI("JPGVOUMFYQBENHZRDKASXLICTW", "ZM");
const Rotor rotor::VII("NZJHGRCXMYSWBOUFAIVLPEKQDT", "ZM");
const Rotor rotor::VIII("FKQHTLXOCBJSPDZRAMEWNIUYGV", "ZM");
const Rotor rotor::Beta("LEYJVCNIXWPBQMDRTAKZGFUHOS", "");
const Rotor rotor::Gamma("FSOKANUERHMBTIYCWLQPZXVGJD", "");

}

}
