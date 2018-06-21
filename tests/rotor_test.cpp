#include <gtest/gtest.h>
#include <enigma/rotor.h>
#include <enigma/historical.h>

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
    enigma::Rotor custom_rotor({"QWERTYUIOPASDFGHJKLZXCVBNM"}, 'A');
    EXPECT_EQ('Q', custom_rotor.TranslateStraight('A'));
    EXPECT_EQ('M', custom_rotor.TranslateStraight('Z'));
    EXPECT_EQ('Y', custom_rotor.TranslateStraight('F'));
    EXPECT_EQ('K', custom_rotor.TranslateReverse('A'));
    EXPECT_EQ('T', custom_rotor.TranslateReverse('Z'));
    EXPECT_EQ('N', custom_rotor.TranslateReverse('F'));
}

TEST(rotor_test, test_historical_I_translate) {
    auto historical_rotor =  enigma::historical::rotor::I;
    EXPECT_EQ('E', historical_rotor.TranslateStraight('A'));
    EXPECT_EQ('J', historical_rotor.TranslateStraight('Z'));
    EXPECT_EQ('G', historical_rotor.TranslateStraight('F'));
    EXPECT_EQ('U', historical_rotor.TranslateReverse('A'));
    EXPECT_EQ('J', historical_rotor.TranslateReverse('Z'));
    EXPECT_EQ('D', historical_rotor.TranslateReverse('F'));
}

TEST(rotor_test, test_historical_II_translate) {
    auto historical_rotor =  enigma::historical::rotor::II;
    EXPECT_EQ('A', historical_rotor.TranslateStraight('A'));
    EXPECT_EQ('E', historical_rotor.TranslateStraight('Z'));
    EXPECT_EQ('I', historical_rotor.TranslateStraight('F'));
    EXPECT_EQ('A', historical_rotor.TranslateReverse('A'));
    EXPECT_EQ('S', historical_rotor.TranslateReverse('Z'));
    EXPECT_EQ('W', historical_rotor.TranslateReverse('F'));
}

TEST(rotor_test, test_historical_III_translate) {
    auto historical_rotor =  enigma::historical::rotor::III;
    EXPECT_EQ('B', historical_rotor.TranslateStraight('A'));
    EXPECT_EQ('O', historical_rotor.TranslateStraight('Z'));
    EXPECT_EQ('L', historical_rotor.TranslateStraight('F'));
    EXPECT_EQ('T', historical_rotor.TranslateReverse('A'));
    EXPECT_EQ('M', historical_rotor.TranslateReverse('Z'));
    EXPECT_EQ('C', historical_rotor.TranslateReverse('F'));
}

TEST(rotor_test, test_historical_IV_translate) {
    auto historical_rotor =  enigma::historical::rotor::IV;
    EXPECT_EQ('E', historical_rotor.TranslateStraight('A'));
    EXPECT_EQ('B', historical_rotor.TranslateStraight('Z'));
    EXPECT_EQ('Z', historical_rotor.TranslateStraight('F'));
    EXPECT_EQ('H', historical_rotor.TranslateReverse('A'));
    EXPECT_EQ('F', historical_rotor.TranslateReverse('Z'));
    EXPECT_EQ('R', historical_rotor.TranslateReverse('F'));
}

TEST(rotor_test, test_historical_V_translate) {
    auto historical_rotor =  enigma::historical::rotor::V;
    EXPECT_EQ('V', historical_rotor.TranslateStraight('A'));
    EXPECT_EQ('K', historical_rotor.TranslateStraight('Z'));
    EXPECT_EQ('I', historical_rotor.TranslateStraight('F'));
    EXPECT_EQ('Q', historical_rotor.TranslateReverse('A'));
    EXPECT_EQ('B', historical_rotor.TranslateReverse('Z'));
    EXPECT_EQ('W', historical_rotor.TranslateReverse('F'));
}
