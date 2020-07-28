#include <iostream>
#include "./src/graph/graph.h"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    Graph_by_adjlist g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    //g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.printGraph();
    g.BFS(2);
    g.DFS(2);
    cout << "done" << endl;
    return 0;
}
