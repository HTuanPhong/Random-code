#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>

int main()
{
    std::set<std::string> words;
    std::fstream          file;
    file.open("shakespeare.txt", std::ios::in);
    if (!file.is_open())
    {
        std::cout << "failure to open file.";
        return 0;
    }
    std::string buffer;
    while (true)
    {
        file >> buffer;
        if (file.eof())
            break;
        char last = buffer.back();
        if (last == '?' || last == ',' || last == '!' || last == ';' || last == '.' || last == ':')
        {
            buffer.pop_back();
        }
        std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);
        words.insert(buffer);
    }
    file.close();
    for (auto i : words)
    {
        std::cout << i << '\n';
    }

    return 0;
}