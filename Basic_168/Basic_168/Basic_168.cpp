// C++20
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

using Skill = string;

struct FPaldna
{
    unordered_set<Skill> PassiveSkills;
};

class FSkillGeneLab
{
public:
    FSkillGeneLab()
    {
        AllPossibleSkills = {
            "화염 저항", "빙결 면역", "HP 회복", "공격력 증가", "방어력 증가",
            "크리티컬 확률 증가", "스태미나 회복", 
            "스킬 쿨다운 감소", "도트 대미지 강화"
        };
        Random.seed(random_device{}());
    }

    FPaldna CreateChildDNA(const FPaldna& ParentA, const FPaldna& ParentB)
    {
        FPaldna Child;
        unordered_set<Skill> Combined;

        // 부모의 스킬을 병합
        Combined.insert(ParentA.PassiveSkills.begin(), 
            ParentA.PassiveSkills.end());
        Combined.insert(ParentB.PassiveSkills.begin(), 
            ParentB.PassiveSkills.end());

        // 유전 확률
        uniform_real_distribution<float> ChanceDist(0.0f, 1.0f);
        for (const Skill& skill : Combined)
        {
            if (ChanceDist(Random) < 0.5f) // 50% 확률로 유전
            {
                Child.PassiveSkills.insert(skill);
            }
        }

        // 70% 확률로 돌연변이 발생 (부모에 없던 새로운 스킬 추가)
        if (ChanceDist(Random) < 0.7f)
        {
            vector<Skill> AvailableMutations;
            for (const Skill& skill : AllPossibleSkills)
            {
                if (!Combined.contains(skill))
                {
                    AvailableMutations.push_back(skill);
                }
            }

            if (!AvailableMutations.empty())
            {
                uniform_int_distribution<int> IndexDist
                (0, static_cast<int>(AvailableMutations.size() - 1));

                Skill MutatedSkill =
                    AvailableMutations[IndexDist(Random)];
                Child.PassiveSkills.insert(MutatedSkill);

                cout << "[돌연변이 발생] 새로운 스킬"
                    << MutatedSkill << "이(가) 자식에게 추가되었습니다."
                    << endl;
            }
        }

        return Child;
    }

private:
    mt19937 Random;
    vector<Skill> AllPossibleSkills;
};

// 예시 실행
int main()
{
    FSkillGeneLab Lab;

    FPaldna ParentA;
    ParentA.PassiveSkills = { "화염 저항", "HP 회복" };

    FPaldna ParentB;
    ParentB.PassiveSkills = { "공격력 증가", "빙결 면역" };

    FPaldna Child = Lab.CreateChildDNA(ParentA, ParentB);

    cout << "자식의 유전된 스킬 목록:\n";
    for (const auto& skill : Child.PassiveSkills)
    {
        cout << "- " << skill << '\n';
    }

    return 0;
}
