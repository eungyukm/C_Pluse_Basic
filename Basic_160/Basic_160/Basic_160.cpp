// C++20
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct FVector
{
    float X, Y;

    float DistanceTo(const FVector& Other) const
    {
        float dx = X - Other.X;
        float dy = Y - Other.Y;
        return sqrt(dx * dx + dy * dy);
    }
};

struct FPalNPC
{
    int ID;
    int FactionID;
    FVector Pos;
    bool InCombat = false;
};

void CheckCombat(vector<FPalNPC>& NPCs, float Range = 300.f)
{
    for (auto& A : NPCs)
    {
        if (A.InCombat)
        {
            continue;
        }

        for (auto& B : NPCs)
        {
            if (&A == &B || B.InCombat)
            {
                continue;
            }

            if (A.FactionID != B.FactionID && A.Pos.DistanceTo(B.Pos) < Range)
            {
                A.InCombat = B.InCombat = true;
                cout << "전투 발생! NPC " << A.ID << " vs NPC " << B.ID << endl;
                break;
            }
        }
    }
}

int main()
{
    vector<FPalNPC> NPCs = {
        {1, 1, {0, 0}},
        {2, 2, {100, 0}},
        {3, 1, {200, 0}},
        {4, 2, {210, 0}},
    };

    CheckCombat(NPCs);
    return 0;
}
