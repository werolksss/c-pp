#include <iostream>
#include <cmath>
using namespace std;

// 1 задание
struct Rectangle {
    double x; // координата X левого верхнего угла
    double y; // координата Y левого верхнего угла
    double width; // ширина
    double height; // высота
};

void moveRect(Rectangle& r, double dx, double dy) {
    r.x += dx;
    r.y += dy;
    cout << "Прямоугольник перемещен на (" << dx << ", " << dy << ")\n";
}

void resizeRect(Rectangle& r, double newWidth, double newHeight) {
    r.width = newWidth;
    r.height = newHeight;
    cout << "Размер изменен: ширина=" << newWidth << ", высота=" << newHeight << "\n";
}

void printRect(Rectangle r) {
    cout << "Прямоугольник:\n";
    cout << "Левая верхняя точка: (" << r.x << ", " << r.y << ")\n";
    cout << "Ширина: " << r.width << "\n";
    cout << "Высота: " << r.height << "\n";
    cout << "Правая нижняя точка: (" << r.x + r.width << ", " << r.y + r.height << ")\n\n";
}

// 2 задание
struct Point {
    double x;
    double y;
};

double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

// 3 задание
struct Fraction {
    int num; 
    int den; 
};

int findGCD(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplify(Fraction& f) {
    int gcd = findGCD(f.num, f.den);
    f.num /= gcd;
    f.den /= gcd;

    if (f.den < 0) {
        f.num = -f.num;
        f.den = -f.den;
    }
}

void toMixedNumber(Fraction f) {
    if (abs(f.num) >= f.den && f.den != 0) {
        int whole = f.num / f.den;
        int remainder = abs(f.num) % f.den;
        cout << whole << " и " << remainder << "/" << f.den;
    }
    else {
        cout << f.num << "/" << f.den;
    }
}

Fraction addFractions(Fraction f1, Fraction f2) {
    Fraction result;
    result.num = f1.num * f2.den + f2.num * f1.den;
    result.den = f1.den * f2.den;
    simplify(result);
    return result;
}

Fraction subtractFractions(Fraction f1, Fraction f2) {
    Fraction result;
    result.num = f1.num * f2.den - f2.num * f1.den;
    result.den = f1.den * f2.den;
    simplify(result);
    return result;
}

Fraction multiplyFractions(Fraction f1, Fraction f2) {
    Fraction result;
    result.num = f1.num * f2.num;
    result.den = f1.den * f2.den;
    simplify(result);
    return result;
}

Fraction divideFractions(Fraction f1, Fraction f2) {
    Fraction result;
    result.num = f1.num * f2.den;
    result.den = f1.den * f2.num;
    simplify(result);
    return result;
}

void printFraction(Fraction f) {
    cout << f.num << "/" << f.den;
}

int main() {
    setlocale(LC_ALL, "ru");

    cout << "Прямоугольник\n\n";

    Rectangle r;
    cout << "Введите координаты левого верхнего угла прямоугольника (x y): ";
    cin >> r.x >> r.y;

    cout << "Введите ширину и высоту прямоугольника: ";
    cin >> r.width >> r.height;

    printRect(r);

    double dx, dy;
    cout << "Введите смещение по X и Y для перемещения: ";
    cin >> dx >> dy;
    moveRect(r, dx, dy);
    printRect(r);

    double newW, newH;
    cout << "Введите новую ширину и высоту: ";
    cin >> newW >> newH;
    resizeRect(r, newW, newH);
    printRect(r);

    cout << "\nРасстояние между точками\n\n";

    Point p1, p2;
    cout << "Введите координаты первой точки (x y): ";
    cin >> p1.x >> p1.y;

    cout << "Введите координаты второй точки (x y): ";
    cin >> p2.x >> p2.y;

    double dist = distance(p1, p2);
    cout << "Расстояние между точками: " << dist << "\n\n";

    cout << "Дроби\n\n";

    Fraction f1, f2;

    cout << "Введите первую дробь (числитель и знаменатель): ";
    cin >> f1.num >> f1.den;

    cout << "Введите вторую дробь (числитель и знаменатель): ";
    cin >> f2.num >> f2.den;

    simplify(f1);
    simplify(f2);

    cout << "\nСокращенные дроби:\n";
    cout << "Дробь 1: "; printFraction(f1); cout << "\n";
    cout << "Дробь 2: "; printFraction(f2); cout << "\n";

    cout << "\nПервая дробь как смешанное число: ";
    toMixedNumber(f1); cout << "\n";

    cout << "Вторая дробь как смешанное число: ";
    toMixedNumber(f2); cout << "\n\n";

    Fraction result;

    result = addFractions(f1, f2);
    cout << "Сумма: "; printFraction(f1); cout << " + "; printFraction(f2);
    cout << " = "; printFraction(result); cout << "\n";

    result = subtractFractions(f1, f2);
    cout << "Разность: "; printFraction(f1); cout << " - "; printFraction(f2);
    cout << " = "; printFraction(result); cout << "\n";

    result = multiplyFractions(f1, f2);
    cout << "Умножение: "; printFraction(f1); cout << " * "; printFraction(f2);
    cout << " = "; printFraction(result); cout << "\n";

    result = divideFractions(f1, f2);
    cout << "Деление: "; printFraction(f1); cout << " / "; printFraction(f2);
    cout << " = "; printFraction(result); cout << "\n";

    return 0;
}