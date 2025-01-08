#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000000;

vector<int> adj[MAXN];
int state[MAXN];
// 0 未访问 1 访问中 2 已访问

bool hasCycle(int node)
{
    if (state[node] == 1)
        return true;
    if (state[node] == 2)
        return false;

    state[node] = 1;

    for (int neighbor : adj[node])
    {
        if (hasCycle(neighbor))
        {
            return true;
        }
    }

    state[node] = 2;
    return false;
}

int main()
{
    int N, M;
    cin >> N >> M;

    fill(state, state + N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    bool has = false;
    for (int i = 1; i <= N; i++)
    {
        if (state[i] == 0)
        {
            if (hasCycle(i))
            {
                has = true;
                break;
            }
        }
    }

    if (has)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}