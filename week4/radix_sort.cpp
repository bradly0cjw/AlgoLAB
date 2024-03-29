//
// Created by LINBEI on 3/29/2024.
//
#include "bits/stdc++.h"

using namespace std;

void print(int *A, int n);

void sort_by_digit(int *A, int n, int r, int p) {
    int base = 1;
    while (p > 0) {
        --p;
        base *= r;
    }
    int count[r], B[n], m = 0;
    for (int j = 0; j < r; ++j)
        count[j] = 0;
    for (int i = 0; i < n; ++i)
        count[(A[i] / base) % r]++;
    for (int j = 0, psum = 0, sum = 0; j < r; ++j) {
        psum = sum;
        sum += count[j];
        count[j] = psum;
    }
    for (int i = 0; i < n; ++i)
        B[count[(A[i] / base) % r]++] = A[i];
    for (int i = 0; i < n; ++i)
        A[i] = B[i];
}

void radix_sort_lsb(int *A, int n, int r, int d) {
    for (int i = 0; i < d; ++i) {
        sort_by_digit(A, n, r, i);
        print(A, n);
    }
    cout << endl;
}

void radix_sort_msb(int *A, int n, int r, int d) {
    for (int i = d - 1; i >= 0; --i) {
        sort_by_digit(A, n, r, i);
        print(A, n);
    }
    cout << endl;
}

int min_usable_digit(int *A, int n, int r) {
    int max = A[0];
    for (int i = 1; i < n; ++i)
        if (A[i] > max)
            max = A[i];
    int count = 0;
    while (max > 0) {
        max /= r;
        count++;
    }
    return count;
}

void print(int *A, int n) {
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
}

int main() {
    int Arr[] = {170, 45, 75, 74, 90, 802, 24, 2, 66};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    int d = min_usable_digit(Arr, n, 10);
    cout << d << endl;
    radix_sort_lsb(Arr, n, 10, d);
    int Arr2[] = {170, 45, 75, 74, 90, 802, 24, 2, 66};
    radix_sort_msb(Arr2, n, 10, d);//wrong answer
    return 0;
}
