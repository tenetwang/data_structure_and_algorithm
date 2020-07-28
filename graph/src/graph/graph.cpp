//
// Created by admin on 2020/7/28.
//

#include "graph.h"
#include <iostream>
#include <list>
using namespace std;

// Graph
// Using adjacency list to represent a graph

Graph_by_adjlist::Graph_by_adjlist(int v) {
    Vn = v;
    adj = new list<int>[Vn];
}

Graph_by_adjlist::~Graph_by_adjlist() {
    delete adj;
}

bool listCheck(int t, list<int> l){
    for(auto i=l.begin(); i!=l.end(); i++){
        if(t == *i){
            return true;
        }
    }
    return false;
}

void Graph_by_adjlist::addEdge(int v, int w) {
    // new node occurs

    if(v > Vn-1 || w > Vn-1){
        auto *temp = new list<int>[Vn+1];
        for(int i=0; i < Vn; i++){
            temp[i] = adj[i];
        }
        list<int> *del = adj;
        adj = temp;
        delete [] del;
    }
    if(!listCheck(v, adj[w]) && !listCheck(w, adj[v])){
        adj[v].push_back(w); // add w to v's list
        if(v != w){
            adj[w].push_back(v);
        }
    }
}

void Graph_by_adjlist::printGraph() {
    for(int i=0; i<Vn; i++){
        cout << "\n Adjacency list of vertex "
             << i << "\n head ";
        for (auto x : adj[i])
            cout << "-> " << x;
        cout << endl;
    }
}

// breadth first search for a graph
void Graph_by_adjlist::BFS(int s) {
    // s is the start point of search

    // we need a array to record whether a node is visited or not
    auto *visited = new bool[Vn];
    for(int i=0; i<Vn; i++){
        visited[i] = false;
    }
    // Create a data structure to store the visited node
    // It can be various kinds of structure, and here list is under used
    list<int> queue, res;
    queue.push_back(s);
    visited[s] = true;
    // Use a iterator i to get all nodes from the adj of the graph
    while (!queue.empty()){
        s = queue.front();
        res.push_back(s);
        queue.pop_front();
        for(auto i=adj[s].begin(); i != adj[s].end(); i++){
            // add an unvisited node to the queue
            if(!visited[*i]){
                queue.push_back(*i);
                visited[*i] = true;
            }
        }
    }
    // print the res as result
    cout << " BFS result:";
    for(auto i=res.begin(); i!=res.end(); i++){
        cout << " "<< *i ;
    }
    cout << endl;
}

void Graph_by_adjlist::DFS_recur(int v, bool visited[], list<int>& res) {
    visited[v] = true;
    res.push_back(v);

    for(auto i=adj[v].begin(); i != adj[v].end(); i++){
        if(!visited[*i]){
            DFS_recur(*i, visited, res);
        }
    }

}

void Graph_by_adjlist::DFS(int s) {
    auto *visited = new bool[Vn];
    list<int> res;
    for(int i=0; i<Vn; i++){
        visited[i] = false;
    }
    DFS_recur(s, visited, res);

    // print the result in res
    cout << " DFS result:" ;
    for(auto i = res.begin(); i!=res.end(); i++){
        cout << " " << *i;
    }
    cout << endl;
}