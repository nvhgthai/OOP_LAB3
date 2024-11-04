#include <iostream>
#include "bai1.cpp"

int main() {
    PhanSo a, b;

    // Nhập hai phân số
    std::cout << "Nhap phan so a:\n";
    std::cin >> a;
    std::cout << "Nhap phan so b:\n";
    std::cin >> b;

    // Thực hiện các phép toán
    PhanSo tong = a + b;
    PhanSo hieu = a - b;
    PhanSo tich = a * b;
    PhanSo thuong = a / b;

    // Xuất kết quả các phép toán
    std::cout << "Tong: " << tong << '\n';
    std::cout << "Hieu: " << hieu << '\n';
    std::cout << "Tich: " << tich << '\n';
    std::cout << "Thuong: " << thuong << '\n';

    // So sánh hai phân số
    std::cout << "So sanh:\n";
    if (a == b) std::cout << "a bang b\n";
    if (a != b) std::cout << "a khac b\n";
    if (a < b) std::cout << "a be hon b\n";
    if (a > b) std::cout << "a lon hon b\n";

    return 0;
}
