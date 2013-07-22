#include "GraphTheoryAlgo.h"
#include <list>
#include <iostream>
using namespace std;

void InitGraph(struct AMGraph& graph)
{
    //input the vertex info
    int nVertices;
    cout << "input the number of vertices: " << endl;
    cin >> nVertices;

    if(nVertices < 0)
    {
        graph.nVertices = -1;
        return;
    }

    cout << "input the vertices: " << endl;
    graph.nVertices = nVertices;
    graph.vertexVec.resize(nVertices);
    graph.edgeMatrix.resize(nVertices*nVertices);
    for(int i = 0; i<nVertices; ++i)
        cin >> graph.vertexVec[i].value;

    for(int i = 0; i<nVertices; ++i)
        for(int j=0; j<nVertices; ++j)
        {
            if(i==j) graph.edgeMatrix[i*nVertices + j].length = 0;
            else graph.edgeMatrix[i*nVertices + j].length = INFINITE_LENGTH;
        }
    //input the edge info
    int first, next;
    cout << "input the edges(beginIndex, endIndex), end with(-1, -1):" << endl;
    for(;;)
    {
        int length;
        cin >> first;
        cin >> next;
        if(first == -1 || next == -1) break;
        cin >> length;

        graph.edgeMatrix[nVertices*first + next].length = length;
        graph.edgeMatrix[nVertices*next + first].length = length;
    }
}
void _DFS(struct AMGraph& graph, int index, std::vector<int>& visitFlagVec)
{
    cout << graph.vertexVec[index].value << " ";
    for(int i = index + 1; i<graph.nVertices; ++i)
    {
        if(visitFlagVec[i] == 0 && graph.edgeMatrix[index*graph.nVertices + i].length < INFINITE_LENGTH)
        {
            visitFlagVec[i] = 1;
            _DFS(graph, i, visitFlagVec);
        }
    }
}
void DFS(struct AMGraph& graph)
{
    std::vector<int> visitFlagVec;
    visitFlagVec.resize(graph.nVertices);

    for(int i=0; i<graph.nVertices; ++i)
    {
        visitFlagVec[i] = 0;
    }

    cout << "DFS result:";
    for(int i=0; i<graph.nVertices; ++i)
    {
        if(visitFlagVec[i] == 0)
        {
            visitFlagVec[i] = 1;
            _DFS(graph, i, visitFlagVec);
        }
    }
    cout << endl;
}
//Desc: make the spanning tree of graph
//output the edge list
struct Node
{
    int length;
    int preindex;
    int index;
};
void Prim(struct AMGraph& graph)
{
    std::vector<Node> nodeVector;
    nodeVector.resize(graph.nVertices - 1);

    for(vector<Node>::iterator it = nodeVector.begin(); it != nodeVector.end(); ++it)
    {
        it->preindex = 0;
        it->index = it - nodeVector.begin() + 1;
        it->length = graph.edgeMatrix[it->index].length;
    }

    cout << "Prim result:" << endl;
    cout << "(0,0): 0" << endl;
    for(int i=1; i<graph.nVertices; ++i)
    {
        //find the min
        vector<Node>::iterator minIter = nodeVector.begin();
        for(vector<Node>::iterator it = nodeVector.begin() + 1; it != nodeVector.end(); ++it)
        {
            if(minIter->length > it->length) minIter = it;
        }
        int preIndex = minIter->preindex;
        int minIndex = minIter->index;
        int minlength = minIter->length;

        cout << "(" << preIndex << "," << minIndex << "):" << " length: " << minlength << endl;
        nodeVector.erase(minIter);

        for(vector<Node>::iterator it = nodeVector.begin(); it != nodeVector.end(); ++it)
        {
            if(it->length > graph.edgeMatrix[it->index * graph.nVertices + minIndex].length)
            {
                it->preindex = minIndex;
                it->length = graph.edgeMatrix[it->index * graph.nVertices + minIndex].length;
            }
        }
    }
}
void Dijkstra(struct AMGraph& graph)
{
    std::vector<Node> nodeVector;
    nodeVector.resize(graph.nVertices - 1);

    for(vector<Node>::iterator it = nodeVector.begin(); it != nodeVector.end(); ++it)
    {
        it->preindex = 0;
        it->index = it - nodeVector.begin() + 1;
        it->length = graph.edgeMatrix[it->index].length;
    }

    cout << "Dijkstra result:" << endl;
    cout << "(0,0): 0" << endl;
    for(int i=1; i<graph.nVertices; ++i)
    {
        //find the min
        vector<Node>::iterator minIter = nodeVector.begin();
        for(vector<Node>::iterator it = nodeVector.begin() + 1; it != nodeVector.end(); ++it)
        {
            if(minIter->length > it->length) minIter = it;
        }
        int preIndex = minIter->preindex;
        int minIndex = minIter->index;
        int minlength = minIter->length;

        cout << "(" << preIndex << "," << minIndex << "):" << " length: " << minlength << endl;
        nodeVector.erase(minIter);

        for(vector<Node>::iterator it = nodeVector.begin(); it != nodeVector.end(); ++it)
        {
            if(it->length > minlength + graph.edgeMatrix[it->index * graph.nVertices + minIndex].length)
            {
                it->preindex = minIndex;
                it->length = minlength + graph.edgeMatrix[it->index * graph.nVertices + minIndex].length;
            }
        }
    }
}
