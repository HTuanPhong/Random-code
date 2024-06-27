#include <iostream>

int reverseNumber(int num) {
    int output = 0;
    while (num > 0) {
        output = output * 10 + (num % 10);
        num = num / 10;
    }
    return output;
}

int demChuSoLe(int num) {
    int output = 0;
    while (num > 0) {
        if ((num % 10) % 2 != 0) output++;
        num = num / 10;
    }
    return output;
}

int main() {
    int num;
    std::cout << "nhap so: ";
    std::cin >> num;
    std::cout << reverseNumber(num) << '\n';
    std::cout << demChuSoLe(num);
    return 0;
}