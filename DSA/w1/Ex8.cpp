#include <cctype>
#include <fstream>
#include <iostream>

void checkPalindrome(const std::string &line)
{
    int beg = 0;
    int end = line.size() - 1;
    while (!std::isalpha(line[beg]))
        beg++;
    while (!std::isalpha(line[end]))
        end--;
    while (beg < end)
    {
        if (std::tolower(line[beg]) != std::tolower(line[end]))
        {
            std::cout << "false\n";
            return;
        }
        beg++;
        end--;
        while (!std::isalpha(line[beg]))
            beg++;
        while (!std::isalpha(line[end]))
            end--;
    }
    std::cout << "true\n";
    return;
}

int main()
{
    std::fstream file("input1.8.1.txt", std::ios_base::in);
    if (!file.is_open())
        std::cerr << "cant open file";

    std::string line;
    while (std::getline(file, line))
    {
        checkPalindrome(line);
    }

    return 0;
}