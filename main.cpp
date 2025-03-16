#include "dijkstra.h"
#include <iostream>

using namespace std;

int main() {
    Dijkstra d(4);  // 4 nodes

    d.addEdge(2, 1, 1);
    d.addEdge(2, 3, 1);
    d.addEdge(3, 4, 1);

    int result = d.shortestPath(2);
    cout << "Shortest time to reach all nodes: " << result << endl;

    return 0;
}
