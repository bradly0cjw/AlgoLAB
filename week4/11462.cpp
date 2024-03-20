//
// Created by LINBEI on 3/20/2024.
//
#include "bits/stdc++.h"

using namespace std;


int n, x, arr[101];

int main() {
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            arr[x]++;
        }
        x = 0;
        for (int i = 1; i <= 100 && x <= n; i++) {
            while (arr[i] != 0) {
                if (x != 0) {
                    printf(" ");
                }
                x++, arr[i]--;
                printf("%d", i);
            }
        }
        printf("\n");
    }
    return 0;
}
