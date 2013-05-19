/*************************************************************************
	> File Name: main.cpp
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年05月19日 星期日 19时23分17秒
 ************************************************************************/
#include "Vector.h"
#include<iostream>
using namespace std;
using namespace QTL;
int main()
{
	Vector<int> vector;

	for(int i=0; i<10; ++i)
		vector.push_back(i);

	for(Vector<int>::iterator iter = vector.begin(); iter != vector.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}
