#include <iostream>

struct student
{
    char *name;
    int   age;
    char *address;
};

void printStudent(student *o)
{
    std::cout << o->name << '\n'
              << o->age << '\n'
              << o->address;
}

int main()
{
    char    name[]    = "aaron";
    char    address[] = "19 pp street";
    student somebody  = {.name    = name,
                         .age     = 11,
                         .address = address};

    printStudent(&somebody);
    return 0;
}