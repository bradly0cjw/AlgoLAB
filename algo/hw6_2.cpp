//
// Created by LINBEI on 6/19/2024.
//
#include <bits/stdc++.h>

using namespace std;

struct Node {
    vector<int> path;
    int level, pathCost, bound;
};

struct Graph {
    vector<vector<int>> costMatrix;
    int numCities;
    Node *root;
};

bool isPresentInPath(int city, Node *node);

int calculateBound(Node *node, Graph *graph) {
    int bound = node->pathCost;
    for (int i = 0; i < graph->numCities; i++) {
        if (!isPresentInPath(i, node)) {
            int min = INT_MAX;
            for (int j = 0; j < graph->numCities; j++) {
                if (graph->costMatrix[i][j] < min) {
                    min = graph->costMatrix[i][j];
                }
            }
            bound += min;
        }
    }
    return bound;
}

bool isPresentInPath(int city, Node *node) {
    for (int i: node->path) {
        if (i == city) {
            return true;
        }
    }
    return false;
}

void TSP(Graph *graph) {
    priority_queue<Node *, vector<Node *>, function<bool(Node *, Node *)>> pq([](Node *a, Node *b) {
        return a->bound > b->bound;
    });
    pq.push(graph->root);
    int minCost = INT_MAX;
    vector<int> minPath;
    while (!pq.empty()) {
        Node *node = pq.top();
        pq.pop();
        if (node->bound < minCost) {
            for (int i = 0; i < graph->numCities; i++) {
                if (!isPresentInPath(i, node)) {
                    Node *child = new Node;
                    child->path = node->path;
                    child->path.push_back(i);
                    child->level = node->level + 1;
                    child->pathCost = node->pathCost + graph->costMatrix[node->path.back()][i];
                    child->bound = calculateBound(child, graph);
                    if (child->level == graph->numCities - 1) {
                        child->pathCost += graph->costMatrix[child->path.back()][child->path.front()];
                        if (child->pathCost < minCost) {
                            minCost = child->pathCost;
                            minPath = child->path;
                        }
                    } else if (child->bound < minCost) {
                        pq.push(child);
                    }
                }
            }
        }
    }
    cout << "Optimal tour: ";
    for (int i: minPath) {
        cout << i + 1 << " ";
    }
    cout << "\nLength of the optimal tour: " << minCost << "\n";
}

int main() {
    Graph *graph = new Graph;
    graph->costMatrix = {
            {0,       5,       8,       INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
            {INT_MAX, 0,       4,       INT_MAX, 4,       INT_MAX, INT_MAX, INT_MAX},
            {INT_MAX, INT_MAX, 0,       2,       INT_MAX, INT_MAX, 5,       INT_MAX},
            {INT_MAX, INT_MAX, INT_MAX, 0,       INT_MAX, INT_MAX, INT_MAX, 7},
            {1,       INT_MAX, INT_MAX, INT_MAX, 0,       INT_MAX, INT_MAX, INT_MAX},
            {INT_MAX, 6,       INT_MAX, INT_MAX, 2,       0,       INT_MAX, INT_MAX},
            {INT_MAX, INT_MAX, INT_MAX, 3,       INT_MAX, 8,       0,       INT_MAX},
            {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5,       4,       0}
    };
    graph->numCities = 8;
    graph->root = new Node;
    graph->root->path.push_back(0);
    graph->root->level = 0;
    graph->root->pathCost = 0;
    graph->root->bound = calculateBound(graph->root, graph);

    TSP(graph);

    return 0;
}