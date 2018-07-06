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

#include <gtest/gtest.h>
#include <enigma/plugboard.h>
#include <enigma/utils.h>

TEST(plugboard_test, test_translate) {
    enigma::Plugboard plugboard;

    EXPECT_EQ('A', plugboard.Translate('A'));
    EXPECT_EQ('M', plugboard.Translate('M'));
    EXPECT_EQ('Z', plugboard.Translate('Z'));

    EXPECT_TRUE(plugboard.Connect('A', 'Z'));

    EXPECT_EQ('Z', plugboard.Translate('A'));
    EXPECT_EQ('M', plugboard.Translate('M'));
    EXPECT_EQ('A', plugboard.Translate('Z'));
}

TEST(plugboard_test, test_connect) {
    enigma::Plugboard plugboard;

    EXPECT_TRUE(plugboard.Connect('A', 'Z'));
    EXPECT_TRUE(plugboard.Connect('M', 'N'));

    EXPECT_FALSE(plugboard.Connect('Z', 'A'));

    plugboard.Reset();

    EXPECT_TRUE(plugboard.Connect('A', 'Z'));
    EXPECT_TRUE(plugboard.Connect('M', 'N'));

    plugboard.Reset();
    for(std::size_t i = 0; i < 13; ++i)
        EXPECT_TRUE(plugboard.Connect(enigma::to_char(i), enigma::to_char(13 + i)));

    EXPECT_FALSE(plugboard.Connect('A', 'Z'));
}
