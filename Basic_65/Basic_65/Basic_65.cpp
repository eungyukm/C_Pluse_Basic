// C++17
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

struct Vector2
{
    float x;
    float y;
};

struct PlayerState
{
    int id;
    Vector2 position;
};

void SendSnapshot(const vector<PlayerState>& players)
{
    cout << "[Server Snapshot]" << endl;
    for (const auto& player : players)
    {
        cout << "Player " << player.id
            << " - Pos: (" << player.position.x << ", "
            << player.position.y << ")" << endl;
    }
    cout << endl;
}

int main()
{
    vector<PlayerState> players = {
        {1, {0.0f, 0.0f}},
        {2, {5.0f, 0.0f}}
    };

    for (int tick = 0; tick < 10; ++tick)
    {
        // 위치 업데이트 (단순 이동)
        for (auto& player : players)
        {
            // 오른쪽으로 이동
            player.position.x += 0.5f;
        }

        SendSnapshot(players);
        // 0.1초 간격
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    return 0;
}
