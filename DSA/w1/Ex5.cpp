#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int          first;
    unsigned int n;
    std::string  path;
    std::cin >> first >> n >> path;

    std::fstream file(path, std::ios_base::in);
    if (!file.is_open())
        std::cerr << "cant open file\n";

    switch (first)
    {
    case 1:
    {
        file.seekg(-1, std::ios_base::end);
        long long   pos = file.tellg();
        int         i   = 0;
        std::string line;
        while (file.tellg() > 0)
        {
            if (file.peek() == '\n')
            {
                pos--;
                i++;
            }

            if (i == n)
            {
                file.seekg(pos + 2, std::ios_base::beg);
                break;
            }
            pos--;
            file.seekg(pos, std::ios_base::beg);
        }
        while (std::getline(file, line))
        {
            std::cout << line << '\n';
        }
    }
    break;
    case 0:
    {
        int         i = 0;
        std::string line;
        while (std::getline(file, line))
        {
            i++;
            std::cout << line << '\n';
            if (i == n)
                break;
        }
    }
    break;

    default:
        std::cerr << "nono babibi only 0 and 1\n";
        break;
    }

    return 0;
}