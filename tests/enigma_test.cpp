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
