#include "GraphTheoryAlgo.h"

int main()
{
    struct Graph graph;

    InitGraph(&graph);
    if(graph.nVertices > 0)
    {
        DFS(graph);
        BFS(graph);
        TopologicalSort(graph);
    }
    return 0;
}
