#ifndef _MULTI_SOLUTION_H
#define _MULTI_SOLUTION_H
#include "SimpleSolution.h"

class MultiSolution : public SimpleSolution
{
    public:
        MultiSolution();
    protected:
        virtual bool Queen(int row);
    private:
        int solutionNum;
};
#endif
