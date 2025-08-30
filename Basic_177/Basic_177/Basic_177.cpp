// C++ 20
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

// 인벤토리 총 무게가 한도를 넘으면 이동 속도 감소
struct FItem
{
    string Name;
    float  UnitWeight{ 0.f };
    int    Count{ 0 };
};

static inline float Clamp(float v, float lo, float hi)
{
    return min(hi, max(lo, v));
}

class FPlayer
{
public:
    // 튜닝 파라미터
    float BaseSpeed{ 600.f };       // 정상 이동 속도
    float WeightLimit{ 100.f };     // 한도 무게
    float MinSpeedScale{ 0.25f };   // 과적 최대 감속 하한 (예: 25%)
    float SlowSlope{ 0.8f };        // 과적 증가당 감속 기울기 (조절용)

    // 상태
    vector<FItem> Inventory;
    float CurrentSpeed{ BaseSpeed };

public:
    void AddItem(const FItem& it) { Inventory.push_back(it); }

    float GetTotalWeight() const
    {
        return accumulate(Inventory.begin(), Inventory.end(), 0.f,
            [](float acc, const FItem& it) 
            { 
                return acc + it.UnitWeight * it.Count; 
            });
    }

    // 총 무게 기반 속도 스케일 계산
    float ComputeSpeedScale(float totalWeight) const
    {
        if (totalWeight <= WeightLimit)
        {
            return 1.f;
        }

        float overRatio =
            (totalWeight - WeightLimit) / max(1.f, WeightLimit);
        float scale = 1.f - SlowSlope * overRatio;
        return Clamp(scale, MinSpeedScale, 1.f);
    }

    // 틱/이벤트에서 호출해 이동 속도 갱신
    void RecalcMovement()
    {
        float total = GetTotalWeight();
        float scale = ComputeSpeedScale(total);
        CurrentSpeed = BaseSpeed * scale;
    }
};

int main()
{
    FPlayer P;
    P.WeightLimit = 80.f;     // 한도 80
    P.BaseSpeed = 600.f;    // 기본 속도 600

    // 아이템 추가 (예시)
    vector<FItem> loot = {
        {"Ore", 2.5f, 10},
        {"Wood", 1.2f, 15},
        {"Meat", 0.8f, 5}
    };
    for (size_t i = 0; i < loot.size(); i++)
    {
        P.AddItem(loot[i]);
    }

    P.RecalcMovement();

    cout << "TotalWeight=" << P.GetTotalWeight()
        << ", Speed=" << P.CurrentSpeed << "\n";

    // 과적 테스트: 무거운 광석 더 줍기
    P.AddItem({ "Ore", 2.5f, 30 });
    P.RecalcMovement();
    cout << "TotalWeight=" << P.GetTotalWeight()
        << ", Speed=" << P.CurrentSpeed << "\n";

    return 0;
}
