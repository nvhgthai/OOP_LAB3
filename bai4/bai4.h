#include <iostream>
using namespace std;

#ifndef BAI4_H
#define BAI4_H

class NgayThangNam {
private:
    int iNgay, iThang, iNam;

public:
    // Constructors
    NgayThangNam();
    NgayThangNam(int Nam, int Thang, int Ngay);

    // Method to calculate the total number of days
    int tinhngay() const;

    // Operator overloads
    NgayThangNam operator+(int ngay);
    NgayThangNam operator-(int ngay);
    int operator-(const NgayThangNam& a) const;

    NgayThangNam& operator++();  // Pre-increment
    NgayThangNam& operator--();  // Pre-decrement

    bool operator==(const NgayThangNam& a) const;
    bool operator!=(const NgayThangNam& a) const;
    bool operator>=(const NgayThangNam& a) const;
    bool operator<=(const NgayThangNam& a) const;
    bool operator>(const NgayThangNam& a) const;
    bool operator<(const NgayThangNam& a) const;

    // Friend functions for input/output
    friend istream& operator>>(istream& in, NgayThangNam& nt);
    friend ostream& operator<<(ostream& os, const NgayThangNam& nt);
};

#endif // BAI4_H
