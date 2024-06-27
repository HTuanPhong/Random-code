#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

int main()
{
    // 1.1

    std::array<double, 10> numbers1;

    std::array<double, 10>::iterator ptr1;

    // 1.2

    std::vector<int> numbers2 = {10, 20, 30, 40, 50};

    std::vector<int> v2 = numbers2;

    std::vector<int>::iterator ptr2;

    for (ptr2 = v2.begin(); ptr2 < v2.end(); ptr2++)
    {
        std::cout << *ptr2 << ' ';
    }

    // 1.3

    std::cout << '\n';
    auto arr = std::vector<int>{1, 2, 3, 4};
    for (auto i = arr.begin(); i < arr.end(); i++)
    {
        std::cout << *i << ' ';
    }

    // 1.4

    std::cout << '\n';
    v2.insert(v2.begin() + v2.size() / 2, 5);
    for (auto i = v2.begin(); i < v2.end(); i++)
    {
        std::cout << *i << ' ';
    }

    // 1.5

    std::map<std::string, int> food;
    food.emplace("rice", 100);
    food.emplace("not rice", 200);

    // 1.6

    std::cout << '\n';
    std::vector<int> vec6 = {5, 10, 15, 37};
    std::cout << "result of search for 10: " << std::binary_search(vec6.begin(), vec6.end(), 10);

    return 0;
}