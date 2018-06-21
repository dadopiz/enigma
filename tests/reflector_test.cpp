#include <gtest/gtest.h>
#include <enigma/reflector.h>
#include <enigma/historical.h>

TEST(reflector_test, test_custom_translate) {
    enigma::Reflector custom_reflector({"QWERTYUIOPASDFGHJKLZXCVBNM"});
    EXPECT_EQ('Q', custom_reflector.Translate('A'));
    EXPECT_EQ('M', custom_reflector.Translate('Z'));
    EXPECT_EQ('Y', custom_reflector.Translate('F'));
}

TEST(reflector_test, test_historical_B_translate) {
    auto historical_reflector =  enigma::historical::reflector::B;
    EXPECT_EQ('Y', historical_reflector.Translate('A'));
    EXPECT_EQ('T', historical_reflector.Translate('Z'));
    EXPECT_EQ('S', historical_reflector.Translate('F'));
}

TEST(reflector_test, test_historical_C_translate) {
    auto historical_reflector =  enigma::historical::reflector::C;
    EXPECT_EQ('F', historical_reflector.Translate('A'));
    EXPECT_EQ('L', historical_reflector.Translate('Z'));
    EXPECT_EQ('A', historical_reflector.Translate('F'));
}
