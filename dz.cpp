#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
//1
    int a, b, c;
    int d;
    int e = 0;
    cout << "Выберите уровень сложности (1-легкий, 2-средний, 3-сложный): ";
    cin >> d;

    for (int i = 0; i < 5; i++) {
        if (d == 1) {
            a = 1 + rand() % 5;
            b = 1 + rand() % 5;
        }
        else if (d == 2) {
            a = 1 + rand() % 8;
            b = 1 + rand() % 8;
        }
        else {
            a = 1 + rand() % 10;
            b = 1 + rand() % 10;
        }

        cout << "Вопрос " << (i + 1) << ": " << a << " * " << b << " = ";
        cin >> c;

        if (c == a * b) {
            cout << "Правильно!\n\n";
            e++;
        }
        else {
            cout << "Неправильно! Правильный ответ: " << a * b << "\n\n";
        }
    }

    cout << "Ваш результат: " << e << " из 5 правильных ответов\n";

    double g = (double)e / 5 * 100;

    if (g >= 90) {
        cout << "Оценка 5\n";
    }
    else if (g >= 70) {
        cout << "Оценка 4\n";
    }
    else if (g >= 50) {
        cout << "Оценка 3\n";
    }
    else {
        cout << "Оценка 2\n";
    }
    cout << "\n\n";
    //2
    cout << "Ромб из звездочек:\n\n";

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5 - i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = 4; i >= 1; i--) {
        for (int j = 1; j <= 5 - i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}