#include "dijkstra.h"
#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>  // <-- Add this line

using namespace std;

Dijkstra::Dijkstra(int nodes) : numNodes(nodes) {}

void Dijkstra::addEdge(int source, int target, int weight) {
    graph[source].push_back({target, weight});
}

int Dijkstra::shortestPath(int start) {
    vector<int> shortestTime(numNodes + 1, numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

    shortestTime[start] = 0;
    minHeap.push({0, start});

    while (!minHeap.empty()) {
        auto [time, node] = minHeap.top();
        minHeap.pop();

        if (time > shortestTime[node]) continue;

        for (auto& edge : graph[node]) {
            int newTime = time + edge.weight;
            if (newTime < shortestTime[edge.target]) {
                shortestTime[edge.target] = newTime;
                minHeap.push({newTime, edge.target});
            }
        }
    }

    int maxTime = *max_element(shortestTime.begin() + 1, shortestTime.end());
    return maxTime == numeric_limits<int>::max() ? -1 : maxTime;
}
