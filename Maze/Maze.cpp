#include "Maze.h"
#include <stdio.h>

bool FindMazePathRecursive(int **maze, int x, int y, int w, int h, std::deque<Direction>& path)
{
    static Direction direction[4] = {{1, 0},{0, 1},{-1, 0}, {0, -1}};

    if(x == w-1 && y == h-1) return true;
    for(int i=0; i<4; ++i)
    {
        int xx = x + direction[i].x;
        int yy = y + direction[i].y;

        if(xx >=0 && yy >=0 &&
            yy < h && xx < w &&
            maze[yy][xx] == 0)
        {
            maze[yy][xx] = 1;
            if(FindMazePathRecursive(maze, xx, yy, w, h, path))
            {
                Direction dir;
                dir.x = xx;
                dir.y = yy;
                path.push_front(dir);
                return true;
            }
            maze[yy][xx] = 0;
        }
    }
    return false;
}
