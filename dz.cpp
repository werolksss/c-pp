#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // 1
    cout << "1 задание:\n";
    int a, b;
    cout << "Введите A: ";
    cin >> a;
    cout << "Введите B: ";
    cin >> b;

    for (int i = a; i <= b; i++) {
        int count = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                count++;
            }
        }
        cout << "Число " << i << " имеет " << count << " делителей\n";
    }
    cout << "\n";

    // 2
    cout << "2 задание:\n";
    for (int i = 2; i <= 1000; i++) {
        bool prostoe = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                prostoe = false;
                break;
            }
        }
        if (prostoe) {
            cout << i << " ";
        }
    }
    cout << "\n\n";

    // 3 

    int n; 
    cout << "введите нечетное положительное число: ";
    cin >> n;

    if (n <= 0 || n % 2 == 0) {
        cout << " вы ввели не положительное нечетное число" << endl;
        return 0;
    }
    for (int a = 0; a < n; a++) {        
        for (int b = 0; b < n; b++) {    
            if (a == b || a + b == n - 1 || a == n / 2 || b == n / 2)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "\n"; 
    }

    // 4 
    cout << "4 задание\n";
    int time = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (i != j && i != k && j != k) {
                    cout << i << j << k << " ";
                    time += 3;
                }
            }
        }
    }
    cout << "\nВремя на подбор: " << time << " секунд\n\n";

    // 5 
    cout << "5 задание:\n";
    int total = 0;

    for (int i = 1; i <= 12; i++) {
        int march, april, may;
        cout << "Сотрудник " << i << ":\n";
        cout << "Зарплата за март: ";
        cin >> march;
        cout << "Зарплата за апрель: ";
        cin >> april;
        cout << "Зарплата за май: ";
        cin >> may;

        int quarter = march + april + may;
        cout << "Итого за квартал: " << quarter << "\n\n";
        total += quarter;
    }

    cout << "Общая выплата по всем сотрудникам: " << total << "\n";

    return 0;
}