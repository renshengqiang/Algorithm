#include "sort.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string strVec[]={"File", "Edit", "View", "Project", "Build", "Debug", "Team", "SQL", "Tool"};
	int intVec[]={45, 23, 98, 28, 198, 67, 128,187, 1};
	QuickSort<string>(strVec, 0, 8);
//	TwoWayMergeSort<int>(intVec, 0, sizeof(intVec)/sizeof(int)-1);
    HeapSort<int>(intVec, sizeof(intVec)/sizeof(int));
	
	for(int i=0; i<9; ++i)
		cout << strVec[i] << " ";
	cout << endl;
	
	for(int i=0;i<sizeof(intVec)/sizeof(int); ++i){
		cout << intVec[i] << " ";
	}
	cout << endl;
#ifdef WIN32
	getchar();
	getchar();
#endif
	return 0;
}
