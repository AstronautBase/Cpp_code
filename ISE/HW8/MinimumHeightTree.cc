#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int node, int parent, const vector<vector<int>> &graph)
{
    int height = 0;
    for (int neighbor : graph[node])
    {
        if (neighbor != parent)
        {
            height = max(height, dfs(neighbor, node, graph) + 1);
        }
    }
    return height;
}

int findMinHeight(int n, const vector<pair<int, int>> &edges)
{
    vector<vector<int>> graph(n);
    for (const auto &edge : edges)
    {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    int minHeight = 100;

    for (int root = 0; root < n; ++root)
    {
        int height = dfs(root, -1, graph);
        minHeight = min(minHeight, height);
    }

    return minHeight;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    int result = findMinHeight(n, edges);
    cout << result << endl;

    return 0;
}