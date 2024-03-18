//
// Created by LINBEI on 3/19/2024.
//
#include <bits/stdc++.h>

using namespace std;

int binary_search(int *A, int key, int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == key) return mid;
        if (A[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 5;
    int n = sizeof(A) / sizeof(A[0]);
    int index = binary_search(A, key, n);
    if (index != -1) cout << "Found at index " << index << endl;
    else cout << "Not found" << endl;
    return 0;
}