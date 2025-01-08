#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<int> size1, dp; // size 子树大小 dp 到其他节点距离之和
int n;

// 计算每个节点子树大小和子树内距离之和
void dfs1(int node, int parent)
{
    size1[node] = 1;
    for (int neighbor : tree[node])
    {
        if (neighbor == parent)
            continue;
        dfs1(neighbor, node);
        size1[node] += size1[neighbor];
        dp[node] += dp[neighbor] + size1[neighbor];
    }
}

// 每个节点的子树外距离之和
void dfs2(int node, int parent)
{
    for (int neighbor : tree[node])
    {
        if (neighbor == parent)
            continue;
        dp[neighbor] = dp[node] - size1[neighbor] + (n - size1[neighbor]);
        // size1[neighbor] neighbor对dp[node]的贡献
        // dp[node] - size1[neighbor] 去掉neighbor的贡献 node到子树外的距离和
        // n - size1[neighbor] neighbor经过node到其他节点多的距离 每个多1
        dfs2(neighbor, node);
    }
}

int main()
{
    cin >> n;
    tree.resize(n);
    size1.resize(n, 0);
    dp.resize(n, 0);

    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs1(0, -1);
    dfs2(0, -1);

    for (int i = 0; i < n; ++i)
    {
        cout << dp[i] << " ";
    }
    cout << endl;

    return 0;
}