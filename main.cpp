#include <iostream>
#include <fstream>
#include <vector>

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
