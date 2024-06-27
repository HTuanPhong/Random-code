#include <iostream>

struct Stack
{
    int   curSize = 0;
    int   maxSize = 10;
    char *stack   = new char[maxSize];

    char pop()
    {
        if (empty())
        {
            std::cerr << "Attempted to pop an empty stack.";
            return -1;
        }
        return stack[--curSize];
    }

    bool push(char c)
    {
        if (curSize == maxSize)
        {
            std::cerr << "Attempted to push a full stack.";
            return false;
        }
        stack[curSize++] = c;
        return true;
    }

    int size()
    {
        return curSize;
    }

    char top()
    {
        if (empty())
        {
            std::cerr << "Attempted to top an empty stack.";
            return -1;
        }
        return stack[curSize - 1];
    }

    bool empty()
    {
        return !curSize;
    }
};

int main()
{
    Stack stack;
    std::cout << stack.empty();
    stack.push('a');
    std::cout << stack.top();
    stack.push('b');
    stack.push('c');
    std::cout << stack.size();
    stack.pop();
    return 0;
}

// struct Stack
// {
//     int   currentSize;
//     int   maxSize;
//     char *array;

//     Stack(int n)
//     {
//         array       = new char[n];
//         maxSize     = n;
//         currentSize = 0;
//     }

//     ~Stack()
//     {
//         delete[] array;
//     }

//     char pop()
//     {
//         if (empty())
//         {
//             std::cerr << "Attempted to pop an empty stack.";
//             return -1;
//         }
//         return array[--currentSize];
//     }

//     bool push(char c)
//     {
//         if (full())
//         {
//             return false;
//         }
//         array[currentSize++] = c;
//         return true;
//     }

//     int size()
//     {
//         return currentSize;
//     }

//     char top()
//     {
//         if (empty())
//         {
//             std::cerr << "Attempted to top an empty stack.";
//             return -1;
//         }
//         return array[currentSize - 1];
//     }

//     bool empty()
//     {
//         return !currentSize;
//     }

//     bool full()
//     {
//         return (currentSize == maxSize);
//     }
// };