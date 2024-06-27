#include <fstream>
#include <iostream>

long long fileSizeToDecimal(const char fileSizeField[12])
{
    long long result = 0;
    for (int i = 0; i < 11; i++)
    {
        result = result * 8 + (fileSizeField[i] - '0');
    }
    return result;
}

void printFiles(const char *tarFile)
{
    while (true)
    {
        if (*tarFile == 0)
            return;
        std::cout << tarFile << ' ';
        tarFile += 124;
        long long fileSize = fileSizeToDecimal(tarFile);
        std::cout << fileSize << '\n';
        tarFile += 388 + (fileSize / 512 + (bool)(fileSize % 512)) * 512; // 389 = 512 - 124
    }
}

int main()
{
    /*cách stream*/
    // std::fstream file;
    // file.open("2208.11970.tar.gz", std::ios::in | std::ios::binary);
    // char name[100];
    // char size[12];
    // while (true)
    // {
    //     file.read(name, 100);
    //     if (name[0] == 0)
    //         break;
    //     file.seekg(24, std::ios::cur);
    //     file.read(size, 12);
    //     long long fileSize = fileSizeToDecimal(size);
    //     file.seekg(376 + (fileSize / 512 + (bool)(fileSize % 512)) * 512, std::ios::cur); // 376 = 512-(124+12)
    //     std::cout << name << ' ';
    //     std::cout << fileSize << '\n';
    // }

    /*cách char pointer*/
    std::string str;
    {
        std::ifstream file("2208.11970.tar.gz", std::ios::binary); // open file for input

        // copy the contents of the file to a to a C++ string
        char c;
        while (file.get(c))
            str += c;
    }

    const char *buffer = str.c_str(); // pointer to first char in the string
    printFiles(buffer);
    return 0;
}