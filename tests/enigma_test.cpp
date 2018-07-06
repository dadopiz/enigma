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
#include <enigma/utils.h>

TEST(utils_test, test_is_valid) {
    for(char letter : enigma::ALPHABET)
        EXPECT_TRUE(enigma::is_valid(letter));

    std::string alphabet = enigma::ALPHABET;
    std::transform(alphabet.begin(), alphabet.end(), alphabet.begin(), ::tolower);
    for(char letter : alphabet)
        EXPECT_FALSE(enigma::is_valid(letter));
}

TEST(utils_test, test_to_char) {
    for(std::size_t i = 0; i < enigma::ALPHABET.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[i], enigma::to_char(i));
}

TEST(utils_test, test_to_index) {
    for(std::size_t i = 0; i < enigma::ALPHABET.size(); ++i)
        EXPECT_EQ(i, enigma::to_index(enigma::ALPHABET[i]));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}
