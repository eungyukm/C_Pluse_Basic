// C++ 20
#include <iostream>
#include <vector>
#include <string>
#include <optional>
using namespace std;

enum class Class
{
    Warrior,
    Mage
};

struct Weapon
{
    int id;
    string name;
    int reqLv;
    Class reqClass;
};

struct Character
{
    string name;
    Class job;
    int lv = 1;
    // optional은 C++ 17에서 추가된 표준 라이브러리 클래스
    // 값이 있을 수도 있고 없을 수 도 있는 객체를 표현할 때 사용
    optional<Weapon> equip;
    vector<Weapon> inv;

    void grantBasic()
    {
        int id = 100;
        inv.push_back({ 
            id++, "Tutorial Sword", 1, Class::Warrior});
        inv.push_back({ 
            id++, "Tutorial Staff", 1, Class::Mage});
    }

    bool equipTutorialWeapon()
    {
        for (size_t i = 0; i < inv.size(); i++)
        {
            Weapon& w = inv[i];
            if (w.reqClass != job) continue;
            if (lv < w.reqLv) continue;

            equip = w;
            inv.erase(inv.begin() + i);
            cout << "Equipped: " << equip->name << endl;
            return true;
        }
        cout << "No tutorial weapon." << endl;
        return false;
    }
};

int main()
{
    Character pc{ "Aria", Class::Warrior, 1 };
    pc.grantBasic();
    pc.equipTutorialWeapon();
    return 0;
}
