#include "sort.h"
#include <stack>

template <typename T>
int QuickSortOnce(T *l, int low, int high)
{
	T temp = l[low];
	while(low<high){
		while(low<high && l[high] >= temp) --high;
		l[low]=l[high];
		while(low<high && l[low] <= temp)++low;
		l[high]=l[low];
	}
	l[low] = temp;
	return low;
}
template <typename T>
void QuickSortRecursive(T *l, int low , int high)
{
	int mid;
	if(low<high){
		mid = QuickSortOnce(l, low, high);
		QuickSort(l, low, mid - 1);
		QuickSort(l, mid+1, high);
	}
}
struct QuickSortStackItem{
	int low, high;
	QuickSortStackItem(int low,int high){ this->low = low; this->high = high;}
};
template <typename T>
void QuickSort(T *l, int low, int high)
{
	QuickSortStackItem item(low, high);
	std::stack<QuickSortStackItem> stack;
	int mid;
	
	stack.push(item);
	while(!stack.empty()){
		item = stack.top();
		stack.pop();
		if(item.low < item.high){
			mid = QuickSortOnce<T>(l, item.low, item.high);
			stack.push(QuickSortStackItem(item.low, mid -1));
			stack.push(QuickSortStackItem(mid+1, item.high));
		}
	}
}