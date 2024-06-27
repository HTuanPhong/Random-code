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
class CircularLinkedList
{
  private:
    Node<T> *current;

  public:
    CircularLinkedList()
    {
        this->current = nullptr;
    }

    ~CircularLinkedList()
    {
        if (this->current == nullptr)
        {
            return;
        }

        Node<T> *p = this->current;
        do
        {
            Node<T> *temp = p;

            p = p->next;
            delete temp;
        } while (p != this->current);
    }

    void insert(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (this->current == nullptr)
        {
            this->current = newNode;
            newNode->next = newNode;
            return;
        }
        newNode->next       = this->current->next;
        this->current->next = newNode;
    }

    int search(T data)
    {
        if (this->current == nullptr)
        {
            return -1;
        }
        Node<T> *p     = this->current;
        int      count = 0;
        do
        {
            if (p->data == data)
            {
                return count;
            }
            p = p->next;
            count++;
        } while (p != this->current);
        return -1;
    }

    void remove()
    {
        if (this->current == nullptr)
        {
            return;
        }
        Node<T> *p = this->current;
        if (this->current == p->next)
        {
            this->current = nullptr;
            delete p;
        }
        Node<T> *del = p->next;
        p->next      = p->next->next;
        delete del;
    }

    void print()
    {
        if (this->current == nullptr)
        {
            return;
        }
        Node<T> *p = this->current;
        do
        {
            std::cout << p->data;
            p = p->next;
        } while (p != this->current);
    }
};

int main()
{
    CircularLinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.print();
    std::cout << '\n'
              << list.search(2) << '\n';
    list.remove();
    list.remove();
    list.print();
    return 0;
}