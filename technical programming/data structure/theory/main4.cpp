#include <iostream>

struct Queue
{
    int  last, first;
    int *arr;
    int  fullSize;
    Queue(int n)
    {
        last     = fullSize - 1;
        first    = fullSize;
        fullSize = n;
        arr      = new int[n];
    }

    void enQueue(int val)
    {
        if ((last + 1) % fullSize == first)
        {
            return;
        }

        last      = (last + 1) % fullSize;
        arr[last] = val;
        first     = first % fullSize;
    }

    void deQueue()
    {
        if (first == fullSize)
        {
            return;
        }
        if (first == last)
        {
            first = fullSize;
            last  = fullSize - 1;
        }
        else
        {
            first = (first + 1) % fullSize;
        }
    }

    void print()
    {
        if (first == -1)
        {
            return;
        }
        if (last >= first)
        {
            for (int i = first; i <= last; i++)
                std::cout << arr[i] << ' ';
        }
        else
        {
            for (int i = first; i < fullSize; i++)
                std::cout << arr[i] << ' ';

            for (int i = 0; i <= last; i++)
                std::cout << arr[i] << ' ';
        }
        std::cout << '\n';
    }
};

int main()
{
    Queue que(4);
    que.enQueue(1);
    que.enQueue(2);
    que.enQueue(3);
    que.enQueue(4);
    que.deQueue();
    que.enQueue(5);
    que.deQueue();
    que.enQueue(6);
    que.deQueue();
    que.enQueue(7);
    que.print();
    return 0;
}