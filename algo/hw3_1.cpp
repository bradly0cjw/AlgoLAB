//
// Created by LINBEI on 6/19/2024.
//
#include <vector>
#include "bits/stdc++.h"

using namespace std;

int combination(int n, int k1, int k2) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i == j || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    if (k1 > n || k2 > n - k1) return 0; // handle the case where k1 or k2 is greater than n or n-k1
    return dp[n][k1] * dp[n - k1][k2];
}

int main() {
    int n, k1, k2;
    n = 10;
    k1 = 2;
    k2 = 3;
//    cin >> n >> k1 >> k2;
    cout << combination(n, k1, k2) << endl;
    n = 2;
    k1 = 3;
    k2 = 2;
    cout << combination(n, k1, k2) << endl;
    n = 3;
    k1 = 3;
    k2 = 2;
    cout << combination(n, k1, k2) << endl;
    return 0;
}