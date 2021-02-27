#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <array>
#include <ctype.h>

//You have to include these classes/files form lab 3:
#include "base.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "op.hpp"
using namespace std;


struct Factory {
  Factory(){ }; 
  Base* parse(char** strInput, int length){
    string strArr[length-1];
    Base* composite;

    for(int i = 1; i< length; i++){
      strArr[i-1]= static_cast<string>(strInput[i]); 
    }

    for(int i = 0; i< length-1; i++){
      //strArr[i]= static_cast<string>(strInput[i]); 
      if(i%2==1){
        if(!(strArr[i]=="+" || strArr[i]=="-" || strArr[i]=="*" || strArr[i]=="/" || strArr[i]=="**")){
          return nullptr;
        }
      } 
      else if(i%2==0){
        if(  !(isdigit(strArr[i].at(0)))  ){
          return nullptr;
        }
      }
    }

   
    if( strArr[1] == "+" ){
      composite = new Add(new Op(stod(strArr[0])), new Op(stod(strArr[2])));
    }
    else if( strArr[1] == "-" ){
      composite = new Sub(new Op(stod(strArr[0])), new Op(stod(strArr[2])));
    }
    else if( strArr[1] == "*" ){
      composite = new Mult(new Op(stod(strArr[0])), new Op(stod(strArr[2])));
    }
    else if( strArr[1] == "/" ){
      composite = new Div(new Op(stod(strArr[0])), new Op(stod(strArr[2])));
    }
    else if( strArr[1] == "**" ){
      composite = new Pow(new Op(stod(strArr[0])), new Op(stod(strArr[2])));
    }
    // else{
    //    return nullptr;
    // }

    
    for(int i = 3; i< length; i+=2){
      if( strArr[i] == "+" ){
        composite = new Add(new Op(composite->evaluate()), new Op(stod(strArr[i+1])));
      }
      else if( strArr[i] == "-" ){
        composite = new Sub(new Op(composite->evaluate()), new Op(stod(strArr[i+1])));
      }
      else if( strArr[i] == "*" ){
        composite = new Mult(new Op(composite->evaluate()), new Op(stod(strArr[i+1])));
      }
      else if( strArr[i] == "/" ){
        composite = new Div(new Op(composite->evaluate()), new Op(stod(strArr[i+1])));
      }
      else if( strArr[i] == "**" ){
        composite = new Pow(new Op(composite->evaluate()), new Op(stod(strArr[i+1])));
      }
      // else{
      //   return nullptr;
      // }
    }
    return composite;
  }
};
#endif
