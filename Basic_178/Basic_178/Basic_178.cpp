// C++20
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

enum class ETech 
{ 
    Workbench,
    Farming,
    Cooking
};
struct FTechMeta 
{
    int Cost;
    vector<ETech> Pre; 
};

struct FPlayer
{
    int Level{ 1 }, TP{ 0 };
    unordered_set<ETech> Techs;

    void LevelUp(int n = 1) 
    { 
        Level += n; 
        TP += n; 
    }
    bool Owns(ETech t) const 
    { 
        return Techs.count(t); 
    }
    bool CanUnlock(const auto& db, ETech t) const
    {
        if (Owns(t) || !db.count(t) || TP < db.at(t).Cost)
        {
            return false;
        }
        for (auto p : db.at(t).Pre)
        {
            if (!Owns(p))
            {
                return false;
            }
        }
        return true;
    }
    bool Unlock(const auto& db, ETech t)
    {
        if (!CanUnlock(db, t))
        {
            return false;
        }
        TP -= db.at(t).Cost;
        Techs.insert(t);
        cout << "Unlocked tech!\n";
        return true;
    }
};

int main()
{
    unordered_map<ETech, FTechMeta> DB{
        {ETech::Workbench,{1,{}}},
        {ETech::Farming,{1,{ETech::Workbench}}},
        {ETech::Cooking,{2,{ETech::Farming}}}
    };

    FPlayer P;
    P.LevelUp(3);
    if (P.Unlock(DB, ETech::Workbench));
    if (P.Unlock(DB, ETech::Farming));
}
