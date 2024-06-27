#include <fstream>
#include <iostream>
#include <sstream>
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
    ifstream fileIn("data-grade.csv");
    fstream  fileOut;
    fileOut.open("data-grade.dat", ios::out | ios::binary);
    char    tempLine[1000];
    Student student;
    fileIn.getline(tempLine, 1000);
    while (fileIn.getline(student.name, 50, ','))
    {
        if (student.name == "")
        {
            break;
        }

        fileIn.getline(student.ID, 10, ',');

        fileIn >> student.math;
        fileIn.ignore();
        fileIn >> student.lit;
        fileIn.ignore();

        fileOut.write((char *)&student, sizeof(Student));
        std::cout << '\n'
                  << student.name << ' ';
    }
    fileIn.close();
    fileOut.close();
    return 0;
}
