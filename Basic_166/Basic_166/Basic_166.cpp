// C++20
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

// 부모 ID 조합 키 정의 (작은 값부터 정렬하여 순서 무시)
struct FPalBreedKey
{
    string ParentA;
    string ParentB;

    FPalBreedKey(string a, string b)
    {
        if (a < b)
        {
            ParentA = a;
            ParentB = b;
        }
        else
        {
            ParentA = b;
            ParentB = a;
        }
    }

    bool operator==(const FPalBreedKey& other) const
    {
        return ParentA == other.ParentA && ParentB == other.ParentB;
    }
};

// 해시 함수 정의
struct FPalBreedKeyHash
{
    size_t operator()(const FPalBreedKey& key) const
    {
        return hash<string>()(key.ParentA) ^ hash<string>()(key.ParentB);
    }
};

// 자식 팰 ID 조합 테이블
unordered_map<FPalBreedKey, string, FPalBreedKeyHash> PalBreedTable;

// 테이블 초기화 함수
void InitBreedTable()
{
    PalBreedTable[FPalBreedKey("FireFox", "IceBird")] = "SteamFalcon";
    PalBreedTable[FPalBreedKey("ThunderCat", "StoneBull")] = "MagnetTiger";
    PalBreedTable[FPalBreedKey("GrassBunny", "WaterFish")] = "BloomFrog";
}

// 자식 팰 ID 조회 함수
string GetChildPalID(const string& parentA, const string& parentB)
{
    FPalBreedKey key(parentA, parentB);
    auto it = PalBreedTable.find(key);

    if (it != PalBreedTable.end())
    {
        return it->second;
    }

    return "Unknown"; // 조합 없음
}

// 예제 테스트
int main()
{
    InitBreedTable();

    cout << "FireFox + IceBird = "
        << GetChildPalID("FireFox", "IceBird") << endl;
    cout << "IceBird + FireFox = " 
        << GetChildPalID("IceBird", "FireFox") << endl;
    cout << "StoneBull + ThunderCat = " 
        << GetChildPalID("StoneBull", "ThunderCat") << endl;
    cout << "Unknown + ??? = " 
        << GetChildPalID("Unknown", "???") << endl;

    return 0;
}
