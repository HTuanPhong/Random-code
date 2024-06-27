#include <iostream>

class Queue
{
  private:
    int   curSize  = 0;
    int   frontPos = 0;
    int   maxSize;
    char *arr;

  public:
    Queue(int maxSize)
        : maxSize(maxSize), arr(new char[maxSize])
    {
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool dequeue()
    {
        if (isEmpty())
        {
            std::cerr << "Attempted to pop an empty queue.\n";
            return false;
        }
        frontPos = (frontPos + 1) % maxSize;
        curSize--;
        return true;
    }

    bool enqueue(char c)
    {
        if (isFull())
        {
            std::cerr << "Attempted to push a full stack.\n";
            return false;
        }
        arr[(frontPos + curSize) % maxSize] = c;
        curSize++;
        return true;
    }

    char front()
    {
        if (isEmpty())
        {
            std::cerr << "Attempted to front an empty queue.\n";
            return 0;
        }
        return arr[frontPos];
    }

    int size()
    {
        return curSize;
    }

    bool isFull()
    {
        return (curSize == maxSize);
    }

    bool isEmpty()
    {
        return !curSize;
    }

    void print()
    {
        int i = 0;
        for (; i < curSize - 1; i++)
        {
            std::cout << arr[(frontPos + i) % maxSize] << ", ";
        }
        std::cout << arr[(frontPos + i) % maxSize];
    }
};

int main()
{
    std::cout << "Enter size: ";
    int n;
    std::cin >> n;
    Queue queue(n);
    int   chosen;
    while (chosen != 3)
    {
        std::cout << "type a number (1 dequeue, 2 enqueue, 3 exit):\n";
        do
        {
            std::cin >> chosen;
        } while (chosen < 1 || chosen > 2);
        if (chosen == 1)
        {
            queue.dequeue();
        }
        else if (chosen == 2)
        {
            char pushVal;
            std::cout << "enqueue value: ";
            std::cin >> pushVal;
            queue.enqueue(pushVal);
        }
        std::cout << "front -> ";
        queue.print();
        std::cout << '\n';
    }
    return 0;
    return 0;
}
