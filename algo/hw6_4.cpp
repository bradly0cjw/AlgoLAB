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

void heapSort(vector<int> &arr) {
    int n = arr.size();

    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
        cout << "[ ";
        for (int j: arr)
            cout << j << " ";
        cout << "] After heapify at index " << i << "\n";
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);

        cout << "[ ";
        for (int j = 0; j < n; j++)
            cout << arr[j] << " ";
        switch (n - i) {
            case 1:
                cout << "] After 1st iteration \n";
                break;
            case 2:
                cout << "] After 2nd iteration \n";
                break;
            case 3:
                cout << "] After 3rd iteration \n";
                break;
            default:
                cout << "] After " << n - i << "th iteration \n";
                break;
        }
    }
}

int main() {
    vector<int> arr = {5, 4, 2, 1, 6, 8, 3, 7};

    heapSort(arr);

    return 0;
}