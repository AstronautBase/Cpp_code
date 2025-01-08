#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 程序段 A: 按行分配数组元素
void assign_array_rows(int M, int N)
{
    vector<vector<int>> a(M, vector<int>(N));
    auto start = high_resolution_clock::now();
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[i][j] = i + j;
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();
    cout << "Program A (rows) with M=" << M << ", N=" << N << " took " << duration << " microseconds." << endl;
}

// 程序段 B: 按列分配数组元素
void assign_array_cols(int M, int N)
{
    vector<vector<int>> a(M, vector<int>(N));
    auto start = high_resolution_clock::now();
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            a[i][j] = i + j;
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();
    cout << "Program B (cols) with M=" << M << ", N=" << N << " took " << duration << " microseconds." << endl;
}

int main()
{
    int M_values[] = {10000, 1000, 100};
    int N_values[] = {100, 1000, 10000};

    for (int i = 0; i < 3; i++)
    {
        int M = M_values[i];
        int N = N_values[i];
        assign_array_rows(M, N);
        assign_array_cols(M, N);
    }

    return 0;
}

/*
Program A (rows) with M=10000, N=100 took 1999 microseconds.
Program B (cols) with M=10000, N=100 took 4003 microseconds.
Program A (rows) with M=1000, N=1000 took 2000 microseconds.
Program B (cols) with M=1000, N=1000 took 6533 microseconds.
Program A (rows) with M=100, N=10000 took 3008 microseconds.
Program B (cols) with M=100, N=10000 took 2999 microseconds.
*/