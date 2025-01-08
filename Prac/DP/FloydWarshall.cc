#include <vector>
#include <iostream>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<vector<int>> FloydWarshallAPSP(int V, const vector<vector<int>> &graph)
{
    vector<vector<int>> dist(V, vector<int>(V, INF));

    for (int i = 0; i < V; i++)
    {
        dist[i][i] = 0;
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] != INF)
            {
                dist[i][j] = graph[i][j];
            }
        }
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF" << " ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    return dist;
}

int main()
{
    int V = 4; // 节点数量
    vector<vector<int>> graph(V, vector<int>(V, INF));

    // 手动构建一个图
    graph[0][1] = 3;
    graph[0][2] = 5;
    graph[1][2] = 1;
    graph[1][3] = 2;
    graph[2][3] = 1;
    graph[2][0] = 2; // 添加一些边和权重

    // 计算所有节点对之间的最短路径
    FloydWarshallAPSP(V, graph);

    // 打印结果矩阵
    // cout << "Shortest paths matrix:" << endl;
    // for (int i = 0; i < V; i++)
    // {
    //     for (int j = 0; j < V; j++)
    //     {
    //         if (graph[i][j] == INF)
    //         {
    //             cout << "INF" << " ";
    //         }
    //         else
    //         {
    //             cout << graph[i][j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    return 0;
}