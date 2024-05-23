//
// Created by LINBEI on 5/24/2024.
//
#include "bits/stdc++.h"
//#define out cout
//#define in cin
using namespace std;

void print_array(vector<int> &dp, ofstream &out) {
    for (int i = 0; i < dp.size(); i++)
        out << dp[i] << " ";
    out << endl;
}

int main() {
    ifstream in("./alg9/10465.in");
    ofstream out("./alg9/10465.out");
    int m, n, t;
    while (in >> m >> n >> t) {
        vector<int> dp(t + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= t; i++) {
            if (i >= m && dp[i - m] != -1)
                dp[i] = dp[i - m] + 1;
            if (i >= n && dp[i - n] != -1)
                dp[i] = max(dp[i], dp[i - n] + 1);
//            print_array(dp, out);
        }
        if (dp[t] != -1)
            out << dp[t] << endl;
        else {
            for (int i = t - 1; i >= 0; i--) {
                if (dp[i] != -1) {
                    out << dp[i] << " " << t - i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
