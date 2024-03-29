//
// Created by LINBEI on 3/20/2024.
//
#include "bits/stdc++.h"

using namespace std;


int n, x;

//int in[20000000], out[20000000];
int main() {
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        vector<int> in(n), out(n);
        int arr[101] = {0};

        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            in[i] = x;
            arr[x]++;
        }
        x = 0;

        for (int i = 1; i <= 100 && x <= n; i++) {
            arr[i] = arr[i] + arr[i - 1];
        }
        for (int i = 0; i < n; i++) {
            out[arr[in[i]] - 1] = in[i];
            arr[in[i]]--;
        }
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                printf(" ");
            }
            printf("%d", out[i]);
        }

        printf("\n");
    }
    return 0;
}
