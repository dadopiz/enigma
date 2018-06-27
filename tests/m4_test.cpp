#include <gtest/gtest.h>
#include <enigma/historical.h>

TEST(m4_test, test_translate) {
    using enigma::historical::rotor;
    using enigma::historical::reflector;
    using enigma::historical::M4;

    M4 machine(rotor::III, rotor::II, rotor::I, rotor::Beta, reflector::BThin);

    std::string result("BDZGOWCXLTKSBTMCDLPBMUQOFXYHCXTGYJFLINHNXSHIUNTHEORXPQPKOVHC");
    for(char res : result)
        EXPECT_EQ(res, machine.Translate('A'));
}

TEST(m4_test, test_translate_phrase) {
    using enigma::historical::rotor;
    using enigma::historical::reflector;
    using enigma::historical::M4;

    M4 machine(rotor::III, rotor::II, rotor::I, rotor::Beta, reflector::BThin);

    std::string input(60, 'A');
    std::string result("BDZGOWCXLTKSBTMCDLPBMUQOFXYHCXTGYJFLINHNXSHIUNTHEORXPQPKOVHC");
    EXPECT_EQ(result, machine.Translate(input));
}
