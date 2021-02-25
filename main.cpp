#include <iostream>
#include <fstream>
#include <vector>
#include "factory.hpp"
#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"

using namespace std;

int main(int argc, char** argv) {
    Factory* f = new Factory();
    Base* test = f -> parse(argv, argc);
    if(!test) {
	cout << "Nullptr got!" << endl;
    }
    else {
	cout << test -> stringify() << " = " << test -> evaluate() << endl;
    }
    return 0; 
}
