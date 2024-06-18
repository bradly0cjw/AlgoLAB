//
// Created by LINBEI on 6/19/2024.
//
//
// Created by LINBEI on 6/19/2024.
//
#include <vector>
#include <algorithm>
#include <cmath>
#include "iostream"
//wrong answer

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

void radixsortMSD(std::vector<int> &arr, int exp) {
    if (exp < 1 || arr.size() <= 1)
        return;

    std::vector<std::vector<int>> buckets(10);
    for (int i = 0; i < arr.size(); i++)
        buckets[(arr[i] / exp) % 10].push_back(arr[i]);

    for (auto &bucket: buckets)
        radixsortMSD(bucket, exp / 10);

    int index = 0;
    for (auto &bucket: buckets)
        for (int num: bucket)
            arr[index++] = num;
}

int main() {
    std::vector<int> arr = {15, 1, 764, 463, 113, 309, 78, 561, 946, 848, 666, 8, 743, 939, 204, 449};
    int maxVal = *std::max_element(arr.begin(), arr.end());
    int exp = 1;
    while (maxVal / exp > 0)
        exp *= 10;
    radixsortMSD(arr, exp / 10);
    for (int i: arr)
        std::cout << i << " ";
    return 0;
}