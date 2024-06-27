#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Student
{
    string name;
    string ID;
    double math;
    double lit;
};

struct ListNode
{
    Student   data;
    ListNode *next;
    ListNode *prev;
    ListNode(Student data, ListNode *next = nullptr, ListNode *prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

struct LinkedList
{
    ListNode *first;
    LinkedList()
    {
        this->first = nullptr;
    }
};

void deleteNode(ListNode *&p)
{
    if (p != nullptr)
    {
        delete p;
        p = nullptr;
    }
}

void deepDeleteNode(ListNode *&p) // vô nghĩa
{
    while (p != nullptr)
    {
        ListNode *temp = p;
        p              = p->next;
        deleteNode(temp);
    }
}

void insertNode(LinkedList &list, ListNode *p)
{
    if (!list.first)
    {
        list.first       = p;
        list.first->next = p;
        list.first->prev = p;
    }
    else
    {
        p->next                = list.first;
        p->prev                = list.first->prev;
        list.first->prev->next = p;
        list.first->prev       = p;
        list.first             = p;
    }
}

void insert(LinkedList &list, Student student)
{
    ListNode *node = new ListNode(student);
    insertNode(list, node);
}

void deleteFirst(LinkedList &list)
{
    if (list.first == nullptr)
        return;

    ListNode *oldFirst = list.first;
    if (oldFirst->next == oldFirst)
    {
        list.first = nullptr;
        deleteNode(oldFirst);
        return;
    }

    list.first           = list.first->next;
    oldFirst->next->prev = oldFirst->prev;
    oldFirst->prev->next = oldFirst->next;
    deleteNode(oldFirst);
}

void insertNodeOrdered(LinkedList &list, ListNode *newNode)
{
    if (list.first == nullptr)
    {
        list.first    = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else
    {
        ListNode *p = list.first;
        do
        {
            if (p->data.ID >= newNode->data.ID)
            {
                break;
            }
            p = p->next;
        } while (p != list.first);

        if (p == list.first)
        {
            list.first = newNode;
        }

        newNode->next = p;
        newNode->prev = p->prev;
        p->prev->next = newNode;
        p->prev       = newNode;
    }
}

void insertOrdered(LinkedList &list, Student student)
{
    ListNode *node = new ListNode(student);
    insertNodeOrdered(list, node);
}

void swapNode(ListNode *a, ListNode *b)
{
    std::swap(a->prev->next, b->prev->next);
    std::swap(a->next, b->next);
    std::swap(a->prev, b->prev);
    std::swap(a->next->prev, b->next->prev);
}

void displayInfo(Student *p)
{
    cout << left;
    cout << setw(20) << p->name;
    cout << setw(15) << p->ID;
    cout << setw(10) << p->math;
    cout << setw(10) << p->lit;
    cout << '\n';
}
void displayHeader()
{
    cout << left;
    cout << setw(20) << "NAME";
    cout << setw(15) << "ID";
    cout << setw(10) << "MATH";
    cout << setw(10) << "LITERATURE";
    cout << '\n';
}
void printList(LinkedList list)
{
    ListNode *p = list.first;
    displayHeader();
    do
    {
        displayInfo(&(p->data));
        p = p->next;
    } while (p != list.first);
}
int main()
{
    ifstream    file("data-grade.csv");
    string      tempLine;
    Student     student;
    LinkedList *list = new LinkedList();
    getline(file, tempLine);
    while (getline(file, tempLine))
    {
        stringstream ss(tempLine);
        getline(ss, student.name, ',');
        getline(ss, student.ID, ',');
        ss >> student.math;
        ss.ignore();
        ss >> student.lit;
        insertOrdered(*list, student);
    }
    file.close();
    printList(*list);
    return 0;
}