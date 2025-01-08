#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

struct Edge
{
    int from, to, weight;
};

bool detectNegativeCycle(int n, const vector<Edge> &edges)
{
    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;

    // 松弛操作
    for (int i = 1; i < n; i++)
    {
        for (const auto &edge : edges)
        {
            if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.weight < dist[edge.to])
            {
                dist[edge.to] = dist[edge.from] + edge.weight;
            }
        }
    }

    for (const auto &edge : edges)
    {
        if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.weight < dist[edge.to])
        {
            return true; // 存在负权回路
        }
    }
    return false;
}

int main()
{
    int F;
    cin >> F;

    while (F--)
    {
        int N, M, W;
        cin >> N >> M >> W;

        vector<Edge> edges;

        for (int i = 0; i < M; i++)
        {
            int S, E, T;
            cin >> S >> E >> T;
            edges.push_back({S, E, T});
            edges.push_back({E, S, T});
        }

        for (int i = 0; i < W; i++)
        {
            int S, E, T;
            cin >> S >> E >> T;
            edges.push_back({S, E, -T});
        }

        if (detectNegativeCycle(N, edges))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
