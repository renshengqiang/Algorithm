#ifndef _ADJACENT_LIST_H
#define _ADJACENT_LIST_H
#include <list>
#include <vector>

struct Edge
{
    int length;
    int index;
};
struct Vertex
{
    char value;
    std::list<Edge> edgeList;
};
struct Graph
{
    int nVertices;
    std::vector<Vertex> vertexVec;
};
#endif
