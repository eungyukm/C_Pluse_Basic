// C++20
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

enum class eTITLE : uint8_t
{
    FirstBlood,   // 첫 보스 처치
    QuestRookie,  // 퀘스트 10회 완료
};

struct Player
{
    int questComp = 0;
    unordered_map<string, int> kill;
    unordered_set<eTITLE> titles;

    void TryGain()
    {
        if (kill["boss"] >= 1)
        {
            titles.insert(eTITLE::FirstBlood);
        }
        if (questComp >= 10)
        {
            titles.insert(eTITLE::QuestRookie);
        }
    }
};

string ToKorean(eTITLE t)
{
    if (t == eTITLE::FirstBlood)
    {
        return "첫 피를 본 자";
    }
    if (t == eTITLE::QuestRookie)
    {
        return "초보 모험가";
    }
    return "알 수 없음";
}

int main()
{
    Player p;
    p.kill["boss"] = 1;
    p.questComp = 12;
    p.TryGain();

    for (auto t : p.titles)
    {
        cout << ToKorean(t) << endl;
    }
        
    return 0;
}
