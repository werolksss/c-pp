#include <iostream>
#include <windows.h>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction() {
        numerator = 0;
        denominator = 1;
    }

    // Ввод дроби
    void input() {
        cout << "Введите числитель: ";
        cin >> numerator;
        cout << "Введите знаменатель: ";
        cin >> denominator;

        if (denominator == 0) {
            cout << "Знаменатель не может быть равен 0\n";
            denominator = 1;
        }
    }

    // Вывод дроби
    void print() {
        cout << numerator << "/" << denominator;
    }

    // Сложение
    Fraction add(Fraction f) {
        Fraction result;
        result.numerator = numerator * f.denominator + f.numerator * denominator;
        result.denominator = denominator * f.denominator;
        return result;
    }

    // Вычитание
    Fraction subtract(Fraction f) {
        Fraction result;
        result.numerator = numerator * f.denominator - f.numerator * denominator;
        result.denominator = denominator * f.denominator;
        return result;
    }

    // Умножение
    Fraction multiply(Fraction f) {
        Fraction result;
        result.numerator = numerator * f.numerator;
        result.denominator = denominator * f.denominator;
        return result;
    }

    // Деление
    Fraction divide(Fraction f) {
        Fraction result;
        result.numerator = numerator * f.denominator;
        result.denominator = denominator * f.numerator;

        if (result.denominator == 0) {
            cout << "\Деление на ноль невозможно\n";
            result.denominator = 1;
        }

        return result;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Fraction f1, f2, result;

    cout << "Работа с дробями\n";

    cout << "Введите первую дробь:\n";
    f1.input();

    cout << "\nВведите вторую дробь:\n";
    f2.input();

    cout << "\nРезультаты операций:\n";

    cout << "Сложение: ";
    result = f1.add(f2);
    result.print();
    cout << endl;

    cout << "Вычитание: ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    cout << "Умножение: ";
    result = f1.multiply(f2);
    result.print();
    cout << endl;

    cout << "Деление: ";
    result = f1.divide(f2);
    result.print();
    cout << endl;

    return 0;
}
