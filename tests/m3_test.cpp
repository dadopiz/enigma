#include <gtest/gtest.h>
#include <enigma/m3.h>
#include <enigma/historical.h>

TEST(m3_test, test_translate) {
    using enigma::historical::rotor;
    using enigma::historical::reflector;

    enigma::M3 machine(rotor::I, rotor::II, rotor::III, reflector::B);

    EXPECT_EQ('B', machine.Translate('A'));
    EXPECT_EQ('D', machine.Translate('A'));
    EXPECT_EQ('Z', machine.Translate('A'));
    EXPECT_EQ('G', machine.Translate('A'));
    EXPECT_EQ('O', machine.Translate('A'));
}
