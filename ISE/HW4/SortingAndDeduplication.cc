#include <iostream>
#include <vector>

int main()
{
    const int MAX_NUMBER = 100000000;
    std::vector<bool> exists(MAX_NUMBER, false);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int number;
    while (std::cin >> number)
    {
        exists[number] = true;
    }

    for (int i = 0; i < MAX_NUMBER; ++i)
    {
        if (exists[i])
        {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";

    return 0;
}
