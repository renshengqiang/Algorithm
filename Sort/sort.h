#ifndef _SORT_H_
#define _SORT_H_

template <typename T>
void QuickSortRecursive(T *l, int low, int high);
template <typename T>
void QuickSort(T *l, int low, int high);
template <typename T>
void TwoWayMergeSortRecursive(T *l, int low, int high);
template <typename T>
void TwoWayMergeSort(T *l, int low, int high);

#include "QuickSort.cpp"
#include "MergeSort.cpp"
#endif