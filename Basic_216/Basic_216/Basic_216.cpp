// C++20
#include <iostream>
#include <string>
using namespace std;

enum class GateState { Open, Sealed };

struct Dungeon
{
    GateState gate = GateState::Open;
    bool bossStarted = false;
    int playersInside = 0;

    void EnterPlayer()
    {
        playersInside++;
        cout << "입장: " << playersInside << "명" << endl;
    }

    void StartBoss()
    {
        bossStarted = true;
        gate = GateState::Sealed;
        cout << "보스전 시작! 문 보쇄" << endl;
    }

    void EndBoss(bool cleared)
    {
        bossStarted = false;
        gate = GateState::Open;
        cout << (cleared ? "보스 처치!" : "전투 중단!") << " 문 개방"
            << endl;
    }

    bool CanEnter() const
    {
        return gate == GateState::Open && bossStarted == false;
    }

    bool CanExit() const
    {
        return gate == GateState::Open;
    }
};

int main()
{
    Dungeon d;

    if (d.CanEnter()) d.EnterPlayer();
    if (d.CanEnter()) d.EnterPlayer();

    d.StartBoss();

    cout << "퇴장 가능? " << (d.CanExit() ? "예" : "아니오") << "\n";

    d.EndBoss(true);

    cout << "퇴장 가능? " << (d.CanExit() ? "예" : "아니오") << "\n";
    return 0;
}
