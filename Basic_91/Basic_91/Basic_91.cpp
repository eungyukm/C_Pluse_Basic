// C++20 기준
#include <iostream>
#include <vector>

using namespace std;

class Graph
{
    int vertexCount;
    vector<vector<int>> adj;

public:



    Graph(int vertices) : vertexCount(vertices), adj(vertices) {}

    void AddEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); // 무방향 그래프
    }

    void PrintGraph()
    {
        for (int i = 0; i < vertexCount; i++)
        {
            cout << "Node " << i << ": ";
            for (int neightbor : adj[i])
            {
                cout << neightbor << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    Graph g(5); // 5개의 노드 (0 ~ 4)

    g.AddEdge(0, 1);
    g.AddEdge(0, 4);
    g.AddEdge(1, 2);
    g.AddEdge(1, 3);
    g.AddEdge(1, 4);
    g.AddEdge(2, 3);
    g.AddEdge(3, 4);

    g.PrintGraph();
}
