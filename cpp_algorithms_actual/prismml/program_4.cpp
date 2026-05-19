#include <iostream>
#include <vector>
using namespace std;

void floydWarshall(int graph[][5], int n) {
    vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max()));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest paths:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << " -> " << j << " with distance " << dist[i][j] << endl;
        }
    }
}

int main() {
    int graph[][5] = {
        {0, 3, 0, 5, 0},
        {3, 0, 2, 0, 1},
        {0, 2, 0, 0, 4},
        {5, 0, 0, 0, 2},
        {0, 1, 4, 2, 0}
    };
    int n = sizeof(graph) / sizeof(graph[0]);

    floydWarshall(graph, n);

    return 0;
}
