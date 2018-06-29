#include <gtest/gtest.h>
#include <enigma/plugboard.h>

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
