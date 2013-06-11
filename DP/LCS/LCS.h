/*************************************************************************
	> File Name: LCS.h
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年06月11日 星期二 19时16分26秒
 ************************************************************************/
#ifndef _LCS_H
#define _LCS_H
/*
 *input: find common subsequence between X & Y
 *output: return the maxLength, outSequence contains the sequences in common
 */
template <typename T>
int LCS(const T *X, const T *Y, int m, int n, T **outSequence)
{
	int **c;
	int maxLength = 0;

	if(m == 0 || n == 0) return 0;
	c = new int*[m+1];
	for(int i=0;i<=m;++i) c[i] = new int[n+1];

	//initialize
	for(int i=0; i<=m; ++i)
		c[i][0] = 0;
	for(int i=0; i<=n; ++i)
		c[0][i] = 0;

	//compute
	for(int i=1; i<=m; ++i)
		for(int j=1; j<=n; ++j)
		{
			if(X[i-1] == Y[j-1])
			{
				c[i][j] = c[i-1][j-1] + 1;
			}
			else if(c[i-1][j] > c[i][j-1])
				c[i][j] = c[i-1][j];
			else
				c[i][j] = c[i][j-1];
		}
	maxLength = c[m][n];
	
	//compute the common sequence
	int i=m,j=n;
	*outSequence = new T[maxLength];
	while(maxLength > 0)
	{
		if(c[i][j] == c[i-1][j-1] + 1)
		{
			(*outSequence)[maxLength - 1] = X[i-1];
			--i;
			--j;
			--maxLength;
		}
		else if(c[i][j] == c[i-1][j])
			--i;
		else
			--j;
	}

	maxLength = c[m][n];
	for(int i=0; i<=m; ++i)
		delete[] c[i];
	delete[] c;
	return maxLength;
}
#endif
