#include <iostream>
#include "bai3.cpp"

using namespace std;

int main() {
    // Khởi tạo thời gian tg1 và tg2 với giờ, phút, giây tương ứng
    ThoiGian tg1(3, 45, 50); // Thời gian 3h 45m 50s
    ThoiGian tg2(5, 05, 30); // Thời gian 5h 05m 30s

    // Nhập thời gian từ người dùng
    cout << "Vui long nhap thoi gian cho tg1:" << endl;
    cin >> tg1;
    cout << "Vui long nhap thoi gian cho tg2:" << endl;
    cin >> tg2;

    // Thực hiện các phép toán
    ThoiGian tong = tg1 + tg2; // Tính tổng
    ThoiGian hieu = tg1 - tg2; // Tính hiệu

    // Xuất kết quả tổng và hiệu
    cout << "Tong cua tg1 va tg2 la: " << tong << endl;
    cout << "Hieu của tg1 va tg2 la: " << hieu << endl;

    // Kiểm tra và xuất kết quả tăng, giảm thời gian
    cout << "Thoi gian tg1 sau khi tang (++) la: " << ++tg1 << endl; // Tăng tg1 và in ra
    cout << "Thoi gian tg2 sau khi giam (--) la: " << --tg2 << endl; // Giảm tg2 và in ra

    // So sánh tg1 và tg2
    if (tg1 > tg2) {
        cout << "tg1 lon hon tg2." << endl;
    } else if (tg1 < tg2) {
        cout << "tg1 nho hon tg2." << endl;
    } else {
        cout << "tg1 bang tg2." << endl;
    }

    return 0;
}
