//
// Created by LINBEI on 4/26/2024.
//
#include "bits/stdc++.h"

using namespace std;

int LIS(vector<int> a) {
    int len = a.size();
    vector<int> dp(len, 1);
    for (int i = 1; i < len; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int a, t, lis, lds;
    while (cin >> a) {
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
        cout << min(lis, lds) * 2 - 1 << endl;
    }
    return 0;
}