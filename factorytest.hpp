#include "gtest/gtest.h"

#include "factory.hpp"
#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"

using namespace std;

TEST(FactoryTest, InvalidInput1) {
	char* test_val[3];
	test_val[0] = "./calculator";
	test_val[1] = "hello";
	test_val[2] = "world";
	Factory* f = new Factory();
	Base* test = f->parse(test_val, 3);
	ASSERT_TRUE(test == nullptr);
}

TEST(FactoryTest, InvalidInput2) {
	char* test_val[4];
	test_val[0] = "./calculator";
	test_val[1] = "5";
	test_val[2] = "+";
	test_val[3] = "g";
	Factory* f = new Factory();
	Base* test = f->parse(test_val, 4);
	ASSERT_TRUE(test == nullptr);
}

TEST(FactoryTest, InvalidInput3) {
        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "a";
        test_val[2] = "f";
        test_val[3] = "g";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 4);
        ASSERT_TRUE(test == nullptr);
}

TEST(FactoryTest, ValidInput1) {
        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "+";
	test_val[3] = "3";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_EQ(test -> stringify(), "5.000000 + 3.000000");
}

TEST(FactoryTest, ValidInput1Part2) {
        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "+";
        test_val[3] = "3";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_NEAR(test -> evaluate(), 8, 0.01);
}

TEST(FactoryTest, ValidInput2) {
        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "-";
        test_val[3] = "3";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_EQ(test -> stringify(), "5.000000 - 3.000000");
}

TEST(FactoryTest, ValidInput2Part2) {
        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "-";
        test_val[3] = "3";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_NEAR(test -> evaluate(), 2, 0.01);
}

TEST(FactoryTest, ValidInput3) {
        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "\*";
        test_val[3] = "3";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_EQ(test -> stringify(), "5.000000 * 3.000000");
}

TEST(FactoryTest, ValidInput3Part2) {
        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "\*";
        test_val[3] = "3";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_NEAR(test -> evaluate(), 15, 0.01);
}

TEST(FactoryTest, ValidInput4) {
        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "/";
        test_val[3] = "3";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_EQ(test -> stringify(), "5.000000 / 3.000000");
}

TEST(FactoryTest, ValidInput4Part2) {
        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "/";
        test_val[3] = "3";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_NEAR(test -> evaluate(), 1.666667, 0.01);
}

TEST(FactoryTest, ValidInput5) {
        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "\*\*";
        test_val[3] = "3";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_EQ(test -> stringify(), "5.000000 ** 3.000000");
}

TEST(FactoryTest, ValidInput5Part2) {
        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "\*\*";
        test_val[3] = "3";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_NEAR(test -> evaluate(), 125, 0.01);
}

TEST(FactoryTest, LongValidInput1) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "+";
        test_val[3] = "3";
	test_val[4] = "-";
	test_val[5] = "1";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        EXPECT_EQ(test -> stringify(), "5.000000 + 3.000000 - 1.000000");
}

TEST(FactoryTest, LongValidInput1Part2) {        
	char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "+";
        test_val[3] = "3";
        test_val[4] = "-";
        test_val[5] = "1";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        EXPECT_NEAR(test -> evaluate(), 7, 0.01);
}

TEST(FactoryTest, LongValidInput2) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "+";
        test_val[3] = "3";
        test_val[4] = "-";
        test_val[5] = "23";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        EXPECT_EQ(test -> stringify(), "5.000000 + 3.000000 - 23.000000");
}

TEST(FactoryTest, LongValidInput2Part2) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "+";
        test_val[3] = "3";
        test_val[4] = "-";
        test_val[5] = "23";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        EXPECT_NEAR(test -> evaluate(), -15, 0.01);
}

TEST(FactoryTest, LongValidInput3) {
        char* test_val[8];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "+";
        test_val[3] = "3";
        test_val[4] = "-";
        test_val[5] = "1";
	test_val[6] = "\*";
	test_val[7] = "2";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 8);
        EXPECT_EQ(test -> stringify(), "5.000000 + 3.000000 - 1.000000 * 2.000000");
}

TEST(FactoryTest, LongValidInput3Part2) {
        char* test_val[8];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "+";
        test_val[3] = "3";
        test_val[4] = "-";
        test_val[5] = "1";
	test_val[6] = "\*";
	test_val[7] = "2";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 8);
        EXPECT_NEAR(test -> evaluate(), 14, 0.01);
}

TEST(FactoryTest, LongValidInput4) {
        char* test_val[8];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "\*";
        test_val[3] = "3";
        test_val[4] = "-";
        test_val[5] = "1";
        test_val[6] = "+";
        test_val[7] = "2";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 8);
        EXPECT_EQ(test -> stringify(), "5.000000 * 3.000000 - 1.000000 + 2.000000");
}

TEST(FactoryTest, LongValidInput4Part2) {
        char* test_val[8];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "\*";
        test_val[3] = "3";
        test_val[4] = "-";
        test_val[5] = "1";
        test_val[6] = "+";
        test_val[7] = "2";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 8);
        EXPECT_NEAR(test -> evaluate(), 16, 0.01);
}

