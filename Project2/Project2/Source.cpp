// Created by Cameron L'Ecuyer
// Last Modified: 10/31/2015

#include "InfixEvaluator.h"
#include <iostream>
using namespace::std;

void main()
{
	InfixEvaluator eval;

	try
	{
		eval.removeWhiteSpace("2 3");
	}
	catch(exception e)
	{
	}
} // end main