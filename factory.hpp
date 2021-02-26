#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "base.hpp"
#include <iostream>
#include <cstring>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <cctype>

using namespace std;
class Base;

class Factory {
    private:
	bool isNumber(const string& input) {
    	    if(input == ".") return false;
   	    unsigned j = 0;
    	    if(input.at(0) == '-') {
        	j++;
    	    }
    	    int dotCount = 0;
    	    for(unsigned i = j; i < input.size(); i++) {
        	if(input.at(i) == '.') {
            	    dotCount++;
        	}
            else if((input.at(i) < '0' || input.at(i) > '9') && input.at(i) != '.') {
            	return false;
            }
            if(dotCount > 1) return false;
    	    }
    	    return true;
 	}
    public:
	Factory() {};
	Base* parse(char** input, int length) {	  
	    if(length == 3 || length%2!=0) {
		return nullptr;
	    }
	    Base* first = nullptr;
	    Base* second = nullptr;
            string stringIn = static_cast<string>(input[1]);
	    string stringIn2 = static_cast<string>(input[3]);
	    if(isNumber(stringIn) && isNumber(stringIn2)){
		first = new Op(stod(stringIn));
		second = new Op(stod(stringIn2));
	    }
	    else {
		return nullptr;
	    }
	    Base* initial = nullptr;
	    string inputString = static_cast<string>(input[2]);
	    if(inputString == "+")
		 initial = new Add(first, second);
	    else if(inputString == "-")
		 initial = new Sub(first, second);
	    else if(inputString == "\*")
                 initial = new Mult(first, second);
	    else if(inputString == "/")
                 initial = new Div(first, second);
	    else if(inputString == "\*\*")
                 initial = new Pow(first, second);
	    else {
		return nullptr;	
	    }
	    for(int i = 4; i + 1 < length; i+=2){
		if(isNumber(static_cast<string>(input[i+1])))
		{
		    inputString = static_cast<string>(input[i]);
		    if(inputString == "+")
                	 initial = new Add(initial, new Op(stod(input[i+1])));
		    else if(inputString == "-")
                	 initial = new Sub(initial, new Op(stod(input[i+1])));
          	    else if(inputString == "*")
                	 initial = new Mult(initial, new Op(stod(input[i+1])));
          	    else if(inputString == "/")
                	 initial = new Div(initial, new Op(stod(input[i+1])));
           	    else if(inputString == "**")
                 	 initial = new Pow(initial, new Op(stod(input[i+1])));
		    else{
			return nullptr;	
		    }
		}
		else {
		    return nullptr;
		}
	    } 
	    return initial;
	}
};

#endif
