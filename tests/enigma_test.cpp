#include <gtest/gtest.h>
#include <enigma/enigma.h>

class reflector_test : public ::testing::Test {
protected:
    reflector_test() {}
    virtual ~reflector_test() {}

    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(reflector_test, test_custom_translate) {
    enigma::Reflector custom_reflector({"QWERTYUIOPASDFGHJKLZXCVBNM"});
    EXPECT_EQ('Q', custom_reflector.Translate('A'));
    EXPECT_EQ('M', custom_reflector.Translate('Z'));
    EXPECT_EQ('Y', custom_reflector.Translate('F'));
}

TEST_F(reflector_test, test_historical_B_translate) {
    using enigma::historical::reflector;
    EXPECT_EQ('Y', reflector::B.Translate('A'));
    EXPECT_EQ('T', reflector::B.Translate('Z'));
    EXPECT_EQ('S', reflector::B.Translate('F'));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}
