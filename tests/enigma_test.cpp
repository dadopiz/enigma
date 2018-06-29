#include <gtest/gtest.h>
#include <enigma/utils.h>

TEST(utils_test, test_is_valid) {
    EXPECT_TRUE(enigma::is_valid('A'));
    EXPECT_TRUE(enigma::is_valid('M'));
    EXPECT_TRUE(enigma::is_valid('Z'));

    EXPECT_FALSE(enigma::is_valid('a'));
    EXPECT_FALSE(enigma::is_valid('?'));
}

TEST(utils_test, test_to_char) {
    EXPECT_EQ('A', enigma::to_char(0));
    EXPECT_EQ('Z', enigma::to_char(25));
    EXPECT_EQ('[', enigma::to_char(26));
}

TEST(utils_test, test_to_index) {
    EXPECT_EQ(0, enigma::to_index('A'));
    EXPECT_EQ(25, enigma::to_index('Z'));
    EXPECT_EQ(26, enigma::to_index('['));
}

TEST(utils_test, test_index_of) {
    EXPECT_EQ(0, enigma::index_of(enigma::ALPHABET, 'A'));
    EXPECT_EQ(25, enigma::index_of(enigma::ALPHABET, 'Z'));
    EXPECT_EQ(enigma::ALPHABET.size(), enigma::index_of(enigma::ALPHABET, '['));
    EXPECT_EQ(enigma::ALPHABET.size(), enigma::index_of(enigma::ALPHABET, 'a'));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}
