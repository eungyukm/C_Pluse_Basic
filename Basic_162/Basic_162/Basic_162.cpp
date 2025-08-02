// C++20
#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

// 팰 클래스
struct FPal
{
    string Name;
    int Level;
    int Exp;

    FPal(string name, int level = 1, int exp = 0)
        : Name(name), Level(level), Exp(exp) {}

    void AddExp(int value)
    {
        Exp += value;
        cout << Name << "가 " << value 
            << " 경험치를 얻었습니다. 총 EXP: " << Exp << '\n';
        // 레벨업 로직 생략 가능
    }
};

// 파티 클래스
class FPalParty
{
public:
    void AddPartyMember(shared_ptr<FPal> pal)
    {
        PartyMembers.push_back(pal);
    }

    void DistributeExp(int totalExp)
    {
        if (PartyMembers.empty())
        {
            return;
        }

        int expPerPal = totalExp / static_cast<int>(PartyMembers.size());
        for (auto& pal : PartyMembers)
        {
            pal->AddExp(expPerPal);
        }
    }

private:
    vector<shared_ptr<FPal>> PartyMembers;
};

// === 예시 ===
int main()
{
    auto pal1 = make_shared<FPal>("파이어팰");
    auto pal2 = make_shared<FPal>("워터팰");
    auto pal3 = make_shared<FPal>("윈드팰");

    FPalParty myParty;
    myParty.AddPartyMember(pal1);
    myParty.AddPartyMember(pal2);
    myParty.AddPartyMember(pal3);

    int droppedExp = 300; // 몬스터로부터 얻은 경험치
    cout << "적 처치! " << droppedExp << " EXP 획득!\n";

    myParty.DistributeExp(droppedExp);

    return 0;
}
