#include <gtest/gtest.h>
#include <enigma/m4.h>
#include <enigma/historical.h>

TEST(m4_test, test_translate) {
    using enigma::historical::rotor;
    using enigma::historical::reflector;

    enigma::M4 machine(rotor::III, rotor::II, rotor::I, rotor::Beta, reflector::BThin);

    std::string result("BDZGOWCXLTKSBTMCDLPBMUQOFXYHCXTGYJFLINHNXSHIUNTHEORXPQPKOVHC");
    for(char res : result)
        EXPECT_EQ(res, machine.Translate('A'));
}

TEST(m4_test, test_translate_phrase) {
    using enigma::historical::rotor;
    using enigma::historical::reflector;

    enigma::M4 machine(rotor::III, rotor::II, rotor::I, rotor::Beta, reflector::BThin);

    std::string input(60, 'A');
    std::string result("BDZGOWCXLTKSBTMCDLPBMUQOFXYHCXTGYJFLINHNXSHIUNTHEORXPQPKOVHC");
    EXPECT_EQ(result, machine.Translate(input));
}

TEST(m4_test, test_connect) {
    using enigma::historical::rotor;
    using enigma::historical::reflector;

    enigma::M4 machine(rotor::III, rotor::II, rotor::I, rotor::Beta, reflector::BThin);

    EXPECT_TRUE(machine.Connect('A', 'Z'));

    EXPECT_EQ('U', machine.Translate('A'));

    machine.ResetPlugboard();

    EXPECT_EQ('D', machine.Translate('A'));
}

TEST(m4_test, test_settings) {
    using enigma::historical::rotor;
    using enigma::historical::reflector;

    enigma::M4 machine(rotor::III, rotor::II, rotor::I, rotor::Beta, reflector::BThin);

    EXPECT_EQ('B', machine.Translate('A'));

    machine.GrundStellung('A', 'A', 'A', 'A');

    EXPECT_EQ('B', machine.Translate('A'));

    machine.GrundStellung('A', 'A', 'A', 'A');
    machine.RingStellung('B', 'B', 'B', 'B');

    EXPECT_EQ('D', machine.Translate('A'));

    machine.GrundStellung('A', 'A', 'A', 'A');
    machine.RingStellung('A', 'A', 'A', 'A');

    EXPECT_EQ('B', machine.Translate('A'));

    machine.GrundStellung('A', 'E', 'A', 'A');
    EXPECT_EQ('F', machine.Translate('A'));
}
