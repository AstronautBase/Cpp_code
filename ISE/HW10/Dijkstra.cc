#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int start, int end, const vector<vector<pair<int, int>>> &graph)
{
    int n = graph.size();
    vector<int> distance(n, INF);
    distance[start] = 0;

    using pii = pair<int, int>; // (distance, vertex)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int d = pq.top().first;  // distance
        int u = pq.top().second; // vertex
        pq.pop();

        if (d > distance[u])
            continue;

        for (const auto &neighbor : graph[u])
        {
            int v = neighbor.first;       // vertex
            int weight = neighbor.second; // weight

            if (distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    cout << distance[end] << endl;
}

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(s, t, adj);
}