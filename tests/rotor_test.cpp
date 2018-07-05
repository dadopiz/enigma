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

    //TODO: reverse translation
    EXPECT_EQ('K', custom_rotor.TranslateReverse('A'));
    EXPECT_EQ('T', custom_rotor.TranslateReverse('Z'));
    EXPECT_EQ('N', custom_rotor.TranslateReverse('F'));
}

TEST(rotor_test, test_historical_I_translate) {
    auto historical_rotor =  enigma::historical::rotor::I;
    std::string rotor_1("EKMFLGDQVZNTOWYHXUSPAIBRCJ");

    for(std::size_t i = 0; i < rotor_1.size(); ++i)
        EXPECT_EQ(rotor_1[i], historical_rotor.TranslateStraight(enigma::to_char(i)));

    //TODO: reverse translation
    EXPECT_EQ('U', historical_rotor.TranslateReverse('A'));
    EXPECT_EQ('J', historical_rotor.TranslateReverse('Z'));
    EXPECT_EQ('D', historical_rotor.TranslateReverse('F'));
}

TEST(rotor_test, test_historical_II_translate) {
    auto historical_rotor =  enigma::historical::rotor::II;
    std::string rotor_2("AJDKSIRUXBLHWTMCQGZNPYFVOE");

    for(std::size_t i = 0; i < rotor_2.size(); ++i)
        EXPECT_EQ(rotor_2[i], historical_rotor.TranslateStraight(enigma::to_char(i)));

    //TODO: reverse translation
    EXPECT_EQ('A', historical_rotor.TranslateReverse('A'));
    EXPECT_EQ('S', historical_rotor.TranslateReverse('Z'));
    EXPECT_EQ('W', historical_rotor.TranslateReverse('F'));
}

TEST(rotor_test, test_historical_III_translate) {
    auto historical_rotor =  enigma::historical::rotor::III;
    std::string rotor_3("BDFHJLCPRTXVZNYEIWGAKMUSQO");

    for(std::size_t i = 0; i < rotor_3.size(); ++i)
        EXPECT_EQ(rotor_3[i], historical_rotor.TranslateStraight(enigma::to_char(i)));

    //TODO: reverse translation
    EXPECT_EQ('T', historical_rotor.TranslateReverse('A'));
    EXPECT_EQ('M', historical_rotor.TranslateReverse('Z'));
    EXPECT_EQ('C', historical_rotor.TranslateReverse('F'));
}

TEST(rotor_test, test_historical_IV_translate) {
    auto historical_rotor =  enigma::historical::rotor::IV;
    std::string rotor_4("ESOVPZJAYQUIRHXLNFTGKDCMWB");

    for(std::size_t i = 0; i < rotor_4.size(); ++i)
        EXPECT_EQ(rotor_4[i], historical_rotor.TranslateStraight(enigma::to_char(i)));

    //TODO: reverse translation
    EXPECT_EQ('H', historical_rotor.TranslateReverse('A'));
    EXPECT_EQ('F', historical_rotor.TranslateReverse('Z'));
    EXPECT_EQ('R', historical_rotor.TranslateReverse('F'));
}

TEST(rotor_test, test_historical_V_translate) {
    auto historical_rotor =  enigma::historical::rotor::V;
    std::string rotor_5("VZBRGITYUPSDNHLXAWMJQOFECK");

    for(std::size_t i = 0; i < rotor_5.size(); ++i)
        EXPECT_EQ(rotor_5[i], historical_rotor.TranslateStraight(enigma::to_char(i)));

    //TODO: reverse translation
    EXPECT_EQ('Q', historical_rotor.TranslateReverse('A'));
    EXPECT_EQ('B', historical_rotor.TranslateReverse('Z'));
    EXPECT_EQ('W', historical_rotor.TranslateReverse('F'));
}
