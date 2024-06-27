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
class LinkedList
{
  private:
    Node<T> *head;

  public:
    LinkedList()
    {
        this->head = nullptr;
    }

    ~LinkedList()
    {
        Node<T> *p = this->head;
        while (p != nullptr)
        {
            Node<T> *temp = p;

            p = p->next;
            delete temp;
        }
    }

    void append(T data)
    {
        this->insert(-1, data);
    }

    void truncate()
    {
        Node<T> *p = this->head;
        if (p == nullptr)
        {
            return;
        }

        if (p->next == nullptr)
        {
            this->head = nullptr;
            delete p;
            return;
        }

        Node<T> *prev = p;
        p             = p->next;
        while (p->next != nullptr)
        {
            prev = p;
            p    = p->next;
        }
        prev->next = nullptr;
        delete p;
    }

    void print()
    {
        Node<T> *p = this->head;
        while (p != nullptr)
        {
            std::cout << p->data << ' ';
            p = p->next;
        }
    }

    void reverse()
    {
        Node<T> *current = this->head;
        Node<T> *prev = nullptr, *next = nullptr;

        while (current != nullptr)
        {
            next          = current->next;
            current->next = prev;
            prev          = current;
            current       = next;
        }
        this->head = prev;
    }

    int search(T data)
    {
        Node<T> *p      = this->head;
        int      result = 0;
        while (p != nullptr)
        {
            if (p->data == data)
            {
                return result;
            }
            p = p->next;
            result++;
        }
        return -1;
    }

    void insert(int index, T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (this->head == nullptr || index == 0)
        {
            newNode->next = head;
            this->head    = newNode;
            return;
        }

        Node<T> *p     = this->head;
        Node<T> *prev  = nullptr;
        int      count = 0;
        while (p != nullptr)
        {
            if (count == index)
            {
                prev->next    = newNode;
                newNode->next = p;
                return;
            }
            prev = p;
            p    = p->next;
            count++;
        }

        prev->next    = newNode;
        newNode->next = nullptr;
    }

    void remove(int index)
    {
        if (this->head == nullptr)
        {
            return;
        }

        Node<T> *p = this->head;
        if (index == 0)
        {
            this->head = p->next;
            delete p;
            return;
        }

        Node<T> *prev  = nullptr;
        int      count = 0;
        while (p != nullptr)
        {
            if (count == index)
            {
                prev->next = p->next;
                delete p;
                return;
            }
            prev = p;
            p    = p->next;
            count++;
        }
    }
};

int main()
{
    LinkedList<int> list;
    list.append(5);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.print();
    list.reverse();
    std::cout << '\n';
    list.print();
    list.truncate();
    list.truncate();
    std::cout << '\n';
    list.print();
    std::cout << '\n';
    std::cout << list.search(5) << ' ' << list.search(0);
    std::cout << '\n';
    list.insert(2, 37);
    list.remove(0);
    list.print();
    return 0;
}