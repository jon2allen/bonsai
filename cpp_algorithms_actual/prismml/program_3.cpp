#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

void dijkstra(int graph[][5], int source, int n) {
    vector<int> dist(n, numeric_limits<int>::max());
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDist > dist[currentNode])
            continue;

        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (graph[currentNode][neighbor] > 0 && dist[neighbor] > dist[currentNode] + graph[currentNode][neighbor]) {
                dist[neighbor] = dist[currentNode] + graph[currentNode][neighbor];
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    cout << "Shortest paths from node " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << i << " -> " << source << " with distance " << dist[i] << endl;
    }
}

int main() {
    int graph[][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 2},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 2, 0, 1, 0}
    };
    int source = 0;
    int n = sizeof(graph) / sizeof(graph[0]);

    dijkstra(graph, source, n);

    return 0;
}
