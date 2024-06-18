#include <bits/stdc++.h>

using namespace std;

struct Item {
    float weight;
    int value;
};

struct Node {
    int level, profit, bound;
    float weight;
    vector<int> items;
};

bool cmp(Item a, Item b) {
    double r1 = (double) a.value / a.weight;
    double r2 = (double) b.value / b.weight;
    return r1 > r2;
}

int bound(Node u, int n, int W, Item arr[]) {
    if (u.weight >= W) return 0;
    int profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;
    while ((j < n) && (totweight + arr[j].weight <= W)) {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }
    if (j < n) profit_bound += (W - totweight) * arr[j].value / arr[j].weight;
    return profit_bound;
}

pair<int, vector<int>> knapsack(Item arr[], int W, int n) {
    sort(arr, arr + n, cmp);
    queue<Node> Q;
    Node u, v;
    u.level = -1;
    u.profit = u.weight = 0;
    Q.push(u);
    int maxProfit = 0;
    vector<int> items;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        if (u.level == -1) v.level = 0;
        if (u.level == n - 1) continue;
        v.level = u.level + 1;
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;
        v.items = u.items;
        if (v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit;
            v.items.push_back(v.level);
            items = v.items;
        }
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit) Q.push(v);
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit) Q.push(v);
    }
    return make_pair(maxProfit, items);
}

int main() {
    Item arr[] = {{2, 20},
                  {5, 30},
                  {7, 35},
                  {3, 12},
                  {1, 3}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int W = 13;
    pair<int, vector<int>> result = knapsack(arr, W, n);
    cout << "Maximum possible profit: " << result.first << "\n";
    cout << "Items included: ";
    for (int i: result.second) {
        cout << i + 1 << " ";
    }
    return 0;
}