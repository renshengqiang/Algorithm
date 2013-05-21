/*************************************************************************
	> File Name: Vector.cpp
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年05月19日 星期日 19时15分46秒
 ************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <utility> //std::swap
/*
 * 设计心得：
 * 1. iterator的实现就是用指针进行的实现，所以iterator失效的情况可以理解为指针失效
 * 2. 内存的管理策略是不够的时候加倍，在删除的时候并没有管理内存
 * 3. 我用的是四个数据来表示这个类，其实用三个就够了：mSize可以忽略，stdc++用的是三个指针来管理的
 * 4. 内存的拷贝我用的是bcopy函数，这个函数在内存发生重叠的时候，可以保证安全。linux中还有许多函数可以实现这样的功能，memmove也可以保证，但是粗略简单，通过另一个temp缓冲区来做中间变量; memcpy没有重叠保证
 * 5. 如果函数返回的是引用，可以对一个空指针解引用用于返回
 * 6. 加入一个新成员的时候，必须构造一个对象出来，保证对象执行的是拷贝函数构造出来的
 * 7. 加入了一个swap函数，该函数必须不抛出异常，否则异常安全没有理论依据
 *    然后，在头文件中加入了一个该模板类的专属swap函数。由于是模板类，没有std::swap的全特化方案，只有偏特化方案。偏特化方案不能用，因此只能始终这种方案。
 *    应用程序使用的时候，需要先声明using std::swap, 保证调用的顺序是:专属swap, 全特化swap, 普通swap
 * 8. 需要查看stl的源码，查阅迭代器是如何实现的，特别是逆向迭代器是如何实现的
 * */
namespace QTL{
    //-----------------------------------------------------------------------------
	template<typename T>
	Vector<T>::Vector()
	{
		pVectorBegin = pVectorEnd = NULL;
		mSize = mMaxSize = 0;
	}
    
