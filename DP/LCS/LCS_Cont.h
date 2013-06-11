/*************************************************************************
	> File Name: LCS-Cont.h
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年06月11日 星期二 22时55分40秒
 ************************************************************************/
#ifndef _LCS_CONT_H
#define _LCS_CONT_H
/*
 * input: X,Y,m,n
 * output: the length of common sequence
 */
template <typename T>
int LCS_Cont(const T *X, const T *Y, int m, int n, T **out)
{
	int start = 0, end = 0, len = 0;
	int *c = new int[n];

	for(int i=0; i<m; ++i)
		for(int j=n-1; j>=0; --j)
		{
			if(X[i] == Y[j])
			{
				if(i==0 || j==0)
				{
					c[j] = 1;
				}
				else
					c[j] = c[j-1] + 1;
			}
			else
				c[j] = 0;
			if(c[j]>len)
			{
				len = c[j];
				end = j;
			}
		}

	*out = new T[len];
	start = end - len + 1;
	for(int i=0; i<len; ++i)
	{
		(*out)[i] = Y[i+start];
	}

	delete[] c;
	return len;
}

#endif
