#include <gtest/gtest.h>
#include <enigma/m3.h>
#include <enigma/historical.h>

TEST(m3_test, test_translate) {
    using enigma::historical::rotor;
    using enigma::historical::reflector;

    enigma::M3 machine(rotor::III, rotor::II, rotor::I, reflector::B);

    std::string result("BDZGOWCXLTKSBTMCDLPBMUQOFXYHCXTGYJFLINHNXSHIUNTHEORXPQPKOVHC");
    for(char res : result)
        EXPECT_EQ(res, machine.Translate('A'));
}
