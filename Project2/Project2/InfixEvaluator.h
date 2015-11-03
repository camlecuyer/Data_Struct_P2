// Created by Cameron L'Ecuyer
// Last Modified: 10/31/2015

#ifndef INFIXEVALUATOR_H_
#define INFIXEVALUATOR_H_

#include <stack>
#include <cctype>
#include <iostream>
#include <string>
using namespace::std;

class InfixEvaluator
{
private:
	static const string OPERATORS[];
	static const int PRECEDENCE[];
	stack<string> operators;
	stack<int> operands;

public:
	// Default constructor
	InfixEvaluator()
	{
	} // end default constructor

	int evaluate(string input);

	string removeWhiteSpace(string input);

	int precedence(string input);

	/*bool isOperator(char input)
	{
		return false;
	} // end isOperator*/

	int evaluateOperators(string& operatorInput);

	int convertNumbers(string& input);
}; // end class InfixEvaluator

#endif