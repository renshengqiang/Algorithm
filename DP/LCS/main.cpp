/*************************************************************************
	> File Name: main.cpp
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年06月11日 星期二 19时35分08秒
 ************************************************************************/

#include "LCS.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char *one = "21232523311324";
	char *two = "312123223445";
	char *out;
	int length;

	length = LCS<char>(one, two, strlen(one), strlen(two), &out);
	cout << "str1: " << one << endl;
	cout << "str2: " << two << endl;
	cout << "common length: " << length << endl;
	cout << "common str: " << out << endl;

	delete[] out;
	return 0;
}
