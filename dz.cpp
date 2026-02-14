#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class AreaCalculator {
private:
    static int calculationCount;
    AreaCalculator() {}

public:
    static double triangleByBaseAndHeight(double base, double height) {
        calculationCount++;
        return 0.5 * base * height;
    }

    static double triangleByThreeSides(double a, double b, double c) {
        calculationCount++;
        if (a + b <= c || a + c <= b || b + c <= a) {
            cout << "Ошибка: треугольник не существует!\n";
            return 0;
        }
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    static double triangleByTwoSidesAndAngle(double a, double b, double angleDegrees) {
        calculationCount++;
        double angleRadians = angleDegrees * M_PI / 180.0;
        return 0.5 * a * b * sin(angleRadians);
    }

    static double triangleByCoordinates(double x1, double y1, double x2, double y2, double x3, double y3) {
        calculationCount++;
        return 0.5 * abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
    }

    static double rectangle(double length, double width) {
        calculationCount++;
        return length * width;
    }

    static double rectangleByDiagonalAndAngle(double diagonal, double angleDegrees) {
        calculationCount++;
        double angleRadians = angleDegrees * M_PI / 180.0;
        return (diagonal * diagonal * sin(angleRadians)) / 2;
    }

    static double square(double side) {
        calculationCount++;
        return side * side;
    }

    static double squareByDiagonal(double diagonal) {
        calculationCount++;
        return (diagonal * diagonal) / 2;
    }

    static double squareByPerimeter(double perimeter) {
        calculationCount++;
        double side = perimeter / 4;
        return side * side;
    }

    static double rhombusByDiagonals(double d1, double d2) {
        calculationCount++;
        return (d1 * d2) / 2;
    }

    static double rhombusBySideAndHeight(double side, double height) {
        calculationCount++;
        return side * height;
    }

    static double rhombusBySideAndAngle(double side, double angleDegrees) {
        calculationCount++;
        double angleRadians = angleDegrees * M_PI / 180.0;
        return side * side * sin(angleRadians);
    }

    static double rhombusByDiagonalAndSide(double diagonal, double side) {
        calculationCount++;
        double secondDiagonal = 2 * sqrt(side * side - (diagonal * diagonal) / 4);
        return (diagonal * secondDiagonal) / 2;
    }

    static int getCalculationCount() {
        return calculationCount;
    }

    static void resetCalculationCount() {
        calculationCount = 0;
        cout << "Счетчик сброшен.\n";
    }
};

int AreaCalculator::calculationCount = 0;

void printResult(const string& figure, double area) {
    cout << "Площадь " << figure << ": " << area << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Калькулятор площади фигур\n\n";

    cout << "Треугольники\n";
    double area = AreaCalculator::triangleByBaseAndHeight(10, 5);
    printResult("треугольника (осн.10, выс.5)", area);

    area = AreaCalculator::triangleByThreeSides(3, 4, 5);
    printResult("треугольника (3,4,5)", area);

    area = AreaCalculator::triangleByTwoSidesAndAngle(6, 8, 30);
    printResult("треугольника (6,8,30°)", area);

    area = AreaCalculator::triangleByCoordinates(0, 0, 4, 0, 0, 3);
    printResult("треугольника по координатам", area);

    cout << "\nПрямоугольники\n";
    area = AreaCalculator::rectangle(5, 8);
    printResult("прямоугольника (5x8)", area);

    area = AreaCalculator::rectangleByDiagonalAndAngle(10, 60);
    printResult("прямоугольника (диаг.10,60°)", area);

    cout << "\nКвадраты\n";
    area = AreaCalculator::square(7);
    printResult("квадрата (стор.7)", area);

    area = AreaCalculator::squareByDiagonal(10);
    printResult("квадрата (диаг.10)", area);

    area = AreaCalculator::squareByPerimeter(20);
    printResult("квадрата (перим.20)", area);

    cout << "\nРомбы\n";
    area = AreaCalculator::rhombusByDiagonals(8, 6);
    printResult("ромба (диаг.8,6)", area);

    area = AreaCalculator::rhombusBySideAndHeight(5, 4);
    printResult("ромба (стор.5,выс.4)", area);

    area = AreaCalculator::rhombusBySideAndAngle(5, 60);
    printResult("ромба (стор.5,60°)", area);

    area = AreaCalculator::rhombusByDiagonalAndSide(8, 5);
    printResult("ромба (диаг.8,стор.5)", area);

    cout << "\nСтатистика\n";
    cout << "Всего подсчетов: " << AreaCalculator::getCalculationCount() << endl;

    cout << "\nДополнительные вычисления\n";
    AreaCalculator::triangleByBaseAndHeight(12, 6);
    AreaCalculator::rectangle(7, 9);
    AreaCalculator::square(4);

    cout << "Всего подсчетов: " << AreaCalculator::getCalculationCount() << endl;

    cout << "\nСброс счетчика\n";
    AreaCalculator::resetCalculationCount();
    cout << "После сброса: " << AreaCalculator::getCalculationCount() << endl;

    return 0;
}