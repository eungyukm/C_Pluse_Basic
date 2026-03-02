// C++20
#include <iostream>
using namespace std;

struct Player
{
    string name{ "모험가" };
    int fatigue{ 5 };      // 0(휴식) ~ 10(피곤)
    bool isSitting{ false };
};

struct Chair
{
    bool occupied{ false };

    bool Sit(Player& p)
    {
        if (occupied || p.isSitting)
        {
            cout << "이미 누군가 앉아있습니다.\n";
            return false;
        }
        occupied = true;
        p.isSitting = true;
        cout << p.name << " 앉음. 휴식 시작" << endl;
        return true;
    }

    bool RestTick(Player& p)
    {
        if (!occupied || !p.isSitting)
        {
            return false;
        }

        if (p.fatigue <= 0)
        {
            cout << "완전 회복! 더 이상 휴식이 필요 없습니다."
                << endl;
            StandUp(p);
            return false;
        }
        p.fatigue--;
        cout << "피로도 회복! 남은 피로도: " << p.fatigue << endl;
        return true;
    }

    void StandUp(Player& p)
    {
        if (!p.isSitting) return;
        p.isSitting = false;
        occupied = false;
        cout << p.name << " 일어섰습니다.\n";
    }
};

int main()
{
    Player you{ "생활 장인", 4 };
    Chair chair;

    if (chair.Sit(you))
    {
        while (chair.RestTick(you)) { /* 휴식 틱 진행 */ }
    }
    return 0;
}
