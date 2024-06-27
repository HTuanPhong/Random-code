#include <iostream>

struct charItem
{
    char      data;
    charItem *next;

    charItem(char c)
    {
        next = nullptr;
        data = c;
    }
};

struct Stack
{
    int       currentSize;
    charItem *top;

    Stack()
    {
        currentSize = 0;
        top         = nullptr;
    }

    int size()
    {
        return currentSize;
    }

    void push(char c)
    {
        charItem *newItem = new charItem(c);

        newItem->next = top;
        top           = newItem;
        currentSize++;
    }

    char pop()
    {
        if (top == nullptr)
        {
            std::cerr << "trying to pop empty stack";
            return 0;
        }

        charItem *oldTop = top;
        char      data   = oldTop->data;

        top = oldTop->next;
        delete oldTop;
        currentSize--;
        return data;
    }

    ~Stack()
    {
        charItem *p = top;
        while (p != nullptr)
        {
            charItem *temp = p;

            p = p->next;
            delete temp;
        }
    }
};

struct Queue
{
    int       currentSize;
    charItem *front;
    charItem *back;

    Queue()
    {
        currentSize = 0;
        front       = nullptr;
        back        = nullptr;
    }

    void push(char c)
    {
        charItem *temp = new charItem(c);
        currentSize++;
        if (back == nullptr)
        {
            front = back = temp;
            return;
        }

        back->next = temp;
        back       = temp;
    }

    char pop()
    {
        if (front == nullptr)
        {
            std::cerr << "trying to pop empty queue.";
            return 0;
        }

        charItem *temp = front;
        currentSize--;
        front = front->next;

        if (front == nullptr)
            back = nullptr;

        char res = temp->data;
        delete temp;
        return res;
    }

    int size()
    {
        return currentSize;
    }
};

bool isPalindromes(const char *string)
{
    Stack *halfStack = new Stack;
    Queue *halfQueue = new Queue;

    const char *p1 = string;

    int step = 0;
    while (*p1 != '\0')
    {
        if (*p1 > 96 && *p1 < 123)
        {
            step++;
            halfQueue->push(*p1);
        }
        else if (*p1 > 64 && *p1 < 91)
        {
            step++;
            halfQueue->push(*p1 + 32);
        }
        if (step == 2) // stack will alway half queue
        {
            step = 0;
            halfStack->push(halfQueue->pop());
        }
        p1++;
    }
    if (halfQueue->size() > halfStack->size())
    {
        halfQueue->pop(); // middle
    }

    bool result = true;
    while (halfQueue->size() != 0)
    {
        if (halfQueue->pop() != halfStack->pop())
        {
            result = false;
            break;
        }
    }

    delete halfQueue;
    delete halfStack;
    return result;
}

int main()
{
    char string[] = "aba";
    std::cout << isPalindromes(string);

    return 0;
}