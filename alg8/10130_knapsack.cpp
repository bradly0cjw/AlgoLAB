//
// Created by LINBEI on 5/24/2024.
//
#include "bits/stdc++.h"

using namespace std;
#define out cout
#define in cin

void print_matrix(vector<vector<int>> &dp, ofstream &out) {
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++)
            out << dp[i][j] << " ";
        out << endl;
    }
    out << endl;
}

int main() {
//    ifstream in("./alg8/10130.in");
//    ofstream out("./alg8/10130.out");
    int t;
    in >> t;
    while (t--) {
        int n;
        in >> n;
        vector<int> w(n), v(n);
        for (int i = 0; i < n; i++)
            in >> v[i] >> w[i];
        int g;
        in >> g;
        vector<int> mw(g);
        for (int i = 0; i < g; i++)
            in >> mw[i];
        vector<vector<int>> dp(n, vector<int>(30, 0));
        for (int i = 0; i < 30; i++)
            dp[0][i] = (w[0] <= i) ? v[0] : 0;
//        print_matrix(dp, out);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < 30; j++) {
                if (w[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
//            print_matrix(dp, out);
        }
        int ans = 0;
        for (int i = 0; i < g; i++)
            ans += dp[n - 1][mw[i]];
        out << ans << endl;
    }
    return 0;
}