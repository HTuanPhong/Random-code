#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
int main()
{
    std::map<std::string, std::set<int>> map;

    std::fstream file;
    file.open("entireShakespeare.txt", std::ios::in);
    if (!file.is_open())
    {
        std::cout << "failure to open file.";
        return 0;
    }
    int         line = 0;
    std::string lineBuffer;
    while (std::getline(file, lineBuffer))
    {
        line++;
        std::transform(lineBuffer.begin(), lineBuffer.end(), lineBuffer.begin(), [](char c)
                       { return (::ispunct(c) && c != '\'') ? ' ' : c; });
        std::stringstream ss(lineBuffer);

        std::string word;
        while (ss >> word)
        {
            if (word.front() == '\'')
            {
                word.erase(0, 1);
            }
            if (word.back() == '\'')
            {
                word.pop_back();
            }
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (word == "")
            {
                continue;
            }
            if (map.find(word) != map.end())
            {
                map[word].insert(line);
            }
            else
            {
                map[word] = std::set<int>{line};
            }
        }
    }

    file.close();
    file.open("index.txt", std::ios::out);
    if (!file.is_open())
    {
        std::cout << "failure to open index file.";
        return 0;
    }
    for (auto i : map)
    {
        file << i.first << ':';
        for (auto j : i.second)
        {
            file << ' ' << j;
        }
        file << '\n';
    }

    return 0;
}