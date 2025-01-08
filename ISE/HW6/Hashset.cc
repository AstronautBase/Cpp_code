#include <iostream>
#include <vector>
#include <unordered_set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;

    while (T--)
    {
        int n;
        std::cin >> n;

        std::vector<int> numbers(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> numbers[i];
        }

        std::unordered_set<int> seen;
        std::vector<int> unique_numbers;

        for (int num : numbers)
        {
            if (seen.find(num) == seen.end())
            {
                seen.insert(num);
                unique_numbers.push_back(num);
            }
        }

        for (size_t i = 0; i < unique_numbers.size(); ++i)
        {
            std::cout << unique_numbers[i];
            if (i < unique_numbers.size() - 1)
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}