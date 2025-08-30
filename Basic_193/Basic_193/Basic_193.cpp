// C++20
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// 로스트아크 스타일: 성장 가이드 조건 달성 시 보상 상자 지급
struct Player
{
    int level = 1;
    unordered_set<int> claimedMilestones; // 이미 받은 구간(중복 방지)
    vector<string> bag;                   // 인벤토리
};

static const vector<int> kMilestones = { 10, 20, 30 };

string MakeChestName(int milestone)
{
    return "GrowthGuideChest_T" + to_string(milestone);
}

bool TryGrantGrowthGuideChest(Player& p)
{
    for (size_t i = 0; i < kMilestones.size(); i++)
    {
        int m = kMilestones[i];
        if (p.level >= m && !p.claimedMilestones.count(m))
        {
            p.bag.push_back(MakeChestName(m));
            p.claimedMilestones.insert(m);
            cout << "[Reward] Level " << m << " 달성 -> "
                << p.bag.back() << " 지급" << endl;
            return true;
        }
    }
    return false;
}

int main()
{
    Player me;
    me.level = 20;

    // 조건 달성 시 상자 지급
    while (TryGrantGrowthGuideChest(me)) 
    {  
    }

    // 레벨 추가 상승
    me.level = 30;
    while (TryGrantGrowthGuideChest(me)) 
    {
    }

    // 결과 확인
    cout << "Bag: ";
    for (auto& it : me.bag) cout << it << ' ';
    cout << '\n';
    return 0;
}
