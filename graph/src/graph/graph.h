//
// Created by admin on 2020/7/28.
//


#include <iostream>
#include <list>
using namespace std;

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
// Undirected Graph
class Graph_by_adjlist{
    int Vn; // number of nodes
    list<int> *adj; // adj is a flexible array, each array element contains the adjacency list of the node
public:
    // constructor
    Graph_by_adjlist(int v);
    // destructor
    ~Graph_by_adjlist();
    //function to add an edge to graph
    void addEdge(int v, int w);
    void printGraph();

    void BFS(int s);

    void DFS_recur(int v, bool visited[], list<int>& res);
    void DFS(int s);
};
#endif //GRAPH_GRAPH_H
