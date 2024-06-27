#include <iostream>

void parenBit(char arr[], int n = 0, bool isInParen = false, int removed = 0)
{
    arr[n - removed] = arr[n];
    if (arr[n] == '\0')
    {
        return;
    }
    if (arr[n] == '(')
    {
        isInParen = true;
    }
    if (!isInParen)
    {
        removed++;
    }
    if (arr[n] == ')')
    {
        isInParen = false;
    }
    return parenBit(arr, n + 1, isInParen, removed);
}

int main()
{
    char arr[] = "(xwd)";
    parenBit(arr);
    for (int i = 0; arr[i] != 0; i++)
    {
        std::cout << arr[i];
    }

    return 0;
}