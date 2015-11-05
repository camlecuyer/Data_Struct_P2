// Created by Cameron L'Ecuyer
// Last Modified: 11/04/2015

#ifndef INFIXEVALUATOR_H
#define INFIXEVALUATOR_H

#include <stack>
#include <cctype>
#include <iostream>
#include <string>
using namespace::std;

// const variable holds all operators, negative (-) is substituted with (.) when stored for simplicity of searching
const string OPERATORS[] =
	{"||", "&&", "==", "!=", ">", ">=", "<", "<=", "+", "-", "*", "/", "%", "^", ".", "--", "++", "!", "(", ")", "[", "]", "{", "}"};
// const variable holds the precedence of the operators
const int PRECEDENCE[] = {1, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 7, 8, 8, 8, 8, -1, -1, -1, -1, -1, -1};

class InfixEvaluator
{
private:
	// stack of operators held as strings
	stack<string> operators;
	// stack of operands stored as integers
	stack<int> operands;

	/** Removes leading and trailing whitespace and extra white spaces
	@param input is the input string passed from caller
	*/
	string InfixEvaluator::removeWhiteSpace(string input)
	{
		// temp variable for whitespace adjustment
		string temp = "";
		// removes leading whitespace
		input = input.erase(0, input.find_first_not_of(" "));
		// removes trailing whitespace
		input = input.erase(input.find_last_not_of(" ") + 1);

		// control flag for loop
		size_t i = 0;
		// bool determines if a space is already found
		// so that additional spaces can be removed
		bool spaceFound = false;

		// loops through input to removes unneccessary spaces
		while(i < input.length())
		{
			// if a space is found enter inner if
			// else add to temp
			if(input[i] == ' ')
			{
				// if no space found add the space to temp and 
				//set spaceFound to true to remove additional spaces
				if(!spaceFound)
				{
					temp += input[i];
					spaceFound = true;
				} // end if
			}
			else
			{
				// if a non-space is found set spaceFound to false and
				// add char to temp
				spaceFound = false;
				temp += input[i];
			} // end if

			i++; // increment control flag
		} // end loop
	
		// return the reduced string
		return temp;
	} // end removeWhiteSpace

	/** Determines the precedence of the operator that is passed in
	@param input is the input string passed from the main function
	*/
	int InfixEvaluator::precedence(string input)
	{
		// control flag used to locate operator and
		// to find precedence
		int i = 0;

		// loop through  OPERATORS to find input match, if it exists
		for(i; i < 24; i++)
		{
			// if match is found break from loop
			if(input == OPERATORS[i])
			{
				break;
			} // end if
		} // end loop

		// return the precedence of the operator
		return PRECEDENCE[i];
	} // end precedence

