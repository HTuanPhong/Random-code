#include <iostream>

void checkSubsetSum(int start, int nums[], int n, int target, bool &result, int sum = 0)
{
    if (start == n)
    {
        if (sum == target)
        {
            result = true;
            return;
        }
    }
    else
    {
        checkSubsetSum(start + 1, nums, n, target, result, sum);
        sum += nums[start];
        checkSubsetSum(start + 1, nums, n, target, result, sum);
        sum -= nums[start];
    }
}

bool groupSum(int start, int nums[], int n, int target)
{
    bool result = false;
    checkSubsetSum(start, nums, n, target, result);

    return result;
}

int main()
{
    int a[] = {2, 4, 8};
    std::cout << groupSum(0, a, 3, 9);
    return 0;
}