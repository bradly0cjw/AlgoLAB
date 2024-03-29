#include <bits/stdc++.h>
using namespace std;

int *sort(int *A, int n) {
// index i divide A[] to 2 partitions
// A[0…i-1] are sorted, A[i…n-1] are unsorted
    for (int i = 1; i < n; ++i) {
        int j = i, val = A[j],count = 1;
        while (j > 0 && !(A[j - 1] <= val)) {
            A[j] = A[j - 1];
            --j;
            count++;
        }
        cout << count << endl;
        A[j] = val;
    }
    return A;
}
