#include <iostream>
using namespace std;

#include "factory.hpp"


//you have to include these classes from lab3
#include "div.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "base.hpp"
#include "mult.hpp"
#include "op.hpp"


//test cases should be removed from the final version of the main function
int main (int argv, char** argc){

//----------------------Test Cases----------------------------- 
  // char* test_val[12]; 
  // test_val[0] = "./calculator"; 
  // test_val[1] = "5"; 
  // test_val[2] = "+"; 
  // test_val[3] = "6"; 
  // test_val[4] = "-"; 
  // test_val[5] = "7"; 
  // test_val[6] = "*";
  // test_val[7] = "3";
  // test_val[8] = "/";
  // test_val[9] = "4";
  // test_val[10] = "**";
  // test_val[11] = "3";
//------------------------------------------------------------  

  Factory* fac = new Factory();
  Base* result = fac->parse(argc, argv);

  if (result == nullptr){
    cout << "Invalid Input" << endl;
  }
  else{
    cout << "Expression: " << result->stringify() << endl;
    cout << "Result: " << result->evaluate() << endl;
  }


return 0;
}
