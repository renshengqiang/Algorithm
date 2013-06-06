#ifndef _SIMPLE_SOLUTION_H
#define _SIMPLE_SOLUTION_H
#define QUEEN_NUM 8
class SimpleSolution
{
public:
    SimpleSolution();
    void Solution(void);
protected:
    virtual bool Queen(int row);
    bool Collision(int row, int column);
    void Mark(int row, int column);
    void Unmark(int row, int column);
protected:
    int result[QUEEN_NUM];
    int collision[QUEEN_NUM], crossCollision1[2*QUEEN_NUM-1], crossCollision2[2*QUEEN_NUM -1];
};
#endif
