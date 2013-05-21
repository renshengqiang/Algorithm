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
    
    //test copy and = operator
    //ok
    Vector<int> vector2;
    vector2.push_back(1);
    vector.clear();
    vector2 = vector;
    
    //test insert
    //ok
    for(int i=0; i<10; ++i)
    {
        vector2.push_front(i);
    }
    Vector<int>::iterator iter = vector2.begin();
    for(int i=0; i<10; ++i)
    {
        iter = vector2.insert(iter, i);
    }
    iter+=12;
    vector2.insert(iter, 100);
    
    //test pop
    //ok
    vector2.pop_back();
    vector2.pop_front();
    iter = vector2.begin() + 2;
    vector2.erase(iter);
    //vector2.clear();

    //test get
    //ok
    cout << "back: " << vector2.back() << endl;
    cout << "front: " << vector2.front() << endl;
    cout << "at(3): " << vector2.at(3) << endl;
    cout << "[3]: " << vector2[3] << endl;
    vector2[3]+=10;

    //test size operate
    //ok
    cout << "Size: " << vector2.size() << endl;
    cout << "Maxsize: " << vector2.max_size() << endl;
    cout << "Vector is empty(true/false):" << vector2.empty() << endl;
    vector2.resize(100);
    cout << "resize Maxsize: " << vector2.max_size() << endl;
    
    //test swap
    //ok
    swap(vector, vector2);
    swap(vector, vector2);
    
	for(Vector<int>::iterator iter = vector2.begin(); iter != vector2.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}
