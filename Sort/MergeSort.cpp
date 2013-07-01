#include "sort.h"
#include <stack>
#define NULL (void *)0
/*
 * 其实归并排序的空间复杂度是O(n),而我这里是O(nlgn),并且有频繁的new和delete
 * O(n)的时间复杂度的实现是将中间工作都放在一个全局的数组中进行的
 * 修改的话，需要对函数的形式进行一定的修改
 */
template <typename T>
void _Merge(T *l, int low, int mid, int high)
{
	T *temp;
	int i,j,k;

	temp = new T[high+1];
	if(temp==NULL) return;
	for(i=k=low,j=mid+1; i<=mid && j<=high; ++k){
		if(l[i]<l[j]) temp[k]=l[i++];
		else temp[k]=l[j++];
	}
	while(i<=mid) temp[k++]=l[i++];
	while(j<=high) temp[k++]=l[j++];
	for(i=low;i<=high;++i) l[i]=temp[i];
	delete []temp;
}
template <typename T>
void TwoWayMergeSortRecursive(T *l, int low, int high)
{
	int mid;
	if(low<high){
		mid = (low+high)/2;
		TwoWayMergeSortRecursive(l, low, mid);
		TwoWayMergeSortRecursive(l, mid+1, high);
		_Merge<T>(l, low, mid, high);
	}
}
struct MergeSortStackItem{
	int low,high,flag;
	MergeSortStackItem(int low ,int high, int flag){this->low = low; this->high=high; this->flag=flag;}
};
template <typename T>
void TwoWayMergeSort(T *l, int low, int high)
{
	MergeSortStackItem item(low, high, 1);
	std::stack<MergeSortStackItem> stack;
	while(item.low<item.high){
		stack.push(item);
		item.high = (item.low+item.high)/2;
	}
	while(!stack.empty()){
		item = stack.top();
		stack.pop();
		if(item.flag==1){
			stack.push(MergeSortStackItem(item.low, item.high, 0));
			item.low = (item.low+item.high)/2+1;
			item.flag=1;
			while(item.low<item.high){
				stack.push(item);
				item.low = (item.low+item.high)/2+1;
			}
		}else{
			_Merge<T>(l, item.low, (item.low+item.high)/2, item.high);
		}
	}
}
