#include <iostream>
#include <windows.h>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
    static int objectCount;  // Статический счетчик объектов

public:
    // Конструктор по умолчанию (0/1)
    Fraction() : Fraction(0, 1) {
        cout << "Конструктор по умолчанию\n";
    }

    // Конструктор с числителем (знаменатель = 1)
    Fraction(int num) : Fraction(num, 1) {
        cout << "Конструктор с числителем\n";
    }

    // Полный конструктор с числителем и знаменателем
    Fraction(int num, int den) {
        numerator = num;

        if (den == 0) {
            cout << "Знаменатель не может быть 0, установлен 1\n";
            denominator = 1;
        }
        else {
            denominator = den;
        }

        objectCount++;
        cout << "Полный конструктор\n";
    }

    // Конструктор копирования
    Fraction(const Fraction& other) {
        numerator = other.numerator;
        denominator = other.denominator;
        objectCount++;
        cout << "Конструктор копирования\n";
    }

    // Деструктор
    ~Fraction() {
        objectCount--;
        cout << "Деструктор для дроби " << numerator << "/" << denominator << "\n";
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
            cout << "Деление на ноль невозможно\n";
            result.denominator = 1;
        }

        return result;
    }

    // Статический метод для получения количества объектов
    static int getObjectCount() {
        return objectCount;
    }

    // Методы доступа
    int getNumerator() { return numerator; }
    int getDenominator() { return denominator; }

    void setNumerator(int num) { numerator = num; }
    void setDenominator(int den) {
        if (den != 0) {
            denominator = den;
        }
        else {
            cout << "Знаменатель не может быть 0\n";
        }
    }
};

// Инициализация статического члена класса
int Fraction::objectCount = 0;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Начальное количество объектов: " << Fraction::getObjectCount() << "\n\n";

    cout << "Создание дроби f1 (конструктор по умолчанию)\n";
    Fraction f1;
    cout << "Объектов: " << Fraction::getObjectCount() << "\n\n";

    cout << "Создание дроби f2 (конструктор с числителем)\n";
    Fraction f2(5);
    cout << "f2 = "; f2.print(); cout << "\n";
    cout << "Объектов: " << Fraction::getObjectCount() << "\n\n";

    cout << "Создание дроби f3 (полный конструктор)\n";
    Fraction f3(3, 4);
    cout << "f3 = "; f3.print(); cout << "\n";
    cout << "Объектов: " << Fraction::getObjectCount() << "\n\n";

    cout << "Создание дроби f4 (копия f3)\n";
    Fraction f4(f3);
    cout << "f4 = "; f4.print(); cout << "\n";
    cout << "Объектов: " << Fraction::getObjectCount() << "\n\n";

    cout << "Ввод первой дроби:\n";
    f1.input();

    cout << "\nВвод второй дроби:\n";
    Fraction f5;
    f5.input();

    cout << "\nРезультаты операций с f1 и f5:\n";

    cout << "f1 = "; f1.print(); cout << ", f5 = "; f5.print(); cout << "\n";

    cout << "Сложение: ";
    Fraction result1 = f1.add(f5);
    result1.print();
    cout << endl;

    cout << "Вычитание: ";
    Fraction result2 = f1.subtract(f5);
    result2.print();
    cout << endl;

    cout << "Умножение: ";
    Fraction result3 = f1.multiply(f5);
    result3.print();
    cout << endl;

    cout << "Деление: ";
    Fraction result4 = f1.divide(f5);
    result4.print();
    cout << endl;

    cout << "\nВсего создано объектов: " << Fraction::getObjectCount() << endl;
    cout << "Завершение программы (деструкторы будут вызваны автоматически)\n";

    return 0;
}