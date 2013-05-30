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
        typedef size_t size_type;
        typedef T value_type;
		typedef T* iterator;
        typedef const T* const_iterator;
        struct reverse_iterator{
            reverse_iterator();
            reverse_iterator(iterator iter);

            reverse_iterator& operator++();
            reverse_iterator operator++(int);
            reverse_iterator& operator--();
            reverse_iterator operator--(int);
            bool operator==(const reverse_iterator& rhs);
            bool operator!=(const reverse_iterator& rhs);

            T&  operator*();
            T*  operator->();
        private:
            T* p;
        };
        typedef const reverse_iterator const_reverse_iterator;

		Vector(size_t size);
		Vector();
		Vector(const Vector<T>& rhs);
        Vector& operator=(const Vector<T>& rhs);
		~Vector();

        const_iterator begin(void) const;
		iterator begin(void);
        const_iterator end(void) const;
		iterator end(void);

        reverse_iterator rbegin(void);
        const_reverse_iterator rbegin(void) const;
        reverse_iterator rend(void);
        const_reverse_iterator rend(void) const;

		void push_back(const T& t);
		void push_front(const T& t);
		iterator insert(iterator iter, const T& t);

		iterator erase(iterator p);
		void clear(void);
		void pop_back(void);
		void pop_front(void);

		size_type size(void);
		size_type max_size(void);
		bool empty(void);
		void resize(size_type size);
		
        T&	back(void);
		T&	front(void);
		T&	at(size_type n);
		T&	operator[](size_type n);

        void swap(Vector<T>& rhs);
	private:
		iterator pVectorBegin, pVectorEnd;/*begin and end of the allocated space*/
		size_t mSize;
		size_t mMaxSize;
	};
    template <typename T>
    void swap(Vector<T>& a, Vector<T>& b)
    {
        a.swap(b);
    }
}
#include <Vector.cpp>
#endif

