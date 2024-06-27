#include <iostream>

char *firstNonWhite(char *a)
{
    for (; *a != '\0'; a++)
    {
        if (*a != ' ')
        {
            return a;
        }
    }
    return nullptr;
}

int main()
{
    char str[] = "hello wassup";
    std::cout << *firstNonWhite(str);
    return 0;
}