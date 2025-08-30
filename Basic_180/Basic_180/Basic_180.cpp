// C++20
#include <iostream>
#include <array>
#include <string>
#include <vector>

using namespace std;
// 튜토리얼 팰월드 초반에 나무 모아오는 퀘스트
enum class ETutorialStep : size_t
{
    GatherWood10,
    CraftStoneAxe,
    BuildCampfire,
    OpenWorldMap,
    TalkToNPC,
    MAX
};

static const string& StepName(ETutorialStep s)
{
    static const vector<string> Names =
    {
        "나무 10개 채집",
        "돌도끼 제작",
        "모닥불 설치",
        "월드맵 열기",
        "NPC 대화"
    };
    return Names[static_cast<size_t>(s)];
}

class FTutorialFlags
{
public:
    // static_cast 명시적으로 타입 변환
    array<bool, static_cast<size_t>(ETutorialStep::MAX)> Flags{};

    void MarkComplete(const ETutorialStep& step)
    {
        Flags[Idx(step)] = true;
    }

    bool IsComplete(const ETutorialStep& step) const
    {
        return Flags[Idx(step)];
    }

    void PrintProgress() const
    {
        for (size_t i = 0; i < Flags.size(); i++)
        {
            cout << StepName(static_cast<ETutorialStep>(i))
                << " : " << (Flags[i] ? "완료" : "미완료") << endl;
        }
    }

private:
    static constexpr size_t Idx(ETutorialStep s)
    {
        return static_cast<size_t>(s);
    }
};

int main()
{
    FTutorialFlags Tutorial;

    Tutorial.MarkComplete(ETutorialStep::GatherWood10);
    Tutorial.MarkComplete(ETutorialStep::CraftStoneAxe);

    Tutorial.PrintProgress();
    return 0;
}
