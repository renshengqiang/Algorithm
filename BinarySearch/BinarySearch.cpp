#include "BinarySearch.h"

template <typename T>
int BinarySearchNormal(const T *array, int b, int e, T element)
{
    if(array == NULL || b < 0) return -1;

    while(b <= e)
    {
        int mid = b + (e - b)/2;
        if(array[mid] == element) return mid;
        else if(array[mid] < element) b = mid + 1;
        else if(array[mid] > element) e = mid - 1;
    }
    return -1;
}

template <typename T>
int BinarySearchMin(const T *array, int b, int e, T element)
{
    if(array == NULL || b < 0) return -1;

    while(b < e-1)
    {
        int mid = b + (e-b)/2;

        if(array[mid] >= element) e = mid;
        else b = mid + 1;
    }
    if(array[b] == element) return b;
    else if(array[e] == element) return e;
    else return -1;
}

template <typename T>
int BinarySearchMax(const T *array, int b, int e, T element)
{
    if(array == NULL || b < 0) return -1;

    while(b < e-1)
    {
        int mid = b + (e-b)/2;

        if(array[mid] <= element) b = mid;
        else e = mid - 1;
    }
    if(array[e] == element) return e;
    else if(array[b] == element) return b;
    else return -1;
}

template <typename T>
int BinarySearchMaxLess(const T *array, int b, int e, T element)
{
    if(array == NULL || b < 0) return -1;

    int low = b, high = e, mid;
    while(low <= high)
    {
        mid = low + (high - low)/2;

        if(array[mid] >= element) high = mid -1;
        else low = mid + 1;
    }
    if(high == b - 1) return -1;
    else return high;
}

template <typename T>
int BinarySearchMinMore(const T *array, int b, int e, T element)
{
    if(array == NULL || b < 0) return -1;
    
    int low = b, high = e, mid;
    while(low <= high)
    {
        mid = low + (high - low)/2;
        if(array[mid] <= element) low = mid + 1;
        else high = mid -1;
    }
    if(low == e + 1) return -1;
    else return low;
}
