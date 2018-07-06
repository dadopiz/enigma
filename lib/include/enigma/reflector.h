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

#ifndef ENIGMA_REFLECTOR_H
#define ENIGMA_REFLECTOR_H

#include <string>

#include <enigma/global.h>

namespace enigma {

/**
 * @brief The Reflector (German: Umkehrwalze) class
 *
 * Generally the reflector was fixed and did not rotate during the encryption.
 * The reflector does not allow Enigma to encrypt a letter in itself.
 */
class ENIGMA_API Reflector {
public:
    /**
     * @brief Reflector
     * @param reflector array of letters used for encryption
     */
    Reflector(const std::string& reflector);

    /**
     * @brief Translate
     * @param letter input letter
     * @return encrypted letter
     */
    char Translate(char letter) const;

private:
    const std::string reflector_;
};

}

#endif // ENIGMA_REFLECTOR_H
