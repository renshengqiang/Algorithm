#ifndef _MAZE_H
#define _MAZE_H

#include <deque>

struct Direction
{
    int x,y;
};

bool FindMazePathRecursive(int **maze, int x, int y, int w, int h, std::deque<Direction>& path);

#endif
