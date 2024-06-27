#include <fstream>
#include <iostream>
#include <set>
int main()
{
    std::fstream file;
    file.open("input1.1.txt", std::fstream::in);
    if (!file.is_open())
    {
        std::cerr << "fail to open file";
        return 0;
    }

    int words     = 0;
    int sentences = 0;

    bool inWord = false;
    char buff;
    while (file.get(buff))
    {
        std::cout << buff;
        switch (buff)
        {
        case '.':
        case '!':
        case '?':
            if (file.peek() <= ' ')
            {
                sentences++;
            }
            break;
        default:
            break;
        }
        if (std::isalpha(buff))
        {
            inWord = true;
        }
        if (file.peek() <= ' ' && inWord)
        {
            words++;
            inWord = false;
        }
    }
    file.close();

    std::cout << "\n\n words count: " << words << '\n';
    std::cout << "sentences count: " << sentences;
}