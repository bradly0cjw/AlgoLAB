//
// Created by LINBEI on 6/6/2024.
//
#include <bits/stdc++.h>

using namespace std;
//#define in cin
//#define out cout

int main() {
    ifstream in("./alg10/10382.in");
    ofstream out("./alg10/10382.out");
    int n;
    double l, w;
    while (in >> n >> l >> w) {
        vector<pair<double, double>> v;
        for (int i = 0; i < n; i++) {
            int x, r;
            in >> x >> r;
            if (r * 2 >= w) {
                double d = sqrt(r * r - w * w / 4);
                v.push_back({x - d, x + d});
            }
        }
        sort(v.begin(), v.end());
        int ans = 0;
        int i = 0;
        int j = 0;
        double cur = 0;
        while (i < v.size() && cur < l) {
            double r = cur;
            while (j < v.size() && v[j].first <= cur) {
                r = max(r, v[j].second);
                j++;
            }
            if (r == cur) {
                break;
            }
            cur = r;
            ans++;
            i = j;
        }
        if (cur < l) {
            out << -1 << endl;
        } else {
            out << ans << endl;
        }
    }
    return 0;
}
