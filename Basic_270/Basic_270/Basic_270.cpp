#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Title 
{
    string name;
    int needKill = 0;
    int needLevel = 0;
    int needDungeon = 0;
    bool got = false;
};

class Player
{
public:
    int lv = 1, kill = 0, chaos = 0;
    vector<Title> titles = 
    {
        {"모험 시작",      0, 10, 0},
        {"몬스터 학살자", 300,  0, 0},
        {"카오스 정복자",   0,  0, 5},
        {"50렙의 영광",     0, 50, 0},
        {"전설의 시작",  1000, 50,10}
    };
    void check()
    {
        for (auto& t : titles)
        {
            if (t.got)
                continue;
            if (kill >= t.needKill && lv >= t.needLevel && chaos >= t.needDungeon)
            {
                t.got = true;
                cout << "칭호 획득! [" << t.name << "]\n";
            }
        }
    }

    void addKill(int n)
    {
        kill += n;
        check();
    }

    void levelUp()
    {
        lv++;
        check();
    }

    void clearChaos()
    {
        chaos++;
        check();
    }

    void print() 
    {
        cout << "\nLv." << lv << "  킬:" << kill << "  카오스:" << chaos << "\n";
        cout << "칭호: ";
        for (const auto& t : titles)
            if (t.got) cout << t.name << " ";
        cout << "\n";
    }
};

int main() 
{
    Player p;
    p.print();

    p.addKill(350);
    p.levelUp(); p.levelUp();
    p.print();

    for (int i = 0; i < 7; i++) p.clearChaos();
    p.addKill(700);
    p.print();

    return 0;
}