// C++20
#include <iostream>
#include <string>
using namespace std;

enum class EQuestState
{
    None,
    Accepted,
    InProgress,
    Completed
};

struct Quest
{
    string Name;
    EQuestState State{ EQuestState::None };
    int TargetCount{ 0 };
    int CurrCount{ 0 };

    void Accept()
    {
        if (State == EQuestState::None)
        {
            State = EQuestState::Accepted;
            cout << "퀘스트 수락: " << Name << endl;
            TryAdvance();
        }
    }

    void OnProgressEvent(int add = 1)
    {
        if (State == EQuestState::Accepted
            || State == EQuestState::InProgress)
        {
            CurrCount += add;
            cout << "진행: " << CurrCount << " / "
                << TargetCount << endl;
            TryAdvance();
        }
    }

    void TryAdvance()
    {
        if (State == EQuestState::Accepted && CurrCount
            < TargetCount)
        {
            State = EQuestState::InProgress;
            cout << "상태 변경 : 진행 중" << endl;
        }
        if (CurrCount >= TargetCount && State
            != EQuestState::Completed)
        {
            State = EQuestState::Completed;
            cout << "상태 변경 : 완료" << endl;
        }
    }
};

int main()
{
    Quest q{ "늑대 3마리 처치", EQuestState::None, 3, 0 };
    q.Accept();
    for (int i = 0; i < 3; i++)
    {
        q.OnProgressEvent(1); // 몬스터 처치 이벤트
    }
    return 0;
}