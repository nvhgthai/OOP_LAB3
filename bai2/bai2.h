#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>

class SoPhuc {
private:
    double real; 
    double imag;
public:
    SoPhuc(); // Constructor mặc định
    SoPhuc(double realPart, double imagPart); // Constructor với tham số

    // Toán tử
    SoPhuc operator+(const SoPhuc& other);
    SoPhuc operator-(const SoPhuc& other);
    SoPhuc operator*(const SoPhuc& other);
    SoPhuc operator/(const SoPhuc& other);

    bool operator==(const SoPhuc& other);
    bool operator!=(const SoPhuc& other);

    // Hàm bạn bè
    friend std::istream& operator>>(std::istream& in, SoPhuc& sp);
    friend std::ostream& operator<<(std::ostream& out, const SoPhuc& sp);
};

#endif // SOPHUC_H
