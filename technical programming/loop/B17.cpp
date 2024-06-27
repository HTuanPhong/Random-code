#include <iostream>
#include <iomanip>

int main()
{
    int phut, giay;
    std::cout << "Nhap vao so phut: ";
    std::cin >> phut;
    std::cout << "Nhap vao so giay: ";
    std::cin >> giay;
    std::cout.fill('0');
    for (int i = (phut * 60 + giay); i >= 0; i--)
    {
        std::cout << std::setw(2) << i / 60 << ":" << std::setw(2) << i % 60;
        if (i == 0)
            std::cout << " Reng reng reng";
        else if (i <= 5)
            std::cout << " Tich tac";
        std::cout << '\n';
    }
}