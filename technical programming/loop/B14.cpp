#include <iostream>

int fibonacci(int n) {
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    do {
        std::cout << "nhap n > 2: ";
        std::cin >> n;
    } while (n <= 2);

    std::cout << fibonacci(n);
    return 0;
}






