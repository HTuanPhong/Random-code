#include <iostream>
#include <map>
#include <string>

void indexSort(std::string arr[], int n)
{
    std::map<std::string, int> count;
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    auto it    = count.begin();
    int  sum   = it->second;
    it->second = 0;
    it++;
    while (it != count.end())
    {
        it->second += sum;
        it++;
        sum = it->second;
    }
    std::string *aux = new std::string[n];
    for (int i = 0; i < n; i++)
    {
        aux[count[arr[i]]++] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = aux[i];
    }
    delete[] aux;
}

int main()
{
    std::string a[4] = {"a", "b", "c", "a"};

    indexSort(a, 4);

    for (auto &i : a)
    {
        std::cout << i << ' ';
    }

    return 0;
}