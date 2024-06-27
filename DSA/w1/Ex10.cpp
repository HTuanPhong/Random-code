#include <fstream>
#include <iostream>

struct Date
{
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct Student
{
    char name[128];
    Date birthdate;
    char address[256];
};

int main()
{
    std::fstream file("output1.9.bin", std::ios_base::in | std::ios_base::binary);
    if (!file.is_open())
        std::cerr << "cant open file";

    Student buff;
    while (file.read((char *)&buff, sizeof(Student)))
    {
        std::cout << "Name: " << buff.name << '\n';
        std::cout << "Birthdate (dd/mm/yy): "
                  << buff.birthdate.day << '/'
                  << buff.birthdate.month << '/'
                  << buff.birthdate.year << '\n';
        std::cout << "Address: " << buff.address << '\n';
    }

    return 0;
}