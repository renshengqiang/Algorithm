/*************************************************************************
	> File Name: vector.h
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年05月19日 星期日 18时57分46秒
 ************************************************************************/
#ifndef _MY_VECTOR_H_
#define _MY_VECTOR_H_
#include <stddef.h>
namespace QTL{
	template <typename T>
	class Vector{
	public:
		typedef T* iterator;

		Vector(size_t size);
		Vector();
		Vector(const Vector<T>& rhs);
		~Vector();
	
		iterator begin(void);
		iterator end(void);

		void push_back(const T& t);
		void push_front(const T& t);
		iterator insert(iterator iter, const T& t);

		iterator erase(iterator p);
		void clear(void);
		void pop_back(void);
		void pop_front(void);

		size_t size(void);
		size_t max_size(void);
		bool empty(void);
		bool resize(size_t size);
		
		T&	back(void);
		T&	front(void);
		T&	at(size_t n);
		T&	operator[](size_t n);
	private:
		iterator pVectorBegin, pVectorEnd;/*begin and end of the allocated space*/
		size_t mSize;
		size_t mMaxSize;
	};
}
#include <Vector.cpp>
#endif

