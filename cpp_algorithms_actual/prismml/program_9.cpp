#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int graph[][5], int source, int n) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (graph[current][neighbor] > 0 && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int graph[][5] = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0}
    };
    int source = 0;
    int n = sizeof(graph) / sizeof(graph[0]);

    cout << "BFS traversal starting from node " << source << ":\n";
    bfs(graph, source, n);

    return 0;
}
