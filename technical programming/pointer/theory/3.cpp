#include <iostream>

struct Person
{
    char         firstName[100];
    char         lastName[100];
    char         title[10];
    unsigned int age;
};

struct Worker
{
    char         firstName[50];
    char         lastName[50];
    char         title[5];
    unsigned int age;
    double       salary = 100;
};

int main()
{
    Person  Tom  = {"tom"};
    Worker  Mary = {"mary"};
    Person *p    = &Tom;
    Worker *q    = &Mary;
    q            = (Worker *)p;
    std::cout << q->firstName;
    return 0;
}