#include <iostream>
using namespace std;


//you hae to include these classes from lab3
//#include "Div.hpp"
//#include "Pow.hpp"
//#include "Sub.hpp
//#include "add.hpp"
//#include "base.hpp"
//#include "mult.hpp"
//#include "op.hpp"


//test cases should be removed from the final version of the main function
int main (int argv, char** argc){

  Factory* f = new Factory();
  Base* result = f->parse(test_val, 11);

  string reslutStr= result->stringify();
  double resultDbl= result->evaluate();

  cout << "Expression: " << reslutStr << endl;
  cout << "Result: " << resultDbl << endl;
  
return 0;
}
