#include <iostream>
#include <windows.h>
using namespace std;

class Fraction {
private:
    int numerator;      // числитель
    int denominator;    // знаменатель

    // Вспомогательная функция для нахождения НОД (наибольший общий делитель)
    int gcd(int a, int b) const {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Метод для сокращения дроби
    void reduce() {
        if (denominator == 0) {
            cout << "Ошибка: знаменатель не может быть равен нулю!\n";
            denominator = 1;
        }

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        int divisor = gcd(numerator, denominator);
        if (divisor > 0) {
            numerator /= divisor;
            denominator /= divisor;
        }
    }

public:
    // Конструктор с параметрами (с использованием списка инициализации)
    Fraction(int num, int den) : numerator(num), denominator(den) {
        reduce();  // Сокращаем дробь при создании
    }

    // Конструктор по умолчанию (делегирование конструктору с параметрами)
    Fraction() : Fraction(0, 1) {}

    // Деструктор
    ~Fraction() {}

    // Метод для вывода дроби на экран
    void print() const {
        if (denominator == 1) {
            cout << numerator;
        }
        else if (numerator == 0) {
            cout << "0";
        }
        else {
            cout << numerator << "/" << denominator;
        }
    }

    // Геттеры (для возможного использования)
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // Сложение дроби с дробью
    Fraction* add(const Fraction& other) {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator = denominator * other.denominator;
        reduce();
        return this;
    }

    // Вычитание дроби с дробью
    Fraction* subtract(const Fraction& other) {
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator = denominator * other.denominator;
        reduce();
        return this;
    }

    // Умножение дроби с дробью
    Fraction* multiply(const Fraction& other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        reduce();
        return this;
    }

    // Деление дроби на дробь (дополнительно, для полноты)
    Fraction* divide(const Fraction& other) {
        if (other.numerator == 0) {
            cout << "Ошибка: деление на ноль!\n";
            return this;
        }
        numerator *= other.denominator;
        denominator *= other.numerator;
        reduce();
        return this;
    }

    // Сложение дроби с целым числом
    Fraction* add(int number) {
        numerator += number * denominator;
        reduce();
        return this;
    }

    // Вычитание целого числа из дроби
    Fraction* subtract(int number) {
        numerator -= number * denominator;
        reduce();
        return this;
    }

    // Умножение дроби на целое число
    Fraction* multiply(int number) {
        numerator *= number;
        reduce();
        return this;
    }

    // Деление дроби на целое число (дополнительно)
    Fraction* divide(int number) {
        if (number == 0) {
            cout << "Ошибка: деление на ноль!\n";
            return this;
        }
        denominator *= number;
        reduce();
        return this;
    }

    // Создание новой дроби как результат сложения (без изменения текущей)
    Fraction addNew(const Fraction& other) const {
        Fraction result(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator
        );
        return result;
    }

    // Создание новой дроби как результат вычитания
    Fraction subtractNew(const Fraction& other) const {
        Fraction result(
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator
        );
        return result;
    }

    // Создание новой дроби как результат умножения
    Fraction multiplyNew(const Fraction& other) const {
        Fraction result(
            numerator * other.numerator,
            denominator * other.denominator
        );
        return result;
    }
};

// Перегрузка оператора вывода для удобства
ostream& operator<<(ostream& os, const Fraction& f) {
    if (f.getDenominator() == 1) {
        os << f.getNumerator();
    }
    else if (f.getNumerator() == 0) {
        os << "0";
    }
    else {
        os << f.getNumerator() << "/" << f.getDenominator();
    }
    return os;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== Класс Дробь ===\n\n";

    // Создание дробей
    cout << "Создание дробей:\n";
    Fraction f1(2, 4);      // Будет сокращена до 1/2
    Fraction f2(3, 6);      // Будет сокращена до 1/2
    Fraction f3(5, 1);      // Целое число 5
    Fraction f4(7, 8);

    cout << "f1 = "; f1.print(); cout << " (2/4 сокращено)\n";
    cout << "f2 = "; f2.print(); cout << " (3/6 сокращено)\n";
    cout << "f3 = "; f3.print(); cout << " (5/1)\n";
    cout << "f4 = "; f4.print(); cout << "\n\n";

    // Демонстрация операций с возвратом this (цепочка вызовов)
    cout << "Цепочка операций (f1 += f2 += f3):\n";
    Fraction f5(1, 3);
    cout << "f5 = "; f5.print(); cout << "\n";

    f5.add(f2)->add(f3);
    cout << "После f5.add(f2)->add(f3): "; f5.print(); cout << "\n\n";

    // Арифметические операции с дробями
    cout << "Арифметические операции с дробями:\n";
    Fraction f6(1, 2);
    Fraction f7(1, 3);

    cout << "f6 = "; f6.print(); cout << "\n";
    cout << "f7 = "; f7.print(); cout << "\n";

    Fraction f8 = f6.addNew(f7);
    cout << "f6 + f7 = "; f8.print(); cout << "\n";

    Fraction f9 = f6.subtractNew(f7);
    cout << "f6 - f7 = "; f9.print(); cout << "\n";

    Fraction f10 = f6.multiplyNew(f7);
    cout << "f6 * f7 = "; f10.print(); cout << "\n\n";

    // Операции с целыми числами
    cout << "Операции с целыми числами:\n";
    Fraction f11(3, 4);
    cout << "f11 = "; f11.print(); cout << "\n";

    f11.add(2);
    cout << "f11 + 2 = "; f11.print(); cout << "\n";

    f11 = Fraction(3, 4);  // Сброс
    f11.subtract(1);
    cout << "f11 - 1 = "; f11.print(); cout << "\n";

    f11 = Fraction(3, 4);  // Сброс
    f11.multiply(3);
    cout << "f11 * 3 = "; f11.print(); cout << "\n\n";

    // Демонстрация сокращения дробей
    cout << "Демонстрация автоматического сокращения:\n";
    Fraction f12(12, 18);
    Fraction f13(24, 36);
    Fraction f14(-8, 12);
    Fraction f15(5, -10);  // Знаменатель станет положительным

    cout << "12/18 = "; f12.print(); cout << "\n";
    cout << "24/36 = "; f13.print(); cout << "\n";
    cout << "-8/12 = "; f14.print(); cout << "\n";
    cout << "5/-10 = "; f15.print(); cout << "\n\n";

    // Демонстрация конструктора по умолчанию (делегирование)
    Fraction f16;
    cout << "Дробь по умолчанию f16 = "; f16.print(); cout << "\n\n";

    // Сложные выражения с использованием цепочек
    cout << "Сложные выражения с цепочками:\n";
    Fraction f17(1, 2);
    cout << "f17 = "; f17.print(); cout << "\n";

    // (f17 + 2) * 3 - 1/4
    f17.add(2)->multiply(3)->subtract(Fraction(1, 4));
    cout << "(f17 + 2) * 3 - 1/4 = "; f17.print(); cout << "\n";

    return 0;
}