#include <iostream>
#include <queue>
#include <string>

using namespace std;

// 숫자 크기로 string을 비교하는 커스텀 함수
struct Compare {
    bool operator()(const string& a, const string& b) const {
        if (a.size() != b.size()) return a.size() > b.size(); // 자리수 비교
        return a > b; // 자리수 같으면 사전순 비교
    }
};

long long findUnluckyNumber(int n) {
    priority_queue<string, vector<string>, Compare> minHeap;

    minHeap.push("4");
    minHeap.push("13");

    string current;
    for (int i = 0; i < n; ++i) {
        current = minHeap.top();
        minHeap.pop();

        minHeap.push(current + "4");
        minHeap.push(current + "13");
    }

    return stoll(current); // 최종 결과를 long long으로
}

int main() {
    int n;
    cin >> n;
    cout << findUnluckyNumber(n) << endl;
    return 0;
}
