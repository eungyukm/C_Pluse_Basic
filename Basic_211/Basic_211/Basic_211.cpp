// C++20
#include <iostream>
#include <string>
using namespace std;

struct Engraving
{
    string Name;
    bool IsClassEngraving;
    int Level;

    Engraving(string name, bool isClass, int level)
        : Name(name), IsClassEngraving(isClass), Level(level) 
    {
    }
};

class Player
{
public:
    void ApplyEngraving(const Engraving& engraving)
    {
        if (engraving.IsClassEngraving && engraving.Level > 0)
        {
            cout << "직업 고유 각인 [" << engraving.Name
                << "] 발동! (Lv." << engraving.Level << ")" << endl;
        }
        else
        {
            cout << "일반 각인 [" << engraving.Name
                << "] 적용됨 (Lv." << engraving.Level << ")" << endl;
        }
    }
};

int main()
{
    Player player;
    Engraving normal("원한", false, 3);
    Engraving classEngraving("광전사의 비기", true, 2);

    player.ApplyEngraving(normal);
    player.ApplyEngraving(classEngraving);

    return 0;
}
