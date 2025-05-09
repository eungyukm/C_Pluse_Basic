#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Unit {
    string name;
    string role; // "tank", "dps"
};

const int ROWS = 4;
const int COLS = 7;

// 유닛 배치 알고리즘
// tanks는 0행, 왼쪽부터
// dps는 마지막 행, 오른쪽부터
void PlaceUnits(const vector<Unit>& units, 
    vector<vector<string>>& board) 
{
    int front = 0;
    int back = COLS - 1;

    for (const auto& u : units)
    {
        int row = (u.role == "tank") ? 0 : ROWS - 1;
        int col = (u.role == "tank") ? front++ : back--;
        board[row][col] = u.name;
    }
}

void PrintBoard(const vector<vector<string>>& board) 
{
    for (const auto& row : board) 
    {
        for (const auto& cell : row)
        {
            cout << (cell.empty() ? "." : cell.substr(0, 1)) << " ";
        }
        cout << '\n';
    }
}

int main() {
    vector<Unit> units = {
        {"Garen", "tank"},
        {"Leona", "tank"},
        {"Ashe", "dps"},
        {"Lux", "dps"}
    };

    vector<vector<string>> board(ROWS, vector<string>(COLS));
    PlaceUnits(units, board);
    PrintBoard(board);
}
