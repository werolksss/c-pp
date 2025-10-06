#include <iostream>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

	// 1
    cout << "1 задание, игра угадай число\n";
    cout << "Программа загадала число от 1 до 500\n";
    cout << "Попробуйте угадать (для выхода введите 0)\n\n";

    srand(time(0)); 
    int a = rand() % 500 + 1; 
    int b; 
    int c = 0; 
    time_t d = time(0); 

    while (true) {
        cout << "Введите число: ";
        cin >> b;
        c++;

        if (b == 0) {
            cout << "Выход из игры\n";
            break;
        }

        if (b == a) {
            time_t e = time(0); 
            int f = e - d; 

            cout << "Поздравляем! Вы угадали!\n";
            cout << "Число попыток: " << c << "\n";
            cout << "Потрачено времени: " << f << " секунд\n";
            break;
        }
        else if (b < a) {
            cout << "Загаданное число БОЛЬШЕ\n\n";
        }
        else {
            cout << "Загаданное число МЕНЬШЕ\n\n";
        }
    }

    cout << "\n" << "----------------------------------------\n\n";

    //2
    cout << "2 задание, валюты\n";

    double g; 
    int h; 
    double i;
    int j = 1; 

    while (j == 1) {
        cout << "Выберите операцию:\n";
        cout << "1 - Доллары в рубли\n";
        cout << "2 - Рубли в доллары\n";
        cout << "3 - Евро в рубли\n";
        cout << "4 - Рубли в евро\n";
        cout << "5 - Выход\n";
        cout << "Ваш выбор: ";
        cin >> h;

        if (h == 5) {
            cout << "Выход из конвертера\n";
            break;
        }

        if (h >= 1 && h <= 4) {
            cout << "Введите сумму: ";
            cin >> g;

            if (h == 1) {
                i = g * 83;
                cout << g << " долларов = " << i << " рублей\n\n";
            }
            else if (h == 2) {
                i = g / 83; // 
                cout << g << " рублей = " << i << " долларов\n\n";
            }
            else if (h == 3) {
                i = g * 96; // 
                cout << g << " евро = " << i << " рублей\n\n";
            }
            else if (h == 4) {
                i = g / 96; // 
                cout << g << " рублей = " << i << " евро\n\n";
            }
        }
        else {
            cout << "Неверный выбор! Попробуйте снова.\n\n";
        }
    }

    return 0;
}