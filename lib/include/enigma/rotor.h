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

#ifndef ENIGMA_ROTOR_H
#define ENIGMA_ROTOR_H

#include <string>

#include <enigma/global.h>

namespace enigma {

/**
 * @brief The Rotor (German: Walzen) class
 *
 * Each rotor was a disk with the 26 letters of the alphabet.
 * A single rotor performs a simple substitution cipher.
 * Each rotor could have zero or more notches that controlled the rotation of the following rotors.
 */
class ENIGMA_API Rotor {
public:
    /**
     * @brief Rotor
     * @param rotor   array of letters used for encryption
     * @param notches letters that determine the rotation of the following rotors
     */
    Rotor(const std::string& rotor, const std::string& notches);

    /**
     * @brief RingStellung
     * @param ring the position of each alphabet ring relative to its rotor wiring
     */
    void RingStellung(char ring);

    /**
     * @brief GrundStellung
     * @param offset starting position of the rotor
     */
    void GrundStellung(char offset);

    /**
     * @brief Turn, rotation of a step
     */
    void Turn();

    /**
     * @brief IsNotch
     * @return true if rotor is in notch position, false otherwise
     */
    bool IsNotch() const;

    /**
     * @brief TranslateStraight
     * The letter is coded in two different ways depending on the direction (straight or reverse).
     * @param letter letter to be encode
     * @return letter encoded
     */
    char TranslateStraight(char letter) const;

    /**
     * @brief TranslateReverse
     * The letter is coded in two different ways depending on the direction (straight or reverse).
     * @param letter letter to be encode
     * @return letter encoded
     */
    char TranslateReverse(char letter) const;

private:
    /**
     * @brief AddOffset
     * @param letter input letter to which to add the offset
     * @param offset offset to be added
     * @return letter with offset
     */
    char AddOffset(char letter, std::size_t offset) const;

    const std::string rotor_;
    const std::string notches_;

    std::size_t ring_;
    std::size_t offset_;
};

}

#endif // ENIGMA_ROTOR_H
