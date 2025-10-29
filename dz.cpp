#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // 2
    cout << "умножение\n";
    int a, b;
    cout << "введите первое число: ";
    cin >> a;
    cout << "введите второе число: ";
    cin >> b;
    int c = a * b;
    cout << "произведение: " << c << "\n\n";

    // 4
    cout << "четность\n";
    int d;
    cout << "введите число: ";
    cin >> d;
    if (d % 2 == 0) {
        cout << "четное\n\n";
    }
    else {
        cout << "нечетное\n\n";
    }

    // 7
    cout << "кубы чисел\n";
    for (int e = 1; e <= 10; e++) {
        int f = e * e * e;
        cout << "куб числа " << e << " = " << f << "\n";
    }
    cout << "\n";

    // 11
	const int size = 8;
    int g[size] = { 45, 12, 78, 23, 56, 89, 34, 67 };
    int h = g[0];

    for (int i = 1; i < size; i++) {
        if (g[i] > h) {
            h = g[i];
        }
    }
    cout << "максимальный элемент: " << h << "\n\n";

    // 13
    cout << "двумерный массив 3х3\n";
    const int j = 3;
    int jkk[j][j]; // Объявление массива
    int k = 1;

    for (int l = 0; l < j; l++) {
        for (int m = 0; m < j; m++) {
            jkk[l][m] = k;
            k++;
        }
    }

    for (int n = 0; n < j; n++) {
        for (int o = 0; o < j; o++) {
            cout << jkk[n][o] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}