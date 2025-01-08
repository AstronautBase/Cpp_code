#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int start, const vector<vector<pair<int, int>>> &graph)
{
    int n = graph.size();
    vector<int> distance(n, INF);
    distance[start] = 0;

    using pii = pair<int, int>; // Pair of (distance, vertex)
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

    for (int i = 0; i < n; ++i)
    {
        if (distance[i] == INF)
            cout << "Distance from " << start << " to " << i << " is INF" << endl;
        else
            cout << "Distance from " << start << " to " << i << " is " << distance[i] << endl;
    }
}

int main()
{
    // Example graph as an adjacency list
    int n = 5; // Number of vertices
    vector<vector<pair<int, int>>> graph(n);

    // Adding edges (source, destination, weight)
    graph[0].emplace_back(1, 10);
    graph[0].emplace_back(2, 3);
    graph[1].emplace_back(2, 1);
    graph[1].emplace_back(3, 2);
    graph[2].emplace_back(1, 4);
    graph[2].emplace_back(3, 8);
    graph[2].emplace_back(4, 2);
    graph[3].emplace_back(4, 7);
    graph[4].emplace_back(3, 9);

    int start = 0; // Starting vertex
    dijkstra(start, graph);

    return 0;
}