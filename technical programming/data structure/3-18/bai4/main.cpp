#include <iostream>

struct intItem
{
    int      data;
    intItem *next;

    intItem(int c)
    {
        next = nullptr;
        data = c;
    }
};

struct Stack
{
    int      currentSize;
    intItem *top;

    Stack()
    {
        currentSize = 0;
        top         = nullptr;
    }

    int size()
    {
        return currentSize;
    }

    void push(int c)
    {
        intItem *newItem = new intItem(c);

        newItem->next = top;
        top           = newItem;
        currentSize++;
    }

    int pop()
    {
        if (top == nullptr)
        {
            std::cerr << "trying to pop empty stack";
            return 0;
        }

        intItem *oldTop = top;
        int      data   = oldTop->data;

        top = oldTop->next;
        delete oldTop;
        currentSize--;
        return data;
    }

    ~Stack()
    {
        intItem *p = top;
        while (p != nullptr)
        {
            intItem *temp = p;

            p = p->next;
            delete temp;
        }
    }
};

struct Queue
{
    int      currentSize;
    intItem *front;
    intItem *back;

    Queue()
    {
        currentSize = 0;
        front       = nullptr;
        back        = nullptr;
    }

    void push(int c)
    {
        intItem *temp = new intItem(c);
        currentSize++;
        if (back == nullptr)
        {
            front = back = temp;
            return;
        }

        back->next = temp;
        back       = temp;
    }

    int pop()
    {
        if (front == nullptr)
        {
            std::cerr << "trying to pop empty queue.";
            return 0;
        }

        intItem *temp = front;
        currentSize--;
        front = front->next;

        if (front == nullptr)
            back = nullptr;

        int res = temp->data;
        delete temp;
        return res;
    }

    int size()
    {
        return currentSize;
    }
};

char *shuntingYard(const char *s)
{
    const char *p1 = s;

    Queue *outputs   = new Queue;
    Stack *operators = new Stack;
    while (*p1 != '\0')
    {
        if (*p1 > 47 && *p1 < 58)
        {
            outputs->push(*p1);
        }
        else if (*p1 == '*' || *p1 == '/')
        {
            while (operators->size() && operators->top->data != '(' && (operators->top->data == '*' || operators->top->data == '/'))
            {
                outputs->push(operators->pop());
            }
            operators->push(*p1);
        }
        else if (*p1 == '+' || *p1 == '-')
        {
            while (operators->size() && operators->top->data != '(' && (operators->top->data == '*' || operators->top->data == '/' || operators->top->data == '+' || operators->top->data == '-'))
            {
                outputs->push(operators->pop());
            }
            operators->push(*p1);
        }
        else if (*p1 == '(')
        {
            operators->push(*p1);
        }
        else if (*p1 == ')')
        {
            while (operators->top->data != '(')
            {
                outputs->push(operators->pop());
            }
            operators->pop();
        }
        p1++;
    }
    while (operators->size())
    {
        outputs->push(operators->pop());
    }
    char *result = new char[outputs->size() * 2];
    int   n      = 0;
    while (outputs->size())
    {
        result[n++] = outputs->pop();
        result[n++] = ' ';
    }
    result[n - 1] = '\0';
    delete operators;
    delete outputs;

    return result;
}

int evalRPN(const char *input)
{
    Stack      *stack = new Stack;
    const char *p1    = input;
    while (*p1 != '\0')
    {
        if (*p1 > 47 && *p1 < 58)
        {
            stack->push(*p1 - '0');
        }
        else if (*p1 == '+')
        {
            int op2 = stack->pop();
            int op1 = stack->pop();
            stack->push(op1 + op2);
        }
        else if (*p1 == '-')
        {
            int op2 = stack->pop();
            int op1 = stack->pop();
            stack->push(op1 - op2);
        }
        else if (*p1 == '*')
        {
            int op2 = stack->pop();
            int op1 = stack->pop();
            stack->push(op1 * op2);
        }
        else if (*p1 == '/')
        {
            int op2 = stack->pop();
            int op1 = stack->pop();
            stack->push(op1 / op2);
        }
        p1++;
    }
    int result = stack->pop();
    delete stack;
    return result;
}

int main()
{
    char string[] = "5 + ((1 + 2) * 4) - 3";
    std::cout << string;
    char *result = shuntingYard(string);
    std::cout << " = " << result;
    std::cout << " = " << evalRPN(result);
    return 0;
}