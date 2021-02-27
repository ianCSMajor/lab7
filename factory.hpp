#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <array>
#include <ctype.h>

//You have to include these classes/files form lab 3:
//// #include "base.hpp"
//// #include "Div.hpp"
//// #include "Pow.hpp"
//// #include "Sub.hpp"
//// #include "add.hpp"
//// #include "mult.hpp"
//// #include "op.hpp"
//// using namespace std;

struct Factory{
	Factory(){};
	Base* parse(char** strInput, int length){
	  string strArr[length];
    	  Base* composite;

          for(int i = 0; i< length; i++){
            strArr[i]= static_cast<string>(strInput[i]); 
          }

	  if( strArr[1] == "+" ){
      	    composite = new Add(new Op(stod(strArr[0])), new Op(		stod(strArr[2])));
    	  }
          else if( strArr[1] == "-" ){
            composite = new Sub(new Op(stod(strArr[0])), new Op(stod            (strArr[2])));
          }
          else if( strArr[1] == "*" ){
            composite = new Mult(new Op(stod(strArr[0])), new Op(sto            d(strArr[2])));
          }
          else if( strArr[1] == "/" ){
            composite = new Div(new Op(stod(strArr[0])), new Op(stod            (strArr[2])));
          }
          else if( strArr[1] == "**" ){
            composite = new Pow(new Op(stod(strArr[0])), new Op(stod            (strArr[2])));
          }
          else{
            cout<< "invalid input"<<endl;
          }
	

	  return composite;
	}

};
#endif
