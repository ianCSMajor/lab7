#ifndef __ADD_HPP__
#define __ADD_HPP__


#include "op.hpp"
#include <iostream>
#include <string>
#include "base.hpp"

class Add : public Base {
    public:
	Add(Base* initialVal, Base* addVal): Base(), val1(initialVal), val2(addVal) {}
	virtual double evaluate() {return val1 -> evaluate() + val2 -> evaluate();}
	virtual std::string stringify() {
	    return val1 -> stringify() + " + " + val2 -> stringify();
	}
    private:
	Base* val1;
	Base* val2;
};
#endif

