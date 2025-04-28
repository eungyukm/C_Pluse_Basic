#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAX_COUNT = 5000;

vector<long long> GenerateUnhappyNumbers(int count) {
    vector<long long> unhappyNumbers;
    queue<long long> generationQueue;

    generationQueue.push(4);
    generationQueue.push(13);

    while (static_cast<int>(unhappyNumbers.size()) < count) {
        long long current = generationQueue.front();
        generationQueue.pop();

        unhappyNumbers.push_back(current);

        if (static_cast<int>(unhappyNumbers.size()) < count) {
            generationQueue.push(current * 100 + 4);
            generationQueue.push(current * 100 + 13);
        }
    }

    return unhappyNumbers;
}

int main() {
    vector<long long> unhappyNumbers;

    try {
        unhappyNumbers = GenerateUnhappyNumbers(MAX_COUNT);
    }
    catch (const exception& e) {
        cerr << "Error generating numbers: " << e.what() << endl;
        return 1;
    }

    int n;
    if (!(cin >> n) || cin.peek() != '\n') {
        cerr << "Error: Invalid input. Please enter a single number." << endl;
        return 1;
    }

    if (n <= 0 || n > MAX_COUNT) {
        cerr << "Error: Input must be between 1 and " << MAX_COUNT << "." << endl;
        return 1;
    }

    cout << unhappyNumbers[n - 1] << '\n';

    return 0;
}
