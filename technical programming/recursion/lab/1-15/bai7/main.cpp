#include <iostream>

int sumArray(int nums[], int n, int i = 0, int sum = 0)
{
    if (i == n)
    {
        return sum;
    }
    return sumArray(nums, n, i + 1, sum + nums[i]);
}

void checkSubsetSum(int nums[], int n, int target, bool &result, int i = 0, int sum = 0)
{
    if (i == n)
    {
        if (sum == target)
        {
            result = true;
            return;
        }
    }
    else
    {
        checkSubsetSum(nums, n, target, result, i + 1, sum);
        sum += nums[i];
        checkSubsetSum(nums, n, target, result, i + 1, sum);
        sum -= nums[i];
    }
}

bool splitArray(int nums[], int n)
{
    int totalSum = sumArray(nums, n);
    if (totalSum % 2 != 0)
    {
        return false;
    }
    bool result = false;
    checkSubsetSum(nums, n, totalSum / 2, result);
    return result;
}

int main()
{
    int a[] = {5, 2, 3};
    std::cout << splitArray(a, 3);
    return 0;
}