#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

bool IsValid(const vector<int>& arr, int k) {
    for (size_t i = 0; i + 1 < arr.size(); ++i) {
        if (abs(arr[i] - arr[i + 1]) > k) {
            return false;
        }
    }
    return true;
}

int MinSwaps(vector<int> arr, int k) {
    queue<pair<vector<int>, int>> q;
    set<vector<int>> visited;

    q.push({ arr, 0 });
    visited.insert(arr);

    while (!q.empty()) {
        auto [current, swaps] = q.front();
        q.pop();

        if (IsValid(current, k)) {
            return swaps;
        }

        int n = current.size();
        // 모든 가능한 쌍 swap
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<int> next = current;
                swap(next[i], next[j]);

                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push({ next, swaps + 1 });
                }
            }
        }
    }

    return -1;
}

int main() {
    vector<int> numbers = { 3, 7, 2, 8, 6, 4, 5, 1 };
    int k = 3;

    cout << MinSwaps(numbers, k) << endl;
    return 0;
}
