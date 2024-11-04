#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu;
    int mau;
public:
    PhanSo(); // Khởi tạo mặc định
    PhanSo(int x, int y); // Khởi tạo với tham số


    PhanSo operator + (const PhanSo& b);
    PhanSo operator - (const PhanSo& b);
    PhanSo operator * (const PhanSo& b);
    PhanSo operator / (const PhanSo& b);

    bool operator == (const PhanSo& b);
    bool operator != (const PhanSo& b);
    bool operator >= (const PhanSo& b);
    bool operator <= (const PhanSo& b);
    bool operator < (const PhanSo& b);
    bool operator > (const PhanSo& b);

  
    friend istream& operator>>(istream &in, PhanSo &b);
    friend ostream& operator<<(ostream& os, const PhanSo& b);
};

#endif // PHANSO_H
