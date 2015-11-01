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

	/*string removeWhiteSpace(string input)
	{
		string temp = "";
		for(int i = 0; i < input.size(); i++)
		{
			if(input[i] == ' ')
			{
				if(i > 0 && isdigit(input[i-1]) && isdigit(input[i+1]))
				{
					cout << "Two operands in a row @ char " << i;
				}
				else if(i > 0 && isOperator(input[i-1]) && isOperator(input[i+1]))
				{
					cout << "Two operands in a row @ char " << i;
				}// end if
			}
			else
			{
				temp += input[i];
			} // end if
		} // end loop

		return temp;
	} // end removeWhiteSpace*/

	/*bool isOperator(char input)
	{
		return false;
	} // end isOperator*/

	int evaluateOperators(string& operatorInput);

	int convertNumbers(string& input);
}; // end class InfixEvaluator

#endif