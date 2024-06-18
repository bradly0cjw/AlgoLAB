#include <vector>
#include <iostream>

using namespace std;

void sumOfSubsets(std::vector<int> &nums, int target, std::vector<int> &subset, int sum, int remaining, int pos) {
//    cout<<sum<<" "<<remaining<<" "<<sum+remaining <<endl;
    for (int num: subset) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    if (sum == target) {
        cout << "result: ";
        for (int num: subset) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        return;
    }

    if (sum + remaining < target || sum > target) {
        return;
    }

    for (int i = pos; i < nums.size(); i++) {
        subset.push_back(nums[i]);
        sumOfSubsets(nums, target, subset, sum + nums[i], remaining - nums[i], i + 1);
        subset.pop_back();
    }
}

int main() {
    std::vector<int> nums = {2, 10, 13, 17, 22, 42};
    int target = 52;
    std::vector<int> subset;
    int sum = 0;
    int remaining = 0;
    for (int num: nums) {
        remaining += num;
    }
    sumOfSubsets(nums, target, subset, sum, remaining, 0);
    return 0;
}//
// Created by LINBEI on 6/19/2024.
//
