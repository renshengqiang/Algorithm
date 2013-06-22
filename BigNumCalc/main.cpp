/*************************************************************************
	> File Name: main.cpp
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年06月22日 星期六 19时39分26秒
 ************************************************************************/
#include "calc.h"
#include <iostream>
using namespace std;

int main()
{
	char *res = Plus("1234567899", "1900000001");

	cout << res << endl;
	
	delete[] res;
	return 0;
}
