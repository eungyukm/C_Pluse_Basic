// C++ 20
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct UI
{
    bool dialogOpen = false;

    void Open(const string& name, const vector<string>& lines)
    {
        dialogOpen = true;
        cout << "[대화] " << name << "\n";
        for (auto& l : lines)
        {
            cout << " - " << l << "\n";
        }
    }
    void Close()
    {
        if (dialogOpen)
        {
            cout << "[대화 종료]\n";
        }
        dialogOpen = false;
    }
};

struct Player
{
    float x = 0, y = 0;
    bool inCombat = false;
};

struct NPC
{
    string name = "마을 주민";
    float x = 2, y = 1;
    bool canTalk = true;
    vector<string> lines{ "안녕하세요.", "도움이 필요해요." };
};

static float Dist2(float ax, float ay, float bx, float by)
{
    float dx = ax - bx, dy = ay - by;
    return dx * dx + dy * dy;
}

struct Interaction
{
    float range = 3.0f;

    void Try(Player& p, NPC& n, UI& ui)
    {
        if (ui.dialogOpen)
        {
            ui.Close();
            return;
        }

        if (p.inCombat)
        {
            cout << "전투 중입니다." << endl;
            return;
        }

        if (!n.canTalk)
        {
            cout << "지금은 대화 불가." << endl;
            return;
        }

        if (Dist2(p.x, p.y, n.x, n.y) > range * range)
        {
            cout << "너무 멀리 있음." << endl;
            return;
        }

        ui.Open(n.name, n.lines);
    }
};

int main()
{
    UI ui; 
    Player p; 
    NPC n; 
    Interaction I;

    I.Try(p, n, ui);
    I.Try(p, n, ui);

    return 0;
}