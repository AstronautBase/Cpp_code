#include <vector>
#include <iostream>
#include <limits>
#include <queue>

using namespace std;
const int INF = numeric_limits<int>::max();

void dijkstra(int start, const vector<vector<pair<int, int>>> &graph)
{
    int n = graph.size();
    vector<int> distance(n, INF);
    distance[start] = 0;

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > distance[u])
            continue;

        for (auto &neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (distance[i] == INF)
            cout << "Distance from " << start << " to " << i << " is INF" << endl;
        else
            cout << "Distance from " << start << " to " << i << " is " << distance[i] << endl;
    }
}

struct Edge
{
    int u, v, weight;
};

bool bellmanFord(int V, int E, const vector<Edge> &edges, int start)
{
    vector<int> distance(V, INF);
    distance[start] = 0;
    for (int i = 1; i <= V - 1; i++)
    {
        for (const auto &edge : edges)
        {
            if (distance[edge.u] != INF && distance[edge.u] + edge.weight < distance[edge.v])
            {
                distance[edge.v] = distance[edge.u] + edge.weight;
            }
        }
    }

    for (const auto &edge : edges)
    {
        if (distance[edge.u] != INF && distance[edge.u] + edge.weight < distance[edge.v])
        {
            cout << "图中存在负权重环" << endl;
            return false;
        }
    }

    cout << "最短路径从源节点 " << start << " 开始:" << endl;
    for (int i = 0; i < V; ++i)
    {
        if (distance[i] == numeric_limits<int>::max())
        {
            cout << "到节点 " << i << " 的距离：INF" << endl;
        }
        else
        {
            cout << "到节点 " << i << " 的距离：" << distance[i] << endl;
        }
    }
    return true; // 没有负权重环
}