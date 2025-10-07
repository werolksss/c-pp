#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // 1
    cout << "1задание, сумма чисел от a до 500\n";
    int a;
    cout << "Введите число a: ";
    cin >> a;

    int b = 0;
    int c = a;
    while (c <= 500) {
        b += c;
        c++;
    }
    cout << "Сумма чисел от " << a << " до 500 = " << b << "\n\n";

    // 2
    cout << "2 задание, степень числа\n";
    int x, y;
    cout << "Введите число x: ";
    cin >> x;
    cout << "Введите степень y: ";
    cin >> y;

    int d = 1;
    int e = 1;
    while (e <= y) {
        d *= x;
        e++;
    }
    cout << x << " в степени " << y << " = " << d << "\n\n";

    // 3
    cout << "3задание, среднее арифметическое от 1 до 1000\n";
    int f = 1;
    int g = 0;
    int h = 0;

    while (f <= 1000) {
        g += f;
        h++;
        f++;
    }
    double i = (double)g / h;
    cout << "Среднее арифметическое = " << i << "\n\n";

    // 4
    cout << "4 задание, произведение чисел от a до 20\n";
    int j;
    cout << "Введите число a (от 1 до 20): ";
    cin >> j;

    long long k = 1;
    int l = j;
    while (l <= 20) {
        k *= l;
        l++;
    }
    cout << "Произведение чисел от " << j << " до 20 = " << k << "\n\n";

    // 5
    cout << "5 задание, таблица умножения\n";
    int m;
    cout << "Введите число k: ";
    cin >> m;

    int n = 2;
    while (n <= 9) {
        cout << m << " x " << n << " = " << m * n << "\n";
        n++;
    }

    return 0;
}