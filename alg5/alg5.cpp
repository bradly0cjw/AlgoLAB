//
// Created by LINBEI on 4/13/2024.
//
#include "bits/stdc++.h"

using namespace std;

int h(vector<int> a) {
    int len = a.size();
    //binary search
    int l = 0;
    int r = len - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] > a[mid + 1]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int f(vector<int> a) {
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

void show_lis(vector<int> a) {
    int len = a.size();
    vector<int> dp(len, 1);
    vector<int> pre(len, -1);
    for (int i = 1; i < len; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
    }
    int max_index = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> lis;
    while (max_index != -1) {
        lis.push_back(a[max_index]);
        max_index = pre[max_index];
    }
    reverse(lis.begin(), lis.end());
    for (int i = 0; i < lis.size(); i++) {
        cout << lis[i] << " ";
    }
    cout << endl;
}


int main() {
    vector<int> a;
    a = {1, 2, 3, 5, 4, 3, 6, 7, 2, 1};
    cout << h(a) << endl;
    cout << f(a) << endl;
    show_lis(a);
    return 0;
}