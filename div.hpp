#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {
    public:
	Div(Base* initVal, Base* divVal) : Base(), val1(initVal), val2(divVal) {}
	virtual double evaluate() {
	    if(val2 -> evaluate() == 0) {
		return NULL;
	    }
	    return val1 -> evaluate() / val2 -> evaluate();
	}
	virtual std::string stringify() {
		return val1 -> stringify() + " / " + val2 -> stringify();
	}
    private:
	Base* val1;
	Base* val2;
};

#endif
