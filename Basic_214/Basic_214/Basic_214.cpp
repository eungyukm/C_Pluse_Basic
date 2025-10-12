// C++20
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct Player
{
    unordered_map<string, int> inventory;
    string lastDungeon;
    bool inDungeon = false;
    int enterCount = 0;
};

bool TryEnterDungeon(Player& p, const string& dungeonId, 
    const string& ticketId)
{
    auto it = p.inventory.find(ticketId);
    if (it == p.inventory.end() || it->second <= 0)
    {
        return false;
    }

    it->second--;
    p.lastDungeon = dungeonId;
    p.inDungeon = true;
    p.enterCount++;
    return true;
}

int main()
{
    Player p;
    p.inventory["Dungeon_Ticket"] = 2;

    cout << (TryEnterDungeon(p, "AncientRuins", "Dungeon_Ticket")
        ? "Enter OK\n" : "Enter FAIL\n");
    cout << "TicketLeft: " << p.inventory["Dungeon_Ticket"] << "\n";
    cout << "InDungeon: " << (p.inDungeon ? 1 : 0) << "\n";
    cout << "EnterCount: " << p.enterCount << "\n";
    return 0;
}
