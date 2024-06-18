//
// Created by LINBEI on 6/19/2024.
//
#include <iostream>
#include <vector>
#include <climits>

#define INF INT_MAX

void floydWarshall(std::vector<std::vector<int>> &graph) {
    int V = graph.size();
    std::vector<std::vector<int>> dist(V, std::vector<int>(V));

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                std::cout << "INF ";
            else
                std::cout << dist[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> graph = {
            {0, 5,  3, 7,  6, 4},
            {8, 0,  2, 9,  5, 3},
            {6, 4,  0, 1,  7, 8},
            {2, 10, 3, 0,  4, 9},
            {7, 1,  8, 2,  0, 6},
            {5, 9,  4, 10, 1, 0}
    };

    floydWarshall(graph);

    return 0;
}