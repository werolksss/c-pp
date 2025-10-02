#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int text, bg;
    cout << "1 задание\n";
    cout << "Изменение цвета консоли\n";
    cout << "Цвета: 0-Черный 1-Синий 2-Зеленый 3-Голубой\n";
    cout << "       4-Красный 5-Фиолетовый 6-Желтый 7-Белый\n";

    cout << "Выберите цвет текста (0-7): ";
    cin >> text;
    cout << "Выберите цвет фона (0-7): ";
    cin >> bg;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bg << 4) | text);

    cout << "Готово, новый цвет текста и фона\n";
    SetConsoleTextAttribute(hConsole, 7);

    double number;
    int stepen;
    cout << "2 задание\n";
    cout << "Возведение в степень\n";
    cout << "Введите число: ";
    cin >> number;
    cout << "Введите степень (0-7): ";
    cin >> stepen;

    if (stepen < 0 || stepen > 7) {
        cout << "Степень должна быть от 0 до 7\n";
        return 1;
    }

    double result = 1;
    for (int i = 0; i < stepen; i++) {
        result = result * number;
    }

    cout << number << " в степени " << stepen << " = " << result << "\n";

    return 0;
}
  