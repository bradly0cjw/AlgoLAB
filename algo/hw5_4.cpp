//
// Created by LINBEI on 6/19/2024.
//

#include <vector>
#include <algorithm>
#include <iostream>

struct Item {
    int profit;
    int weight;
    float ratio;
};

bool promising(int i, int profit, int weight, std::vector<Item> &items, int W);

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

void knapsack(int i, int profit, int weight, std::vector<Item> &items, int W, std::vector<bool> &include,
              std::vector<bool> &bestSet, int &maxProfit) {
    if (weight <= W && profit > maxProfit) {
        maxProfit = profit;
        bestSet = include;
    }

    if (promising(i, profit, weight, items, W)) {
        include[i + 1] = true;
        knapsack(i + 1, profit + items[i + 1].profit, weight + items[i + 1].weight, items, W, include, bestSet,
                 maxProfit);
        include[i + 1] = false;
        knapsack(i + 1, profit, weight, items, W, include, bestSet, maxProfit);
    }
}

bool promising(int i, int profit, int weight, std::vector<Item> &items, int W) {
    if (weight >= W) {
        return false;
    }

    int j = i + 1;
    int bound = profit;
    int totalWeight = weight;

    while (j < items.size() && totalWeight + items[j].weight <= W) {
        totalWeight += items[j].weight;
        bound += items[j].profit;
        j++;
    }

    if (j < items.size()) {
        bound += (W - totalWeight) * items[j].ratio;
    }

    return bound > profit;
}

int main() {
    std::vector<Item> items = {{20, 2, 10},
                               {30, 5, 6},
                               {35, 7, 5},
                               {12, 3, 4},
                               {3,  1, 3}};
    std::sort(items.begin(), items.end(), compare);
    int W = 9;
    std::vector<bool> include(items.size(), false);
    std::vector<bool> bestSet(items.size(), false);
    int maxProfit = 0;
    knapsack(-1, 0, 0, items, W, include, bestSet, maxProfit);

    std::cout << "Max profit: " << maxProfit << std::endl;
    std::cout << "Items included: ";
    for (int i = 0; i < bestSet.size(); i++) {
        if (bestSet[i]) {
            std::cout << i + 1 << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
