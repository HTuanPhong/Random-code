#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::fstream file1("input1.4.1.txt", std::ios::in);
    std::fstream file2("input1.4.2.txt", std::ios::in);
    if (!file1.is_open() || !file2.is_open())
        std::cerr << "file open fail";

    std::string line1;
    std::string line2;

    int lineNum = 0;
    while (std::getline(file1, line1))
    {
        lineNum++;
        if (std::getline(file2, line2))
        {
            if (line1 != line2)
            {
                std::cout << lineNum << "// " << line1 << '\n';
                std::cout << lineNum << "\\\\ " << line2 << '\n';
            }
        }
        else
        {
            std::cout << lineNum << "// " << line1 << '\n';
            std::cout << lineNum << "\\\\ " << '\n';
        }
    }
    while (std::getline(file2, line2))
    {
        lineNum++;
        std::cout << lineNum << "// " << '\n';
        std::cout << lineNum << "\\\\ " << line2 << '\n';
    }

    return 0;
}