#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight;
};

class DisjointSet
{
public:
    DisjointSet(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
        {
            parent[u] = find(parent[u]); // 路径压缩
        }
        return parent[u];
    }

    bool unionSets(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            return true;
        }
        return false; // 形成环
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.weight < b.weight; });

    DisjointSet ds(n);
    int mstWeight = 0;

    // Kruskal 算法
    for (const auto &edge : edges)
    {
        if (ds.unionSets(edge.u, edge.v))
        {
            mstWeight += edge.weight;
        }
    }

    cout << mstWeight << endl;
    return 0;
}