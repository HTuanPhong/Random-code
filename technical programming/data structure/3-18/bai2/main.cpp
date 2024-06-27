#include <iostream>

struct Queue
{
    int  curSize = 0;
    int  maxSize = 10;
    int *queue   = new int[maxSize];

    int front()
    {
        if (empty())
        {
            std::cerr << "Attempted to front an empty queue.";
            return 0;
        }
        return queue[0];
    }

    int back()
    {
        if (empty())
        {
            std::cerr << "Attempted to back an empty queue.";
            return 0;
        }
        return queue[curSize - 1];
    }

    int size()
    {
        return curSize;
    }

    bool push(int num)
    {
        if (curSize == maxSize)
        {
            std::cerr << "Attempted to push a full queue.";
            return false;
        }
        curSize++;
        for (int i = curSize - 1; i > 0; i--)
        {
            queue[i] = queue[i - 1];
        }
        queue[0] = num;
        return true;
    }

    int pop()
    {
        if (empty())
        {
            std::cerr << "Attempted to pop an empty queue.";
            return 0;
        }
        return queue[--curSize];
    }

    bool empty()
    {
        return !curSize;
    }
};

int main()
{
    Queue queue;
    std::cout << queue.empty() << '\n';
    std::cout << queue.push(1) << '\n';
    queue.push(2);
    queue.push(3);
    std::cout << queue.size() << '\n';
    std::cout << queue.front() << '\n';
    std::cout << queue.back() << '\n';
    return 0;
}

// struct Queue
// {
//     int   front, back, currentSize, maxSize;
//     char *array;

//     Queue(int n)
//     {
//         array       = new char[n];
//         maxSize     = n;
//         front       = 0;
//         back        = n - 1;
//         currentSize = 0;
//     }

//     ~Queue()
//     {
//         delete[] array;
//     }

//     char peekFront()
//     {
//         if (empty())
//         {
//             std::cerr << "Attempted to peek empty queue.";
//             return -1;
//         }

//         return array[front];
//     }

//     char peekBack()
//     {
//         if (empty())
//         {
//             std::cerr << "Attempted to peek empty queue.";
//             return -1;
//         }

//         return array[back];
//     }

//     int size()
//     {
//         return currentSize;
//     }

//     bool empty()
//     {
//         return !currentSize;
//     }

//     bool full()
//     {
//         return (currentSize == maxSize);
//     }

//     bool push(char c)
//     {
//         if (full())
//         {
//             return false;
//         }
//         back        = (back + 1) % maxSize;
//         array[back] = c;
//         currentSize++;
//         return true;
//     }

//     char pop()
//     {
//         if (empty())
//         {
//             std::cerr << "Attempted to pop an empty queue.";
//             return -1;
//         }
//         char result = array[front];
//         front       = (front + 1) % maxSize;
//         currentSize--;
//         return result;
//     }
// };