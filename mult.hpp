
#ifndef MULT_HPP
#define MULT_HPP

#include "base.hpp"

class Mult : public Base {
    public:
        Mult(Base* initVal, Base* multVal) : Base(), val1(initVal), val2(multVal) {}
        virtual double evaluate() {return val1 -> evaluate() * val2 -> evaluate(); }
        virtual std::string stringify() {
            return val1 -> stringify() + " * " + val2 -> stringify();
        }
    private:
        Base* val1;
        Base* val2;
};

#endif


