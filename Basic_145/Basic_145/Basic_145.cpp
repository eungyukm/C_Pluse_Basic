// C++20
#include <iostream>
#include <string>
using namespace std;

enum class PlayerState
{
    Normal,
    Interacting
};

enum class PartnerState
{
    Idle,
    Following,
    Attacking,
    Waiting
};

struct PartnerPal
{
    PartnerState state = PartnerState::Idle;

    void Update(PlayerState playerState)
    {
        if (playerState == PlayerState::Interacting)
        {
            if (state != PartnerState::Waiting)
            {
                state = PartnerState::Waiting;
                cout << "파트너 팰: 상호작용 중이라 대기 상태로 전환" << endl;
            }
        }
        else
        {
            if (state == PartnerState::Waiting)
            {
                state = PartnerState::Following;
                cout << "파트너 팰 : 다시 따라가기 시작" << endl;
            }
        }
    }
};

int main()
{
    PartnerPal pal;
    PlayerState playerState = PlayerState::Normal;

    // 플레이어가 상호작용 시작
    playerState = PlayerState::Interacting;
    pal.Update(playerState);

    // 상호작용 종료
    playerState = PlayerState::Normal;
    pal.Update(playerState);
}
