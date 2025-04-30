// C++17
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, float> cooldowns;

const float FIREBALL_COOLTIME = 5.0f;
const string FIRE_BALL = "FireBall";
const string DASH = "DASH";

bool UseSkill(const string& skillName,
	float cooldownTime)
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
			<< cooldowns[skillName] << "s left"
			<< endl;
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
	cooldowns[FIRE_BALL] = 0.0f;
	cooldowns[DASH] = 0.0f;

	UseSkill(FIRE_BALL, FIREBALL_COOLTIME);
	UseSkill(DASH, 3.0f);

	// 2초 흐름
	Update(2.0f);

	// 아직 사용 불가
	UseSkill(FIRE_BALL, FIREBALL_COOLTIME);

	// 추가로 3초 흐름
	Update(3.0f);

	// 이제 사용 가능
	UseSkill(FIRE_BALL, FIREBALL_COOLTIME);
}
