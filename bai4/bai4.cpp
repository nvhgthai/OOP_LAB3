#include "bai4.h"

// Default constructor
NgayThangNam::NgayThangNam() : iNgay(4), iThang(6), iNam(2005) {}

// Parameterized constructor
NgayThangNam::NgayThangNam(int Nam, int Thang, int Ngay) : iNam(Nam), iThang(Thang), iNgay(Ngay) {}

// Calculate total number of days from the date
int NgayThangNam::tinhngay() const {
    int D[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Check for leap year
    if ((iNam % 4 == 0 && iNam % 100 != 0) || (iNam % 400 == 0)) {
        D[2] = 29;
    }

    int totalDays = 0;
    // Calculate total days for previous years
    for (int year = 1; year < iNam; year++) {
        totalDays += (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 366 : 365;
    }
    // Add days for the months in the current year
    for (int month = 1; month < iThang; month++) {
        totalDays += D[month];
    }
    // Add current day
    totalDays += iNgay;
    return totalDays;
}

// Operator overloading for adding days
NgayThangNam NgayThangNam::operator+(int Ngay) {
    NgayThangNam result = *this;
    while (Ngay > 0) {
        int daysInCurrentMonth = (result.iThang == 2 && ((result.iNam % 4 == 0 && result.iNam % 100 != 0) || (result.iNam % 400 == 0))) ? 29 : (result.iThang == 2 ? 28 : (result.iThang == 4 || result.iThang == 6 || result.iThang == 9 || result.iThang == 11 ? 30 : 31));

        if (result.iNgay + Ngay > daysInCurrentMonth) {
            Ngay -= (daysInCurrentMonth - result.iNgay + 1);
            result.iNgay = 1;
            result.iThang++;
            if (result.iThang > 12) {
                result.iThang = 1;
                result.iNam++;
            }
        } else {
            result.iNgay += Ngay;
            Ngay = 0;
        }
    }
    return result;
}

// Operator overloading for subtracting days
NgayThangNam NgayThangNam::operator-(int Ngay) {
    NgayThangNam result = *this;
    while (Ngay > 0) {
        if (result.iNgay - Ngay < 1) {
            Ngay -= result.iNgay;
            result.iThang--;
            if (result.iThang < 1) {
                result.iThang = 12;
                result.iNam--;
            }
            // Calculate days in the previous month
            int daysInPreviousMonth = (result.iThang == 2 && ((result.iNam % 4 == 0 && result.iNam % 100 != 0) || (result.iNam % 400 == 0))) ? 29 : (result.iThang == 2 ? 28 : (result.iThang == 4 || result.iThang == 6 || result.iThang == 9 || result.iThang == 11 ? 30 : 31));
            result.iNgay = daysInPreviousMonth;
        } else {
            result.iNgay -= Ngay;
            Ngay = 0;
        }
    }
    return result;
}

// Pre-increment operator
NgayThangNam& NgayThangNam::operator++() {
    *this = *this + 1; // Increment by one day
    return *this;
}

// Pre-decrement operator
NgayThangNam& NgayThangNam::operator--() {
    *this = *this - 1; // Decrement by one day
    return *this;
}

// Operator overloading for date difference
int NgayThangNam::operator-(const NgayThangNam& a) const {
    return this->tinhngay() - a.tinhngay();
}

// Equality operator
bool NgayThangNam::operator==(const NgayThangNam& a) const {
    return iNgay == a.iNgay && iThang == a.iThang && iNam == a.iNam;
}

// Inequality operator
bool NgayThangNam::operator!=(const NgayThangNam& a) const {
    return !(*this == a);
}

// Greater than or equal operator
bool NgayThangNam::operator>=(const NgayThangNam& a) const {
    return tinhngay() >= a.tinhngay();
}

// Less than or equal operator
bool NgayThangNam::operator<=(const NgayThangNam& a) const {
    return tinhngay() <= a.tinhngay();
}

// Greater than operator
bool NgayThangNam::operator>(const NgayThangNam& a) const {
    return tinhngay() > a.tinhngay();
}

// Less than operator
bool NgayThangNam::operator<(const NgayThangNam& a) const {
    return tinhngay() < a.tinhngay();
}

// Input operator
istream& operator>>(istream& in, NgayThangNam& nt) {
    cout << "Nhap ngay: ";
    in >> nt.iNgay;
    cout << "Nhap thang: ";
    in >> nt.iThang;
    cout << "Nhap nam: ";
    in >> nt.iNam;
    return in;
}

// Output operator
ostream& operator<<(ostream& out, const NgayThangNam& nt) {
    out << nt.iNgay << "/" << nt.iThang << "/" << nt.iNam;
    return out;
}
