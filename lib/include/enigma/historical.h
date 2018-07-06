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

#ifndef ENIGMA_HISTORICAL_H
#define ENIGMA_HISTORICAL_H

#include <enigma/global.h>
#include <enigma/rotor.h>
#include <enigma/reflector.h>

namespace enigma {

namespace historical {

/**
 * @brief Historical rotors
 */
struct ENIGMA_API rotor {
    /**
     * @brief Rotors I, II and III
     *
     * Standard rotors, used in M3 machine.
     */
    static const Rotor I;
    static const Rotor II;
    static const Rotor III;

    /**
     * @brief Rotors IV and V
     *
     * Introduced in 1938 for M3 machine.
     */
    static const Rotor IV;
    static const Rotor V;

    /**
     * @brief Rotors VI, VII and VIII
     *
     * Introduced in 1939 for M3 and M4 machines.
     */
    static const Rotor VI;
    static const Rotor VII;
    static const Rotor VIII;

    /**
     * @brief Rotor Beta
     *
     * Introduced in 1941 for M4 machine.
     */
    static const Rotor Beta;

    /**
     * @brief Rotor Gamma
     *
     * Introduced in 1942 for M4 machine.
     */
    static const Rotor Gamma;
};

/**
 * @brief Historical reflectors
 */
struct ENIGMA_API reflector {
    /**
     * @brief Reflectors B and C
     *
     * Standard reflectors, used in M3 machine.
     */
    static const Reflector B;
    static const Reflector C;

    /**
     * @brief Reflectors BThin and CThin
     *
     * Introduced in 1940 for M3 and M4 machines.
     */
    static const Reflector BThin;
    static const Reflector CThin;
};

}

}

#endif // ENIGMA_HISTORICAL_H
