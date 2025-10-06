#include <iostream>
using namespace std;

int main() {
    setlocale(0, "");
    // 1 задание
    int a, b, c, d;          
    float p1, p2, p3, p4;    
    float n1, n2, n3;        
    float p, n, s;          

    p1 = 4.55;
    p2 = 7.2;
    p3 = 10;
    p4 = 10.5;
    n1 = 2;
    n2 = 1.5;
    n3 = 2;
    s = 0;

    cout << "1 задание, пиццерия\n";
    cout << "Выберите пиццу:\n";
    cout << "1 — Сырная $" << p1 << "\n";
    cout << "2 — Гавайская $" << p2 << "\n";
    cout << "3 — Барбекю $" << p3 << "\n";
    cout << "4 — Морская $" << p4 << "\n";
    cin >> a;
    cout << "Введите количество пицц: ";
    cin >> b;

    switch (a) {
    case 1: p = p1; break;
    case 2: p = p2; break;
    case 3: p = p3; break;
    case 4: p = p4; break;
    default:
        cout << "Такой пиццы нет!\n";
        p = 0;
    }
    if (b >= 5) {
        int freePizza = b / 5;
        cout << "Акция! Бесплатных пицц: " << freePizza << endl;
        b = b - freePizza;
    }

    s = s + b * p;

    cout << "\nВыберите напиток:\n";
    cout << "1 — Кола $" << n1 << "\n";
    cout << "2 — Фанта $" << n2 << "\n";
    cout << "3 — Вода $" << n3 << "\n";
    cin >> c;
    cout << "Введите количество напитков: ";
    cin >> d;

    switch (c) {
    case 1: n = n1; break;
    case 2: n = n2; break;
    case 3: n = n3; break;
    default:
        cout << "Такого напитка нет!\n";
        n = 0;
    }

    float drinkSum = n * d;

    if (n > 2 && d >= 3) {
        cout << "Акция! Скидка 15% на напитки!\n";
        drinkSum = drinkSum * 0.85;
    }

    s = s + drinkSum;

    if (s > 50) {
        cout << "Скидка 20% на весь заказ!\n";
        s = s * 0.8;
    }

    cout << "\n=== ЧЕК ===\n";
    cout << "Пицца №" << a << " — $" << p << " x " << b << "\n";
    cout << "Напиток №" << c << " — $" << n << " x " << d << "\n";
    cout << "Итого: $" << s << "\n";
    cout << "Приятного аппетита!\n\n";

    // 2 задание
    float x1, x2, x3; 
    float y1, y2, y3; 
    int best = 1;     

    cout << "2 задание, зарплата менеджеров\n";
    cout << "Введите продажи менеджера 1: ";
    cin >> x1;
    cout << "Введите продажи менеджера 2: ";
    cin >> x2;
    cout << "Введите продажи менеджера 3: ";
    cin >> x3;

    if (x1 < 500) y1 = 200 + x1 * 0.03;
    else if (x1 < 1000) y1 = 200 + x1 * 0.05;
    else y1 = 200 + x1 * 0.08;

    if (x2 < 500) y2 = 200 + x2 * 0.03;
    else if (x2 < 1000) y2 = 200 + x2 * 0.05;
    else y2 = 200 + x2 * 0.08;

    if (x3 < 500) y3 = 200 + x3 * 0.03;
    else if (x3 < 1000) y3 = 200 + x3 * 0.05;
    else y3 = 200 + x3 * 0.08;

    if (x2 > x1) best = 2;
    if (x3 > x2 && x3 > x1) best = 3;

    if (best == 1) y1 += 200;
    else if (best == 2) y2 += 200;
    else y3 += 200;

    cout << "\nЛучший менеджер: #" << best << " (премия +200$)\n";
    cout << "Менеджер 1: $" << y1 << endl;
    cout << "Менеджер 2: $" << y2 << endl;
    cout << "Менеджер 3: $" << y3 << endl;

    return 0;
}
