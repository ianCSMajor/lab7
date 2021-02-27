#ifndef _POW_HPP_
#define _POW_HPP_

#include <math.h>
#include "op.hpp"
using namespace std; 
class Pow : public Base
{
	public: 
		Pow( Base* left, Base* right):Base()	
		{
			lstring = left -> stringify();
			rstring = right -> stringify();
			ldouble = left -> evaluate();
			rdouble = right -> evaluate();
		}
		virtual double evaluate()
		{
			return(pow(ldouble, rdouble));
		}
		virtual string stringify()
		{
			return(lstring + " ** " + rstring);
		}
	private:
		string lstring;
		string rstring;
		double ldouble;
		double rdouble;
};

#endif