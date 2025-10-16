/*
1. C) 22
2. A) char
3. A) const, D) constexpr
4. A) x++;
5. C) if(x==10){...}
6. B) Альтернативный способ записи условного выражения вида "если ..., иначе..."
7. A) Вход данных из потока ввода
8. C) do-while
9. C) Целочисленные значения и символы
10. B) Для обработки двумерных структур данных (например, матриц)
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    //1
    cout << "задание 1:\n";
    int a, b, c;
    cout << "Введите три числа: ";
    cin >> a >> b >> c;

    int max = a;

    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }

    cout << "Наибольшее число: " << max << "\n\n";

    //2
    cout << "задание 2:\n";
    int n;
    cout << "Введите размер таблицы: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i * j << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    //3
    cout << "задание 3:\n";
    int x;
    cout << "Введите число: ";
    cin >> x;

    if (x % 3 == 0 && x % 5 == 0) {
        cout << "FizzBuzz\n\n";
    }
    else if (x % 3 == 0) {
        cout << "Fizz\n\n";
    }
    else if (x % 5 == 0) {
        cout << "Buzz\n\n";
    }
    else {
        cout << x << "\n\n";
    }

    //4
    cout << "задание 4:\n";
    int num;
    cout << "Введите число: ";
    cin >> num;

    long factorial = 1;

    for (int i = 1; i <= num; i++) {
        factorial = factorial * i;
    }

    cout << "Факториал: " << factorial << "\n\n";

    //6
    cout << "задание 6:\n";
    int N;
    cout << "Введите число: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        if (i % 15 == 0) {
            cout << "ThreeFive ";
        }
        else if (i % 3 == 0) {
            cout << "Three ";
        }
        else {
            cout << i << " ";
        }
    }
    cout << "\n";

    return 0;
}