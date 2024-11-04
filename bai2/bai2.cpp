#include "bai2.h"

// Hàm khởi tạo mặc định
SoPhuc::SoPhuc() : real(0), imag(0) {}

// Hàm khởi tạo với tham số
SoPhuc::SoPhuc(double realPart, double imagPart) : real(realPart), imag(imagPart) {}

// Định nghĩa các toán tử
SoPhuc SoPhuc::operator + (const SoPhuc& other) {
    return SoPhuc(real + other.real, imag + other.imag);
}

SoPhuc SoPhuc::operator - (const SoPhuc& other) {
    return SoPhuc(real - other.real, imag - other.imag);
}

SoPhuc SoPhuc::operator * (const SoPhuc& other) {
    double realPart = real * other.real - imag * other.imag;
    double imagPart = real * other.imag + imag * other.real;
    return SoPhuc(realPart, imagPart);
}

SoPhuc SoPhuc::operator / (const SoPhuc& other) {
    double denominator = other.real * other.real + other.imag * other.imag;
    // Tránh chia cho 0
    if (denominator == 0) {
        throw std::runtime_error("Error: Division by zero in complex number division.");
    }
    double realPart = (real * other.real + imag * other.imag) / denominator;
    double imagPart = (imag * other.real - real * other.imag) / denominator;
    return SoPhuc(realPart, imagPart);
}

bool SoPhuc::operator == (const SoPhuc& other) {
    return (real == other.real) && (imag == other.imag);
}

bool SoPhuc::operator != (const SoPhuc& other) {
    return !(*this == other);
}

// Định nghĩa hàm bạn bè
std::istream& operator>>(std::istream &in, SoPhuc &b) {
    std::cout << "Nhap phan thuc: ";
    in >> b.real;
    std::cout << "Nhap phan ao: ";
    in >> b.imag;
    return in;
}

std::ostream& operator<<(std::ostream& out, const SoPhuc& b) {
    out << b.real << (b.imag >= 0 ? "+" : "") << b.imag << "i";
    return out;
}
