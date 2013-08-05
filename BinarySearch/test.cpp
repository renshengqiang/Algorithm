#include "BinarySearch.h"
#include <assert.h>

int main()
{
    int array[] = {1, 2, 2, 2, 3};

    //success
    assert(BinarySearchMin(array, 0, 4, 2) == 1);
    assert(BinarySearchMax(array, 0, 4, 2) == 3);

    assert(BinarySearchMin(array, 1, 3, 2) == 1);
    assert(BinarySearchMax(array, 1, 3, 2) == 3);

    assert(BinarySearchMin(array, 1, 2, 2) == 1);
    assert(BinarySearchMax(array, 1, 2, 2) == 2);

    assert(BinarySearchMin(array, 1, 1, 2) == 1);
    assert(BinarySearchMax(array, 1, 1, 2) == 1);

    //failure
    assert(BinarySearchMin(array, 0, 4, 4) == -1);
    assert(BinarySearchMax(array, 0, 4, 4) == -1);

    int array2[] = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8, 9};

    assert(BinarySearchMaxLess(array2, 0, 10, 4) == 2);
    assert(BinarySearchMaxLess(array2, 0, 10, 0) == -1);
    assert(BinarySearchMaxLess(array2, 0, 10, 10) == 10);
    assert(BinarySearchMaxLess(array2, 0, 0, 2) == 0);
    assert(BinarySearchMaxLess(array2, 0, 0, 0) == -1);
    assert(BinarySearchMaxLess(array2, 0, 1, 3) == 1);

    assert(BinarySearchMinMore(array2, 0, 10, 4) == 6);
    assert(BinarySearchMinMore(array2, 0, 10, 0) == 0);
    assert(BinarySearchMinMore(array2, 0, 10, 10) == -1);
    assert(BinarySearchMinMore(array2, 0, 0, 2) == -1);
    assert(BinarySearchMinMore(array2, 0, 0, 0) == 0);
    return 0;
}
