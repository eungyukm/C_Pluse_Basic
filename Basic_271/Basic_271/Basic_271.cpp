#include <iostream>
#include <string>
using namespace std;

class Player {
public:
    int lv = 1;
    float moveSpeed = 1.0f;     // 기본 이동속도 배율 (1.0 = 100%)
    bool isMounted = false;
    string mountName = "";

    void summonMount(const string& name, float speedBonus) {
        if (isMounted) {
            cout << "이미 탈것을 타고 있습니다!\n";
            return;
        }

        mountName = name;
        isMounted = true;
        moveSpeed = 1.0f + speedBonus;

        cout << "[" << name << "] 소환! 이동속도 +"
            << (speedBonus * 100) << "% ("
            << moveSpeed * 100 << "%\n";
    }

    void dismount() {
        if (!isMounted) {
            cout << "탈것을 타고 있지 않습니다.\n";
            return;
        }

        cout << mountName << " 하차. 이동속도 원상복구\n";
        isMounted = false;
        mountName = "";
        moveSpeed = 1.0f;
    }

    void printStatus() {
        cout << "\nLv." << lv << "   이동속도: " << (moveSpeed * 100) << "%";
        if (isMounted) {
            cout << "   (" << mountName << " 탑승 중)";
        }
        cout << "\n";
    }
};

int main() {
    Player p;
    p.printStatus();

    p.summonMount("검은 바람의 말", 0.40f);   // +40% → 140%
    p.printStatus();

    p.summonMount("황금 그리핀", 0.70f);      // 이미 타고 있어서 실패
    p.printStatus();

    p.dismount();
    p.printStatus();

    p.summonMount("스피드 바이크", 1.20f);    // +120% → 220%
    p.printStatus();

    return 0;
}