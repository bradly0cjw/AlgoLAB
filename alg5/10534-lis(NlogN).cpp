#include <bits/stdc++.h>

using namespace std;

// Define the maximum size of the array
const int MXN = 10001;

// Global variables
int N; // Size of the input array
int l; // Variable used in the LIS and LDS functions
int n[MXN]; // Input array
int seq[MXN]; // Helper array used in the LIS and LDS functions
int L[MXN]; // Array to store the lengths of the longest increasing subsequences
int LR[MXN]; // Array to store the lengths of the longest decreasing subsequences

int binary_search(int arr[], int l, int target) {
    int left = 0;
    int right = l;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

// Function to calculate the length of the longest increasing subsequence
void LIS() {
    memset(seq, 0, sizeof(seq)); // Initialize seq array to 0
    l = 0; // Initialize l to 0
    for (int i = 0; i < N; ++i) {
        int pos = binary_search(seq, l, n[i]); // Find the position to replace in seq
        seq[pos] = n[i]; // Replace the element at pos in seq with n[i]
        L[i] = pos + 1; // Update the length of the longest increasing subsequence ending at i
        if (pos == l) ++l; // If pos is equal to l, increment l
    }
}

// Function to calculate the length of the longest decreasing subsequence
void LDS() {
    memset(seq, 0, sizeof(seq)); // Initialize seq array to 0
    l = 0; // Initialize l to 0
    for (int i = N - 1; i >= 0; --i) {
        int pos = binary_search(seq, l, n[i]); // Find the position to replace in seq
        seq[pos] = n[i]; // Replace the element at pos in seq with n[i]
        LR[i] = pos + 1; // Update the length of the longest decreasing subsequence ending at i
        if (pos == l) ++l; // If pos is equal to l, increment l
    }
}

// Main function
int main() {
    while (cin >> N) { // While there is input
        for (int i = 0; i < N; ++i) {
            cin >> n[i]; // Read the array elements
            L[i] = LR[i] = 1; // Initialize L[i] and LR[i] to 1
        };
        LIS(); // Call the LIS function
        LDS(); // Call the LDS function
        int ans = 1; // Initialize ans to 1
        for (int i = 0; i < N; ++i) {
            ans = max(min(L[i], LR[i]) * 2 - 1, ans); // Calculate the length of the longest "wiggle" subsequence
        };
        cout << ans << '\n'; // Print the result
    }
}