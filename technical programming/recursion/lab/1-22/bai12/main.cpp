#include <iostream>

void permutation(char A[], int n, char B[], int k, bool chosen[], int amountChosen = 0)
{
    if (amountChosen == k)
    {
        for (int i = 0; i < k; i++)
        {
            std::cout << B[i];
        }
        std::cout << '\n';
    }
    for (int i = 0; i < n; i++)
    {
        if (chosen[i])
            continue;
        chosen[i]       = 1;
        B[amountChosen] = A[i];
        permutation(A, n, B, k, chosen, amountChosen + 1);
        chosen[i] = 0;
    }
}

int main()
{
    char A[5] = {'A', 'B', 'C', 'D', 'E'};
    char B[5];
    bool chosen[5] = {0};

    permutation(A, 5, B, 3, chosen);
}