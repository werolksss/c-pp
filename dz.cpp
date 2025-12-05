#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // 3
    cout << " задание 3 \n";

    int m1, n1;
    cout << "введите размер массива a: ";
    cin >> m1;
    cout << "введите размер массива b: ";
    cin >> n1;

    // создаем массивы
    int* a1 = new int[m1];
    int* b1 = new int[n1];

    // заполняем
    cout << "введите " << m1 << " чисел для массива a:\n";
    for (int i = 0; i < m1; i++) {
        cin >> a1[i];
    }

    cout << "введите " << n1 << " чисел для массива b:\n";
    for (int i = 0; i < n1; i++) {
        cin >> b1[i];
    }

    // временный массив для результата
    int* temp1 = new int[m1 + n1];
    int count1 = 0;

    // добавляем элементы из a
    for (int i = 0; i < m1; i++) {
        bool duplicate = false;
        for (int k = 0; k < count1; k++) {
            if (temp1[k] == a1[i]) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            temp1[count1] = a1[i];
            count1++;
        }
    }

    // добавляем элементы из b
    for (int i = 0; i < n1; i++) {
        bool duplicate = false;
        for (int k = 0; k < count1; k++) {
            if (temp1[k] == b1[i]) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            temp1[count1] = b1[i];
            count1++;
        }
    }

    // создаем финальный массив
    int* c1 = new int[count1];
    for (int i = 0; i < count1; i++) {
        c1[i] = temp1[i];
    }

    cout << "\nрезультат (все уникальные элементы из a и b):\n";
    for (int i = 0; i < count1; i++) {
        cout << c1[i] << " ";
    }
    if (count1 == 0) {
        cout << "массивы пустые";
    }
    cout << "\n\n";

    delete[] a1;
    delete[] b1;
    delete[] temp1;
    delete[] c1;

    // 4
    cout << " задание 4 \n";

    int m2;
    cout << "введите размер массива: ";
    cin >> m2;

    // создаем массив
    int* a2 = new int[m2];

    // заполняем 
    cout << "введите " << m2 << " чисел для массива:\n";
    for (int i = 0; i < m2; i++) {
        cin >> a2[i];
    }

    // выбор пользователя
    int choice;
    cout << "\nчто удалить?\n";
    cout << "1 - четные числа\n";
    cout << "2 - нечетные числа\n";
    cout << "ваш выбор: ";
    cin >> choice;

    // временный массив для результата
    int* temp2 = new int[m2];
    int count2 = 0;

    // удаляем в зависимости от выбора
    if (choice == 1) {
        // удаляем четные (оставляем нечетные)
        for (int i = 0; i < m2; i++) {
            if (a2[i] % 2 != 0) {
                temp2[count2] = a2[i];
                count2++;
            }
        }
    }
    else if (choice == 2) {
        // удаляем нечетные (оставляем четные)
        for (int i = 0; i < m2; i++) {
            if (a2[i] % 2 == 0) {
                temp2[count2] = a2[i];
                count2++;
            }
        }
    }
    else {
        cout << "неверный выбор!\n";
        delete[] a2;
        delete[] temp2;
        return 0;
    }

    // создаем финальный массив
    int* result = new int[count2];
    for (int i = 0; i < count2; i++) {
        result[i] = temp2[i];
    }

    cout << "\nмассив после удаления:\n";
    for (int i = 0; i < count2; i++) {
        cout << result[i] << " ";
    }
    if (count2 == 0) {
        cout << "все элементы удалены";
    }
    cout << "\n\n";

    delete[] a2;
    delete[] temp2;
    delete[] result;

    return 0;
}