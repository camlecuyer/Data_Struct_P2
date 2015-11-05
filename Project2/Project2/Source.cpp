// Created by Cameron L'Ecuyer
// Last Modified: 11/04/2015

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
		cout << eval.evaluate("(-6 / 3) + 8 % 3 < 5^2 - 8") << endl;
		cout << eval.evaluate("[-9 / 3] >= 3 - 6 && !{8 / 2 > 4}") << endl;
		cout << eval.evaluate("++3 == --5") << endl;
		cout << eval.evaluate("[11 - 8] != 2*6 || ++8 > 4^4") << endl;
		cout << eval.evaluate("4^4") << endl;
	}
	catch(exception e)
	{
		cout << e.what() << endl;
	} // end try/catch
} // end main