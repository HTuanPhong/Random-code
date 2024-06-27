#include <cstring>
#include <iostream>

int find(char str[], char key[], int n = 0, int m = 0)
{
    if (n < 0 || m < 0)
    {
        return -1;
    }
    int keyLength = strlen(key);
    if (keyLength == m + 1)
    {
        return n - keyLength + 1;
    }
    if (str[n] == '\0')
    {
        return -1;
    }
    if (str[n] == key[m])
    {
        m = m + 1;
    }
    else
    {
        m = 0;
    }
    return find(str, key, n + 1, m);
}

int findLast(char str[], char key[], int n = 0, int prevFound = -1)
{
    if (n < 0)
    {
        return -1;
    }
    int found = find(str, key, n);
    if (found == -1)
    {
        return prevFound;
    }
    return findLast(str, key, found + 1, found);
}

int strDist(char str[], char key[])
{
    int firstFound = find(str, key);
    int lastFound  = findLast(str, key);
    if (firstFound == -1)
    {
        return 0;
    }
    return lastFound + strlen(key) - firstFound;
}

int main()
{
    std::cout << strDist("catcowcat", "cow");
    return 0;
}