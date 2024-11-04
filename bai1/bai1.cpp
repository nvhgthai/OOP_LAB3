#include <iostream>   
#include <algorithm>  
#include "bai1.h"

// Hàm khởi tạo mặc định
PhanSo::PhanSo() : tu(0), mau(1) {}

// Hàm khởi tạo với tham số
PhanSo::PhanSo(int x, int y) : tu(x), mau(y) {
    int gcd = std::__gcd(tu, mau); // Sử dụng std::__gcd
    tu /= gcd;
    mau /= gcd;
    if (mau < 0) { // Đảm bảo mẫu số luôn dương
        tu = -tu;
        mau = -mau;
    }
}

// Định nghĩa các toán tử
PhanSo PhanSo::operator + (const PhanSo& b) {
    int newTu = tu * b.mau + mau * b.tu;
    int newMau = mau * b.mau;
    int gcd = std::__gcd(newTu, newMau);
    return PhanSo(newTu / gcd, newMau / gcd);
}

PhanSo PhanSo::operator - (const PhanSo& b) {
    int newTu = tu * b.mau - mau * b.tu;
    int newMau = mau * b.mau;
    int gcd = std::__gcd(newTu, newMau);
    return PhanSo(newTu / gcd, newMau / gcd);
}

PhanSo PhanSo::operator * (const PhanSo& b) {
    int newTu = tu * b.tu;
    int newMau = mau * b.mau;
    int gcd = std::__gcd(newTu, newMau);
    return PhanSo(newTu / gcd, newMau / gcd);
}

PhanSo PhanSo::operator / (const PhanSo& b) {
    int newTu = tu * b.mau;
    int newMau = mau * b.tu;
    int gcd = std::__gcd(newTu, newMau);
    return PhanSo(newTu / gcd, newMau / gcd);
}

bool PhanSo::operator == (const PhanSo& b) {
    return tu * b.mau == mau * b.tu;
}

bool PhanSo::operator != (const PhanSo& b) {
    return !(*this == b);
}

bool PhanSo::operator > (const PhanSo& b) {
    return tu * b.mau > mau * b.tu;
}

bool PhanSo::operator < (const PhanSo& b) {
    return tu * b.mau < mau * b.tu;
}

bool PhanSo::operator >= (const PhanSo& b) {
    return tu * b.mau >= mau * b.tu;
}

bool PhanSo::operator <= (const PhanSo& b) {
    return tu * b.mau <= mau * b.tu;
}

// Định nghĩa hàm bạn bè
std::istream& operator>>(std::istream &in, PhanSo &b) {
    std::cout << "Nhap tu: ";
    in >> b.tu;
    std::cout << "Nhap mau: ";
    in >> b.mau;
    int gcd = std::__gcd(b.tu, b.mau);
    b.tu /= gcd;
    b.mau /= gcd;
    if (b.mau < 0) {
        b.tu = -b.tu;
        b.mau = -b.mau;
    }
    return in;
}

std::ostream& operator<<(std::ostream& os, const PhanSo& b) {
    os << b.tu << "/" << b.mau;
    return os;
}
