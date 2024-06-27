#include <fstream>
#include <iostream>
#include <map>
#include <random>
int main()
{
    std::map<std::string, std::string> map;

    std::fstream file;
    std::string  stateBuffer;
    std::string  capitolBuffer;
    file.open("stateCapitols.txt", std::ios::in);
    if (!file.is_open())
    {
        std::cout << "failure to open file.";
        return 0;
    }

    while (true)
    {
        std::getline(file, stateBuffer, ',');
        std::getline(file, capitolBuffer, '\n');
        if (file.eof())
        {
            break;
        }
        map.insert({stateBuffer, capitolBuffer});
    }
    file.close();
    std::random_device rd;
    std::mt19937       mt(rd());
    std::string        answer;
    std::cout << "Respect the names, case and space sensitive!\n";
    while (map.size())
    {
        std::uniform_int_distribution<> dist(0, map.size() - 1);

        auto it = map.begin();
        std::advance(it, dist(mt));
        std::cout << "Whats the capitol of " << it->first << " ?\n";
        std::getline(std::cin, answer);
        if (answer != it->second)
        {
            std::cout << "It was " << it->second << '.';
            return 0;
        }
        map.erase(it->first);
    }
    std::cout << "Congrat! nerd.";
    return 0;
}