#include "AdjacentList.h"
#include "AdjacentMatrix.h"

//about adjacent list
void InitGraph(struct Graph *pGraph);
void BFS(struct Graph& graph);
void DFS(struct Graph& graph);
void TopologicalSort(struct Graph& graph);

//about adjacent matrix
void InitGraph(struct AMGraph& graph);
void DFS(struct AMGraph& graph);
void Prim(struct AMGraph& graph);
void Dijkstra(struct AMGraph& graph);
