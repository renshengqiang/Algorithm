#include "KnapSackDP.h"
#include <iostream>
using namespace std;

int main()
{
    int pVolumn[10]={1,2,3,4,5,6,7,8,9,10};
    int pValue[10]={2,3,4,5,6,7,8,9,10,11};
    KnapSackDP knapSack(25, 10, pVolumn, pValue);
    bool *pResult;

    knapSack.Solve();
    cout << "Max Value: " << knapSack.GetMaxValue() << endl;
    pResult = knapSack.GetItemSelection();
    for(int i = 0; i<10; ++i)
    {
        if(pResult[i])
            cout << "[" << i <<"]" << pValue[i] << " ";
    }
    cout << endl;
    return 0;
}
