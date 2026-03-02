// C++20
#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum class EQuestState 
{ 
    None, Assigned, Completed, Rewarded 
};

struct Quest
{
    int Id;
    string Name;
    int Target;
    int Progress = 0;
    EQuestState State = EQuestState::None;

    void Assign() 
    { 
        State = EQuestState::Assigned;
        cout << "[Quest] 부여: " << Name << "\n"; 
    }
    void OnKill() 
    { 
        if (State == EQuestState::Assigned && Progress < Target)
        {
            Progress++;
            if (Progress == Target)
            {
                State = EQuestState::Completed;
                cout << "[Quest] 완료: " << Name << endl;
            }
        }
    }
    void Reward() 
    { 
        if (State == EQuestState::Completed) 
        { 
            State = EQuestState::Rewarded;
            cout << "[Quest] 보상 지급\n"; 
        } 
    }
};

struct Player
{
    vector<Quest> Quests;

    bool HasQuest(int id)
    {
        for (int i = 0; i < (int)Quests.size(); i++) 
            if (Quests[i].Id == id) 
                return true;
        return false;
    }

    void AddQuest(const Quest& q)
    {
        Quests.push_back(q);
        Quests.back().Assign();
    }

    void KillMob()
    {
        for (int i = 0; i < (int)Quests.size(); i++)
            Quests[i].OnKill();
    }

    void ClaimRewards()
    {
        for (int i = 0; i < (int)Quests.size(); i++)
            Quests[i].Reward();
    }
};

struct FieldEvent
{
    int EventId;
    int AutoQuestId;
    string AutoQuestName;
    int KillTarget;

    Quest MakeAutoQuest() const 
    { 
        return Quest{ AutoQuestId, AutoQuestName, KillTarget }; 
    }

    void Participate(Player& p)
    {
        if (!p.HasQuest(AutoQuestId))
        {
            p.AddQuest(MakeAutoQuest());
        }
    }
};

int main()
{
    Player p;
    FieldEvent fe{ 100, 5001, "필드 정화 작전", 3 };

    fe.Participate(p);      // 필드 퀘스트 참여 → 자동 퀘스트 부여
    p.KillMob();            // 1/3
    p.KillMob();            // 2/3
    p.KillMob();            // 3/3 → 완료
    p.ClaimRewards();       // 보상

    return 0;
}
