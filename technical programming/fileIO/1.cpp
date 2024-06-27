#include <fstream>
#include <iostream>
#include <string>

int copyFile(char input[], char output[])
{
    std::fstream ifile;
    ifile.open(input, std::fstream::in);
    if (!ifile.is_open())
    {
        std::cout << "cant open input file!";
        return false;
    }

    std::fstream ofile;
    ofile.open(output, std::fstream::out | std::fstream::app);
    if (!ofile.is_open())
    {
        std::cout << "cant open output file!";
        return false;
    }

    std::string data;
    while (getline(ifile, data))
    {
        ofile << data << '\n';
    }

    ifile.close();
    ofile.close();
    return true;
}

int convertFile60CharsperLine(char input[], char output[])
{
    std::fstream ifile;
    ifile.open(input, std::fstream::in);
    if (!ifile.is_open())
    {
        std::cout << "cant open input file!";
        return false;
    }

    std::fstream ofile;
    ofile.open(output, std::fstream::out | std::fstream::app);
    if (!ofile.is_open())
    {
        std::cout << "cant open output file!";
        return false;
    }

    std::string dataNoDownLine;
    std::string data;
    while (getline(ifile, data))
    {
        dataNoDownLine += data;
    }

    for (int i = 0; i < dataNoDownLine.size(); i++)
    {
        ofile << dataNoDownLine[i];
        if ((i + 1) % 60 == 0)
        {
            ofile << '\n';
        }
    }

    ifile.close();
    ofile.close();
    return true;
}

double countAverageChar(char input[])
{
    std::fstream ifile;
    ifile.open(input, std::fstream::in);
    if (!ifile.is_open())
    {
        std::cout << "cant open input file!";
        return false;
    }

    std::string data;
    int sum = 0;
    int i = 0;
    while (getline(ifile, data))
    {
        i++;
        sum += data.size();
    }

    ifile.close();
    return sum * 1.0 / i;
}

int printSource()
{
    std::fstream ifile;
    ifile.open(__FILE__, std::fstream::in);
    if (!ifile.is_open())
    {
        std::cout << "cant open input file!";
        return false;
    }

    std::string data;
    while (getline(ifile, data))
    {
        std::cout << data << '\n';
    }

    ifile.close();
    return true;
}

int sumMatrix(char input[])
{
    std::fstream ifile;
    ifile.open(input, std::fstream::in);
    if (!ifile.is_open())
    {
        std::cout << "can't open input file.";
        return 0;
    }

    int m, n;
    int sum = 0;
    ifile >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int data;
            ifile >> data;
            sum += data;
        }
    }
    ifile.close();
    return sum;
}

void sortListName(char input[])
{
    std::fstream ifile;
    ifile.open(input, std::ifstream::in);
    if (!ifile.is_open())
    {
        std::cout << "can't open input file.";
        return;
    }
    char data[10][10];
    int n = 0;
    while (ifile.getline(data[n], 10))
    {
        n++;
    }

    char alphabet[52] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F',
                         'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k',
                         'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q',
                         'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v',
                         'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z'};
    for (char key : alphabet)
    {
        for (int i = 0; i < n; i++)
        {
            if (data[i][0] == key)
            {
                std::cout << data[i] << '\n';
            }
        }
    }
}

int main()
{
    char input[] = "input.txt";
    char output[] = "output.txt";

    return 0;
}