    //-----------------------------------------------------------------------------
	template<typename T>
	Vector<T>::Vector(size_t size)
    {
        pVectorBegin = pVectorEnd = (T*)malloc(size*sizeof(T));
        mSize = 0;
        mMaxSize = size;
    }
    //-----------------------------------------------------------------------------
	template<typename T>
    Vector<T>::Vector(const Vector<T>& rhs)
    {
        pVectorBegin = (T*)malloc(rhs.mMaxSize*sizeof(T));
        bcopy(rhs.pVectorBegin, pVectorBegin, rhs.mSize * sizeof(T));
        pVectorEnd = pVectorBegin + rhs.mSize;
        mSize = rhs.mSize;
        mMaxSize = rhs.mMaxSize;
    }
    //-----------------------------------------------------------------------------
    template <typename T>
    Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
    {
        //release the vector created before
		if(pVectorBegin)
		{
			free(pVectorBegin);
		}
        //create the new vector
        pVectorBegin = (T*)malloc(rhs.mMaxSize*sizeof(T));
        bcopy(rhs.pVectorBegin, pVectorBegin, rhs.mSize * sizeof(T));
        pVectorEnd = pVectorBegin + rhs.mSize;
        mSize = rhs.mSize;
        mMaxSize = rhs.mMaxSize;
    }
    //-----------------------------------------------------------------------------
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
    //-----------------------------------------------------------------------------
    template <typename T>
    const T* Vector<T>::begin() const
    {
        return pVectorBegin;
    }
    //-----------------------------------------------------------------------------
	template<typename T>
	T* Vector<T>::begin() 
	{
		return pVectorBegin;
	}
    //-----------------------------------------------------------------------------
    template <typename T>
    const T* Vector<T>::end() const
    {
        return pVectorEnd;
    }
    //-----------------------------------------------------------------------------
	template<typename T>
	T* Vector<T>::end()
	{
		return pVectorEnd;
	}
    //-----------------------------------------------------------------------------
	template <typename T>
	void Vector<T>::push_back(const T& item)
	{
        T   temp(item);
		if(mMaxSize > mSize)
		{
			bcopy(&temp, pVectorEnd, sizeof(T));
			++mSize;
			++pVectorEnd;
		}
		else
		{
			if(0 == mSize)
			{
				pVectorBegin = new T;
				bcopy(&temp, pVectorBegin, sizeof(T));
				mMaxSize = mSize = 1;
				pVectorEnd = pVectorBegin + 1;
			}
			else
			{
				pVectorBegin = (T*)realloc(pVectorBegin, 2*mMaxSize*sizeof(T));
				pVectorEnd = pVectorBegin + mMaxSize;
				bcopy(&temp, pVectorEnd, sizeof(T));
				++mSize;
				++pVectorEnd;
				mMaxSize*=2;
			}
		}
	}//push_back
    //-----------------------------------------------------------------------------
    template <typename T>
    void Vector<T>::push_front(const T& item)
    {
       T temp(item);
       if(mMaxSize > mSize)
       {
           bcopy(pVectorBegin, pVectorBegin + 1, mSize * sizeof(T));
           bcopy(&temp, pVectorBegin, sizeof(T));
           ++pVectorEnd;
           ++mSize;
       }
       else
       {
           if(0 == mSize)
           {
				pVectorBegin = new T;
				bcopy(&temp, pVectorBegin, sizeof(T));
				mMaxSize = mSize = 1;
				pVectorEnd = pVectorBegin + 1;
           }
           else
           {
               T *temp2 = (T*)malloc(2*mMaxSize*sizeof(T));
               bcopy(pVectorBegin, temp2 + 1, mSize*sizeof(T));
               bcopy(&temp, temp2, sizeof(T));
               free(pVectorBegin);
               pVectorBegin = temp2;
               pVectorEnd = pVectorBegin + mSize + 1;
               ++mSize;
               mMaxSize*=2;
           }
       }
    }//push_front
    //-----------------------------------------------------------------------------
    template <typename T>
    T* Vector<T>::insert(T* iter, const T& item)
    {
       T t(item);
       if(iter < pVectorBegin || iter > pVectorEnd)
       {
           return NULL;
       }
       if(mMaxSize > mSize)
       {
           bcopy(iter, iter + 1, (pVectorEnd - iter)*sizeof(T));
           bcopy(&t, iter, sizeof(T));
           ++mSize;
           ++pVectorEnd;
           return iter;
       }
       else
       {
            T *temp = (T*)malloc(2*mMaxSize*sizeof(T));
            size_t n = iter - pVectorBegin;
            bcopy(pVectorBegin, temp, n * sizeof(T));
            bcopy(&t, temp + n, sizeof(T));
            bcopy(iter, temp + n + 1, (mSize-n)*sizeof(T));
            free(pVectorBegin);
            pVectorBegin = temp;
            pVectorEnd = pVectorBegin + mSize + 1;
            ++mSize;
            mMaxSize*=2;
            return pVectorBegin + n;
       }
    }//insert
    //-----------------------------------------------------------------------------
    template <typename T>
    T* Vector<T>::erase(T* item)
    {
       if(item < pVectorBegin || item > pVectorEnd)
       {
           return NULL;
       }
       bcopy(item + 1, item, (pVectorEnd - item)*sizeof(T));
       --pVectorEnd;
       --mSize;
    }
    //-----------------------------------------------------------------------------
    template <typename T>
    void Vector<T>::clear()
    {
        if(pVectorBegin)
        {
            free(pVectorBegin);
        }
        pVectorBegin = pVectorEnd = NULL;
        mSize = mMaxSize = 0;
    }
    //-----------------------------------------------------------------------------
    template <typename T>
    void Vector<T>::pop_back()
    {
        if(pVectorBegin)
        {
            --pVectorEnd;
            --mSize;
        }
    }
    //-----------------------------------------------------------------------------
    template <typename T>
    void Vector<T>::pop_front()
    {
        if(pVectorBegin)
        {
            bcopy(pVectorBegin + 1, pVectorBegin, (mSize - 1)*sizeof(T));
            --mSize;
            --pVectorEnd;
        }
    }
    //-----------------------------------------------------------------------------
    template <typename T>
    size_t Vector<T>::size()
    {
        return mSize;
    }
    //-----------------------------------------------------------------------------
    template <typename T>
    size_t Vector<T>::max_size()
    {
        return mMaxSize;
    }
    //-----------------------------------------------------------------------------
    template <typename T>
    bool Vector<T>::empty()
    {
        return mSize==0;
    }
    //-----------------------------------------------------------------------------
    template <typename T>
    void Vector<T>::resize(size_t size)
    {
        pVectorBegin = (T*)realloc(pVectorBegin, size*sizeof(T));
        mMaxSize = size;
        pVectorEnd = pVectorBegin + mSize;
    }
    //-----------------------------------------------------------------------------
    template <typename T>
    T& Vector<T>::back()
    {
        if(pVectorEnd)
        {
            return *(--pVectorEnd);
        }
        else
        {
            return *pVectorEnd;
        }
    }
    //-----------------------------------------------------------------------------
    template <typename T>
    T& Vector<T>::front()
    {
        return *pVectorBegin;
    }
    //-----------------------------------------------------------------------------
    template <typename T>
    T& Vector<T>::at(size_t n)
    {
        return *(pVectorBegin + n);
    }
    //-----------------------------------------------------------------------------
    template <typename T>
    T& Vector<T>::operator[](size_t n)
    {
        return *(pVectorBegin + n);
    }
    //-----------------------------------------------------------------------------
    //此函数必须保证是异常安全的，只有这个是安全的才能保证外面是安全的
    template <typename T>
    void Vector<T>::swap(Vector<T>& rhs)
    {
        using std::swap;
        swap(this->pVectorBegin, rhs.pVectorBegin);
        swap(this->pVectorEnd, rhs.pVectorEnd);
        swap(this->mSize, rhs.mSize);
        swap(this->mMaxSize, rhs.mMaxSize);
    }
}
