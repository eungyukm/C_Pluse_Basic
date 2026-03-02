// C++20
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Player
{
    string Name;
    bool InParty = false;
};

struct Party
{
    vector<Player*> Members;

    void Add(Player* p)
    {
        if (p == nullptr || p->InParty)
            return;
        Members.push_back(p);
        p->InParty = true;
        cout << "[Party] " << p->Name << " 가입\n";
    }

    void Print()
    {
        cout << "[Party] 멤버: ";
        for (int i = 0; i < (int)Members.size(); i++) 
            cout << Members[i]->Name 
            << (i + 1 < (int)Members.size() ? ", " : "\n");
    }
};

struct Invite
{
    Player* From;
    Player* To;
    Party* TargetParty;
    bool Active = true;

    void Accept()
    {
        if (!Active)
            return;
        Active = false;
        cout << "[Invite] " << To->Name << "수락" << endl;
        TargetParty->Add(To);
    }

    void Decline()
    {
        if (!Active)
            return;

        Active = false;
        cout << "[Invite] " << To->Name << "거절" << endl;
    }
};

int main()
{
    Player a{ "Alice" }, b{ "Bob" };
    Party party;
    party.Add(&a); // Alice가 파티 리더라고 가정

    Invite inv{ &a, &b, &party };
    cout << "[System] " << a.Name << " → " 
        << b.Name << " 파티 초대\n";

    inv.Accept();   // 수락 시 파티 가입
    party.Print();

    return 0;
}
