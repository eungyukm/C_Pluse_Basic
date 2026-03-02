// C++20
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Player
{
    string name;
};

struct Match
{
    vector<Player> teamA;
    vector<Player> teamB;
};

struct PvpQueue
{
    vector<Player> wait;

    void Enqueue(const Player& p)
    {
        cout << p.name << " 대기열 진입\n";
        wait.push_back(p);
    }

    bool TryStartMatch(int needPerTeam)
    {
        int need = needPerTeam * 2;
        if ((int)wait.size() < need)
        {
            cout << "인원 부족" << wait.size()
                << " / " << need << endl;
            return false;
        }

        Match m;
        for (int i = 0; i < needPerTeam; i++)
        {
            m.teamA.push_back(wait.back());
            wait.pop_back();
        }

        for (int i = 0; i < needPerTeam; i++)
        {
            m.teamB.push_back(wait.back());
            wait.pop_back();
        }
        cout << "PvP 매칭 시작\n";
        cout << " TeamA vs TeamB\n";
        return true;
    }
};

int main()
{
    PvpQueue q;

    q.Enqueue({ "Player1" });
    q.Enqueue({ "Player2" });
    q.Enqueue({ "Player3" });
    q.Enqueue({ "Player4" });

    int needPerTeam = 2;
    q.TryStartMatch(needPerTeam);

    return 0;
}
