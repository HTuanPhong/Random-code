#include <iostream>

const int MAX = 100;

void set2dArray(int a[][MAX], int &m, int &n) {
    std::cout << "nhap dong: ";
    std::cin >> m;
    std::cout << "nhap cot: ";
    std::cin >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }    
    }
}

void print2dArray(int a[][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << a[i][j] << '\t';
        }
        std::cout << '\n';    
    }
}

int sumArray(int a[][MAX], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum += a[i][j];
        }  
    }
    return sum;
}

int sumDiagonal(int a[][MAX], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += a[i][i];
    }
    return sum;
}

int findMin(int a[][MAX], int m, int n) {
    int min = a[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] < min) min = a[i][j];
        }  
    }
    return min;
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int countNumberofPrime(int a[][MAX], int m, int n) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(a[i][j])) count++;
        }  
    }
    return count;
}

bool isInArray(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) return true;
    }
    return false;
}

int countNumberofUniquePrime(int a[][MAX], int m, int n) {
    int uniquePrime[100] = {0};
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(a[i][j])) {
                if (!isInArray(uniquePrime, count, a[i][j])) {
                    uniquePrime[count] = a[i][j];
                    count++;
                }
            }
        }  
    }
    return count;
}

int countOccurrences(int a[][MAX], int m, int n, int x) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) count++;
        }
    }
    return count;
}

void deleteItems(int a[][MAX], int &row, int &col, int x) {
    bool markedRow[row] = {0};
    bool markedCol[col] = {0};

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (a[i][j] == x) {
                markedRow[i] = 1;
                markedCol[j] = 1;
            }
        }
    }    

    int removedRow = 0;
    int removedCol = 0;

    for (int i = 0; i < row; i++) {
        if (markedRow[i]) {
            removedRow++;
            continue;
        }
        removedCol = 0;
        for (int j = 0; j < col; j++) {
            if (markedCol[j]) removedCol++;
            else a[i-removedRow][j-removedCol] = a[i][j];
        }
    }

    row -= removedRow;
    col -= removedCol;
}

void turnClockWise(int a[][MAX], int m, int n, int r) {
    
}

int main() {
    int a[MAX][MAX];
    int m, n;
    set2dArray(a, m, n);
    print2dArray(a, m, n);
    std::cout << countNumberofUniquePrime(a, m, n);
    return 0;
}