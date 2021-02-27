#ifndef _DIV_HPP_
#define _DIV_HPP_

#include "op.hpp"
using namespace std;
class Div : public Base {
  private:
		Base* val1;
		Base* val2;

	public:
		Div( Base* op1, Base* op2) : Base(), val1(op1), val2(op2){}

		virtual double evaluate(){
			return(val1->evaluate() / val2->evaluate());
		}

		virtual string stringify(){
			return (val2->stringify() + " / " + val2->stringify());
		}
	
};


#endif

