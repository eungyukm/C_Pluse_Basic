// C++20
#include <iostream>
using namespace std;

struct Player
{
    int Level = 10;
    bool inSafeArea = true;
    bool CutsceneSeen = false;
};

int main()
{
    Player p;

    if (p.Level >= 10 && p.inSafeArea && !p.CutsceneSeen)
    {
        cout << "메인 스토리 컷씬 자동 재생" << endl;
        p.CutsceneSeen = true;
    }
    else
    {
        cout << "조건 미충족, 컷씬 대기..." << endl;
    }
    return 0;
}
