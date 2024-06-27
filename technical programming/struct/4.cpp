/**
 * Description:
 *          CSC10001 Struct homework
 *          chương trình quản lý một danh sách lớp theo thông tin SinhVien
 *          (ID, tên, điểm Toán, Lý, Hoá), xuất ra điểm trung bình max, min.
 *
 * Original Author:    H.T.Phong
 * Created:   Dec 1, 2023
 *
 **/

#include <iostream>
#include <string>
using std::string;

const int aviableCourses = 3;
const int maxClassSize = 50;
const string coursesName[aviableCourses] = {"math", "physic", "chemistry"};

struct Student
{
    int id;
    string name;
    float scores[aviableCourses]; // math, phys, chem;
};

struct Class
{
    int size;
    Student students[maxClassSize];
};

float getStudentAvg(Student student)
{
    float sum = 0;
    for (int i = 0; i < aviableCourses; i++)
    {
        sum += student.scores[i];
    }
    return sum / aviableCourses;
}

Student findMaxAvgScore(Class c)
{
    Student *studentList = c.students;
    Student maxAvg = studentList[0];
    for (int i = 1; i < c.size; i++)
    {
        if (getStudentAvg(maxAvg) < getStudentAvg(studentList[i]))
        {
            maxAvg = studentList[i];
        }
    }
    return maxAvg;
}

Student findMinAvgScore(Class c)
{
    Student *studentList = c.students;
    Student minAvg = studentList[0];
    for (int i = 1; i < c.size; i++)
    {
        if (getStudentAvg(minAvg) > getStudentAvg(studentList[i]))
        {
            minAvg = studentList[i];
        }
    }
    return minAvg;
}

void getStudentInput(Student &student)
{
    std::cout << "id: ";
    std::cin >> student.id;
    std::cout << "name: ";
    std::cin.ignore();
    std::getline(std::cin, student.name);
    for (int i = 0; i < aviableCourses; i++)
    {
        std::cout << coursesName[i] << " score: ";
        std::cin >> student.scores[i];
    }
}

void getClassInput(Class &c)
{
    std::cout << "class's size: ";
    do
    {
        std::cin >> c.size;

    } while (c.size < 1 || c.size > 50);
    for (int i = 0; i < c.size; i++)
    {
        std::cout << "enter student " << i + 1 << "'s data: " << '\n';
        getStudentInput(c.students[i]);
    }
}

void printStudentData(Student student)
{
    std::cout << "id: " << student.id << '\n';
    std::cout << "name: " << student.name << '\n';
    for (int i = 0; i < aviableCourses; i++)
    {
        std::cout << coursesName[i] << " score: " << student.scores[i] << '\n';
    }
}

void printClassData(Class c)
{
    std::cout << "class's size: " << c.size << '\n';
    for (int i = 0; i < c.size; i++)
    {
        std::cout << "student " << i + 1 << "'s data: " << '\n';
        printStudentData(c.students[i]);
    }
}

int main()
{
    Class abc;
    getClassInput(abc);
    printStudentData(findMaxAvgScore(abc));
    printStudentData(findMinAvgScore(abc));
    return 0;
}