#include <fstream>
#include <iostream>
#include <string>

struct Fraction
{
    int num;
    int den;
};

int gcd(int a, int b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if (a == 0 || b == 0)
    {
        return a + b;
    }
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

Fraction toStandardForm(Fraction a)
{
    int gcdResult = gcd(a.num, a.den);
    a.num /= gcdResult;
    a.den /= gcdResult;
    if (a.den < 0)
    {
        a.num = -a.num;
        a.den = -a.den;
    }
    return a;
}

int main()
{
    std::fstream ifile;
    ifile.open("input1.2.txt", std::fstream::in);
    if (!ifile.is_open())
    {
        std::cerr << "fail to open file in";
        return 0;
    }
    std::fstream ofile;
    ofile.open("output1.2.txt", std::fstream::out);
    if (!ofile.is_open())
    {
        std::cerr << "fail to open fileout";
        return 0;
    }

    int r;
    int c;
    ifile >> r;
    ifile >> c;

    std::string buff;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            Fraction frac;
            std::getline(ifile, buff, '/');
            frac.num = std::stoi(buff);
            ifile >> buff;
            frac.den = std::stoi(buff);
            frac     = toStandardForm(frac);
            ofile << frac.num << '/' << frac.den << ' ';
        }
        ofile << '\n';
    }

    ofile.close();
    ifile.close();
}