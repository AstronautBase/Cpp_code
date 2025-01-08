#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1000006;

vector<int> adj[MAXN];
int color[MAXN]; // 0-未着色，1-颜色1，2-颜色2

bool bfs(int start)
{
    queue<int> q;
    q.push(start);
    color[start] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node])
        {
            if (color[neighbor] == 0)
            {
                color[neighbor] = 3 - color[node];
                q.push(neighbor);
            }
            else if (color[neighbor] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int N, M;
    cin >> N >> M;

    fill(color, color + N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isBipartite = true;

    for (int i = 1; i <= N; i++)
    {
        if (color[i] == 0)
        {
            if (!bfs(i))
            {
                isBipartite = false;
                break;
            }
        }
    }

    if (!isBipartite)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        vector<int> set1, set2;

        for (int i = 1; i <= N; i++)
        {
            if (color[i] == 1)
                set1.push_back(i);
            else if (color[i] == 2)
                set2.push_back(i);
        }

        for (int node : set1)
            cout << node << " ";
        cout << endl;
        for (int node : set2)
            cout << node << " ";
        cout << endl;
    }

    return 0;
}