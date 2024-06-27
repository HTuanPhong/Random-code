#include <iostream>

int main()
{
    float max = 0, min = 0;
    while (true) {
        float height;
        std::cout << "Nhap vao chieu cao: ";
        std::cin >> height;
        if (height <= 0)
            break;
        if (max == 0 || min == 0)
            max, min = height;
        if (height > max)
            max = height;
        if (height < min)
            min = height;
    }
    std::cout << "Chieu cao cua hoc sinh dung dau danh sach: " << max << " (m)" << '\n';
    std::cout << "Chieu cao cua hoc sinh dung cuoi danh sach: " << min << " (m)";
    return 0;
}