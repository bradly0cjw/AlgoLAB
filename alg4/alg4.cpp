//
// Created by LINBEI on 4/26/2024.
//
#include "bits/stdc++.h"

using namespace std;


#include <iostream>

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}


void countSort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n) {
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void aggregateAndSort(int a[], int na, int b[], int nb, int c[], int nc, int d[], int nd) {
    int total = na + nb + nc + nd;
    int result[total];

    memcpy(result, a, na * sizeof(int));
    memcpy(result + na, b, nb * sizeof(int));
    memcpy(result + na + nb, c, nc * sizeof(int));
    memcpy(result + na + nb + nc, d, nd * sizeof(int));

    radixsort(result, total);

    for (int i = 0; i < total; i++) {
        cout << result[i] << " ";
    }
}


int main() {
    return 0;
}