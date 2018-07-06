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

#ifndef ENIGMA_GLOBAL_H
#define ENIGMA_GLOBAL_H

#ifdef ENIGMA_SHARED
#ifdef ENIGMA_EXPORT
#define ENIGMA_API __declspec(dllexport)
#else
#define ENIGMA_API __declspec(dllimport)
#endif
#endif

#ifndef ENIGMA_API
#define ENIGMA_API
#endif

#endif // ENIGMA_GLOBAL_H
