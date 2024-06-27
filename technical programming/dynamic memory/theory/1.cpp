#include <fstream>
#include <iostream>
#include <string>

struct Student
{
    std::string name;
    std::string id;
    double      math, literature;
};

void extendDynamicArray(Student *&a, int &max)
{
    Student *b = new Student[max * 2];
    for (int i = 0; i < max; i++)
    {
        b[i] = a[i];
    }
    max *= 2;
    delete[] a;
    a = b;
}

void printData(const Student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << s[i].name << ','
                  << s[i].id << ','
                  << s[i].math << ','
                  << s[i].literature << '\n';
    }
}

void RemoveStudent(Student *&student, int &n, std::string id)
{
    for (int i = 0; i < n; i++)
    {
        if (student[i].id == id)
        {
            student[i] = student[n - 1];
        }
    }
    n -= 1;
}

int main()
{
    std::fstream file("data-grade.csv");
    if (!file.is_open())
    {
        std::cout << "can't open file";
        return 0;
    }
    int         MAX   = 10;
    int         count = 0;
    Student    *a     = new Student[MAX];
    std::string temp;
    std::getline(file, temp);
    while (!file.eof())
    {
        if (count == MAX - 1)
        {
            extendDynamicArray(a, MAX);
        }
        std::getline(file, a[count].name, ',');
        std::getline(file, a[count].id, ',');
        file >> a[count].math;
        file.ignore();
        file >> a[count].literature;
        count++;
    }
    file.close();
    RemoveStudent(a, count, "14000053");
    printData(a, count);
    return 0;
}