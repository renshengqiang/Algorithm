/*************************************************************************
	> File Name: calc.c
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年06月22日 星期六 19时05分41秒
 ************************************************************************/
#include <string.h>
#include <iostream>
using namespace std;

/*
 * the number string is must a positive num begin with num char
 * input: the num to dianose
 * output: true for legal, false for illegal
 */
bool _IsLegalNum(const char *num)
{
	for(const char *p = num; *p!=0; ++p)
	{
		if(*p<'0' || *p>'9') return false;
	}
	return true;
}
/*
 * calc the plus of num string lhs and rhs
 * input: the number string to be added
 * output: the llegal string of the result
 */
char *Plus(const char *lhs, const char *rhs)
{
	/*legal num?*/
	if(!_IsLegalNum(lhs) || !_IsLegalNum(rhs))
	{
		cerr << "Plus Error: illegal number input "<< endl;
		return NULL;
	}

	/*alloc memory*/
	int lLength = strlen(lhs);
	int rLength = strlen(rhs);
	int resultLength = lLength > rLength ? lLength + 2 : rLength + 2;
	char *result;

	result = new char[resultLength];
	if(result == NULL)
	{
		cerr << "Plus Error: memory error" << endl;
		return NULL;
	}
	memset(result, 0, resultLength);

	/*calc*/
	int carry = 0;
	int i = lLength - 1, j = rLength - 1, k = resultLength - 2;
	for(;i>=0 || j>=0;--i,--j,--k)
	{
		int l = 0, r = 0;
		if(i>=0) l = lhs[i] - '0';
		if(j>=0) r = rhs[j] - '0';
		l += (r + carry);
		result[k] = '0' + l%10;//ascii 48
		carry = l /10;
	}
	if(carry) result[0]='0' + carry;

	/*make the result string legal*/
	if(result[0]==0)
	{
		memmove(result, result + 1, resultLength - 1);
		result[resultLength - 1] = 0;
	}
	return result;
}

char *Substraction(const char *lhs, const char *rhs)
{
	/*legal num?*/
	if(!_IsLegalNum(lhs) || !_IsLegalNum(rhs))
	{
		cerr << "Substraction Error: illegal number input" << endl;
		return NULL;
	}

	/*make sure lhs > rhs*/
	bool negFlag = false;
	if(strcmp(lhs, rhs) < 0)
	{
		const char *temp = rhs;
		rhs = lhs;
		lhs = temp;
		negFlag = true;
	}

	/*alloc memory*/
	int lLength = strlen(lhs);
	int rLength = strlen(rhs);
	int resultLength = lLength > rLength ? lLength + 2 : rLength + 2;
	char *result;

	result = new char[resultLength];
	if(result == NULL)
	{
		cerr << "Plus Error: memory error" << endl;
		return NULL;
	}
	memset(result, 0, resultLength);

	/*calc*/
	int carry = 0;
	int i = lLength - 1, j = rLength -1, k = resultLength - 2;
	for(;i>=0; --i, --j, --k)
	{
		int l = 0, r = 0;
		l = lhs[i] - '0';
		if(j>=0) r = rhs[j] - '0';
		l -= (r + carry);
		if(l < 0)
		{
			l+=10;
			carry = 1;
		}
		else
			carry = 0;
		result[k] = '0' + l;
	}

	/*make the result string legal, may start with a negative flag*/
	int zeroLength = 0 ;
	for(i=0; i<resultLength; ++i)
	{
		if(result[i] == 0 || result[i]=='0')
		{
			result[i] = '-';
			++zeroLength;
		}
		else
			break;
	}
	if(negFlag) --zeroLength;
	if(zeroLength > 0)
	{
		memmove(result, result + zeroLength, resultLength - zeroLength);
		result[resultLength - zeroLength] = 0;
	}
	return result;
}
