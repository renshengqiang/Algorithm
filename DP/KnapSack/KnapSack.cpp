#include "KnapSack.h"

KnapSack::KnapSack(int maxCapcity, int itemSize, const int *pItemVolumn, const int *pItemValue)
{
    this->maxCapcity = maxCapcity;
    this->itemSize = itemSize;
    this->pItemVolumn = pItemVolumn;
    this->pItemValue = pItemValue;
    maxValue = 0;
    pItemSelection = new bool[itemSize];
    for(int i=0; i<itemSize; ++i)
    {
        pItemSelection[i]=0;
    }
}
KnapSack::~KnapSack()
{
    delete[] pItemSelection;
}
void KnapSack::Solve()
{
    maxValue = _SolveItem(0, maxCapcity);
}
/*
 * 递归解法：遍历整个解空间树，得到最大值
 * 注意自己做的不好的：
 * 1. 递归的出口条件弄得太复杂，越简单越好。既然已经是递归，不在乎那多余的一层调用;
 * 2. 最后得到的选择序列保存在pItemSelection中，这个序列的获取颇费周折。我本来想利用归并排序的思想，申请另外一个缓冲区来达到目的，但是是不行的，因为两次递归调用，后面的总会覆盖前面的选择信息。后来得到了现在的解法，确实是参考别人的程序的：既然已经覆盖了，那么就让我们选择的那个递归调用再来一次，这样子就会得到我们想要的最优序列
 * 3.递归算是一种遍历解空间树的一种朴素方法，不要再对它有什么成见，它确实是一种算法技巧
 */
int KnapSack::_SolveItem(int index, int leftCapcity)
{
    if(leftCapcity<=0 || index >= itemSize)
    {
        return 0;
    }
    if(leftCapcity >= pItemVolumn[index])
    {
        int value1, value2;
        value1 = _SolveItem(index + 1, leftCapcity - pItemVolumn[index])  + pItemValue[index];
        value2 = _SolveItem(index + 1, leftCapcity);
        if(value1 > value2)
        {
            pItemSelection[index] = true;
            return  _SolveItem(index + 1, leftCapcity - pItemVolumn[index])  + pItemValue[index];
        }
        else
        {
            pItemSelection[index] = false;
            return value2;
        }
    }
    else
    {
        pItemSelection[index] = false;
        return _SolveItem(index + 1, leftCapcity);
    }
}

