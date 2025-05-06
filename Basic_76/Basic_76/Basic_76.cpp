// C++17
#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class ActionType { Move, Attack, Heal };

struct ActionLog 
{
    int tick, playerId;
    ActionType type;
    string detail;
};

class Logger
{
    vector<ActionLog> logs;

public:
    void Log(int tick, int id, ActionType type, const string& detail) 
    {
        logs.push_back({ tick, id, type, detail });
    }

    void Replay() const 
    {
        for (const auto& log : logs)
        {
            cout << "[Tick " << log.tick << "] Player "
                << log.playerId << " ";
            if (log.type == ActionType::Move)
            {
                cout << "moved " << log.detail;
            }
            else if (log.type == ActionType::Attack)
            {
                cout << "attacked " << log.detail;
            }
            else if (log.type == ActionType::Heal)
            {
                cout << "healed" << log.detail;
            }
            cout << '\n';
        }
    }
};

int main() {
    Logger logger;

    logger.Log(1, 1, ActionType::Move, "to(2,3)");
    logger.Log(2, 2, ActionType::Attack, "target:1");
    logger.Log(3, 3, ActionType::Heal, "target:2 +40");

    logger.Replay();

    return 0;
}
