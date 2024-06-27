#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::fstream ifile;
    ifile.open("input1.3.txt", std::fstream::in);
    if (!ifile.is_open())
    {
        std::cerr << "fail to open file in";
        return 0;
    }
    std::fstream ofile;
    ofile.open("output1.3.txt", std::fstream::out);
    if (!ofile.is_open())
    {
        std::cerr << "fail to open fileout";
        return 0;
    }

    int d;
    ifile >> d;

    std::string buff;
    std::getline(ifile, buff);
    ofile << "avg high low\n";
    for (int i = 0; i < d; i++)
    {
        std::getline(ifile, buff);
        std::stringstream ss(buff);
        std::string       tempString;
        ss >> tempString;
        double temp  = std::stod(tempString);
        double max   = temp;
        double min   = temp;
        double sum   = 0;
        int    count = 1;
        while (ss >> tempString)
        {
            double temp = std::stod(tempString);
            if (max < temp)
                max = temp;
            if (min > temp)
                min = temp;
            sum += temp;
            count++;
        }
        ofile << sum / count << ' ' << max << ' ' << min << '\n';
    }

    ofile.close();
    ifile.close();
}