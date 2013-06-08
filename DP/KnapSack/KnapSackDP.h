#ifndef _KNAP_SACK_DP_H
#define _KNAP_SACK_DP_H
#include "KnapSack.h"

class KnapSackDP : public KnapSack{
public:
    KnapSackDP(int maxCapcity, int itemSize, const int *pItemVolumn, const int *pItemValue);
    virtual void Solve(void);
};

#endif
