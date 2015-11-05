// Created by Cameron L'Ecuyer
// Last Modified: 11/04/2015

#ifndef INFIXEVALUATOR_H
#define INFIXEVALUATOR_H

#include <stack>
#include <cctype>
#include <iostream>
#include <string>
using namespace::std;

const string OPERATORS[] =
	{"||", "&&", "==", "!=", ">", ">=", "<", "<=", "+", "-", "*", "/", "%", "^", ".", "--", "++", "!", "(", ")", "[", "]", "{", "}"};
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

	int InfixEvaluator::evaluate(string input)
	{
		input = removeWhiteSpace(input);

		bool lastNum = false;

		if(input[0] == ')' || input[0] == '}' || input[0] == ']')
		{
			cout << "Expression cannot start with closing parenthesis @ char 0";
			throw exception("Error Occurred");
		}
		else if(input[0] == '<' || input[0] == '>' || input[0] == '=')
		{
			cout << "Expression cannot start with binary operator @ char 0";
			throw exception("Error Occurred");
		}

		int result = 0;
		string temp = "";
		size_t i = 0;

		while(i < input.length())
		{
			if(input[i] == '=')
			{
				temp += input[i];
				i++;

				if(input[i] != '=')
				{
					cout << "Invalid operator = @ char " << i << endl;
					throw exception("Error Occurred");
				}
				else
				{
					temp += input[i];
				} // end if
			}
			else if(input[i] == '!')
			{
				temp += input[i];

				if(input[i + 1] == '=')
				{
					i++;
					temp += input[i];
				} // end if
			}
			else if(input[i] == '|')
			{
				temp += input[i];
				i++;

				if(input[i] != '|')
				{
					cout << "Invalid operator | @ char " << i << endl;
					throw exception("Error Occurred");
				}
				else
				{
					temp += input[i];
				} // end if
			}
			else if(input[i] == '&')
			{
				temp += input[i];
				i++;

				if(input[i] != '&')
				{
					cout << "Invalid operator & @ char " << i << endl;
					throw exception("Error Occurred");
				}
				else
				{
					temp += input[i];
				} // end if
			} 
			else if(input[i] == '<')
			{
				temp += input[i];

				if(input[i + 1] == '=')
				{
					i++;
					temp += input[i];	
				} // end if
			}
			else if(input[i] == '>')
			{
				temp += input[i];

				if(input[i + 1] == '=')
				{
					i++;
					temp += input[i];
				} // end if
			} 
			else if(input[i] == '+')
			{
				temp += input[i];

				if(input[i + 1] == '+')
				{
					i++;
					temp += input[i];
				} // end if
			}
			else if(input[i] == '-')
			{
				if(input[i + 1] == '-')
				{
					temp += input[i];
					i++;
					temp += input[i];
				}
				else if(i == 0)
				{
					temp += '.';
				}
				else if(i >= 1 && !lastNum)
				{
					temp += '.';
				}
				else
				{
					temp += input[i];
				} // end if
			}
			else if(input[i] == '*' || input[i] == '/' || input[i] == '%' || input[i] == '^')
			{
				temp += input[i];
			}
			else if(input[i] == '(' || input[i] == '[' || input[i] == '{' || input[i] == ')' || input[i] == ']' || input[i] == '}')
			{
				temp += input[i];
			}
			else if(isdigit(input[i]))
			{
				temp += input[i];

				while(isdigit(input[i + 1]))
				{
					i++;
					temp += input[i];
				} // end loop
				
				operands.push(convertNumbers(temp));
				lastNum = true;
				temp = "";
			}
			else if(input[i] == ' ')
			{
				if(isdigit(input[i-1]) && isdigit(input[i+1]))
				{
					cout << "Two operands in a row @ char " << i << endl;
					throw exception("Error Occurred");
				} // end if

				if((input[i-1] == '|' || input[i-1] == '&') && (input[i+1] == '|' || input[i+1] == '&'))
				{
					cout << "Two operators in a row @ char " << i << endl;
					throw exception("Error Occurred");
				} // end if
			}
			else
			{
				cout << "Invalid character input @ char " << i << endl;
				throw exception("Error Occurred");
			}// end if

			if(temp == ")" || temp == "]" || temp == "}")
			{
				while(operators.size() > 0 && ((operators.top() != "(") && (operators.top() != "[") && (operators.top() != "{")))
				{
					operands.push(evaluateOperators(operators.top()));
					operators.pop();
				} // end loop

				lastNum = false;
				operators.pop();

				temp = "";
			} // end if

			if(temp != "")
			{
				if(operators.size() > 0 && (precedence(operators.top()) >= precedence(temp))  && (precedence(temp) > 0))
				{
					while(operators.size() > 0 && (precedence(operators.top()) >= precedence(temp)))
					{
						operands.push(evaluateOperators(operators.top()));
						operators.pop();
					} // end loop
				} // end if
				
				operators.push(temp);
				lastNum = false;
				temp = "";
			} // end if

			i++;
		} // end loop

		while(!operators.empty())
		{
			operands.push(evaluateOperators(operators.top()));
			operators.pop();
		} // end loop

		if(!operands.empty())
		{
			result = operands.top();
			operands.pop();
		}
		else
		{
			throw exception("Operand stack is empty");
		}// end if 

		if(!operands.empty())
		{
			throw exception("Operand stack should be empty");
		} // end if

		return result;
	} // end evaluate

	string InfixEvaluator::removeWhiteSpace(string input)
	{
		string temp = "";
		input = input.erase(0, input.find_first_not_of(" "));
		input = input.erase(input.find_last_not_of(" ") + 1);

		size_t i = 0;
		bool spaceFound = false;

		while(i < input.length())
		{
			if(input[i] == ' ')
			{
				if(!spaceFound)
				{
					temp += input[i];
					spaceFound = true;
				} // end if
			}
			else
			{
				spaceFound = false;
				temp += input[i];
			} // end if

			i++;
		} // end loop
	
		return temp;
	} // end removeWhiteSpace

	int InfixEvaluator::precedence(string input)
	{
		int i = 0;

		for(i; i < 24; i++)
		{
			if(input == OPERATORS[i])
			{
				break;
			} // end if
		} // end loop

		return PRECEDENCE[i];
	} // end precedence

	/*bool isOperator(char input)
	{
		return false;
	} // end isOperator*/

	int InfixEvaluator::evaluateOperators(string& operatorInput)
	{
		int result = 0;
		int i = 0;

		for(i; i < 18; i++)
		{
			if(operatorInput == OPERATORS[i])
			{
				break;
			} // end if
		} // end loop

		if (operands.empty()) 
		{
			throw exception("Stack is empty");
		} // end if

		int temp1, temp2;

		temp1 = operands.top();
		operands.pop();

		switch(i)
		{
			case 0:
			{
				if (operands.empty()) 
				{
					throw exception("Stack is empty");
				} // end if

				temp2 = operands.top();
				operands.pop();

				return temp1 || temp2;
				break;
			}
			case 1:
			{
				if (operands.empty()) 
				{
					throw exception("Stack is empty");
				} // end if

				temp2 = operands.top();
				operands.pop();

				return temp1 && temp2;
				break;
			}
			case 2:
			{
				if (operands.empty()) 
				{
					throw exception("Stack is empty");
				} // end if

				temp2 = operands.top();
				operands.pop();

				return temp1 == temp2;
				break;
			}
			case 3:
			{
				if (operands.empty()) 
				{
					throw exception("Stack is empty");
				} // end if

				temp2 = operands.top();
				operands.pop();

				return temp1 != temp2;
				break;
			}
			case 4:
			{
				if (operands.empty()) 
				{
					throw exception("Stack is empty");
				} // end if

				temp2 = operands.top();
				operands.pop();

				return temp1 < temp2;
				break;
			}
			case 5:
			{
				if (operands.empty()) 
				{
					throw exception("Stack is empty");
				} // end if

				temp2 = operands.top();
				operands.pop();

				return temp1 <= temp2;
				break;
			}
			case 6:
			{
				if (operands.empty()) 
				{
					throw exception("Stack is empty");
				} // end if

				temp2 = operands.top();
				operands.pop();

				return temp1 > temp2;
				break;
			}
			case 7:
			{
				if (operands.empty()) 
				{
					throw exception("Stack is empty");
				} // end if

				temp2 = operands.top();
				operands.pop();

				return temp1 >= temp2;
				break;
			}
			case 8:
			{
				if (operands.empty()) 
				{
					throw exception("Stack is empty");
				} // end if

				temp2 = operands.top();
				operands.pop();

				return temp1 + temp2;
				break;
			}
			case 9:
			{
				if (operands.empty()) 
				{
					throw exception("Stack is empty");
				} // end if

				temp2 = operands.top();
				operands.pop();

				return temp2 - temp1;
				break;
			}
			case 10:
			{
				if (operands.empty()) 
				{
					throw exception("Stack is empty");
				} // end if

				temp2 = operands.top();
				operands.pop();

				return temp1 * temp2;
				break;
			}
			case 11:
			{
				if (operands.empty()) 
				{
					throw exception("Stack is empty");
				} // end if

				temp2 = operands.top();
				operands.pop();

				if(temp1 == 0)
				{
					throw exception("Divide by zero error attempted");
				} // end if

				return temp2 / temp1;
				break;
			}
			case 12:
			{
				if (operands.empty()) 
				{
					throw exception("Stack is empty");
				} // end if

				temp2 = operands.top();
				operands.pop();

				return temp2 % temp1;
				break;
			}
			case 13:
			{
				if (operands.empty()) 
				{
					throw exception("Stack is empty");
				} // end if

				temp2 = operands.top();
				operands.pop();

				int tempRes = temp2;

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
					for(int i = 1; i < temp1; i++)
					{
						tempRes *= temp2;
					} // end loop
				} // end if

				return tempRes;
				break;
			}
			case 14:
			{
				return 0 - temp1;
				break;
			}
			case 15:
			{
				return --temp1;
				break;
			}
			case 16:
			{
				return ++temp1;
				break;
			}
			case 17:
			{
				return !temp1;
				break;
			}
		} // end switch
	} // end evaluateOperators

	int InfixEvaluator::convertNumbers(string& input)
	{
		return stoi(input, nullptr, 10);
	} // end convertNumbers
}; // end class InfixEvaluator

#endif