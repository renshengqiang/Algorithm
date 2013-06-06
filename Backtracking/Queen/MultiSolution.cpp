#include "MultiSolution.h"
#include <iostream>
using namespace std;

MultiSolution::MultiSolution():
    solutionNum(0)
{
}
bool MultiSolution::Queen(int row)
{
    if(row >= QUEEN_NUM)
    {
        ++solutionNum;
        cout << "solution "<< solutionNum << ": ";
        for(int i=0; i<QUEEN_NUM; ++i)
        {
            cout << result[i] << " ";
        }
        cout << endl;
        return true;
    }
    for(int i=0; i<QUEEN_NUM; ++i)
    {
        if(!Collision(row, i))
        {
            result[row] = i;
            Mark(row, i);
            Queen(row + 1);
            Unmark(row, i);
        }
    }
    return true;
}
