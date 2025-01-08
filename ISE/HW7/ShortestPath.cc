#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100005;
const int MAXM = 1000006;

vector<int> adj[MAXN];
int dist[MAXN];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    fill(dist, dist + N + 1, -1);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);

    for (int i = 2; i <= N; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}