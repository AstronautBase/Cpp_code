#include <iostream>

int mult(int a, int b)
{
    int alen = 0, blen = 0;
    int aarr[1000], barr[1000];
    while (a)
    {
        aarr[alen++] = a % 10;
        a /= 10;
    }
    while (b)
    {
        barr[blen++] = b % 10;
        b /= 10;
    }
    int res[2000] = {0};
    for (int i = 0; i < alen; i++)
    {
        int carry = 0;
        for (int j = 0; j < blen; j++)
        {
            int tmp = aarr[i] * barr[j] + carry + res[i + j];
            carry = tmp / 10;
            res[i + j] = tmp % 10;
        }
    }
    int ans = 0;
    for (int i = 0; i < alen + blen; i++)
    {
        ans = ans * 10 + res[i];
    }
    return ans;
}

int main()
{
    return 0;
}