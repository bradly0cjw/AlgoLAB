//
// Created by LINBEI on 4/26/2024.
//
#include "bits/stdc++.h"

using namespace std;

vector<int> LIS(vector<int> a) {
    int len = a.size();
    vector<int> dp(len, 1);
    for (int i = 1; i < len; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp;
}

int main() {
    int a, t;
    while (cin >> a) {
        vector<int> lis, lds;
        vector<int> v;
        for (int i = 0; i < a; i++) {
            cin >> t;
            v.push_back(t);
        }
//        for(int i=0;i<a;i++){
//            cout<<v[i]<<" ";
//        }
//        cout<<endl;
        lis = LIS(v);
        reverse(v.begin(), v.end());
        lds = LIS(v);
        int ans = 0;
        for (int i = 0; i < a; i++) {
            ans = max(ans, min(lis[i], lds[a - i - 1]));
        }
        cout << 2 * ans - 1 << endl;
    }
    return 0;
}