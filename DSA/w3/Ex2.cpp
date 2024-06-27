#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Word
{
    std::string word;
    std::string meaning;
};

int linearSearch(const std::vector<Word> &arr, const std::string &key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].word == key)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "not enough argument";
        return 0;
    }

    std::fstream ifile("English-Vietnamese Dictionary.txt", std::ios::in);
    std::fstream ofile(argv[argc - 1], std::ios::out);
    if (!ifile.is_open())
    {
        std::cout << "missing dictionary";
    }

    std::vector<Word> dictionary;
    std::string       word;
    std::string       meaning;
    while (std::getline(ifile, word, ':'))
    {
        for (auto &i : word)
        {
            i = std::tolower(i);
        }
        std::getline(ifile, meaning);
        dictionary.push_back({word, meaning});
    }

    for (int i = 1; i < argc - 1; i++)
    {
        std::string argWord(argv[i]);
        for (auto &i : argWord)
        {
            i = std::tolower(i);
        }
        int res = linearSearch(dictionary, argWord);
        if (res != -1)
        {
            ofile << argWord << ": " << dictionary[res].meaning << '\n';
        }
        else
        {
            ofile << argWord << ": not in dictionary.\n";
        }
    }

    return 0;
}