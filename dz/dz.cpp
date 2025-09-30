#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // 1 
    cout << "Задание 1\n";
    int a, b, c, d, e;
    cout << "Введите оценку 1: ";
    cin >> a;
    cout << "Введите оценку 2: ";
    cin >> b;
    cout << "Введите оценку 3: ";
    cin >> c;
    cout << "Введите оценку 4: ";
    cin >> d;
    cout << "Введите оценку 5: ";
    cin >> e;

    double f = (a + b + c + d + e) / 5.0;
    cout << "Средний балл: " << f << "\n";
    if (f >= 4.0)
        cout << "Студент допущен к экзамену.\n";
    else
        cout << "Студент не допущен к экзамену.\n";

    cout << "\n";

    // 2
    cout << "Задание 2\n";
    int g;
    cout << "Введите число: ";
    cin >> g;
    if (g % 2 == 0)
        cout << "Число четное. Результат: " << g * 3 << "\n";
    else
        cout << "Число нечетное. Результат: " << g / 2.0 << "\n";

    cout << "\n";

    // 3
    cout << "Задание 3\n";
    double h, i;
    char j;
    cout << "Введите первое число: ";
    cin >> h;
    cout << "Введите второе число: ";
    cin >> i;
    cout << "Выберите операцию (+, -, *, /): ";
    cin >> j;

    if (j == '+') {
        cout << "Результат: " << h + i << "\n";
    }
    else if (j == '-') {
        cout << "Результат: " << h - i << "\n";
    }
    else if (j == '*') {
        cout << "Результат: " << h * i << "\n";
    }
    else if (j == '/') {
        if (i != 0)
            cout << "Результат: " << h / i << "\n";
        else
            cout << "Ошибка: деление на ноль\n";
    }
    else {
        cout << "Ошибка: неизвестная операция.\n";
    }

    return 0;
}
