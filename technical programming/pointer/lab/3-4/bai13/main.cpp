#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

void ERROR_ARG()
{
    std::cout << "Error missing argument! try\n.exe -f \"file path\" or .exe -s \"string\".";
    exit(0);
}

void ERROR_FILE()
{
    std::cout << "Error can't open file!";
    exit(0);
}

int *countChar(char *s)
{
    int *re = new int[95]{};
    while (*s != '\0')
    {
        ++re[(int)*s - 32];
        ++s;
    }
    return re;
}

int *countFile(char *path)
{
    int *re = new int[95]{};

    std::fstream file(path);
    if (!file.is_open())
    {
        ERROR_FILE();
    }

    char s;
    while (file.get(s))
    {
        ++re[(int)s - 32];
    }
    return re;
}

void printStat(int *s)
{
    int max = s[0];
    for (int i = 0; i < 95; i++)
    {
        if (s[i] > max)
        {
            max = s[i];
        }
    }

    for (int i = 0; i < 95; i++)
    {
        if (s[i] > 0)
        {
            std::cout << (char)(i + 32) << ": [";
            int j = 0;
            for (; j < s[i]; j++)
            {
                std::cout << '#';
            }
            for (; j < max + 6; j++)
            {
                std::cout << '.';
            }

            std::cout << "]\n";
        }
    }
    std::cout << "5   ";
    for (int i = 0; i < max + 6; i++)
    {
        if ((i + 1) % 5 == 0)
        {
            std::cout << '^';
        }
        else
        {
            std::cout << ' ';
        }
    }
    std::cout << "\n10  ";
    for (int i = 0; i < max + 6; i++)
    {
        if ((i + 1) % 10 == 0)
        {
            std::cout << '|';
        }
        else
        {
            std::cout << ' ';
        }
    }
    std::cout << "\n20  ";
    for (int i = 0; i < max + 6; i++)
    {
        if ((i + 1) % 20 == 0)
        {
            std::cout << '|';
        }
        else
        {
            std::cout << ' ';
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        ERROR_ARG();
    }

    int *result;
    if (!strncmp(argv[1], "-f", 2))
    {
        result = countFile(argv[2]);
    }
    else if (!strncmp(argv[1], "-s", 2))
    {
        result = countChar(argv[2]);
    }
    else
    {
        ERROR_ARG();
    }

    printStat(result);
    return 0;
}