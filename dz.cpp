//F10 = запуск откладчика
//Ctrl + D + A - если отсуствует панель переменных
//Shift + F5 = остановка
// F9 - точка остановки
// F5 - запуск с точкой остановки

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    //1
    cout << "Таблица умножения" << endl;
    for (int a = 1; a <= 10; a++) {
        for (int b = 1; b <= 10; b++) {
            int c = a * b;
            cout << a << " * " << b << " = " << c << endl;
        }
        cout << endl;
    }

    //2
    cout << "Простые числа" << endl;
    int d;
    cout << "Введите диапазон простых чисел: ";
    cin >> d;

    for (int a = 2; a <= d; a++) {
        int e = 1;
        for (int b = 2; b < a; b++) {
            if (a % b == 0) {
                e = 0;
                break;
            }
        }
        if (e == 1) {
            cout << a << " ";
        }
    }
    cout << endl;

    //3
    cout << "Матрица" << endl;
    int f, g;
    cout << "Введите M и N: ";
    cin >> f >> g;

    int h = 1;
    for (int a = 0; a < f; a++) {
        for (int b = 0; b < g; b++) {
            cout << h << " ";
            h++;
        }
        cout << endl;
    }

    // Задание 4: Перестановки
    cout << "Перестановки" << endl;
    int i;
    cout << "Введите число: ";
    cin >> i;

    if (i == 1) {
        cout << "1" << endl;
    }
    if (i == 2) {
        cout << "1 2" << endl;
        cout << "2 1" << endl;
    }
    if (i == 3) {
        cout << "1 2 3" << endl;
        cout << "1 3 2" << endl;
        cout << "2 1 3" << endl;
        cout << "2 3 1" << endl;
        cout << "3 1 2" << endl;
        cout << "3 2 1" << endl;
    }

    return 0;
}