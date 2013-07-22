#ifndef _ADJACENT_MATRIX_H
#define _ADJACENT_MATRIX_H

#include <vector>
#define INFINITE_LENGTH 32767
struct AMEdge
{
   int length; 
};

struct AMVertex
{
    char value;
};

struct AMGraph
{
    int nVertices;
    std::vector<Vertex> vertexVec;
    std::vector<Edge> edgeMatrix;
};

#endif
