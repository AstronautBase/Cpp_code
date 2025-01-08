#include <iostream>
#include <vector>
#include <set>
using namespace std;

void maximumIndependentSetUtil(const vector<vector<int>> &graph, vector<bool> &visited, set<int> &independentSet, int node)
{
    if (visited[node])
        return;

    visited[node] = true;
    independentSet.insert(node);
    // 禁止选择相邻节点
    for (int neighbor : graph[node])
    {
        visited[neighbor] = true;
    }
}

set<int> maximumIndependentSet(vector<vector<int>> &graph)
{
    vector<bool> visited(graph.size(), false);
    set<int> independentSet;

    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited[i])
        {
            maximumIndependentSetUtil(graph, visited, independentSet, i);
        }
    }

    return independentSet;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    set<int> inSet = maximumIndependentSet(graph);
    for (int node : inSet)
    {
        cout << node << " ";
    }
    return 0;
}