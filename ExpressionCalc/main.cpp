/*************************************************************************
	> File Name: main.cpp
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年07月20日 星期六 23时56分52秒
 ************************************************************************/

#include <string>
#include <stack>
#include <map>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int _Calc(char op, int n1, int n2)
{
	switch(op)
	{
		case '+': return n1+n2;
		case '-': return n1-n2;
		case '*': return n1*n2;
		case '/': return n1/n2;
	}
	return -1;
}
//Desc: calc the value of a string expression
//return the result of the expression
int Calc(const char*strExpression, int length)
{
		if(strExpression == NULL || length <= 0)
		{
			fprintf(stderr, "invalid parameters\n");
			return -1;
		}
		//create a priority map to facilate query about operator's priotity
		std::map<char, int> priorityMap;
		priorityMap.insert(make_pair('=', 1));
		priorityMap.insert(make_pair(')', 2));
		priorityMap.insert(make_pair('+', 3));
		priorityMap.insert(make_pair('-', 3));
		priorityMap.insert(make_pair('*', 4));
		priorityMap.insert(make_pair('/', 4));
		priorityMap.insert(make_pair('(', 5));

		//create two stack to store operator and number
		std::stack<char> operatorStack;
		std::stack<int> numberStack;

		operatorStack.push('=');
		for(int n=0; n < length; ++n )
		{
			char ch = strExpression[n];
			if(isdigit(ch))
			{
				numberStack.push(ch - '0');
			}
			else
			{
				if(operatorStack.empty())
				{
					fprintf(stderr, "expression error\n");
					return -1;
				}
				char topOparator = operatorStack.top();
				if(priorityMap[ch] > priorityMap[topOparator])
					operatorStack.push(ch);
				else
				{
					if(ch == ')' && topOparator == '(') operatorStack.pop();
					else if(topOparator == '(') operatorStack.push(ch);
					else if(ch == '=' && topOparator == '=') operatorStack.pop();
					else
					{
						if(numberStack.size() < 2)
						{
							fprintf(stderr, "expression error\n");
							return -1;
						}
						int n2 = numberStack.top();
						numberStack.pop();
						int n1 = numberStack.top();
						numberStack.pop();

						numberStack.push(_Calc(topOparator, n1, n2));
						operatorStack.pop();
						--n;/*don't move on*/
					}
				}
			}
		}
		return numberStack.top();
}
int main()
{
	char expression[1024];

	printf("input the expression:\n");
	scanf("%s", expression);
	
	printf("result: %d\n", Calc(expression, strlen(expression)));
	return 0;
}
