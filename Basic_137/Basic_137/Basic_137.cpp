// C++20
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Pal
{
    string name;

    Pal(const string& n) : name(n) {}
};

int main()
{
    queue<Pal> hotSpringQueue;

    // 팰들이 도착
    hotSpringQueue.push(Pal("Pengullet"));
    hotSpringQueue.push(Pal("Foxparks"));
    hotSpringQueue.push(Pal("Lamball"));

    // 온천 사용
    while (!hotSpringQueue.empty())
    {
        Pal pal = hotSpringQueue.front();
        hotSpringQueue.pop();

        cout << pal.name << " is using the hot spring." << endl;
    }
    return 0;
}