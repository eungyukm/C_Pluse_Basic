#include <iostream>
#include <string>

using namespace std;

struct Pal
{
    string name;
    float fallHeight;
    int hp = 100;

    void DropDamage()
    {
        if (fallHeight > 5.0f)
        {
            int damage = static_cast<int>((fallHeight - 5.0f) * 10);
            hp -= damage;
            cout << name << " took " << damage
                << " fall damage! HP : " << hp << endl;
        }
        else
        {
            cout << name << " landed safely." << endl;
        }
    }
};

int main()
{
    Pal pal{ "Foxparks", 7.3f };
    pal.DropDamage();
}
