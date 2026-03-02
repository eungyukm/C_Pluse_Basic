// C++20
using namespace std;

#include <iostream>
struct SeasonPass
{
    int level;
    int exp;
    int expPerLevel;
};

void GainSeasonPassExp(SeasonPass& pass, int gainedExp)
{
    pass.exp += gainedExp;

    while (pass.exp >= pass.expPerLevel)
    {
        pass.exp -= pass.expPerLevel;
        pass.level++;
        cout << "Season Pass Level Up " << pass.level << endl;
    }
}
int main()
{
    SeasonPass pass = { 1, 0, 100 };

    GainSeasonPassExp(pass, 30); // 일일 퀘스트
    GainSeasonPassExp(pass, 80); // 던전 클리어
    GainSeasonPassExp(pass, 150); // 레이드 보상

    cout << "Final Level " << pass.level << endl;
    cout << "Remaining Exp " << pass.exp << endl;
    return 0;
}
