#include <iostream>
template <typename T>
class Node
{
  private:
  public:
    Node *next;
    T     data;

    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
bool detectCycle(Node<T> *head)
{
    if (head == nullptr)
    {
        return false;
    }

    Node<T> *fastP = head;
    Node<T> *slowP = head;

    while (fastP != nullptr)
    {
        fastP = fastP->next;
        if (fastP == slowP)
        {
            return true;
        }
        if (fastP != nullptr)
        {
            fastP = fastP->next;
            slowP = slowP->next;
        }
    }
    return false;
}

int main()
{
    Node<int> a(5);
    Node<int> b(5);
    Node<int> c(5);
    Node<int> d(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &c;
    std::cout << detectCycle(&a);
    return 0;
}