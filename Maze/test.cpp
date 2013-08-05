#include "Maze.h"
#include <iostream>
using namespace std;

int main()
{
    std::deque<Direction> queue;
    int maze1[] = {0, 1, 0, 0, 0, 1, 1, 0, 0};
    int maze2[] = {0, 0, 0, 0, 1, 1, 0, 1, 1};
    int maze3[] = {0, 0, 0, 0, 0, 0, 0, 1, 1};
    int maze4[] = {1, 1, 0, 1, 1, 1, 1, 0, 1};
    int maze5[] = {1, 1, 0, 0, 0, 1, 0, 0, 0};
    int maze6[] = {0, 0, 0, 1, 0, 0, 0, 1, 0};
    int *maze[6] = {maze1, maze2, maze3, maze4, maze5, maze6};

    bool ret = FindMazePathRecursive(maze, 0, 0, 9, 6, queue);

    if(ret)
    {
        for(std::deque<Direction>::iterator it = queue.begin(); it != queue.end(); ++it)
        {
            cout << "(" << it->y << "," << it->x << ")" << "--->";
        }
        cout << endl;
    }
    else
        cout << "can not find a path" << endl;
}
