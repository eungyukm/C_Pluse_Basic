// C++20
#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Pal
{
    string name;

    void UseUniqueSkill()
    {
        cout << name << " used its unique skill!" << endl;
    }
};

struct Player
{
    shared_ptr<Pal> partner;

    void TriggerPartnerSkill()
    {
        if (partner)
        {
            partner->UseUniqueSkill();
        }
        else
        {
            cout << "No partner assigned!" << endl;
        }
    }
};
int main()
{
    Player player;
    // make_shared는 c++의 스마트 포인터
    player.partner = make_shared<Pal>(Pal{ "Pengullet" });

    // 파트너의 팰의 고유 스킬 자동 발동
    player.TriggerPartnerSkill();
    return 0;
}
