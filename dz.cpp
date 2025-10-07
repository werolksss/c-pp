#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // 1
    cout << "//1 задание\n";
    int a, b = 0, c = 0, d = 0, e;
    cout << "Введите число: ";
    cin >> a;
    e = abs(a);

    if (a == 0) {
        cout << "Количество цифр: 1\n";
        cout << "Сумма: 0\n";
        cout << "Среднее: 0\n";
        cout << "Количество нулей: 1\n";
    }
    else {
        for (; e > 0; e /= 10) {
            int f = e % 10;
            c += f;
            if (f == 0) d++;
            b++;
        }
        cout << "Количество цифр: " << b << "\n";
        cout << "Сумма цифр: " << c << "\n";
        cout << "Среднее арифметическое: " << (double)c / b << "\n";
        cout << "Количество нулей: " << d << "\n";
    }

    cout << "\n---------------------------------\n";

    // 2 
    cout << "//2 задание\n";
    int g, h, i;
    cout << "Введите размер клеточки: ";
    cin >> g;

    for (h = 0; h < 8 * g; h++) {
        for (i = 0; i < 8 * g; i++) {
            if (((h / g) + (i / g)) % 2 == 0)
                cout << "*";
            else
                cout << "-";
        }
        cout << "\n";
    }

    cout << "\n---------------------------------\n";

    // 3
    cout << "//3 задание\n";
    int j, k, l;
    double m = 0;
    cout << "На сколько человек заказ? ";
    cin >> j;

    for (k = 1; k <= j; k++) {
        double n = 0;
        cout << "\nМеню для человека " << k << ":\n";
        cout << "1. Кофе - 150 руб\n";
        cout << "2. Чай - 100 руб\n";
        cout << "3. Пирожное - 200 руб\n";
        cout << "4. Сок - 120 руб\n";
        cout << "5. Завершить заказ\n";

        for (;;) {
            cout << "Выберите пункт меню: ";
            cin >> l;
            if (l == 1) n += 150;
            else if (l == 2) n += 100;
            else if (l == 3) n += 200;
            else if (l == 4) n += 120;
            else if (l == 5) break;
            else cout << "Нет такого пункта!\n";
        }

        cout << "Сумма заказа для человека " << k << ": " << n << " руб\n";
        m += n;
    }

    cout << "\nОбщая сумма заказа: " << m << " руб\n";

    cout << "\n---------------------------------\n";

    // 4 
    cout << "//4 задание\n";
    int o, p;
    char q;
    cout << "Морской бой:\n\n";
    for (o = 0; o < 10; o++) {
        for (p = 0; p < 10; p++) {
            q = 'A' + p;
            cout << q << o << " ";
        }
        cout << "\n";
    }

    return 0;
}

