#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge
{
    int src, dest, weight;
};

class DisjointSet
{
public:
    vector<int> parent, rank;

    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]); // 路径压缩
        }
        return parent[u];
    }

    void unionSets(int u, int v)
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
        }
    }
};

bool compareEdges(Edge &a, Edge &b)
{
    return a.weight < b.weight;
}

void kruskal(int n, vector<Edge> &edges)
{
    DisjointSet ds(n);
    vector<Edge> mst;

    sort(edges.begin(), edges.end(), compareEdges);

    for (const Edge &edge : edges)
    {
        int u = edge.src;
        int v = edge.dest;

        if (ds.find(u) != ds.find(v))
        {
            mst.push_back(edge);
            ds.unionSets(u, v);
        }
    }

    for (const Edge &edge : mst)
    {
        cout << edge.src << "-" << edge.dest << "\t 权重：" << edge.weight << endl;
    }
}

int main()
{
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    int n = 4; // 顶点数
    kruskal(n, edges);
    return 0;
}
