/*************************************************************************
	> File Name: calc.c
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年06月22日 星期六 19时05分41秒
 ************************************************************************/
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*
 * the number string is must a positive num begin with num char
 * input: the num to dianose
 * output: true for legal, false for ilegal
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
 * output: the legal string of the result
 */
char *Plus(const char *lhs, const char *rhs)
{
	/*legal num?*/
	if(!_IsLegalNum(lhs) || !_IsLegalNum(rhs))
	{
		cerr << "Plus Error: ilegal number input "<< endl;
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

/*
 * calc the substraction of num string lhs and rhs
 * input: the number string to be substracted
 * output: the legal string of the result
 */
char *Substraction(const char *lhs, const char *rhs)
{
	/*legal num?*/
	if(!_IsLegalNum(lhs) || !_IsLegalNum(rhs))
	{
		cerr << "Substraction Error: ilegal number input" << endl;
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
/*
 * calc the multiplycation of num string lhs and rhs
 * input: the number string to be added
 * output: the legal string of the result
 */
char *Multiply(const char *lhs, const char *rhs)
{
	/*legal num?*/
	if(!_IsLegalNum(lhs) || !_IsLegalNum(rhs))
	{
		cerr << "Substraction Error: ilegal number input" << endl;
		return NULL;
	}

	/*calc the temp result using plus*/
	const char *zero = "0";
	const char *tempTen[10];
	tempTen[0] = zero;
	tempTen[1] = lhs;
	for(int i=2; i<10; ++i)
	{
		tempTen[i] = Plus(tempTen[i-1], tempTen[1]);
	}

	/*calc*/
	char *result, *resultTemp;
	result = new char[2];
	result[0]='0'; result[1]=0;
	int rLength = strlen(rhs);
	for(int i = rLength - 1; i >=0; --i)
	{
		int r = rhs[i] - '0';
		char *temp = new char[strlen(tempTen[r]) + rLength - i];
		memcpy(temp, tempTen[r], strlen(tempTen[r]));
		for(int j=strlen(tempTen[r]); j < strlen(tempTen[r]) + rLength - i; ++j)
		{
			temp[j] = '0';
		}
		temp[strlen(tempTen[r]) + rLength -i - 1] = 0;
		resultTemp = result;
		result = Plus(result, temp);
		delete[] resultTemp;
		delete[] temp;
	}
	return result;
}
char *Devide(const char *lhs, const char *rhs, int *remainder)
{
	/*legal num?*/
	if(!_IsLegalNum(lhs) || !_IsLegalNum(rhs))
	{
		cerr << "Substraction Error: ilegal number input" << endl;
		return NULL;
	}

	/*calc*/
	int lLength = strlen(lhs);
	int r = atoi(rhs);
	int temp = 0;
	char *result = new char[lLength + 1];
	int j = 0;
	for(int i=0; i<lLength; ++i,++j)
	{
		temp = temp * 10 + lhs[i] - '0';
		result[j] = temp/r + '0';
		temp = temp%r;
	}
	result[lLength] = 0;
	if(remainder) *remainder = temp;

	/*make the result string legal, may start with a negative flag*/
	int zeroLength = 0 ;
	for(int i=0; i<lLength; ++i)
	{
		if(result[i]=='0')
		{
			++zeroLength;
		}
		else
			break;
	}
	if(zeroLength > 0)
	{
		memmove(result, result + zeroLength, lLength - zeroLength);
		result[lLength - zeroLength] = 0;
	}
	return result;
}
