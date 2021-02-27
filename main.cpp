#include <iostream>
using namespace std;

#include "factory.hpp"


//you have to include these classes from lab3
#include "Div.hpp"
#include "Pow.hpp"
#include "Sub.hpp"
#include "add.hpp"
#include "base.hpp"
#include "mult.hpp"
#include "op.hpp"


//test cases should be removed from the final version of the main function
int main (int argv, char** argc){

//----------------------Test Case----------------------------- 
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
//------------------------------------------------------------  

  Factory* f = new Factory();
  Base* result = f->parse(test_val, 11);

  string reslutStr= result->stringify();
  double resultDbl= result->evaluate();

    cout << "Expression: " << reslutStr << endl;
    cout << "Result: " << resultDbl << endl;
  



return 0;
}
