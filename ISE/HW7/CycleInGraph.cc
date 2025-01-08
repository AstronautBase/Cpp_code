#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000006;

vector<int> adj[MAXN];
int state[MAXN];
// 访问状态：0 -> 未访问, 1 -> 访问中, 2 -> 已访问

bool hasCycleDFS(int node)
{
    if (state[node] == 1)
    {
        return true;
    }
    if (state[node] == 2)
    {
        return false;
    }

    state[node] = 1;

    for (int neighbor : adj[node])
    {
        if (hasCycleDFS(neighbor))
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

    bool hasCycle = false;
    for (int i = 1; i <= N; i++)
    {
        if (state[i] == 0)
        {
            if (hasCycleDFS(i))
            {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}