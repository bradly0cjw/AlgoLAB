//
// Created by LINBEI on 5/10/2024.
//
#include "bits/stdc++.h"

using namespace std;

int main() {
//    ifstream in("./alg7/10986.in");
//    ofstream out("./alg7/10986.out");
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, m, s, e;
        cin >> n >> m >> s >> e;
        vector<int> u, v, w;
        for (int l = 0; l < m; l++) {
            int u_temp, v_temp, w_temp;
            cin >> u_temp >> v_temp >> w_temp;
            u.push_back(u_temp);
            v.push_back(v_temp);
            w.push_back(w_temp);
            u.push_back(v_temp);
            v.push_back(u_temp);
            w.push_back(w_temp);
        }
        vector<int> dist(n, 1e9);
        dist[s] = 0;
        for (int k = 0; k < n - 1; k++)
            for (int j = 0; j < u.size(); j++)
                if (dist[u[j]] + w[j] < dist[v[j]])
                    dist[v[j]] = dist[u[j]] + w[j];
        cout << "Case #" << i << ": ";
        if (dist[e] == 1e9)
            cout << "unreachable" << endl;
        else
            cout << dist[e] << endl;
    }
    return 0;
}
