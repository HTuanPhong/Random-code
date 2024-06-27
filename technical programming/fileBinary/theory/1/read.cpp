#include <fstream>
#include <iostream>
#pragma pack(1)
using namespace std;
struct Student
{
    char   name[50]{};
    char   ID[10]{};
    double math;
    double lit;
};
int main()
{
    fstream file;
    file.open("data-grade.dat", ios::in | ios::binary);

    Student student;
    while (!file.eof())
    {
        file.read((char *)&student, sizeof(Student));
        std::cout << '\n'
                  << student.name << ' ' << student.ID << ' ' << student.math << ' ' << student.lit;
        file.peek();
    }
    file.close();
    return 0;
}