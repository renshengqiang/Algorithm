#ifndef _KNAP_SACK_H
#define _KNAP_SACK_H

class KnapSack{
public:
    KnapSack(int maxCapcity, int itemSize, const int *pItemVolumn, const int *pItemValue);
    ~KnapSack();
    int GetMaxValue(void) const{ return maxValue;}
    bool* GetItemSelection(void) const{ return  pItemSelection;}
    virtual void Solve(void);
protected:
    int _SolveItem(int index, int leftCapicity);/*返回最大价值*/
protected:
    int maxCapcity;/*背包的最大容量*/
    int itemSize;/*物品的个数*/
    const int *pItemVolumn;/*每个物品的体积数组*/
    const int *pItemValue;/*每个物品的价值数组*/
    int maxValue;/*最后得到的最大价值*/
    bool *pItemSelection;/*每个物品是否选择数组*/
};

#endif
