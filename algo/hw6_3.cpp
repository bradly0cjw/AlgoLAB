//
// Created by LINBEI on 6/19/2024.
//
#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void printHeap(const vector<int> &arr) {
    for (int i: arr)
        cout << i << " ";
    cout << "\n";
}

int main() {
    vector<int> arr = {5, 4, 2, 1, 6, 8, 3, 7};
    int n = arr.size();

    cout << "Original array:\n";
    printHeap(arr);

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
        cout << "Heap after heapify at index " << i << ":\n";
        printHeap(arr);
    }

    return 0;
}