	/** Evaluates the various operators
	@param operatorInput is the input string passed from the caller
	*/
	int InfixEvaluator::evaluateOperators(string& operatorInput)
	{
		// holds the result of the operation
		int result = 0;
		// control flag for use in loop and switch
		int i = 0;

		// loop through OPERATORS to find match to operatorInput
		for(i; i < 18; i++)
		{
			// if a match is found break from loop
			if(operatorInput == OPERATORS[i])
			{
				break;
			} // end if
		} // end loop

		// throw exception if operands stack is empty
		if (operands.empty()) 
		{
			throw exception("Operand stack is empty");
		} // end if

		// work variables
		int temp1, temp2;

		// place the first (right) operand into the work variable
		// and pop it from the stack
		temp1 = operands.top();
		operands.pop();

		// switch control to find correct operation
		// uses input from the match determined in loop
		switch(i)
		{
			// || operation
			case 0:
			{
				// throw exception if operands stack is empty
				if (operands.empty()) 
				{
					throw exception("Operand stack is empty");
				} // end if

				// place the second (left) operand into the work variable
				// and pop it from the stack
				temp2 = operands.top();
				operands.pop();

				// return temp1 || temp2
				return temp1 || temp2;
				break;
			}
			// && operation
			case 1:
			{
				// throw exception if operands stack is empty
				if (operands.empty()) 
				{
					throw exception("Operand stack is empty");
				} // end if

				// place the second (left) operand into the work variable
				// and pop it from the stack
				temp2 = operands.top();
				operands.pop();

				// return temp1 && temp2
				return temp1 && temp2;
				break;
			}
			// == operation
			case 2:
			{
				// throw exception if operands stack is empty
				if (operands.empty()) 
				{
					throw exception("Operand stack is empty");
				} // end if

				// place the second (left) operand into the work variable
				// and pop it from the stack
				temp2 = operands.top();
				operands.pop();

				// return temp1 == temp2
				return temp1 == temp2;
				break;
			}
			// != operation
			case 3:
			{
				// throw exception if operands stack is empty
				if (operands.empty()) 
				{
					throw exception("Operand stack is empty");
				} // end if

				// place the second (left) operand into the work variable
				// and pop it from the stack
				temp2 = operands.top();
				operands.pop();

				// return temp1 != temp2
				return temp1 != temp2;
				break;
			}
			// > operation
			case 4:
			{
				// throw exception if operands stack is empty
				if (operands.empty()) 
				{
					throw exception("Operand stack is empty");
				} // end if

				// place the second (left) operand into the work variable
				// and pop it from the stack
				temp2 = operands.top();
				operands.pop();

				// return temp1 < temp2
				return temp1 < temp2;
				break;
			}
			// >= operation
			case 5:
			{
				// throw exception if operands stack is empty
				if (operands.empty()) 
				{
					throw exception("Operand stack is empty");
				} // end if

				// place the second (left) operand into the work variable
				// and pop it from the stack
				temp2 = operands.top();
				operands.pop();

				// return temp1 <= temp2
				return temp1 <= temp2;
				break;
			}
			// < operation
			case 6:
			{
				// throw exception if operands stack is empty
				if (operands.empty()) 
				{
					throw exception("Operand stack is empty");
				} // end if

				// place the second (left) operand into the work variable
				// and pop it from the stack
				temp2 = operands.top();
				operands.pop();

				// return temp1 > temp2
				return temp1 > temp2;
				break;
			}
			// <= operation
			case 7:
			{
				// throw exception if operands stack is empty
				if (operands.empty()) 
				{
					throw exception("Operand stack is empty");
				} // end if

				// place the second (left) operand into the work variable
				// and pop it from the stack
				temp2 = operands.top();
				operands.pop();

				// return temp1 >= temp2
				return temp1 >= temp2;
				break;
			}
			// + operation
			case 8:
			{
				// throw exception if operands stack is empty
				if (operands.empty()) 
				{
					throw exception("Operand stack is empty");
				} // end if

				// place the second (left) operand into the work variable
				// and pop it from the stack
				temp2 = operands.top();
				operands.pop();

				// return temp1 + temp2
				return temp1 + temp2;
				break;
			}
			// - operation
			case 9:
			{
				// throw exception if operands stack is empty
				if (operands.empty()) 
				{
					throw exception("Operand stack is empty");
				} // end if

				// place the second (left) operand into the work variable
				// and pop it from the stack
				temp2 = operands.top();
				operands.pop();

				// return temp2 - temp1
				return temp2 - temp1;
				break;
			}
			// * operation
			case 10:
			{
				// throw exception if operands stack is empty
				if (operands.empty()) 
				{
					throw exception("Operand stack is empty");
				} // end if

				// place the second (left) operand into the work variable
				// and pop it from the stack
				temp2 = operands.top();
				operands.pop();

				// return temp1 * temp2
				return temp1 * temp2;
				break;
			}
			// / operation
			case 11:
			{
				// throw exception if operands stack is empty
				if (operands.empty()) 
				{
					throw exception("Operand stack is empty");
				} // end if

				// place the second (left) operand into the work variable
				// and pop it from the stack
				temp2 = operands.top();
				operands.pop();

				// tests if the right operand is zero
				// if it is it throws an exception
				if(temp1 == 0)
				{
					throw exception("Divide by zero error attempted");
				} // end if

				// return temp2 / temp1
				return temp2 / temp1;
				break;
			}
			// % operation
			case 12:
			{
				// throw exception if operands stack is empty
				if (operands.empty()) 
				{
					throw exception("Operand stack is empty");
				} // end if

				// place the second (left) operand into the work variable
				// and pop it from the stack
				temp2 = operands.top();
				operands.pop();

				// tests if the right operand is zero
				// if it is it throws an exception
				if(temp1 == 0)
				{
					throw exception("Divide by zero error attempted");
				} // end if

				// return temp2 % temp1
				return temp2 % temp1;
				break;
			}
			// ^ operation
			case 13:
			{
				// throw exception if operands stack is empty
				if (operands.empty()) 
				{
					throw exception("Operand stack is empty");
				} // end if

				// place the second (left) operand into the work variable
				// and pop it from the stack
				temp2 = operands.top();
				operands.pop();

				// places temp2 into a tempory result
				int tempRes = temp2;

				// if temp1 is 0 return a 1
				// if temp1 is 1 reuturn temp2
				// else calculate power
				if(temp1 == 0)
				{
					return 1;
				}
				else if(temp1 == 1)
				{
					return temp2;
				}
				else
				{
					// loop until equal to power
					for(int i = 1; i < temp1; i++)
					{
						// multiply answer by base
						tempRes *= temp2;
					} // end loop
				} // end if

				// return temp2 ^ temp1
				return tempRes;
				break;
			}
			// - (negative) operation
			case 14:
			{
				// return - temp1
				return 0 - temp1;
				break;
			}
			// -- operation
			case 15:
			{
				// return --temp1
				return --temp1;
				break;
			}
			// ++ operation
			case 16:
			{
				// return ++temp1
				return ++temp1;
				break;
			}
			// ! operation
			case 17:
			{
				// return !temp1
				return !temp1;
				break;
			}
		} // end switch
	} // end evaluateOperators

