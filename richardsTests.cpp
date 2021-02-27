//#ifndef _TESTS_HPP_
//#define _TESTS_HPP_

#include "gtest/gtest.h"
#include <iostream>
#include "factory.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "base.hpp"
#include "op.hpp"
using namespace std;

TEST(FactorySuite, addition) {
  char* test_val[3]; 
  test_val[0] = "5"; 
  test_val[1] = "+"; 
  test_val[2] = "6"; 

  Factory* fac = new Factory();
  Base* result = fac->parse(test_val, 3);

  EXPECT_EQ("5.000000 + 6.000000", result->stringify());
  EXPECT_EQ(11, result->evaluate());
}



TEST(FactorySuite, everyOperation) {
  char* test_val[11]; 
  test_val[0] = "5"; 
  test_val[1] = "+"; 
  test_val[2] = "6"; 
  test_val[3] = "-"; 
  test_val[4] = "7"; 
  test_val[5] = "*";
  test_val[6] = "3";
  test_val[7] = "/";
  test_val[8] = "4";
  test_val[9] = "**";
  test_val[10] = "3";

  Factory* fac = new Factory();
  Base* result = fac->parse(test_val, 11);

  EXPECT_EQ("3.000000 ** 3.000000", result->stringify());
  EXPECT_EQ(27, result->evaluate());
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
