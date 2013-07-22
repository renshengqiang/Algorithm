/*************************************************************************
	> File Name: algo.c
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年07月20日 星期六 10时24分16秒
 ************************************************************************/
#include "algo.h"
#include <stdio.h>
#include <stdlib.h>

//Name: _StrEqual, functional function
//Desc: compare two string, and return value indicate if they are equal till length
int _StrEqual(const char* str1, const char * str2, int length)
{
	if(NULL == str1 || NULL == str2 || length <0)
	{
		fprintf(stderr, "_StrEqual: not valid parameter\n");
		return FALSE;
	}
	for(int i=0; i<length; ++i)
		if(str1[i] != str2[i]) return FALSE;
	return TRUE;
}

//Desc: string matcher function using naive algo, compleity(O(m*n))
void NaiveStringMatcher(const char *text, const char *pattern, int textLength, int patternLength)
{
	if(NULL == text || NULL == pattern || textLength <=0 || patternLength <= 0) return;

	for(int i=0; i <= (textLength - patternLength); ++i)
		if(_StrEqual(text + i, pattern, patternLength) == TRUE)
			printf("Matching at %d %s\n", i, text + i);
	return;
}

//Desc: string matcher function using Robin-Karp algo
//d: jinzhi, q: the mod
void RobinKarpMatcher(const char *text, const char *pattern, int textLength, int patternLength, int d, int q)
{
	if(NULL == text || NULL == pattern || textLength <= 0 || patternLength <= 0) return;

	int p=0, t=0, h=1;
	//pre-process
	for(int i=0; i<patternLength; ++i)
	{
		p = (d*p + pattern[i])%q;
		t = (d*t + text[i])%q;
		if(i!=patternLength-1)
			h = (d*h)%q;
	}

	//matching
	for(int i=0; i<= (textLength - patternLength); ++i)
	{
		if(p == t && _StrEqual(text+i, pattern, patternLength)==TRUE)
			printf("Matching at %d %s\n", i, text+i);
		if(i < textLength-patternLength)
		{
			t = (d *(t - text[i]*h) + text[i+patternLength])%q;
			t = (t + q)%q;
		}
	}
	return;
}

//Desc: cacl the prefix array of pattern, the number in prefix indicates that there are n char matching from begining to end
void _ComputePrefix(const char *pattern, int *prefix, int patternLength)
{
	prefix[0] = 0;
	int k = 0;

	for(int i = 1; i < patternLength; ++i)
	{
		while(k>0 && pattern[k] != pattern[i])
			k = prefix[k-1];
		if(pattern[k] == pattern[i]) ++k;
		prefix[i] = k;
	}
}

//Desc:string matching function using Knuth-Morris-Pratt algo
void KMPMatcher(const char *text, const char *pattern, int textLength, int patternLength)
{
	if(text == NULL || pattern == NULL || textLength <= 0 || patternLength <= 0) return;

	//pre-process
	int *prefix = (int *)malloc(patternLength * sizeof(int));
	_ComputePrefix(pattern, prefix, patternLength);

	int j = 0;
	//matching
	for(int i=0; i < textLength; ++i)
	{
		while(j>0 && pattern[j] != text[i])
			j = prefix[j - 1];//number equal to next index
		if(pattern[j] == text[i])
		{
			if(j == patternLength - 1)
			{
				printf("Matching At %d %s\n", i - patternLength + 1, text+i-patternLength+1);
				j = prefix[j];
			}
			else
				++j;
		}
	}
	return;
}
