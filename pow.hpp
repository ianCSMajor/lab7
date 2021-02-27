
#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <math.h>

class Pow : public Base {
    public:
	Pow(Base* baseVal, Base* expVal) : Base(), base(baseVal), exp(expVal) {}
	virtual double evaluate() {pow(base -> evaluate(), exp -> evaluate());}
	virtual std::string stringify() {
		return base -> stringify() + " ** " + exp -> stringify();
	}
    private:
	Base* base;
	Base* exp;
};

#endif

