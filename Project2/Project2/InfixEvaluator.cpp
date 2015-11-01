// Created by Cameron L'Ecuyer
// Last Modified: 10/31/2015

#include "InfixEvaluator.h"
using namespace::std;

const string InfixEvaluator::OPERATORS[] = 
	{"||", "&&", "==", "!=", ">", ">=", "<", "<=", "+", "-", "*", "/", "%", "^", ".", "--", "++", "!", "(", ")", "[", "]", "{", "}"};
const int InfixEvaluator::PRECEDENCE[] = {1, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 7, 8, 8, 8, 8, -1, -1, -1, -1, -1, -1};

int InfixEvaluator::evaluate(string input)
{
	if(input[0] == ')' || input[0] == '}' || input[0] == ']')
	{
		cout << "Expression cannot start with closing parenthesis @ char 0";
		throw exception();
	}
	else if(input[0] == '<' || input[0] == '>' || input[0] == '=')
	{
		cout << "Expression cannot start with binary operator @ char 0";
		throw exception();
	}

	int result = 0;
	string temp = "";
	bool updated = false;
	int i = 0;

	while(i < input.length())
	{
		updated = false;

		if(input[i] == '=')
		{
			temp += input[i];
			i++;

			if(input[i] != '=')
			{
				cout << "Invalid operator = @ char " << i << endl;
				throw exception();
			}
			else
			{
				temp += input[i];
				operators.push(temp);
				updated = true;
				temp = "";
			} // end if
		} // end if

		if(input[i] == '!')
		{
			temp += input[i];
			i++;

			if(input[i] == '=')
			{
				temp += input[i];
			} // end if

			operators.push(temp);
			updated = true;
			temp = "";
		} // end if

		if(input[i] == '|')
		{
			temp += input[i];
			i++;

			if(input[i] != '|')
			{
				cout << "Invalid operator | @ char " << i << endl;
				throw exception();
			}
			else
			{
				temp += input[i];
				operators.push(temp);
				updated = true;
				temp = "";
			} // end if
		} // end if

		if(input[i] == '&')
		{
			temp += input[i];
			i++;

			if(input[i] != '&')
			{
				cout << "Invalid operator & @ char " << i << endl;
				throw exception();
			}
			else
			{
				temp += input[i];
				operators.push(temp);
				updated = true;
				temp = "";
			} // end if
		} // end if

		if(input[i] == '<')
		{
			temp += input[i];
			i++;

			if(input[i] == '=')
			{
				temp += input[i];
			} // end if

			operators.push(temp);
			updated = true;
			temp = "";
		} // end if

		if(input[i] == '>')
		{
			temp += input[i];
			i++;

			if(input[i] == '=')
			{
				temp += input[i];
			} // end if

			operators.push(temp);
			updated = true;
			temp = "";
		} // end if

		if(input[i] == '+')
		{
			temp += input[i];
			i++;

			if(input[i] == '+')
			{
				temp += input[i];
			} // end if

			operators.push(temp);
			updated = true;
			temp = "";
		} // end if

		if(input[i] == '-')
		{
			if(!isdigit(input[i-1]) || !isdigit(input[i-2]))
			{
				temp += '.';
			}
			else
			{
				temp += input[i];
			}// end if

			i++;

			if(input[i] == '-')
			{
				temp += input[i];
			} // end if

			operators.push(temp);
			updated = true;
			temp = "";
		} // end if

		if(input[i] == '*' || input[i] == '/' || input[i] == '%' || input[i] == '^')
		{
			temp += input[i];
			i++;
			operators.push(temp);
			updated = true;
			temp = "";
		} // end if

		if(input[i] == '(' || input[i] == ')' || input[i] == '[' || input[i] == ']' || input[i] == '{' || input[i] == '}')
		{
			temp += input[i];
			i++;
			operators.push(temp);
			updated = true;
			temp = "";
		} // end if

		if(isdigit(input[i]))
		{
			while(isdigit(input[i]))
			{
				temp += input[i];
				i++;
			} // end loop
				
			operands.push(convertNumbers(temp));
			updated = true;
			temp = "";
		} // end if

		if(!updated)
		{
			if(isalpha(input[i]))
			{
				cout << "Letters are invalid input @ char " << i << endl;
				throw exception();
			} // end if

			if(isdigit(input[i-1]) && isdigit(input[i+1]))
			{
				cout << "Two operands in a row @ char " << i << endl;
				throw exception();
			} // end if

			if((input[i-1] == '|' || input[i-1] == '&') && (input[i+1] == '|' || input[i+1] == '&'))
			{
				cout << "Two operators in a row @ char " << i << endl;
				throw exception();
			} // end if

			i++;
		} // end if
	} // end loop

	return result;
} // end evaluate

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

	int temp1, temp2;

	switch(i)
	{
		case 0:
		{
			temp1 = operands.top();
			operands.pop();
			temp2 = operands.top();
			operands.pop();

			return temp1 || temp2;
			break;
		}
		case 1:
		{
			temp1 = operands.top();
			operands.pop();
			temp2 = operands.top();
			operands.pop();

			return temp1 && temp2;
			break;
		}
		case 2:
		{
			temp1 = operands.top();
			operands.pop();
			temp2 = operands.top();
			operands.pop();

			return temp1 == temp2;
			break;
		}
		case 3:
		{
			temp1 = operands.top();
			operands.pop();
			temp2 = operands.top();
			operands.pop();

			return temp1 != temp2;
			break;
		}
		case 4:
		{
			temp1 = operands.top();
			operands.pop();
			temp2 = operands.top();
			operands.pop();

			return temp1 < temp2;
			break;
		}
		case 5:
		{
			temp1 = operands.top();
			operands.pop();
			temp2 = operands.top();
			operands.pop();

			return temp1 <= temp2;
			break;
		}
		case 6:
		{
			temp1 = operands.top();
			operands.pop();
			temp2 = operands.top();
			operands.pop();

			return temp1 > temp2;
			break;
		}
		case 7:
		{
			temp1 = operands.top();
			operands.pop();
			temp2 = operands.top();
			operands.pop();

			return temp1 >= temp2;
			break;
		}
		case 8:
		{
			temp1 = operands.top();
			operands.pop();
			temp2 = operands.top();
			operands.pop();

			return temp1 + temp2;
			break;
		}
		case 9:
		{
			temp1 = operands.top();
			operands.pop();
			temp2 = operands.top();
			operands.pop();

			return temp1 - temp2;
			break;
		}
		case 10:
		{
			temp1 = operands.top();
			operands.pop();
			temp2 = operands.top();
			operands.pop();

			return temp1 * temp2;
			break;
		}
		case 11:
		{
			temp1 = operands.top();
			operands.pop();
			temp2 = operands.top();
			operands.pop();

			return temp2 / temp1;
			break;
		}
		case 12:
		{
			temp1 = operands.top();
			operands.pop();
			temp2 = operands.top();
			operands.pop();

			return temp2 % temp1;
			break;
		}
		case 13:
		{
			temp1 = operands.top();
			operands.pop();
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
			temp1 = operands.top();
			operands.pop();

			return 0 - temp1;
			break;
		}
		case 15:
		{
			temp1 = operands.top();
			operands.pop();

			return --temp1;
			break;
		}
		case 16:
		{
			temp1 = operands.top();
			operands.pop();

			return ++temp1;
			break;
		}
		case 17:
		{
			temp1 = operands.top();
			operands.pop();

			return !temp1;
			break;
		}
	} // end switch
} // end evaluateOperators

int InfixEvaluator::convertNumbers(string& input)
{
	return stoi(input, nullptr, 10);
} // end convertNumbers