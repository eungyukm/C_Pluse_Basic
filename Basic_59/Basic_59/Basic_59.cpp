#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long findUnluckyNumber(int n) {
    vector<long long> dp(20, 0);
    dp[1] = 1; // 4
    dp[2] = 1; // 13
    for (int i = 3; i < 20; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2]; // 피보나치 유사 점화식
    }

    long long total = 0;
    int len = 0;
    for (int i = 1; i < 20; ++i) {
        if (total + dp[i] >= n) {
            len = i;
            break;
        }
        total += dp[i];
    }
    n -= total;
    if (n <= 0) n = 1;

    string result;
    while (len > 0) {
        if (len == 1) {
            result += '4';
            break;
        }
        if (len == 2) {
            result += "13";
            break;
        }
        if (n <= dp[len - 1]) {
            result += '4';
            len -= 1;
        }
        else {
            result += "13";
            n -= dp[len - 1];
            len -= 2;
        }
    }

    return stoll(result);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    cout << findUnluckyNumber(n) << endl;
    return 0;
}