//
// Created by LINBEI on 3/19/2024.
//
#include "bits/stdc++.h"

using namespace std;


int main() {
    int test;
    double pi = acos(-1);
    cin >> test;
    for (int x = 0; x < test; x++) {
        int pie, person;
        cin >> pie >> person;
        double arr[pie];
        double max = 0;
        for (int i = 0; i < pie; i++) {
            cin >> arr[i];
            arr[i] = arr[i] * arr[i];
            max = std::max(arr[i], max);
        }
        double left = 0, right = max;
        while (right - left > 0.00001) {
            double mid = (left + right) / 2;
            int count = 0;
            for (int i = 0; i < pie; i++) {
                count += (int) (arr[i] / mid);
            }
            if (count > person) left = mid;
            else right = mid;
        }
        cout.precision(4);
        cout << fixed << pi * left << endl;
    }
    return 0;
}
