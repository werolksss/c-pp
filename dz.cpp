#include <iostream>
#include <windows.h>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeap(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInMonth(int m, int y) const {
        if (m == 2) {
            return isLeap(y) ? 29 : 28;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        }
        return 31;
    }

    long dateToDays() const {
        long days = 0;

        for (int y = 1; y < year; y++) {
            days += isLeap(y) ? 366 : 365;
        }

        for (int m = 1; m < month; m++) {
            days += daysInMonth(m, year);
        }

        days += day;

        return days;
    }

public:
    Date(int d = 1, int m = 1, int y = 2000) {
        day = d;
        month = m;
        year = y;
    }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    int operator-(const Date& other) const {
        long days1 = this->dateToDays();
        long days2 = other.dateToDays();
        return abs(days1 - days2);
    }

    Date& operator+=(int days) {
        while (days > 0) {
            int daysInCurrentMonth = daysInMonth(month, year);
            if (day + days <= daysInCurrentMonth) {
                day += days;
                days = 0;
            }
            else {
                days -= (daysInCurrentMonth - day + 1);
                day = 1;
                month++;
                if (month > 12) {
                    month = 1;
                    year++;
                }
            }
        }
        return *this;
    }

    Date operator+(int days) const {
        Date result = *this;
        result += days;
        return result;
    }

    friend ostream& operator<<(ostream& os, const Date& d) {
        os << d.day << "." << d.month << "." << d.year;
        return os;
    }

    friend istream& operator>>(istream& is, Date& d) {
        cout << "Введите день: ";
        is >> d.day;
        cout << "Введите месяц: ";
        is >> d.month;
        cout << "Введите год: ";
        is >> d.year;
        return is;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Работа с датами" << endl;

    Date d1(15, 3, 2024);
    Date d2(1, 1, 2025);

    cout << "Дата 1: " << d1 << endl;
    cout << "Дата 2: " << d2 << endl;

    int diff = d2 - d1;
    cout << "Разность между датами: " << diff << " дней" << endl;

    Date d3(28, 2, 2024);
    cout << "\nНачальная дата: " << d3 << endl;

    d3 += 5;
    cout << "После +5 дней: " << d3 << endl;

    Date d4 = d3 + 30;
    cout << "Еще +30 дней: " << d4 << endl;

    cout << "\nВведите свои даты" << endl;
    Date d5, d6;
    cout << "Введите первую дату:" << endl;
    cin >> d5;
    cout << "Введите вторую дату:" << endl;
    cin >> d6;

    cout << "\nПервая дата: " << d5 << endl;
    cout << "Вторая дата: " << d6 << endl;
    cout << "Разность: " << (d6 - d5) << " дней" << endl;

    int days;
    cout << "\nВведите количество дней для добавления к первой дате: ";
    cin >> days;

    Date d7 = d5 + days;
    cout << "Результат: " << d7 << endl;

    return 0;
}