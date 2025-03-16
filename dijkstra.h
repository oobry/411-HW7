#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <unordered_map>

struct Edge {
    int target;
    int weight;
};

class Dijkstra {
public:
    Dijkstra(int nodes);
    void addEdge(int source, int target, int weight);
    int shortestPath(int start);

private:
    std::unordered_map<int, std::vector<Edge>> graph;
    int numNodes;
};

#endif
