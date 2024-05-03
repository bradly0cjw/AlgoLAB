//
// Created by LINBEI on 5/3/2024.
//
#include "bits/stdc++.h"

using namespace std;

int main() {
//    ifstream in("./alg6/558.in");
//    ofstream out("./alg6/558.out");
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> u(m), v(m), w(m);
        for (int i = 0; i < m; i++)
            cin >> u[i] >> v[i] >> w[i];
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < m; j++)
                if (dist[u[j]] + w[j] < dist[v[j]])
                    dist[v[j]] = dist[u[j]] + w[j];
        bool neg_cycle = false;
        for (int i = 0; i < m; i++)
            if (dist[u[i]] + w[i] < dist[v[i]])
                neg_cycle = true;
        cout << (neg_cycle ? "possible" : "not possible") << endl;
    }
    return 0;
}