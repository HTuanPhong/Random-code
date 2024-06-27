#include <fstream>
#include <iostream>

int linearSearch(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int linearSentinalSearch(int *arr, int n, int key)
{
    int last   = arr[n - 1];
    arr[n - 1] = key;
    int result = -1;
    for (int i = 0;; i++)
    {
        if (arr[i] == key)
        {
            if (i != n - 1 || key == last)
            {
                result = i;
            }
            break;
        }
    }
    arr[n - 1] = last;
    return result;
}

int binarySearch(int *arr, int n, int key)
{
    int left = 0, right = n - 1, mid;
    do
    {
        mid = (left + right) / 2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    } while (left <= right);
    return -1;
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        std::cerr << "not enough argument.";
        return -1;
    }

    std::fstream ifile(argv[3], std::ios::in);
    std::fstream ofile(argv[4], std::ios::out);
    if (!ifile.is_open())
    {
        std::cerr << "bad input file.";
        return -1;
    }

    int result;
    int length;
    int key = std::atoi(argv[2]);
    ifile >> length;
    int *arr = new int[length];
    for (int i = 0; i < length; i++)
    {
        ifile >> arr[i];
    }

    switch (std::atoi(argv[1]))
    {
    case 1:
        result = linearSearch(arr, length, key);
        break;
    case 2:
        result = linearSentinalSearch(arr, length, key);
        break;
    case 3:
        result = binarySearch(arr, length, key);
        break;
    default:
        std::cerr << "bad options";
        return -1;
        break;
    }

    ofile << result;
    ofile.close();
    ifile.close();
    delete[] arr;
    return 0;
}