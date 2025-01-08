#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int node, int parent, const vector<vector<int>> graph)
{
    int height = 0;
    for (int n : graph[node])
    {
        if (n != parent)
        {
            height = max(height, dfs(n, node, graph) + 1);
        }
    }
    return height;
}

int findMinHeight(int n, const vector<pair<int, int>> edges)
{
    vector<vector<int>> graph(n);
    for (auto &edge : edges)
    {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    int minHeight = 100;
    for (int root = 0; root < n; root++)
    {
        int height = dfs(root, -1, graph);
        minHeight = min(minHeight, height);
    }
    return minHeight;
}