TEST(FactoryTest, LongValidInput5) {
        char* test_val[8];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "\*\*";
        test_val[3] = "3";
        test_val[4] = "-";
        test_val[5] = "1";
        test_val[6] = "\*";
        test_val[7] = "2";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 8);
        EXPECT_EQ(test -> stringify(), "5.000000 ** 3.000000 - 1.000000 * 2.000000");
}

TEST(FactoryTest, LongValidInput5Part2) {
        char* test_val[8];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "\*\*";
        test_val[3] = "3";
        test_val[4] = "-";
        test_val[5] = "1";
        test_val[6] = "\*";
        test_val[7] = "2";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 8);
        EXPECT_NEAR(test -> evaluate(), 248, 0.01);
}

TEST(FactoryTest, LongValidInput6) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "\*\*";
        test_val[3] = "3";
        test_val[4] = "/";
        test_val[5] = "5";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        EXPECT_EQ(test -> stringify(), "5.000000 ** 3.000000 / 5.000000");
}

TEST(FactoryTest, LongValidInput6Part2) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "\*\*";
        test_val[3] = "3";
        test_val[4] = "/";
        test_val[5] = "5";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        EXPECT_NEAR(test -> evaluate(), 25, 0.01);
}

TEST(FactoryTest, LongValidInput7) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "-";
        test_val[3] = "3";
        test_val[4] = "*";
        test_val[5] = "4";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        EXPECT_EQ(test -> stringify(), "5.000000 - 3.000000 * 4.000000");
}

TEST(FactoryTest, LongValidInput7Part2) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "-";
        test_val[3] = "3";
        test_val[4] = "*";
        test_val[5] = "4";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        EXPECT_NEAR(test -> evaluate(), 8, 0.01);
}

TEST(FactoryTest, LongValidInput8) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "+";
        test_val[3] = "3";
        test_val[4] = "\*\*";
        test_val[5] = "2";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        EXPECT_EQ(test -> stringify(), "5.000000 + 3.000000 ** 2.000000");
}

TEST(FactoryTest, LongValidInput8Part2) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "+";
        test_val[3] = "3";
        test_val[4] = "\*\*";
        test_val[5] = "2";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        EXPECT_NEAR(test -> evaluate(), 64, 0.01);
}

TEST(FactoryTest, LongValidInput9) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "6";
        test_val[2] = "/";
        test_val[3] = "3";
        test_val[4] = "\*";
        test_val[5] = "2";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        EXPECT_EQ(test -> stringify(), "6.000000 / 3.000000 * 2.000000");
}

TEST(FactoryTest, LongValidInput9Part2) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "6";
        test_val[2] = "/";
        test_val[3] = "3";
        test_val[4] = "\*";
        test_val[5] = "2";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        EXPECT_NEAR(test -> evaluate(), 4, 0.01);
}

TEST(FactoryTest, LongInvalidInput1) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "+";
        test_val[3] = "3";
	test_val[4] = "-";
	test_val[5] = "f";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        ASSERT_TRUE(test == nullptr);
}

TEST(FactoryTest, LongInvalidInput2) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "+";
        test_val[3] = "3";
        test_val[4] = "g";
        test_val[5] = "1";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        ASSERT_TRUE(test == nullptr);
}

TEST(FactoryTest, LongInvalidInput3) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "g";
        test_val[2] = "+";
        test_val[3] = "3";
        test_val[4] = "-";
        test_val[5] = "1";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        ASSERT_TRUE(test == nullptr);
}

TEST(FactoryTest, LongInvalidInput4) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "5";
        test_val[2] = "f";
        test_val[3] = "3";
        test_val[4] = "-";
        test_val[5] = "1";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        ASSERT_TRUE(test == nullptr);
}

TEST(FactoryTest, LongInvalidInput5) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "hello";
        test_val[2] = "+";
        test_val[3] = "3";
        test_val[4] = "world";
        test_val[5] = "1";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        ASSERT_TRUE(test == nullptr);
}

TEST(FactoryTest, LongInvalidInput6) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "hello";
        test_val[2] = "this";
        test_val[3] = "is";
        test_val[4] = "a";
        test_val[5] = "message";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        ASSERT_TRUE(test == nullptr);
}

TEST(FactoryTest, LongInvalidInput7) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "oh";
        test_val[2] = "wait";
        test_val[3] = "too";
        test_val[4] = "late";
        test_val[5] = "huh";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 6);
        ASSERT_TRUE(test == nullptr);
}

TEST(FactoryTest, LongInvalidInput8) {
        char* test_val[7];
        test_val[0] = "./calculator";
        test_val[1] = "well";
        test_val[2] = "i";
        test_val[3] = "guess";
        test_val[4] = "1";
        test_val[5] = "is";
	test_val[6] = "invalid";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 7);
        ASSERT_TRUE(test == nullptr);
}

TEST(FactoryTest, LongInvalidInput9) {
        char* test_val[5];
        test_val[0] = "./calculator";
        test_val[1] = "ok";
        test_val[2] = "last";
        test_val[3] = "1";
        test_val[4] = "2";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 5);
        ASSERT_TRUE(test == nullptr);
}
