// Created by Cameron L'Ecuyer
// Last Modified: 10/31/2015

#include "InfixEvaluator.cpp"
#include <iostream>
using namespace::std;

void main()
{
	InfixEvaluator eval;

	try
	{
		//eval.removeWhiteSpace("2 3");
		//eval.evaluate("123");
		//eval.evaluate("123 + 5 * 6");
		eval.evaluate("123+5*6");
	}
	catch(exception e)
	{
	}
} // end main