// C++20
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

enum class Biome
{
	Grassland, Volcano, Snow
};

unordered_map<Biome, vector<string>> treeMap = {
	{ Biome::Grassland, {"LeafyTree", "SmallBush"}},
	{ Biome::Volcano, { "LavaTree"}},
	{ Biome::Snow, {"SnowPine"}}
};

void Place(Biome biome)
{
	for (auto& name : treeMap[biome])
	{
		cout << "Placed " << name << endl;
	}
}

int main()
{
	Place(Biome::Grassland);
	return 0;
}