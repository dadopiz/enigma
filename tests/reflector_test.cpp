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
#include <enigma/reflector.h>
#include <enigma/historical.h>

TEST(reflector_test, test_custom_translate) {
    enigma::Reflector reflector("QWERTYUIOPASDFGHJKLZXCVBNM");
    EXPECT_EQ('Q', reflector.Translate('A'));
    EXPECT_EQ('M', reflector.Translate('Z'));
    EXPECT_EQ('Y', reflector.Translate('F'));
}

TEST(reflector_test, test_historical_B_translate) {
    auto reflector =  enigma::historical::reflector::B;
    EXPECT_EQ('Y', reflector.Translate('A'));
    EXPECT_EQ('T', reflector.Translate('Z'));
    EXPECT_EQ('S', reflector.Translate('F'));
}

TEST(reflector_test, test_historical_C_translate) {
    auto reflector =  enigma::historical::reflector::C;
    EXPECT_EQ('F', reflector.Translate('A'));
    EXPECT_EQ('L', reflector.Translate('Z'));
    EXPECT_EQ('A', reflector.Translate('F'));
}

TEST(reflector_test, test_historical_thinB_translate) {
    auto reflector =  enigma::historical::reflector::BThin;
    EXPECT_EQ('E', reflector.Translate('A'));
    EXPECT_EQ('S', reflector.Translate('Z'));
    EXPECT_EQ('U', reflector.Translate('F'));
}

TEST(reflector_test, test_historical_thinC_translate) {
    auto reflector =  enigma::historical::reflector::CThin;
    EXPECT_EQ('R', reflector.Translate('A'));
    EXPECT_EQ('Q', reflector.Translate('Z'));
    EXPECT_EQ('N', reflector.Translate('F'));
}
