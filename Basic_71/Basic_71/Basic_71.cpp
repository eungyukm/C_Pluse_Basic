#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool solution(const vector<int>& A, const vector<int>& B)
{
    int edge_count = A.size();
    unordered_map<int, int> out_degree;
    unordered_map<int, int> in_degree;
    unordered_map<int, int> next_node; // A[i] -> B[i]
    unordered_set<int> vertex_set;

    // 간선 정보 저장 및 in/out-degree 계산
    for (int i = 0; i < edge_count; ++i)
    {
        out_degree[A[i]]++;
        in_degree[B[i]]++;
        next_node[A[i]] = B[i];
        vertex_set.insert(A[i]);
        vertex_set.insert(B[i]);
    }

    int vertex_count = vertex_set.size();

    // 모든 정점의 in-degree, out-degree가 1인지 확인
    for (int vertex : vertex_set)
    {
        if (in_degree[vertex] != 1 || out_degree[vertex] != 1)
            return false;
    }

    // 연결 여부 확인 (하나의 사이클인지)
    int start_vertex = A[0];
    int current = start_vertex;
    unordered_set<int> visited;

    for (int i = 0; i < vertex_count; ++i)
    {
        if (visited.count(current)) return false; // 중복 방문 시 실패
        visited.insert(current);
        current = next_node[current];
    }

    return current == start_vertex; // 다시 시작점으로 돌아왔는지 확인
}

int main()
{
    vector<int> A = { 1, 3, 2, 4 };
    vector<int> B = { 4, 1, 3, 2 };

    cout << (solution(A, B) ? "true" : "false") << endl;
}
