// C++20
#include <iostream>
#include <string>
using namespace std;

enum class QuestState { InProgress, Completed };

struct Player
{
    int gold = 0;
    int exp = 0;
};

struct Quest
{
    QuestState state = QuestState::InProgress;
    int rewardGold = 50;
    int rewardExp = 100;
    bool rewarded = false;
};

void CompleteQuest(Player& p, Quest& q)
{
    if (q.state == QuestState::InProgress && !q.rewarded)
    {
        p.gold += q.rewardGold;
        p.exp += q.rewardExp;
        q.rewarded = true;
        q.state = QuestState::Completed;
        cout << "퀘스트 완료! 골드 "
            << q.rewardGold << ", 경험치 "
            << q.rewardExp << " 지급." << endl;
    }
}

int main()
{
    Player me;
    Quest quest;
    CompleteQuest(me, quest);
    cout << "최종 골드: " << me.gold << ", EXP: " 
        << me.exp << endl;
}
