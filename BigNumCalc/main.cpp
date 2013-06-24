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
	cout << "1234567899 * 1900000001 = ";
	char *res = Multiply("1234567899", "1900000001");
	cout << res << endl;
	delete[] res;

	int remainder;
	cout << "1234567899 / 3456 = ";
	res = Devide("1234567899", "3456", &remainder);
	cout << res << "------" << remainder << endl;
	delete[] res;

    cout << "1234567899: ";
    res = Decimal2N("1234567899", 8);
    cout << res << endl;
    delete[] res;
	return 0;
}
