#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool find_cycle_and_topological_sort(int n, int m, const vector<pair<int, int>> &edges)
{
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);

    for (const auto &edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        indegree[v]++;
    }

    vector<int> topo_order;
    queue<int> q; // 进行BFS

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo_order.push_back(node);
        for (int neighbor : graph[node])
        {
            indegree[neighbor]--;

            if (indegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    if (topo_order.size() != n)
    {

        cout << "YES" << endl;
        return true;
    }
    else
    {
        cout << "NO" << endl;
        for (int i = 0; i < topo_order.size(); i++)
        {
            cout << topo_order[i] << " ";
        }
        cout << endl;
        return false;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = make_pair(u, v);
    }

    find_cycle_and_topological_sort(n, m, edges);
    return 0;
}