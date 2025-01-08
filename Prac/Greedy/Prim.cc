#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge
{
    int to;
    int weight;
};

void prim(const vector<vector<Edge>> &graph)
{
    int n = graph.size();
    vector<int> key(n, INF);      // 最小边权重
    vector<int> parent(n, -1);    // 最小边权重对应的顶点
    vector<bool> inMST(n, false); // 是否在最小生成树中

    key[0] = 0;
    // priority_queue<T, Container, Compare> T 数据类型 Container 存放数据的容器 Compare 决定优先级顺序
    // first 权重 second 顶点
    // greater 按权重从小到大维护最小堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 最小堆
    pq.push({0, 0});

    while (!pq.empty())
    {
        // 当前顶点
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;
        inMST[u] = true;

        // 更新与u相连的边 权重最小的边
        for (const Edge &edge : graph[u])
        {
            int v = edge.to;
            int weight = edge.weight;
            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "边 \t 权重\n";
    for (int i = 1; i < n; ++i)
    {
        cout << parent[i] << " - " << i << "\t " << key[i] << endl; // 打印边和权重
    }
}

int main()
{
    // 定义图（邻接表）
    vector<vector<Edge>> graph(5); // 创建一个有5个顶点的图

    // 添加边（无向边）
    graph[0].push_back({1, 2});
    graph[1].push_back({0, 2});
    graph[1].push_back({2, 3});
    graph[1].push_back({4, 5});
    graph[2].push_back({1, 3});
    graph[2].push_back({4, 7});
    graph[3].push_back({0, 6});
    graph[3].push_back({1, 8});
    graph[3].push_back({4, 9});
    graph[4].push_back({1, 5});
    graph[4].push_back({2, 7});
    graph[4].push_back({3, 9});

    prim(graph);
    return 0;
}