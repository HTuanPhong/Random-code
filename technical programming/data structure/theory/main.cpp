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
    ListNode(Student data, ListNode *next = nullptr)
    {
        this->data = data;
        this->next = next;
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

void deepDeleteNode(ListNode *&p)
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
    ListNode *oldFirst = list.first;
    list.first         = p;
    p->next            = oldFirst;
}

void insert(LinkedList &list, Student student)
{
    ListNode *node = new ListNode(student);
    insertNode(list, node);
}

// void insertNodeOrdered1(LinkedList &list, ListNode *newNode)
// {
//     if (list.first == nullptr)
//     {
//         list.first    = newNode;
//         newNode->next = nullptr;
//     }
//     else
//     {
//         ListNode *p    = list.first;
//         ListNode *prev = nullptr;
//         while (p != nullptr && p->data.ID < newNode->data.ID)
//         {
//             prev = p;
//             p    = p->next;
//         }

//         if (prev == nullptr)
//         {
//             list.first    = newNode;
//             newNode->next = p;
//         }
//         else
//         {
//             prev->next    = newNode;
//             newNode->next = p;
//         }
//     }
// }

void insertNodeOrdered(ListNode *&nodePtr, ListNode *newNode)
{
    if (nodePtr == nullptr || newNode->data.ID < nodePtr->data.ID)
    {
        newNode->next = nodePtr;
        nodePtr       = newNode;
    }
    else
    {
        insertNodeOrdered(nodePtr->next, newNode);
    }
}

void insertOrdered(LinkedList &list, Student student)
{
    ListNode *node = new ListNode(student);
    insertNodeOrdered(list.first, node);
}

bool ascendingCompareID(ListNode *left, ListNode *right)
{
    return (left->data.ID < right->data.ID);
}

void sortLinkList(LinkedList &list)
{
    ListNode *p1    = list.first;
    ListNode *prev1 = nullptr;

    while (p1 != nullptr)
    {
        ListNode *p2    = p1->next;
        ListNode *prev2 = p1;
        while (p2 != nullptr)
        {
            if (p2->data.ID < p1->data.ID)
            {
                if (prev1 == nullptr)
                {
                    list.first = p2;
                }
                else
                {
                    prev1->next = p2;
                }
                prev2->next = p1;
                std::swap(p1->next, p2->next);
                std::swap(p1, p2);
            }
            prev2 = p2;
            p2    = p2->next;
        }
        prev1 = p1;
        p1    = p1->next;
    }
}

void Qsort(ListNode *&head, ListNode *tail = nullptr)
{
    if (head != tail)
    {
        ListNode *pivot = head;
        ListNode *prev  = head;
        ListNode *p     = head->next;
        while (p != tail)
        {
            if (p->data.ID < pivot->data.ID)
            {
                ListNode *temp = p;
                p              = p->next;
                prev->next     = p;
                temp->next     = head;
                head           = temp;
            }
            else
            {
                prev = p;
                p    = p->next;
            }
        }
        if (pivot != head)
            Qsort(head, pivot);
        Qsort(pivot->next);
    }
}

void Bsort(LinkedList &list)
{
    ListNode *p;
    ListNode *temp;
    for (int i = 0; i < 32; i++)
    {
        p = list.first;
        while (p->next != nullptr)
        {
            if (p->data.ID > p->next->data.ID)
            {
                temp       = p->next;
                p->next    = p->next->next;
                temp->next = p;
                p          = temp;
            }
            p = p->next;
        }
    }
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

    while (p != nullptr)
    {
        displayInfo(&(p->data));
        p = p->next;
    }
}
void printListReverse(LinkedList list)
{
    ListNode *p = list.first;
    displayHeader();

    while (p != nullptr)
    {
        displayInfo(&(p->data));
        p = p->next;
    }
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
        insert(*list, student);
    }
    file.close();
    sortLinkList(*list);
    printList(*list);
    return 0;
}
