#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    //пузырьковая сортировка
    cout << "задание 1: пузырьковая сортировка\n";
    int a[5] = { 5, 2, 8, 1, 9 };
    int n = 5;
    cout << "исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    cout << "отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n\n";
    // сортировка вставками
    cout << "задание 2: сортировка вставками\n";
    int b[5] = { 5, 2, 8, 1, 9 };

    cout << "исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";

    for (int i = 1; i < n; i++) {
        int key = b[i];
        int j = i - 1;
        while (j >= 0 && b[j] > key) {
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = key;
    }

    cout << "отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n\n";

    //успеваемость
    cout << "задание 3: успеваемость\n";
    int m[10];

    cout << "введите 10 оценок:\n";
    for (int i = 0; i < 10; i++) {
        cin >> m[i];
    }

    int ch;
    do {
        cout << "\n1 - оценки\n2 - пересдача\n3 - стипендия\n0 - выход\n";
        cin >> ch;

        if (ch == 1) {
            for (int i = 0; i < 10; i++) {
                cout << m[i] << " ";
            }
            cout << "\n";
        }
        else if (ch == 2) {
            int num, nm;
            cout << "номер и новая оценка: ";
            cin >> num >> nm;
            if (num >= 1 && num <= 10) {
                m[num - 1] = nm;
            }
        }
        else if (ch == 3) {
            float s = 0;
            for (int i = 0; i < 10; i++) {
                s += m[i];
            }
            float avg = s / 10;
            cout << "средний бал: " << avg << "\n";
            if (avg >= 10.7) {
                cout << "стипендия есть\n";
            }
            else {
                cout << "стипендии нет\n";
            }
        }
    } while (ch != 0);
    //быстрая сортировка
    cout << "\nзадание 4: быстрая сортировка\n";
    int c[5] = { 5, 2, 8, 1, 9 };
    cout << "исходный массив: ";
    for (int i = 0; i < 5; i++) {
        cout << c[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (c[i] > c[j]) {
                int t = c[i];
                c[i] = c[j];
                c[j] = t;
            }
        }
    }
    cout << "отсортированный массив: ";
    for (int i = 0; i < 5; i++) {
        cout << c[i] << " ";
    }
    cout << "\n\n";

    //сложная сортировка
    cout << "задание 5: сложная сортировка\n";
    int d[6] = { 3, -1, 7, 2, 8, 4 };

    cout << "исходный массив: ";
    for (int i = 0; i < 6; i++) {
        cout << d[i] << " ";
    }
    cout << "\n";

    float s = 0;
    for (int i = 0; i < 6; i++) {
        s += d[i];
    }
    float avg = s / 6;

    int k;
    if (avg > 0) {
        k = 4; // 2/3 от 6
    }
    else {
        k = 2; // 1/3 от 6
    }

    // сортируем первую часть
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (d[j] > d[j + 1]) {
                int t = d[j];
                d[j] = d[j + 1];
                d[j + 1] = t;
            }
        }
    }

    // обратный порядок для остального
    for (int i = k; i < 5; i++) {
        for (int j = k; j < 5; j++) {
            if (d[j] < d[j + 1]) {
                int t = d[j];
                d[j] = d[j + 1];
                d[j + 1] = t;
            }
        }
    }

    cout << "результат: ";
    for (int i = 0; i < 6; i++) {
        cout << d[i] << " ";
    }
    cout << "\n";

    return 0;
}