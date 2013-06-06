#include "SimpleSolution.h"
#include <iostream>
using namespace std;
SimpleSolution::SimpleSolution()
{
    for(int i=0; i<QUEEN_NUM; ++i)
    {
        result[i] = collision[i];
    }
    for(int i=0; i<2*QUEEN_NUM; ++i)
    {
        crossCollision1[i] = crossCollision2[i] = 0;
    }
}
void SimpleSolution::Solution()
{
    Queen(0);
}
bool SimpleSolution::Queen(int row)
{
    if(row >= QUEEN_NUM){
        cout << "solution: ";
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
            if(Queen(row + 1)) return true;
            Unmark(row, i);
        }
    }
    return false;
}
bool SimpleSolution::Collision(int row, int column)
{
    if(collision[column] == 1) return true;
    if(crossCollision1[row + column] == 1) return true;
    if(crossCollision2[QUEEN_NUM - 1 + column - row] == 1) return true;
    return false;
}
void SimpleSolution::Mark(int row, int column)
{
    collision[column] = 1;
    crossCollision1[row + column] = 1;
    crossCollision2[QUEEN_NUM -1 + column - row] = 1;
}
void SimpleSolution::Unmark(int row, int column)
{
    collision[column] = 0;
    crossCollision1[row + column] = 0;
    crossCollision2[QUEEN_NUM -1 + column - row] = 0;
}
