#include <iostream>
using namespace std;

struct Ship
{
    int fuel{ 10 };
    int position{ 0 };

    bool Move(int distance)
    {
        for (int i = 0; i < distance; i++)
        {
            if (fuel <= 0)
            {
                cout << "연료가 부족해 더 이동할 수 없습니다." << endl;
                return false;
            }
            position++;
            fuel--;
        }
        cout << distance << "칸 이도 완료! 남은 연료: "
            << fuel << endl;
        return true;
    }

    void Refuel(int amount)
    {
        fuel += amount;
        cout << "연료 보급 완료! 현재 연료: " 
            << fuel << "\n";
    }
};

int main()
{
    Ship ship;
    ship.Move(6);
    ship.Refuel(3);
    ship.Move(10);
}
