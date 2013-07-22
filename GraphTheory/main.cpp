#include "GraphTheoryAlgo.h"

int main()
{
    /*
    struct Graph graph;

    InitGraph(&graph);
    if(graph.nVertices > 0)
    {
        DFS(graph);
        BFS(graph);
        TopologicalSort(graph);
    }
    */
    struct AMGraph graph;
    InitGraph(graph);
    if(graph.nVertices > 0)
    {
        DFS(graph);
        Prim(graph);
        Dijkstra(graph);
    }
    return 0;
}
