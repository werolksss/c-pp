#include <iostream>
#include <windows.h>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    // Вспомогательная функция для сокращения дроби (может быть inline)
    inline void reduce() {
        int gcd = findGCD(abs(numerator), abs(denominator));
        if (gcd > 0) {
            numerator /= gcd;
            denominator /= gcd;
        }
    }

    // Вспомогательная функция для нахождения НОД
    inline int findGCD(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    // Конструктор по умолчанию с инициализатором
    Fraction() : numerator(0), denominator(1) {}

    // Конструктор с одним параметром (целое число)
    explicit Fraction(int num) : numerator(num), denominator(1) {}

    // Конструктор с двумя параметрами
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            cout << "Знаменатель не может быть равен 0. Установлено значение 1.\n";
            denominator = 1;
        }
        reduce(); // Сокращаем дробь при создании
    }

    // Конструктор копирования (inline через определение в классе)
    Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {}

    // Деструктор
    ~Fraction() = default;

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
        reduce();
    }

    // Вывод дроби (inline)
    inline void print() const {
        cout << numerator << "/" << denominator;
    }

    // Геттеры (inline)
    inline int getNumerator() const { return numerator; }
    inline int getDenominator() const { return denominator; }

    // Сеттеры
    inline void setNumerator(int num) {
        numerator = num;
        reduce();
    }

    inline void setDenominator(int denom) {
        if (denom != 0) {
            denominator = denom;
            reduce();
        }
        else {
            cout << "Знаменатель не может быть равен 0\n";
        }
    }

    // Сложение
    Fraction add(const Fraction& f) const {
        int newNumerator = numerator * f.denominator + f.numerator * denominator;
        int newDenominator = denominator * f.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // Вычитание
    Fraction subtract(const Fraction& f) const {
        int newNumerator = numerator * f.denominator - f.numerator * denominator;
        int newDenominator = denominator * f.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // Умножение
    Fraction multiply(const Fraction& f) const {
        int newNumerator = numerator * f.numerator;
        int newDenominator = denominator * f.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // Деление
    Fraction divide(const Fraction& f) const {
        if (f.numerator == 0) {
            cout << "Деление на ноль невозможно. Возвращена исходная дробь.\n";
            return *this;
        }
        int newNumerator = numerator * f.denominator;
        int newDenominator = denominator * f.numerator;
        return Fraction(newNumerator, newDenominator);
    }

    // Перегрузка операторов (как бонус)
    Fraction operator+(const Fraction& f) const { return add(f); }
    Fraction operator-(const Fraction& f) const { return subtract(f); }
    Fraction operator*(const Fraction& f) const { return multiply(f); }
    Fraction operator/(const Fraction& f) const { return divide(f); }

    // Преобразование в double
    inline double toDouble() const {
        return static_cast<double>(numerator) / denominator;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Демонстрация различных конструкторов
    cout << "Демонстрация различных конструкторов:\n";

    Fraction f1;  // конструктор по умолчанию
    cout << "f1 (по умолчанию): ";
    f1.print();
    cout << endl;

    Fraction f2(5);  // конструктор с одним параметром
    cout << "f2 (5): ";
    f2.print();
    cout << endl;

    Fraction f3(3, 6);  // конструктор с двумя параметрами (сократится до 1/2)
    cout << "f3 (3/6 после сокращения): ";
    f3.print();
    cout << " = " << f3.toDouble() << endl;

    Fraction f4(f3);  // конструктор копирования
    cout << "f4 (копия f3): ";
    f4.print();
    cout << endl;

    cout << "\nРабота с дробями\n";

    cout << "Введите первую дробь:\n";
    f1.input();

    cout << "\nВведите вторую дробь:\n";
    Fraction f5;
    f5.input();

    cout << "\nРезультаты операций:\n";

    cout << "Сложение: ";
    Fraction result = f1.add(f5);
    result.print();
    cout << " = " << result.toDouble() << endl;

    cout << "Вычитание: ";
    result = f1.subtract(f5);
    result.print();
    cout << " = " << result.toDouble() << endl;

    cout << "Умножение: ";
    result = f1.multiply(f5);
    result.print();
    cout << " = " << result.toDouble() << endl;

    cout << "Деление: ";
    result = f1.divide(f5);
    result.print();
    cout << " = " << result.toDouble() << endl;

    // Демонстрация перегруженных операторов
    cout << "\nС использованием перегруженных операторов:\n";
    result = f1 + f5;
    cout << f1.getNumerator() << "/" << f1.getDenominator() << " + ";
    f5.print();
    cout << " = ";
    result.print();
    cout << " = " << result.toDouble() << endl;

    return 0;
}