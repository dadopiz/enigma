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

#include <iostream>
#include <algorithm>

#include <enigma/enigma.h>

std::string format_input(const std::string& text) {
    std::string str(text);

    std::transform(str.begin(), str.end(), str.begin(), ::toupper);

    str.erase(std::remove_if(str.begin(), str.end(), [](char x)
    {
        return !enigma::is_valid(x);
    }), str.end());

    return str;
}

std::string format_output(const std::string& text) {
    std::string str(text);
    for(std::size_t i = 1; i < str.size(); ++i)
        if(i % 5 == 0)
            str.insert(i - 1, 1, ' ');
    return str;
}

int main(int, const char**) {
    using enigma::historical::rotor;

    enigma::Reflector custom_reflector("QWERTYUIOPASDFGHJKLZXCVBNM");
    enigma::M3 machine(rotor::III, rotor::II, rotor::I, custom_reflector);

    std::cout << "Enigma, say hello:" << std::endl;

    std::string hello = "Hello, World!";
    hello = format_input(hello);
    hello = machine.Translate(hello);
    hello = format_output(hello);

    std::cout << hello << std::endl;

    return 0;
}
