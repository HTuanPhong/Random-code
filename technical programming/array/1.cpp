#include <iostream>

void setArray(int a[], int &n) {
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cout << "a[" << i << "] = ";
        std::cin >> a[i];
    }
}

void printArray(int a[], int n) {
    std::cout << "{ ";
    for (int i = 0; i < n-1; i++)
    {
        std::cout << a[i] <<  ", "; 
    }
    std::cout << a[n-1] << " }" << '\n';
}

int sumArray(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}

int findMin(int a[], int n) {
    int min = a[0];
    for (int i = 0; i < n; i++)
    {
        min = min < a[i] ? min : a[i];
    }
    return min;
}

bool checkPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int countNumberofPrime(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkPrime(a[i])) count++;
    }
    return count;
}

bool isAscendingOrder(int a[], int n) {
    for (int i = 0; i < n-1; i++)
    {
        if (a[i+1] < a[i]) return false;
    }
    return true;
}

int countOccurrences(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x) count++;
    }
    return count;
}

void deleteItems(int a[], int &n, int x) {
    int removed = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x) removed++;         
        else a[i-removed] = a[i];
    }
    n -= removed;
}

void deleteItemsFromIndex(int a[], int &n, int index, int no_items) {
    for (int i = index + no_items; i < n; i++)
    {
        a[i-no_items] = a[i];
    }
    n -= no_items;
}

void concatTwoArrays(int a[], int n, int b[], int m, int c[]) {
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i];
    }
    for (int i = 0; i < m; i++)
    {
        c[n+i] = b[i];
    }
}

void concatInterspersedlyTwoArrays(int a[], int n, int b[], int m, int c[]) {
    int ia = 0, ib = 0, ic = 0;

    while (ia < n && ib < m) {
        c[ic++] = a[ia++];
        c[ic++] = b[ib++];
    }

    while (ia < n)
        c[ic++] = a[ia++];

    while (ib < m)
        c[ic++] = b[ib++];

    // dc lay idea ra tu mot algorithm khac
}

int main() {
    int n = 5;
    int array[n] = { 2,3,3,1,2 };
    printArray(array, n);
    std::cout << "sum array: " << sumArray(array, n) << '\n';
    std::cout << "find min: " << findMin(array, n) << '\n';
    std::cout << "count prime: " << countNumberofPrime(array, n) << '\n';
    std::cout << "isAscendingOrder: " << isAscendingOrder(array, n) << '\n';
    std::cout << "countOccurrences: " << countOccurrences(array, n, 1) << '\n';
    deleteItems(array, n, 2);
    std::cout << "deleteItems: ";
    printArray(array, n);
    int n1 = 3;
    int a[n1] = {1,2,3};
    int m = 5;
    int b[m] = {1,2,3,4,5};
    int c[m+n1];

    concatInterspersedlyTwoArrays(a,n1,b,m,c);
    printArray(c, n1+m);
    return 0;
}