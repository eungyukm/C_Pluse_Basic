// C++20
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Player
{
    int id;
    string name;
    vector<string> inbox;

    void ReceiveParty(int fromId, const string& text)
    {
        inbox.push_back("[" + to_string(fromId) + "] " + text);
    }
};

struct Party
{
    vector<Player*> members;

    void Join(Player* p)
    {
        if (!p) return;
        members.push_back(p);
    }

    bool SendParty(Player* sender, const string& msg)
    {
        if (!sender) return false;
        if (msg.empty() || msg.size() > 200) return false;

        auto canReceive = [&](Player* p)
            {
                if (!p) return false;
                return true;
            };

        for (int i = 0; i < (int)members.size(); i++)
        {
            Player* p = members[i];
            if (!canReceive(p)) continue;
            p->ReceiveParty(sender->id, msg);
        }
        return true;
    }
};

int main()
{
    Player a{ 1, "Archer" };
    Player b{ 2, "Warrior" };

    Party party;
    party.Join(&a);
    party.Join(&b);
    
    party.SendParty(&a, "Field boss at 3 oclock");

    for (int i = 0; i < (int)party.members.size(); i++)
    {
        Player* p = party.members[i];
        cout << p->name << " inbox\n";
        for (int j = 0; j < (int)p->inbox.size(); j++)
        {
            cout << "  " << p->inbox[j] << "\n";
        }
    }
    return 0;
}
