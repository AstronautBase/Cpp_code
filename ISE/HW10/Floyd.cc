#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(M);
    for (int i = 0; i < M; i++)
    {
        cin >> A[i];
        A[i]--;
    }

    vector<vector<int>> danger(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> danger[i][j];
        }
    }

    vector<vector<int>> dist = danger;
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int total_danger = 0;
    for (int i = 1; i < M; i++)
    {
        int from = A[i - 1];
        int to = A[i];
        total_danger += dist[from][to];
    }

    cout << total_danger << endl;

    return 0;
}
