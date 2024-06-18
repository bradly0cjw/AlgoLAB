#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void printArray(const std::vector<int> &arr) {
    for (int num: arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int findMedian(std::vector<int> &arr) {
    std::sort(arr.begin(), arr.end());
    return arr[arr.size() / 2];
}

int MoM(std::vector<int> &arr, int k) {
    if (arr.size() <= 5)
        return findMedian(arr);

    std::vector<int> medians;
    for (int i = 0; i < arr.size(); i += 5) {
        std::vector<int> group(arr.begin() + i, arr.begin() + std::min(i + 5, (int) arr.size()));
        medians.push_back(findMedian(group));
    }

    int mom = MoM(medians, medians.size() / 2 + 1);

    std::vector<int> left, mid, right;
    for (int num: arr) {
        if (num < mom)
            left.push_back(num);
        else if (num > mom)
            right.push_back(num);
        else
            mid.push_back(num);
    }

    std::cout << "Left: ";
    printArray(left);
    std::cout << "Mid: ";
    printArray(mid);
    std::cout << "Right: ";
    printArray(right);

    if (k <= left.size())
        return MoM(left, k);
    else if (k <= left.size() + mid.size())
        return mom;
    else
        return MoM(right, k - left.size() - mid.size());
}

int main() {
    std::vector<int> arr = {34, 11, 26, 32, 9, 1, 23, 29, 24, 30, 25, 21, 3, 33, 18, 28, 35, 16, 12, 2, 4, 19, 14, 27,
                            10, 13, 6, 5, 8, 31, 22, 15, 20, 7, 17};
    int result = MoM(arr, 7);
    std::cout << "The 7th smallest number is " << result << std::endl;
    return 0;
}