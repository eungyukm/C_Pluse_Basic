#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int GetMaxSquareArea(vector<vector<bool>>& map) {
        int rowCount = map.size();
        int colCount = map[0].size();

        vector<vector<int>> maxSquareEndingHere(rowCount, vector<int>(colCount, 0));
        vector<pair<int, int>> squareTopLeftBySize[301];  // 최대 크기 가정: 300

        // 각 셀에서 끝나는 가장 큰 정사각형 한 변의 길이 계산
        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < colCount; ++col) {
                if (!map[row][col]) continue;

                if (row == 0 || col == 0)
                    maxSquareEndingHere[row][col] = 1;
                else
                    maxSquareEndingHere[row][col] = min({
                        maxSquareEndingHere[row - 1][col],
                        maxSquareEndingHere[row][col - 1],
                        maxSquareEndingHere[row - 1][col - 1]
                        }) + 1;

                int squareSize = maxSquareEndingHere[row][col];
                squareTopLeftBySize[squareSize].emplace_back(row - squareSize + 1, col - squareSize + 1);
            }
        }

        // 큰 정사각형부터 겹치지 않는 2개가 있는지 확인
        for (int size = min(rowCount, colCount); size >= 1; --size) {
            const auto& positions = squareTopLeftBySize[size];
            if (positions.size() < 2) continue;

            for (size_t i = 0; i < positions.size(); ++i) {
                for (size_t j = i + 1; j < positions.size(); ++j) {
                    auto [top1, left1] = positions[i];
                    auto [top2, left2] = positions[j];

                    bool isOverlapping = !(
                        top1 + size <= top2 || top2 + size <= top1 ||
                        left1 + size <= left2 || left2 + size <= left1
                        );

                    if (!isOverlapping)
                        return size * size;
                }
            }
        }

        return 0;
    }
};
