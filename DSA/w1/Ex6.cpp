#include <iostream>

class Stack
{
  private:
    int   curSize = 0;
    int   maxSize;
    char *arr;

  public:
    Stack(int maxSize)
        : maxSize(maxSize), arr(new char[maxSize])
    {
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool pop()
    {
        if (isEmpty())
        {
            std::cerr << "Attempted to pop an empty stack.\n";
            return false;
        }
        curSize--;
        return true;
    }

    bool push(char c)
    {
        if (isFull())
        {
            std::cerr << "Attempted to push a full stack.\n";
            return false;
        }
        arr[curSize++] = c;
        return true;
    }

    int size()
    {
        return curSize;
    }

    char top()
    {
        if (isEmpty())
        {
            std::cerr << "Attempted to top an empty stack.\n";
            return 0;
        }
        return arr[curSize - 1];
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
            std::cout << arr[i] << ", ";
        }
        std::cout << arr[i];
    }
};

int main()
{
    std::cout << "Enter size: ";
    int n;
    std::cin >> n;
    Stack stack(n);
    int   chosen;
    while (chosen != 3)
    {
        std::cout << "type a number (1 pop, 2 push, 3 exit):\n";
        do
        {
            std::cin >> chosen;
        } while (chosen < 1 || chosen > 2);
        if (chosen == 1)
        {
            stack.pop();
        }
        else if (chosen == 2)
        {
            char pushVal;
            std::cout << "push value: ";
            std::cin >> pushVal;
            stack.push(pushVal);
        }
        stack.print();
        std::cout << " <- top\n";
    }
    return 0;
}