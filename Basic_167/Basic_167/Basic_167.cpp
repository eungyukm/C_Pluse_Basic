#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <unordered_set>

using namespace std;

struct PassiveSkill
{
    string Name;

    PassiveSkill(string name) : Name(move(name)) {}
};

struct Pal
{
    string Name;
    vector<PassiveSkill> PassiveSkills;

    Pal(string name, vector<string> skills)
        : Name(move(name))
    {
        for (const auto& s : skills)
        {
            PassiveSkills.emplace_back(s);
        }
    }
};

// 유전 확률 기반 자식 팰 패시브 스킬 유전 함수
vector<PassiveSkill> InheritPassiveSkills
(const Pal& parentA, const Pal& parentB, float inheritChance = 0.5f)
{
    vector<PassiveSkill> inherited;
    unordered_set<string> selected; // 중복 방지
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    auto try_inherit = [&](const vector<PassiveSkill>& skills)
        {
            for (const auto& skill : skills)
            {
                if (dis(gen) < inheritChance &&
                    selected.find(skill.Name) == selected.end())
                {
                    inherited.push_back(skill);
                    selected.insert(skill.Name);
                }
            }
        };

    try_inherit(parentA.PassiveSkills);
    try_inherit(parentB.PassiveSkills);
    return inherited;
}

// 테스트 예제
int main()
{
    Pal parentA("Flareon", { "FireBoost", "Agility", "Bravery" });
    Pal parentB("Glaceon", { "IceShield", "Focus", "Agility" });

    vector<PassiveSkill> childSkills = 
        InheritPassiveSkills(parentA, parentB, 0.5f);

    cout << "[자식에게 유전된 패시브 스킬 목록]\n";
    for (const auto& skill : childSkills)
    {
        cout << "- " << skill.Name << '\n';
    }

    return 0;
}
