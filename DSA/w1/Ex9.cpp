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
    std::fstream file("output1.9.bin", std::ios_base::out | std::ios_base::binary);
    if (!file.is_open())
        std::cerr << "cant open file";

    while (true)
    {
        Student stu{};
        std::cout << "Name(128 characters): ";
        std::cin.getline(stu.name, 128);

        std::cout << "Birthdate dd mm yy: ";
        std::cin >> stu.birthdate.day;
        std::cin >> stu.birthdate.month;
        std::cin >> stu.birthdate.year;
        std::cin.ignore();

        std::cout << "Address(256 characters): ";
        std::cin.getline(stu.address, 256);

        file.write((char *)&stu, sizeof(Student));
        std::cout << "Continue? Y/N\n";
        char ans;
        std::cin.get(ans);
        std::cin.ignore();
        if (ans == 'N')
            break;
    }
}