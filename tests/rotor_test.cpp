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
#include <enigma/rotor.h>
#include <enigma/historical.h>
#include <enigma/utils.h>

TEST(rotor_test, test_notch) {
    auto test_rotor =  enigma::historical::rotor::I;

    EXPECT_FALSE(test_rotor.IsNotch());
    test_rotor.GrundStellung('Q');
    EXPECT_TRUE(test_rotor.IsNotch());

    test_rotor.GrundStellung('A');
    EXPECT_FALSE(test_rotor.IsNotch());

    for(std::size_t idx = 0; idx < enigma::to_index('Q'); ++idx)
        test_rotor.Turn();
    EXPECT_TRUE(test_rotor.IsNotch());

    test_rotor.Turn();
    EXPECT_FALSE(test_rotor.IsNotch());

    test_rotor.GrundStellung('A');
    EXPECT_EQ('E', test_rotor.TranslateStraight('A'));
    test_rotor.GrundStellung('B');
    EXPECT_EQ('J', test_rotor.TranslateStraight('A'));
    test_rotor.Turn();
    EXPECT_EQ('K', test_rotor.TranslateStraight('A'));
}

TEST(rotor_test, test_ring) {
    auto test_rotor =  enigma::historical::rotor::I;
    EXPECT_EQ('E', test_rotor.TranslateStraight('A'));

    test_rotor.RingStellung('B');
    EXPECT_EQ('K', test_rotor.TranslateStraight('A'));
}

TEST(rotor_test, test_custom_translate) {
    std::string rotor("QWERTYUIOPASDFGHJKLZXCVBNM");
    enigma::Rotor test_rotor(rotor, "A");

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(rotor[i], test_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor.find(enigma::to_char(i))], test_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_I_translate) {
    auto test_rotor =  enigma::historical::rotor::I;
    std::string rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ");

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(rotor[i], test_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor.find(enigma::to_char(i))], test_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_II_translate) {
    auto test_rotor =  enigma::historical::rotor::II;
    std::string rotor("AJDKSIRUXBLHWTMCQGZNPYFVOE");

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(rotor[i], test_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor.find(enigma::to_char(i))], test_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_III_translate) {
    auto test_rotor =  enigma::historical::rotor::III;
    std::string rotor("BDFHJLCPRTXVZNYEIWGAKMUSQO");

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(rotor[i], test_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor.find(enigma::to_char(i))], test_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_IV_translate) {
    auto test_rotor =  enigma::historical::rotor::IV;
    std::string rotor("ESOVPZJAYQUIRHXLNFTGKDCMWB");

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(rotor[i], test_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor.find(enigma::to_char(i))], test_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_V_translate) {
    auto test_rotor =  enigma::historical::rotor::V;
    std::string rotor("VZBRGITYUPSDNHLXAWMJQOFECK");

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(rotor[i], test_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor.find(enigma::to_char(i))], test_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_VI_translate) {
    auto test_rotor =  enigma::historical::rotor::VI;
    std::string rotor("JPGVOUMFYQBENHZRDKASXLICTW");

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(rotor[i], test_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor.find(enigma::to_char(i))], test_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_VII_translate) {
    auto test_rotor =  enigma::historical::rotor::VII;
    std::string rotor("NZJHGRCXMYSWBOUFAIVLPEKQDT");

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(rotor[i], test_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor.find(enigma::to_char(i))], test_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_VIII_translate) {
    auto test_rotor =  enigma::historical::rotor::VIII;
    std::string rotor("FKQHTLXOCBJSPDZRAMEWNIUYGV");

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(rotor[i], test_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor.find(enigma::to_char(i))], test_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_Beta_translate) {
    auto test_rotor =  enigma::historical::rotor::Beta;
    std::string rotor("LEYJVCNIXWPBQMDRTAKZGFUHOS");

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(rotor[i], test_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor.find(enigma::to_char(i))], test_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_Gamma_translate) {
    auto test_rotor =  enigma::historical::rotor::Gamma;
    std::string rotor("FSOKANUERHMBTIYCWLQPZXVGJD");

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(rotor[i], test_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor.find(enigma::to_char(i))], test_rotor.TranslateReverse(enigma::to_char(i)));
}
