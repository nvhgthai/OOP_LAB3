#include <iostream>
#include "bai2.cpp"

int main() {
    SoPhuc a, b;

    // Nhập hai số phức
    std::cout << "Nhap so phuc a:\n";
    std::cin >> a;
    std::cout << "Nhap so phuc b:\n";
    std::cin >> b;

    // Thực hiện phép toán
    SoPhuc sum = a + b;
    SoPhuc difference = a - b;
    SoPhuc product = a * b;
    SoPhuc quotient;

    // Kiểm tra chia cho 0 trước khi thực hiện phép chia
    try {
        quotient = a / b;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1; // Kết thúc chương trình với mã lỗi
    }

    // Xuất kết quả
    std::cout << "Tong: " << sum << std::endl;
    std::cout << "Hieu: " << difference << std::endl;
    std::cout << "Tich: " << product << std::endl;
    std::cout << "Thuong: " << quotient << std::endl;

    // So sánh
    if (a == b) {
        std::cout << "Hai so phuc bang nhau." << std::endl;
    } else {
        std::cout << "Hai so phuc khac nhau." << std::endl;
    }

    return 0;
}
