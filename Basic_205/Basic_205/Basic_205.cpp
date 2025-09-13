// C++20
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Accessory
{
    string name;
    int option = 0;

    void Reforge(int material)
    {
        if (material <= 0)
        {
            cout << "재료 부족" << endl;
        }

        option = rand() % 100;
        cout << name << " 옵션이 " << option << " 으로 변경됨" << endl;
    }
};

int main()
{
    srand((unsigned)time(nullptr));

    Accessory ring{ "Ring of Power" };
    int material = 1;

    ring.Reforge(material);

    return 0;
}
