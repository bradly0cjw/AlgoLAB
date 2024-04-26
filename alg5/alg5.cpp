//
// Created by LINBEI on 4/13/2024.
//
#include "bits/stdc++.h"

using namespace std;

void h2(vector<int> a) {
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
    int max_index = len - 1;
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

int h3(vector<int> &a) {
    vector<int> tails(a.size(), 0);
    int length = 1;

    tails[0] = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < tails[0]) {
            tails[0] = a[i];
        } else if (a[i] > tails[length - 1]) {
            tails[length++] = a[i];
        } else {
            int l = -1, r = length - 1;
            while (r - l > 1) {
                int m = l + (r - l) / 2;
                if (tails[m] >= a[i]) r = m;
                else l = m;
            }
            tails[r] = a[i];
        }
    }

    while (tails[length - 1] > a[a.size() - 1]) {
        tails.pop_back();
        length--;
    }
    return length;
}

int h(vector<int> a) {
    int len = a.size();
    //binary search
    int l = 0;
    int r = len - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        int count = 1;
        bool flag = false;
        for (int i = 1; i < a.size(); i++) {
            if (a[i - 1] <= a[i]) {
                count++;
            } else {
                count = 1;
            }
            if (count > mid) {
                flag = true;
                break;
            }
        }
        if (!flag) {
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
//    a = {1, 2, 2, 6, 2, 2, 2, 2};
    h3(a);
    cout << h(a) << endl;
    cout << f(a) << endl;
    show_lis(a);
    return 0;
}
