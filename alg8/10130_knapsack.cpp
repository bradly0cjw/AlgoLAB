//
// Created by LINBEI on 5/24/2024.
//
#include "bits/stdc++.h"

using namespace std;

int main() {
//    ifstream in("./alg8/10130.in");
//    ofstream out("./alg8/10130.out");
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int w[1005], v[1005];
        for (int i = 0; i < n; i++)
            cin >> v[i] >> w[i];
        int g;
        cin >> g;
        int mw[105];
        for (int i = 0; i < g; i++)
            cin >> mw[i];
        int dp[1005][35] = {};
        for (int i = 0; i < n; i++)
            dp[i][0] = 0;
        for (int i = 0; i < 35; i++)
            dp[0][i] = (w[0] <= i) ? v[0] : 0;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < 35; j++) {
                if (w[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i < g; i++)
            ans += dp[n - 1][mw[i]];
        cout << ans << endl;
    }
    return 0;
}