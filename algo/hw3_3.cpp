#include <vector>
#include <limits>
#include <iostream>
#include "bits/stdc++.h"

using namespace std;

void print_dp(std::vector<std::vector<int>> &dp) {
    for (auto &row: dp) {
        for (auto &cell: row) {
            if (cell == std::numeric_limits<int>::max())
                std::cout << "INF" << " ";
            else
                printf("%3d ", cell);
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int MatrixChainOrder(std::vector<int> &dimensions) {
    int n = dimensions.size();

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, std::numeric_limits<int>::max()));

    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < dp[i][j]) {
//                    cout << "cost: " << cost <<" dpik: "<<dp[i][k] <<" dp+1: " <<dp[k+1][j]<< " i: " << i << " j: " << j << " k: " << k << endl;
                    dp[i][j] = cost;
                    print_dp(dp);
                }
            }
        }
    }
    print_dp(dp);
    return dp[1][n - 1];
}

int main() {
    std::vector<int> dimensions = {3, 4, 5, 2, 7, 6};
    int minCost = MatrixChainOrder(dimensions);
    std::cout << "Minimum number of multiplications is " << minCost << std::endl;
    return 0;
}