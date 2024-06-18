#include <vector>
#include <algorithm>
#include <iostream>

void countingSort(std::vector<int> &arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10);

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsortLSD(std::vector<int> &arr) {
    int maxVal = *std::max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main() {
    std::vector<int> arr = {15, 1, 764, 463, 113, 309, 78, 561, 946, 848, 666, 8, 743, 939, 204, 449};
    radixsortLSD(arr);
    for (int i: arr)
        std::cout << i << " ";
    return 0;
}