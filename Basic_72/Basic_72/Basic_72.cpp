#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int U, vector<int>& weight) {
    int n = weight.size();
    int result = n;

    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> selected;
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0) {
                selected.push_back(weight[i]); // 되돌아가지 않는 차량만 사용
            }
        }

        queue<int> bridge;
        int sum = 0;
        bool valid = true;

        for (int w : selected) {
            // 다리 위에 차량이 2대 이상이면 가장 먼저 들어간 차량부터 내림
            if (bridge.size() == 2) {
                sum -= bridge.front();
                bridge.pop();
            }

            // 새로운 차량이 올라올 수 있는지 확인
            if (sum + w > U) {
                valid = false;
                break;
            }

            bridge.push(w);
            sum += w;
        }

        if (valid) {
            int turnedBack = n - selected.size();
            result = min(result, turnedBack);
        }
    }

    return result;
}


int main() {
    vector<int> weight = { 5, 3, 8, 1, 8, 7, 7, 6 };
    int U = 9;
    cout << solution(U, weight) << endl; // 결과: 4

    vector<int> weight2 = { 7, 6, 5, 2, 7, 4, 5, 4};
    int U2 = 7;
    cout << solution(U2, weight) << endl; // 결과: 5

    vector<int> weight3 = { 3, 7, 5, 5, 6, 3, 9, 10, 8, 4};
    int U3 = 2;
    cout << solution(U3, weight) << endl; // 결과: 10
}