	/** Converts strings into integers
	@param input is the input string passed in to be converted
	*/
	int InfixEvaluator::convertNumbers(string& input)
	{
		// converts a string into a decimal number and returns it
		return stoi(input, nullptr, 10);
	} // end convertNumbers

public:
	// Default constructor
	InfixEvaluator()
	{
	} // end default constructor

	/** Evaluates the input
	@param input is the input string passed from the main function
	*/
	int InfixEvaluator::evaluate(string input)
	{
		// removes extra white space from input
		input = removeWhiteSpace(input);

		// bool to determine if a number was last char found
		bool lastNum = false;

		// throws excpetion if first char is a parathesis or comparison operator
		if(input[0] == ')' || input[0] == '}' || input[0] == ']')
		{
			throw exception("Expression cannot start with closing parenthesis @ char 0");
		}
		else if(input[0] == '<' || input[0] == '>' || input[0] == '=' || input[0] == '&' || input[0] == '|')
		{
			throw exception("Expression cannot start with binary operator @ char 0");
		} // end if

		// holds final result to be passed back
		int result = 0;
		// temp work variable
		string temp = "";
		// control flag for loop
		size_t i = 0;

		// loop through input string to evaluate expression
		while(i < input.length())
		{
			// determine if valid operator or digit
			if(input[i] == '=')
			{
				// if char is = add to temp variable and increment control flag
				temp += input[i];
				i++;

				// if next char is not = throw error
				if(input[i] != '=')
				{
					cout << "Invalid operator = @ char " << i << endl;
					throw exception("Error Occurred");
				}
				else
				{
					// else add it to temp
					temp += input[i];
				} // end if
			}
			else if(input[i] == '!')
			{
				// if char is ! add to temp
				temp += input[i];

				// if next char is =
				if(input[i + 1] == '=')
				{
					// increment control var and add to temp
					i++;
					temp += input[i];
				} // end if
			}
			else if(input[i] == '|')
			{
				// if char is | add to temp and increment control
				temp += input[i];
				i++;

				// the next char is not | throw error
				if(input[i] != '|')
				{
					cout << "Invalid operator | @ char " << i << endl;
					throw exception("Error Occurred");
				}
				else
				{
					// if char is | add to temp
					temp += input[i];
				} // end if
			}
			else if(input[i] == '&')
			{
				// if char is & add to temp and increment control
				temp += input[i];
				i++;

				// if next char is not & throw error
				if(input[i] != '&')
				{
					cout << "Invalid operator & @ char " << i << endl;
					throw exception("Error Occurred");
				}
				else
				{
					// if it is & add to temp
					temp += input[i];
				} // end if
			} 
			else if(input[i] == '<')
			{
				// if char is < add to temp
				temp += input[i];

				// if next char is =
				if(input[i + 1] == '=')
				{
					// increment control and add to temp
					i++;
					temp += input[i];	
				} // end if
			}
			else if(input[i] == '>')
			{
				// if char is > add to temp
				temp += input[i];

				// if next char is =
				if(input[i + 1] == '=')
				{
					// increment control and add to temp
					i++;
					temp += input[i];
				} // end if
			} 
			else if(input[i] == '+')
			{
				// if char is + add to temp
				temp += input[i];

				// if next char is +
				if(input[i + 1] == '+')
				{
					// increment control and add to temp
					i++;
					temp += input[i];
				} // end if
			}
			else if(input[i] == '-')
			{
				// if char is - check next char
				if(input[i + 1] == '-')
				{
					// if next char is - add both to temp
					// with an increment in between
					temp += input[i];
					i++;
					temp += input[i];
				}
				else if(i == 0)
				{
					// if - in first position
					// add negative symbol to temp
					temp += '.';
				}
				else if(i >= 1 && !lastNum)
				{
					// if the last digit added was not a number
					// add negative to temp
					temp += '.';
				}
				else
				{
					// else add - to temp
					temp += input[i];
				} // end if
			}
			else if(input[i] == '*' || input[i] == '/' || input[i] == '%' || input[i] == '^')
			{
				// if char is * / % or ^ add to temp
				temp += input[i];
			}
			else if(input[i] == '(' || input[i] == '[' || input[i] == '{' || input[i] == ')' || input[i] == ']' || input[i] == '}')
			{
				// if char is () [] or {} add to temp
				temp += input[i];
			}
			else if(isdigit(input[i]))
			{
				// if char is digit add to temp
				temp += input[i];

				// check to see if more digits
				while(isdigit(input[i + 1]))
				{
					// add all consecutive digits to temp
					i++;
					temp += input[i];
				} // end loop
				
				// push converted number onto operands stack
				operands.push(convertNumbers(temp));
				// set variable to true as a number was the last item added
				lastNum = true;
				// reset temp
				temp = "";
			}
			else if(input[i] == ' ')
			{
				// if the digit is a space, check to either side for a number
				if(isdigit(input[i-1]) && isdigit(input[i+1]))
				{
					// if a number is on both sides, throw an error
					cout << "Two operands in a row @ char " << i << endl;
					throw exception("Error Occurred");
				} // end if

				// if there are two binary operators (or binary and unary) throw error
				if((input[i-1] == '|' || input[i-1] == '&') && (input[i+1] == '|' || input[i+1] == '&'))
				{
					cout << "Two operators in a row @ char " << i << endl;
					throw exception("Error Occurred");
				} // end if
			}
			else
			{
				// if this case is reached character is invalid input
				cout << "Invalid character input @ char " << i << endl;
				throw exception("Error Occurred");
			}// end if

			// if closing char found
			if(temp == ")" || temp == "]" || temp == "}")
			{
				// loop through to remove operators until opening char is found
				while(operators.size() > 0 && ((operators.top() != "(") && (operators.top() != "[") && (operators.top() != "{")))
				{
					// evaluate operators and pop them from the stack
					// push the evaluated operands back onto operand stack
					operands.push(evaluateOperators(operators.top()));
					operators.pop();
				} // end loop

				// set to false as last char found was operator
				lastNum = false;
				// pop the opening operator from stack
				operators.pop();
				// reset temp
				temp = "";
			} // end if

			// if temp holds an operator
			if(temp != "")
			{
				// compare the operator temp is holding to the top of the operator stack
				// if the top of the stack is greater than temp's operator enter the if
				if(operators.size() > 0 && (precedence(operators.top()) >= precedence(temp))  && (precedence(temp) > 0))
				{
					// evaluate operators until temp's operator is the greatest
					while(operators.size() > 0 && (precedence(operators.top()) >= precedence(temp)))
					{
						// evaluate operators and pop them from the stack
						// push the evaluated operands back onto operand stack
						operands.push(evaluateOperators(operators.top()));
						operators.pop();
					} // end loop
				} // end if
				
				// push temp's operator onto the stack
				operators.push(temp);
				// set to false as last char found was operator
				lastNum = false;
				// reset temp
				temp = "";
			} // end if

			// increment control
			i++;
		} // end loop

		// if there are still operators on the operator stack
		while(!operators.empty())
		{
			// evaluate operators and pop them from the stack
			// push the evaluated operands back onto operand stack
			operands.push(evaluateOperators(operators.top()));
			operators.pop();
		} // end loop

		// if operands stack is empty throw error
		if(!operands.empty())
		{
			// if the stack is not empty get the final answer
			// and pop it from the operands stack
			result = operands.top();
			operands.pop();
		}
		else
		{
			throw exception("Operand stack is empty, too many operators");
		}// end if 

		// throw error if the operands stack is not empty after getting answer
		if(!operands.empty())
		{
			throw exception("Operand stack should be empty, too few operators");
		} // end if

		// return result to caller
		return result;
	} // end evaluate
}; // end class InfixEvaluator
#endif