#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    //1
    cout << "задание 1\n";

    int m1, n1;
    cout << "введите размер массива A: ";
    cin >> m1;
    cout << "введите размер массива B: ";
    cin >> n1;

    // создаем массивы
    int* a1 = new int[m1];
    int* b1 = new int[n1];

    // заполняем
    cout << "введите " << m1 << " чисел для массива A:\n";
    for (int i = 0; i < m1; i++) {
        cin >> a1[i];
    }

    cout << "введите " << n1 << " чисел для массива B:\n";
    for (int i = 0; i < n1; i++) {
        cin >> b1[i];
    }

    // временный массив для результата
    int* temp1 = new int[m1];
    int count1 = 0;

    // ищем элементы из A, которых нет в B
    for (int i = 0; i < m1; i++) {
        bool found = false;
        for (int j = 0; j < n1; j++) {
            if (a1[i] == b1[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
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
    }

    // финальный массив
    int* c1 = new int[count1];
    for (int i = 0; i < count1; i++) {
        c1[i] = temp1[i];
    }

    cout << "\nрезультат (элементы A, которых нет в B):\n";
    for (int i = 0; i < count1; i++) {
        cout << c1[i] << " ";
    }
    if (count1 == 0) {
        cout << "таких элементов нет";
    }
    cout << "\n\n";
    delete[] a1;
    delete[] b1;
    delete[] temp1;
    delete[] c1;

    //  2
    cout << "задание 2\n";

    int m2, n2;
    cout << "введите размер массива A: ";
    cin >> m2;
    cout << "введите размер массива B: ";
    cin >> n2;

    // создаем массивы
    int* a2 = new int[m2];
    int* b2 = new int[n2];

    // заполняем
    cout << "введите " << m2 << " чисел для массива A:\n";
    for (int i = 0; i < m2; i++) {
        cin >> a2[i];
    }

    cout << "введите " << n2 << " чисел для массива B:\n";
    for (int i = 0; i < n2; i++) {
        cin >> b2[i];
    }

    // временный массив
    int* temp2 = new int[m2 + n2];
    int count2 = 0;

    // элементы из A, которых нет в B
    for (int i = 0; i < m2; i++) {
        bool found = false;
        for (int j = 0; j < n2; j++) {
            if (a2[i] == b2[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            bool duplicate = false;
            for (int k = 0; k < count2; k++) {
                if (temp2[k] == a2[i]) {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate) {
                temp2[count2] = a2[i];
                count2++;
            }
        }
    }

    // элементы из B, которых нет в A
    for (int i = 0; i < n2; i++) {
        bool found = false;
        for (int j = 0; j < m2; j++) {
            if (b2[i] == a2[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            bool duplicate = false;
            for (int k = 0; k < count2; k++) {
                if (temp2[k] == b2[i]) {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate) {
                temp2[count2] = b2[i];
                count2++;
            }
        }
    }

    // финальный массив
    int* c2 = new int[count2];
    for (int i = 0; i < count2; i++) {
        c2[i] = temp2[i];
    }

    cout << "\nрезультат (элементы, которые не общие для A и B):\n";
    for (int i = 0; i < count2; i++) {
        cout << c2[i] << " ";
    }
    if (count2 == 0) {
        cout << "таких элементов нет";
    }
    cout << "\n\n";

    delete[] a2;
    delete[] b2;
    delete[] temp2;
    delete[] c2;

    return 0;
}