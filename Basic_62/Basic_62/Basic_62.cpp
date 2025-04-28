// C++17
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, float> cooldowns;

bool UseSkill
(const string& skillName, float cooldownTime)
{
    if (cooldowns[skillName] <= 0.0f)
    {
        cooldowns[skillName] = cooldownTime;
        cout << "Used " << skillName << endl;
        return true;
    }
    else
    {
        cout << skillName << " is cooling down: "
            << cooldowns[skillName] << "s left\n";
        return false;
    }
}

void Update(float deltaTime)
{
    for (auto& [skill, time] : cooldowns)
    {
        time = max(0.0f, time - deltaTime);
    }
}

int main() 
{
    cooldowns["Fireball"] = 0.0f;
    cooldowns["Dash"] = 0.0f;

    UseSkill("Fireball", 5.0f);
    UseSkill("Dash", 3.0f);

    Update(2.0f); // 2초 흐름
    UseSkill("Fireball", 5.0f); // 아직 사용 불가

    Update(3.0f); // 추가 3초 흐름
    UseSkill("Fireball", 5.0f); // 이제 사용 가능

    return 0;
}
