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

#ifndef ENIGMA_PLUGBOARD_H
#define ENIGMA_PLUGBOARD_H

#include <string>

#include <enigma/global.h>

namespace enigma {

/**
 * @brief The Plugboard  (German: Steckerbrett) class
 *
 * The Plugboard allows a variable configuration by the operator.
 * This possibility has improved encryption in the Enigma machine.
 */
class ENIGMA_API Plugboard {
public:
    /**
     * @brief Plugboard
     */
    Plugboard();

    /**
     * @brief Translate
     * @param letter input letter
     * @return encrypted letter
     */
    char Translate(char letter) const;

    /**
     * @brief Reset the plugboard
     */
    void Reset();

    /**
     * @brief Connect
     * Connects two letters to each other by inverting their translation
     * @param lhs left letter
     * @param rhs right letter
     * @return true if connected, false otherwise
     */
    bool Connect(char lhs, char rhs);

private:
    /**
     * @brief AreConnected
     * @param lhs left letter
     * @param rhs right letter
     * @return true if are connected, false otherwise
     */
    bool AreConnected(char lhs, char rhs) const;

    int cables_;
    std::string plugboard_;
};

}

#endif // ENIGMA_PLUGBOARD_H
