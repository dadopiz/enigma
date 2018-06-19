#include <gtest/gtest.h>
#include <enigma/enigma.h>

class lib_test : public ::testing::Test {
protected:
    lib_test() {}

    virtual ~lib_test() {}

    virtual void SetUp() {}

    virtual void TearDown() {}

    enigma::M3 lib;
};

TEST_F(lib_test, test_1) {
    EXPECT_EQ(true, true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}
