#include "KnapSackDP.h"

KnapSackDP::KnapSackDP(int maxCapcity, int itemSize, const int *pItemVolumn, const int *pItemValue):
    KnapSack(maxCapcity, itemSize, pItemVolumn, pItemValue)
{
}
void KnapSackDP::Solve()
{
	/*注意多申请了一个空间，方便后面的取用*/
    int **maxValueTable = new int*[itemSize + 1];
    for(int i=0; i<=itemSize; ++i)
        maxValueTable[i] = new int[maxCapcity + 1];

    /*初始化*/
    for(int i=0; i<=itemSize; ++i)
        for(int j=0; j<=maxCapcity; ++j)
            maxValueTable[i][j] = 0;
    /*DP求解过程*/
    for(int i=1; i<=itemSize; ++i)
        for(int j=1; j<=maxCapcity; ++j)
        {
			
            int value1, value2;
            if(j >= pItemVolumn[i-1])
            {
				/*
				  *当物品为i件体积为j时，如果第i件的体积小于体积j时，maxValueTable[i][j]为下列两种情况之一：  
	              *(1)物品i不放入背包中，所以maxValueTable[i][j]为maxValueTable[i-1][j]的值  
	              *(2)物品i放入背包中，则背包剩余体积为j-pItemValue[i-1],所以maxValueTable[i][j]为maxValueTable[i-1][j-pItemValue[i-1]]的值加上当前物品i的价值  
				*/
                value1 = maxValueTable[i-1][j-pItemVolumn[i-1]] + pItemValue[i-1];
                value2 = maxValueTable[i-1][j];
                if(value1 > value2)
                    maxValueTable[i][j] = value1;
                else
                    maxValueTable[i][j] = value2;
            }
            else
            {
                maxValueTable[i][j] = maxValueTable[i-1][j];
            }
        }

    maxValue = maxValueTable[itemSize][maxCapcity];
    /*逆向推导最优序列,从最后一个状态记录maxValueTable[itemSize][maxCapcity]开始逆推*/
    int max = maxCapcity;
    for(int i=itemSize; i>0; --i)
    {
        pItemSelection[i-1] = 0;/*default*/
		//如果maxValueTable[i][max]大于maxValueTable[i-1][max]，说明maxValueTable[i][max]这个最优值中包含了pItemValue[i-1](注意这里是i-1，因为maxValueTable数组长度是itemSize+1)
        if(maxValueTable[i][max] > maxValueTable[i-1][max])
        {
            pItemSelection[i-1] = 1;
            max -= pItemValue[i-1];
        }
    }
   
    /*end: free*/
    for(int i=0; i<itemSize; ++i)
        delete[] maxValueTable[i];
    delete[] maxValueTable;
}
