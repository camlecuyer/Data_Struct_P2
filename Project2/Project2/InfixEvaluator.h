// Created by Cameron L'Ecuyer
// Last Modified: 10/31/2015

#include <stack>
#include <cctype>
#include <iostream>
using namespace::std;

const string OPERATORS[] = 
	{"||", "&&", "==", "!=", ">", ">=", "<", "<=", "+", "-", "*", "/", "%", "^", "-", "--", "++", "!", "(", ")", "[", "]", "{", "}"};
const int PRECEDENCE[] = {1, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 7, 8, 8, 8, 8, -1, -1, -1, -1, -1, -1};

class InfixEvaluator
{
private:
	stack<string> operators;
	stack<int> operands;

public:
	// Default constructor
	InfixEvaluator()
	{
	} // end default constructor

	int evaluate(string& input)
	{
		return 0;
	} // end evaluate

	string removeWhiteSpace(string input)
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
	} // end removeWhiteSpace

	bool isOperator(string input)
	{
		return false;
	} // end isOperator

	int evaluateOperators(string& operatorInput)
	{
		return 0;
	} // end evaluateOperators

	int convertNumbers(string& input)
	{
		return 0;
	} // end convertNumbers
}; // end class InfixEvaluator