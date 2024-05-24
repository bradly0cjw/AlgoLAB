//
// Created by LINBEI on 5/10/2024.
//
#include "bits/stdc++.h"

using namespace std;

void print_array(vector<int> &dist, ofstream &out);

void find_path(vector<int> &prev, int s, int e, ofstream &out);


void dijkstra(ifstream &in, ofstream &out) {
    int n, m, s, e;
    in >> n >> m >> s >> e;
    vector<vector<int>> cost(n, vector<int>(n, 1e9));
    for (int l = 0; l < m; l++) {
        int u_temp, v_temp, w_temp;
        in >> u_temp >> v_temp >> w_temp;
        cost[u_temp][v_temp] = w_temp;
        cost[v_temp][u_temp] = w_temp;
    }
    vector<int> dist(n, 1e9);
    vector<int> prev(n, -1);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u])
            continue;
        for (int v = 0; v < n; v++) {
            if (dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    print_array(dist, out);
    print_array(prev, out);
    find_path(prev, s, e, out);
}

void find_path(vector<int> &prev, int s, int e, ofstream &out) {
    if (e == s) {
        out << s << " ";
        return;
    }
    if (prev[e] == -1) {
        out << "no path" << endl;
        return;
    }
    find_path(prev, s, prev[e], out);
    out << e << " ";
}

void print_array(vector<int> &dist, ofstream &out) {
    for (int i = 0; i < dist.size(); i++) {
        out << dist[i] << " ";
//        out << endl;
    }
    out << endl;
}

int main() {
    ifstream in("./alg7/dijkstra.in");
    ofstream out("./alg7/dijkstra.out");
    dijkstra(in, out);
    return 0;
}
