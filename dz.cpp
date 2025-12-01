#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    //1 задание
    cout << "1 задание - наибольшее из двух чисел\n";
    int a, b;
    cout << "введите два числа: ";
    cin >> a >> b;

    int* p1 = &a;
    int* p2 = &b;

    if (*p1 > *p2) {
        cout << "наибольшее число: " << *p1 << "\n\n";
    }
    else {
        cout << "наибольшее число: " << *p2 << "\n\n";
    }

    //2 задание
    cout << "2 задание - определить знак числа\n";
    int c;
    cout << "введите число: ";
    cin >> c;

    int* p3 = &c;

    if (*p3 > 0) {
        cout << "число положительное\n\n";
    }
    else if (*p3 < 0) {
        cout << "число отрицательное\n\n";
    }
    else {
        cout << "число равно нулю\n\n";
    }

    //3 задание 
    cout << "3 задание - обменять местами значения\n";
    int d = 5, e = 10;
    cout << "до обмена: d = " << d << ", e = " << e << "\n";

    int* p4 = &d;
    int* p5 = &e;
    int temp = *p4;
    *p4 = *p5;
    *p5 = temp;

    cout << "после обмена: d = " << d << ", e = " << e << "\n\n";

    //4 задание
    cout << "4 задание - калькулятор\n";
    float f, g;
    char op;
    cout << "введите два числа и оператор (+, -, *, /): ";
    cin >> f >> g >> op;

    float* p6 = &f;
    float* p7 = &g;
    float result;
    float* pres = &result;

    if (op == '+') {
        *pres = *p6 + *p7;
    }
    else if (op == '-') {
        *pres = *p6 - *p7;
    }
    else if (op == '*') {
        *pres = *p6 * *p7;
    }
    else if (op == '/') {
        if (*p7 != 0) {
            *pres = *p6 / *p7;
        }
        else {
            cout << "ошибка: деление на ноль!\n\n";
            return 1;
        }
    }
    else {
        cout << "неверный оператор!\n\n";
        return 1;
    }

    cout << "результат: " << *pres << "\n\n";

    //5 задание
    cout << "5 задание - сумма элементов массива\n";
    int arr[5] = { 1, 2, 3, 4, 5 };
    int sum = 0;
    int* parr = arr;

    for (int i = 0; i < 5; i++) {
        sum += *(parr + i);
    }

    cout << "сумма элементов массива: " << sum << "\n";

    return 0;
}