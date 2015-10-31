// Created by Cameron L'Ecuyer
// Last Modified: 10/31/2015

#include <stack>
#include <cctype>
using namespace::std;

const string OPERATORS[] = 
	{"||", "&&", "==", "!=", ">", ">=", "<", "<=", "+", "-", "*", "/", "%", "^", "-", "--", "++", "!", "(", ")", "[", "]", "{", "}"};
const int PRECEDENCE[] = {1, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 7, 8, 8, 8, 8, -1, -1, -1, -1, -1, -1};

class InfixEvaluator
{
private:
	stack<string> operators;
	stack<string> operands;

public:
	// Default constructor
	InfixEvaluator()
	{

	} // end default constructor

	string removeWhiteSpace(string input)
	{
		return "";
	} // end removeWhiteSpace

	int evaluate(string& input)
	{
		return 0;
	} // end evaluate

	int evaluateOperators(string& operatorInput)
	{
		return 0;
	} // end evaluateOperators

	int convertNumbers(string& input)
	{
		return 0;
	} // end convertNumbers
}; // end class InfixEvaluator