#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight;
};

// krustal
class DisjointSet
{
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unionSet(int u, int v)
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
        return false;
    }
};

int krustal(vector<Edge> &edges)
{
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.weight < b.weight; });

    DisjointSet ds(edges.size());
    vector<Edge> mst;
    int mstWeight = 0;
    for (const auto &edge : edges)
    {
        if (ds.unionSet(edge.u, edge.v))
        {
            mstWeight += edge.weight;
            mst.push_back(edge);
        }
    }

    for (Edge e : edges)
    {
        cout << e.u << " " << e.v;
    }

    return mstWeight;
}