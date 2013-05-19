/*************************************************************************
	> File Name: Vector.cpp
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年05月19日 星期日 19时15分46秒
 ************************************************************************/
#include <stdlib.h>
#include <string.h>
namespace QTL{
	template<typename T>
	Vector<T>::Vector()
	{
		pVectorBegin = pVectorEnd = NULL;
		mSize = mMaxSize = 0;
	}

	template<typename T>
	Vector<T>::~Vector()
	{
		if(pVectorBegin)
		{
			free(pVectorBegin);
		}
		pVectorBegin = pVectorEnd = NULL;
		mSize = mMaxSize = 0;
	}

	template<typename T>
	T* Vector<T>::begin() 
	{
		return pVectorBegin;
	}

	template<typename T> 
	T* Vector<T>::end()
	{
		return pVectorEnd;
	}

	template<typename T>
	void Vector<T>::push_back(const T& item)
	{
		if(mMaxSize > mSize)
		{
			bcopy(&item, pVectorEnd, sizeof(item));
			++mSize;
			++pVectorEnd;
		}
		else
		{
			if(0 == mSize)
			{
				pVectorBegin = new T;
				bcopy(&item, pVectorBegin, sizeof(item));
				mMaxSize = mSize = 1;
				pVectorEnd = pVectorBegin + 1;
			}
			else
			{
				pVectorBegin = (T*)realloc(pVectorBegin, 2*mMaxSize*sizeof(T));
				pVectorEnd = pVectorBegin + mMaxSize;
				bcopy(&item, pVectorEnd, sizeof(item));
				++mSize;
				++pVectorEnd;
				mMaxSize*=2;
			}
		}
	}//push_back
}
