#ifndef _TESTS_HPP_
#define _TESTS_HPP_

#include "gtest/gtest.h"
#include <iostream>
#include "factory.hpp"
#include "add.hpp"
#include "Sub.hpp"
#include "mult.hpp"
#include "Div.hpp"
#include "Pow.hpp"
#include "base.hpp"
#include "op.hpp"
using namespace std;



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

  // string resultStr = test->stringify();
  // double resultDbl = test->evaluate();


  EXPECT_EQ("3 ** 3", test->stringify());
  EXPECT_EQ(27, test->evaluate());
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}