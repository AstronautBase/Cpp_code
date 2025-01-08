#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
public:
    UnionFind(int size)
    {
        parent.resize(size + 1);
        for (int i = 0; i <= size; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            parent[rootY] = rootX;
        }
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }

private:
    vector<int> parent;
};

int main()
{
    int N, M;
    cin >> N >> M;
    UnionFind uf(M);

    for (int i = 0; i < N; ++i)
    {
        int operation, x, y;
        cin >> operation >> x >> y;
        if (operation == 1)
        {
            uf.unionSets(x, y);
        }
        else if (operation == 2)
        {
            if (uf.connected(x, y))
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}