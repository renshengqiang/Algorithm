/*************************************************************************
	> File Name: main.cpp
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年06月11日 星期二 19时35分08秒
 ************************************************************************/

#include "LCS.h"
#include "LCS_Cont.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	const char *one = "21232523311324";
	const char *two = "312123223445";
	char *out;
	int length;

	cout << "str1: " << one << endl;
	cout << "str2: " << two << endl;
	
	length = LCS<char>(one, two, strlen(one), strlen(two), &out);
	cout << "common length: " << length << endl;
	cout << "common str: ";
	for(int i=0; i<length; ++i)
		cout << out[i];
	cout << endl;
	delete[] out;

	length = LCS_Cont<char>(one, two, strlen(one), strlen(two), &out);
	cout << "common length: " << length << endl;
	cout << "common str: ";
	for(int i=0; i<length; ++i)
		cout << out[i];
	cout << endl;
	delete[] out;
	return 0;
}
