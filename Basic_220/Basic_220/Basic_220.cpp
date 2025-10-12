// C++20
#include <iostream>
using namespace std;

struct Player
{
    int fatigue = 100;

    bool CanGather() const
    {
        return fatigue > 0;
    }

    void TryGather()
    {
        if (CanGather())
        {
            fatigue -= 10;
            cout << "채집 성공! 남은 피로도: " << fatigue << endl;
        }
        else
        {
            cout << "피로도가 부족합니다." << endl;
        }
    }
};

int main()
{
    Player p;

    for (int i = 0; i < 12; i++)
    {
        p.TryGather();
    }
    return 0;
}
