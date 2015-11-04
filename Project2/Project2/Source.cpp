// Created by Cameron L'Ecuyer
// Last Modified: 10/31/2015

//#include "InfixEvaluator.cpp"
#include "InfixEvaluator.h"

void main()
{
	InfixEvaluator eval;

	try
	{
		cout << eval.evaluate("123 + 5 * 6") << endl;
		cout << eval.evaluate("123+5*6") << endl;
		cout << eval.evaluate("(-4) * 6 + 8 / 2 ^ 2") << endl;
		cout << eval.evaluate("4 <= 4") << endl;
	}
	catch(exception e)
	{
		cout << e.what();
	}
} // end main