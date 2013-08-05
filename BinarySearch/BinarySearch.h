#ifndef _BINARY_SEARCH_H
#define _BINARY_SEARCH_H

#define NULL (void *)0
template <typename T>
int BinarySearchNormal(const T *array, int b, int e, T element);

template <typename T>
int BinarySearchMin(const T *array, int b, int e, T element);

template <typename T>
int BinarySearchMax(const T *array, int b, int e, T element);

template <typename T>
int BinarySearchMaxLess(const T *array, int b, int e, T element);

template <typename T>
int BinarySearchMinMore(const T *array, int b, int e, T element);
#include "BinarySearch.cpp"
#endif
