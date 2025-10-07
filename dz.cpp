#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // 1 
    cout << "\n1 задание\n";
    int a;
    cout << "введите число: ";
    cin >> a;

    cout << "обратное число: ";
    for (; a > 0; a /= 10) {
        cout << a % 10;
    }
    cout << endl;

    //2
    cout << "\n2задание\n";
    cout << "Введите число: ";
    cin >> a;

    int b = 0;
    for (; a > 0; a /= 10) {
        b += a % 10;
    }
    cout << "Сумма цифр = " << b << endl;

    //3
    cout << "\n3 задание\n";
    int n;
    cout << "Введите количество дней: ";
    cin >> n;

    int total = 0;
    int b_dist = 15;
    for (int i = 1; i <= n; i++) {
        total += b_dist;
        b_dist += 2;
    }
    cout << "Общее расстояние = " << total << " см" << endl;

    //4 
    cout << "\n4 задание\n";
    int coin, count = 0;
    cout << "Введите 9 раз (1 = орел, 0 = решка):\n";
    for (int i = 1; i <= 9; i++) {
        cin >> coin;
        if (coin == 1) count++;
    }
    if (count % 2 == 0)
        cout << "Решение: положительное" << endl;
    else
        cout << "Решение: отрицательное" << endl;

    //5
    cout << "\n5 задание\n";
    int days, start;
    cout << "Введите количество дней в месяце: ";
    cin >> days;
    cout << "Введите первый день недели (1=Пн 2=Вт 3=Ср 4=Чт 5=Пт 6=Сб 7=Вс): ";
    cin >> start;

    cout << "\n Пн Вт Ср Чт Пт Сб Вс\n";

    for (int i = 1; i < start; i++) {
        cout << "   ";
    }

    for (int a_day = 1; a_day <= days; a_day++) {
        cout.width(3);
        cout << a_day;
        if ((a_day + start - 1) % 7 == 0) cout << endl;
    }
    cout << endl;

    return 0;
}