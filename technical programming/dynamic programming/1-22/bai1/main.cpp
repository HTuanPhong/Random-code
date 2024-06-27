#include <iostream>

int longestNonDecreasingSubArray(const int arr[], int n, int subOptimal[])
{
    int length[n] = {};
    int maxAt     = 0;

    for (int i = 0; i < n; i++)
    {
        // get longest length end at i
        length[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] <= arr[i] && length[i] < length[j] + 1) // the latter condition is for max
            {                                                  // a=max(a,b) b/c of the two a we can do this.
                length[i] = length[j] + 1;
            }
        }

        // get max index
        if (length[maxAt] < length[i])
        {
            maxAt = i;
        }
    }

    // output
    int j           = length[maxAt] - 1;
    subOptimal[j--] = arr[maxAt];
    int i           = maxAt - 1;
    int last        = maxAt;
    while (i >= 0)
    {
        if (arr[i] <= arr[last] && length[i] == length[last] - 1)
        {
            subOptimal[j--] = arr[i];
            last            = i;
        }
        i--;
    }

    return length[maxAt];
}

int main()
{
    int a[]          = {1, 8, 10, 9, 3, 1, 7, 5, 6, 1, 10, 10, 4};
    int size         = sizeof(a) / sizeof(int);
    int output[size] = {};
    int m            = longestNonDecreasingSubArray(a, size, output);
    std::cout << m << '\n';
    for (int i = 0; i < m; i++)
    {
        std::cout << ' ' << output[i];
    }

    return 0;
}