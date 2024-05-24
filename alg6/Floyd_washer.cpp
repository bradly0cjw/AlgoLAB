//
// Created by LINBEI on 5/10/2024.
//
#include "bits/stdc++.h"

using namespace std;

void print_matrix(vector<vector<int>> &dist, ofstream &out);

void floyd_washer_algo(ifstream &in, ofstream &out) {
    int n;
    in >> n;
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    int m;
    in >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        in >> u >> v >> w;
        dist[u][v] = w;
    }
    print_matrix(dist, out);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
        print_matrix(dist, out);
    }
    print_matrix(dist, out);
}

void print_matrix(vector<vector<int>> &dist, ofstream &out) {
    for (int i = 0; i < dist.size(); i++) {
        for (int j = 0; j < dist.size(); j++)
            (dist[i][j] == 1e9) ? out << "INF" << " " : out << dist[i][j] << " ";
        out << endl;
    }
    out << endl;
}

int main() {
    ifstream in("./alg6/floyd.in");
    ofstream out("./alg6/floyd.out");
    floyd_washer_algo(in, out);
    return 0;
}