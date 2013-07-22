#include "GraphTheoryAlgo.h"
#include <queue>
#include <iostream>
using namespace std;

void InitGraph(struct Graph *pGraph)
{
    //input vertex info
    int nVertices;
    cout << "input the number of vertices:" << endl;
    cin >> nVertices;

    if(nVertices<0)
    {
        pGraph->nVertices = -1;
    }

    cout << "input the vertices:" << endl;
    pGraph->nVertices = nVertices;
    pGraph->vertexVec.resize(nVertices);
    for(int i=0; i<nVertices; ++i)
    {
        cin >> *(&(pGraph->vertexVec[i].value));
    }

    //input edge info
    int first, next;
    struct Edge edge;
    cout << "input the edges(beginIndex, endIndex), end with (-1,-1):" << endl;
    for(;;)
    {
        cin >> first;
        cin >> next;
        if(first == -1 || next == -1) break;
        edge.index = next;
        //insert into 
        pGraph->vertexVec[first].edgeList.push_back(edge);
    }
}

void _DFS(struct Graph& graph, int index, int *pVisitFlagVec)
{
    cout << graph.vertexVec[index].value << " ";
    
    for(std::list<Edge>::iterator it = graph.vertexVec[index].edgeList.begin(); 
            it != graph.vertexVec[index].edgeList.end(); ++it)
    {
        if(pVisitFlagVec[(*it).index] == 0)
        {
            pVisitFlagVec[(*it).index] = 1;
            _DFS(graph, (*it).index, pVisitFlagVec);
        }
    }
}
void DFS(struct Graph& graph)
{
    int *pVisitFlagVec;
    pVisitFlagVec = new int[graph.nVertices];

    for(int i=0; i<graph.nVertices; ++i)
        pVisitFlagVec[i] = 0; //not visited

    cout << "DFS result:";
    for(int i=0; i<graph.nVertices; ++i)
        if(pVisitFlagVec[i] == 0)
        {
            pVisitFlagVec[i] = 1;
            _DFS(graph, i, pVisitFlagVec);
        }
    cout << endl;
    delete[] pVisitFlagVec;
}

void BFS(struct Graph& graph)
{
    int *pVisitFlagVec;
    pVisitFlagVec = new int[graph.nVertices];

    for(int i=0; i<graph.nVertices; ++i)
        pVisitFlagVec[i] = 0; //not visited

    std::queue<int> indexQueue;
   
    cout << "BFS result:";
    for(int i = 0; i < graph.nVertices; ++i)
    {
        if(pVisitFlagVec[i] == 0)
        {
            indexQueue.push(i);
            while(!indexQueue.empty())
            {
                int index = indexQueue.front();
                indexQueue.pop();
                if(pVisitFlagVec[index] == 0) 
                {
                    pVisitFlagVec[index] = 1;
                    cout << graph.vertexVec[index].value << " ";
                }
                for(std::list<Edge>::iterator it = graph.vertexVec[index].edgeList.begin();
                        it != graph.vertexVec[index].edgeList.end(); ++it)
                {
                    if(pVisitFlagVec[(*it).index] == 0)
                        indexQueue.push((*it).index);
                }
            }
        }
    }
    cout << endl;
    delete[] pVisitFlagVec;
}
void _TopologicalSort(struct Graph& graph, int index, int *pVisitFlagVec, std::list<int>& resultList)
{
    for(std::list<Edge>::iterator it = graph.vertexVec[index].edgeList.begin(); 
            it != graph.vertexVec[index].edgeList.end(); ++it)
    {
        if(pVisitFlagVec[(*it).index] == 0)
        {
            pVisitFlagVec[(*it).index] = 1;
            _TopologicalSort(graph, (*it).index, pVisitFlagVec, resultList);
        }
    }
    resultList.push_front(index);
}
void TopologicalSort(struct Graph& graph)
{
    int *pVisitFlagVec;
    pVisitFlagVec = new int[graph.nVertices];
    std::list<int> resultList;

    for(int i=0; i<graph.nVertices; ++i)
        pVisitFlagVec[i] = 0; //not visited

    cout << "topological sort result:";
    for(int i=0; i<graph.nVertices; ++i)
        if(pVisitFlagVec[i] == 0)
        {
            pVisitFlagVec[i] = 1;
            _TopologicalSort(graph, i, pVisitFlagVec, resultList);
        }

    for(std::list<int>::iterator it = resultList.begin(); it != resultList.end(); ++it)
    {
        cout << graph.vertexVec[*it].value << " ";
    }
    cout << endl;
    delete[] pVisitFlagVec;
}
