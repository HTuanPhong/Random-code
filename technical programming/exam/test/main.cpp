#include <iostream>

typedef double Array2D[100][100];

void scaleArray(Array2D b, int m, int n, double desiredSum)
{
    // Compute the current sum
    double currentSum = 0.0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            currentSum += b[i][j];
        }
    }

    // Calculate the scaling factor
    double scalingFactor = desiredSum / currentSum;

    // Scale the array
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] *= scalingFactor;
        }
    }

    // Verify the sum of the scaled array
    double scaledSum = 0.0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scaledSum += b[i][j];
        }
    }

    // Output the scaled array and its sum
    std::cout << "Scaled Array:" << std::endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << b[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Sum of Scaled Array: " << scaledSum << std::endl;
}

int main()
{
    int     m          = 3;
    int     n          = 3;
    double  desiredSum = 4.0;
    Array2D b          = {
        {1.0, 2.0, 3.0},
        {0.5, 1.0, 1.5},
        {0.2, 0.3, 0.5}};

    scaleArray(b, m, n, desiredSum);

    return 0;
}