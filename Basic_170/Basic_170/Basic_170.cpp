// C++20
#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

// 알 타입 정의
enum class EGG_TYPE
{
    Normal,
    Rare,
    Legendary
};

// 알의 기본 부화 시간 설정 (단위: 초)
unordered_map<EGG_TYPE, int> BaseHatchTime =
{
    { EGG_TYPE::Normal, 300 },
    { EGG_TYPE::Rare, 600 },
    { EGG_TYPE::Legendary, 1200 }
};

// 적정 온도 범위
constexpr float IdealTempMin = 24.0f;
constexpr float IdealTempMax = 28.0f;

// 온도 보정 함수
float GetTemperatureMultiplier(float temperature)
{
    if (temperature < IdealTempMin)
    {
        float diff = IdealTempMin - temperature;
        return 1.0f + diff * 0.05f; // 추우면 느려짐
    }
    else if (temperature > IdealTempMax)
    {
        float diff = temperature - IdealTempMax;
        return 1.0f + diff * 0.05f; // 더우면 느려짐
    }
    return 1.0f; // 적정 온도
}

// 부화 시간 계산 함수
int CalculateHatchTime(EGG_TYPE eggType, float temperature)
{
    int baseTime = BaseHatchTime[eggType];
    float multiplier = GetTemperatureMultiplier(temperature);
    return static_cast<int>(round(baseTime * multiplier));
}

// 예제 실행
int main()
{
    EGG_TYPE egg = EGG_TYPE::Rare;
    float incubatorTemp = 22.5f;

    int hatchTime = CalculateHatchTime(egg, incubatorTemp);
    cout << "부화 예상 시간: " << hatchTime << "초" << endl;
}
