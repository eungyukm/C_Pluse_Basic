// C++20
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Pal
{
    string name;
    bool isNocturnal;

    Pal(const string& n, bool nocturnal) : name(n), isNocturnal(nocturnal) {}
};

// 낮/밤 체크 함수 (간단히 예시로 사용)
bool IsNight()
{
    // 실제 게임이라면 현재 시간 체크로 교체
    return true; // 지금은 밤이라고 가정
}

int main()
{
    queue<Pal> hotSpringQueue;

    // 팰들이 도착 (야행성 팰 포함)
    hotSpringQueue.push(Pal("Pengullet", false));
    hotSpringQueue.push(Pal("Foxparks", true));
    hotSpringQueue.push(Pal("Lamball", false));

    // 온천 사용 처리
    while (!hotSpringQueue.empty())
    {
        Pal pal = hotSpringQueue.front();
        hotSpringQueue.pop();

        if (IsNight() && !pal.isNocturnal)
        {
            cout << pal.name << " is resting at night." << endl;
            continue;
        }

        cout << pal.name << " is using the hot spring." << endl;
    }
    return 0;
}
