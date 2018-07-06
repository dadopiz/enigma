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
    auto historical_rotor =  enigma::historical::rotor::I;

    EXPECT_FALSE(historical_rotor.IsNotch());
    historical_rotor.GrundStellung('Q');
    EXPECT_TRUE(historical_rotor.IsNotch());

    historical_rotor.GrundStellung('A');
    EXPECT_FALSE(historical_rotor.IsNotch());

    for(std::size_t idx = 0; idx < enigma::to_index('Q'); ++idx)
        historical_rotor.Turn();
    EXPECT_TRUE(historical_rotor.IsNotch());

    historical_rotor.Turn();
    EXPECT_FALSE(historical_rotor.IsNotch());

    historical_rotor.GrundStellung('A');
    EXPECT_EQ('E', historical_rotor.TranslateStraight('A'));
    historical_rotor.GrundStellung('B');
    EXPECT_EQ('J', historical_rotor.TranslateStraight('A'));
    historical_rotor.Turn();
    EXPECT_EQ('K', historical_rotor.TranslateStraight('A'));
}

TEST(rotor_test, test_ring) {
    auto historical_rotor =  enigma::historical::rotor::I;
    EXPECT_EQ('E', historical_rotor.TranslateStraight('A'));

    historical_rotor.RingStellung('B');
    EXPECT_EQ('K', historical_rotor.TranslateStraight('A'));
}

TEST(rotor_test, test_custom_translate) {
    std::string rotor("QWERTYUIOPASDFGHJKLZXCVBNM");
    enigma::Rotor custom_rotor(rotor, "A");

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(rotor[i], custom_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor.find(enigma::to_char(i))],
                custom_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_I_translate) {
    auto historical_rotor =  enigma::historical::rotor::I;
    std::string rotor_1("EKMFLGDQVZNTOWYHXUSPAIBRCJ");

    for(std::size_t i = 0; i < rotor_1.size(); ++i)
        EXPECT_EQ(rotor_1[i], historical_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor_1.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor_1.find(enigma::to_char(i))],
                historical_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_II_translate) {
    auto historical_rotor =  enigma::historical::rotor::II;
    std::string rotor_2("AJDKSIRUXBLHWTMCQGZNPYFVOE");

    for(std::size_t i = 0; i < rotor_2.size(); ++i)
        EXPECT_EQ(rotor_2[i], historical_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor_2.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor_2.find(enigma::to_char(i))],
                historical_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_III_translate) {
    auto historical_rotor =  enigma::historical::rotor::III;
    std::string rotor_3("BDFHJLCPRTXVZNYEIWGAKMUSQO");

    for(std::size_t i = 0; i < rotor_3.size(); ++i)
        EXPECT_EQ(rotor_3[i], historical_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor_3.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor_3.find(enigma::to_char(i))],
                historical_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_IV_translate) {
    auto historical_rotor =  enigma::historical::rotor::IV;
    std::string rotor_4("ESOVPZJAYQUIRHXLNFTGKDCMWB");

    for(std::size_t i = 0; i < rotor_4.size(); ++i)
        EXPECT_EQ(rotor_4[i], historical_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor_4.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor_4.find(enigma::to_char(i))],
                historical_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_V_translate) {
    auto historical_rotor =  enigma::historical::rotor::V;
    std::string rotor_5("VZBRGITYUPSDNHLXAWMJQOFECK");

    for(std::size_t i = 0; i < rotor_5.size(); ++i)
        EXPECT_EQ(rotor_5[i], historical_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor_5.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor_5.find(enigma::to_char(i))],
                historical_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_VI_translate) {
    auto historical_rotor =  enigma::historical::rotor::VI;
    std::string rotor_6("JPGVOUMFYQBENHZRDKASXLICTW");

    for(std::size_t i = 0; i < rotor_6.size(); ++i)
        EXPECT_EQ(rotor_6[i], historical_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor_6.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor_6.find(enigma::to_char(i))],
                historical_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_VII_translate) {
    auto historical_rotor =  enigma::historical::rotor::VII;
    std::string rotor_7("NZJHGRCXMYSWBOUFAIVLPEKQDT");

    for(std::size_t i = 0; i < rotor_7.size(); ++i)
        EXPECT_EQ(rotor_7[i], historical_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor_7.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor_7.find(enigma::to_char(i))],
                historical_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_VIII_translate) {
    auto historical_rotor =  enigma::historical::rotor::VIII;
    std::string rotor_8("FKQHTLXOCBJSPDZRAMEWNIUYGV");

    for(std::size_t i = 0; i < rotor_8.size(); ++i)
        EXPECT_EQ(rotor_8[i], historical_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor_8.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor_8.find(enigma::to_char(i))],
                historical_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_Beta_translate) {
    auto historical_rotor =  enigma::historical::rotor::Beta;
    std::string rotor("LEYJVCNIXWPBQMDRTAKZGFUHOS");

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(rotor[i], historical_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor.find(enigma::to_char(i))],
                historical_rotor.TranslateReverse(enigma::to_char(i)));
}

TEST(rotor_test, test_historical_Gamma_translate) {
    auto historical_rotor =  enigma::historical::rotor::Gamma;
    std::string rotor("FSOKANUERHMBTIYCWLQPZXVGJD");

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(rotor[i], historical_rotor.TranslateStraight(enigma::to_char(i)));

    for(std::size_t i = 0; i < rotor.size(); ++i)
        EXPECT_EQ(enigma::ALPHABET[rotor.find(enigma::to_char(i))],
                historical_rotor.TranslateReverse(enigma::to_char(i)));
}
