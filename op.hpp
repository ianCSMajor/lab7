#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
        Op(double value) : Base() {
     val = value;
     str = std::to_string(val);
     str.erase(str.find_last_not_of('0') + 1, std::string::npos);
     str.erase(str.find_last_not_of('.') + 1, std::string::npos);
 }
        virtual double evaluate() { return val; }
        virtual std::string stringify() { return str; }
    protected:
    double val;
    std::string str;
};

#endif //__OP_HPP__