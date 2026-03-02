// C++20
#include <iostream>
using namespace std;

struct Tool
{
    string name;
    int durability;

    Tool(string n, int d) : name(n), durability(d)
    {

    }

    bool Use()
    {
        if (durability <= 0)
        {
            cout << name
                << "은(는) 내구도가 0이라 사용할 수 없습니다.\n";
            return false;
        }

        durability--;
        cout << name << " 사용! 남은 내구도: "
            << durability << endl;
        return true;
    }
};

int main()
{
    Tool axe("벌목 도끼", 3);

    while (axe.Use())
    {
    }

    return 0;
}
