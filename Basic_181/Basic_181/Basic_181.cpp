// C++20
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct FPlayer
{
    int HP{ 80 };
    int MaxHP{ 100 };
    int Stamina{ 45 };
    int MaxStamina{ 60 };
    bool bSprinting{ false };
};

// cosnt 참조
// 큰 객체를 복사하지 않고 일기 전용으로 받는 방법입니다.
// 예) const string& name -> name은 복사 없이 읽기만 합니다.
string DrawBar(const string& label, int value, 
    int max, int width = 20)
{
    value = clamp(value, 0, max);
    int filled = (max > 0) ? value * width / max : 0;
    string bar;
    bar.reserve(width);
    for (int i = 0; i < width; i++)
    {
        bar += (i < filled) ? '#' : '-';
    }
    return label + " [" + bar + "] " + 
        to_string(value) + "/" + to_string(max);
}

// 팰월드 느낌의 아주 기본 UI 업데이트/표시 로직
void TickStamina(FPlayer& P)
{
    if (P.bSprinting && P.Stamina > 0)
    {
        P.Stamina -= 3;
    }
    else if (!P.bSprinting && P.Stamina < P.MaxStamina)
    {
        P.Stamina += 2;
    }
    P.Stamina = clamp(P.Stamina, 0, P.MaxStamina);
}

void TickHP(FPlayer& P)
{
    int t = 0;
    if (P.HP < P.MaxHP)
    {
        P.HP += 1;
    }
    P.HP = clamp(P.HP, 0, P.MaxHP);
}

void RenderHUD(const FPlayer& P)
{
    cout << DrawBar("HP", P.HP, P.MaxHP) << "\n";
    cout << DrawBar("ST", P.Stamina, P.MaxStamina) << "\n";
    cout << "Sprinting: " << (P.bSprinting ? "Yes" : "No") << "\n";
    cout << "------------------------------\n";
}

int main()
{
    FPlayer Player{};
    for (int frame = 0; frame < 12; frame++)
    {
        // 0~5프레임: 달리기, 이후 휴식
        Player.bSprinting = (frame < 6);

        TickStamina(Player);
        TickHP(Player);
        RenderHUD(Player);
    }
    return 0;
}
