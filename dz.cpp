#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // задание 1
    cout << "задание 1: справочник\n";
    long long mob[5] = { 89141111111, 89001111111, 89140000000, 89049999999, 89111111111 };
    long long home[5] = { 1234567, 7654321, 5556677, 8889999, 1112233 };

    int ch;
    do {
        cout << "\n1 - сортировать по мобильным\n";
        cout << "2 - сортировать по домашним\n";
        cout << "3 - вывести данные\n";
        cout << "0 - выход\n";
        cout << "выберите: ";
        cin >> ch;

        if (ch == 1) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4 - i; j++) {
                    if (mob[j] > mob[j + 1]) {
                        long long t = mob[j];
                        mob[j] = mob[j + 1];
                        mob[j + 1] = t;

                        long long th = home[j];
                        home[j] = home[j + 1];
                        home[j + 1] = th;
                    }
                }
            }
            cout << "отсортировано по мобильным\n";
        }
        else if (ch == 2) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4 - i; j++) {
                    if (home[j] > home[j + 1]) {
                        long long t = home[j];
                        home[j] = home[j + 1];
                        home[j + 1] = t;

                        long long tm = mob[j];
                        mob[j] = mob[j + 1];
                        mob[j + 1] = tm;
                    }
                }
            }
            cout << "отсортировано по домашним\n";
        }
        else if (ch == 3) {
            cout << "мобильные\tдомашние\n";
            for (int i = 0; i < 5; i++) {
                cout << mob[i] << "\t" << home[i] << "\n";
            }
        }
    } while (ch != 0);

    // задание 2
    cout << "\nзадание 2: усовершенствованная пузырьковая сортировка\n";
    int arr[6] = { 5, 2, 8, 1, 9, 3 };
    int size = 6;

    cout << "исходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    cout << "отсортированный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    // задание 3
    cout << "задание 3: стопка оладий\n";
    int pancakes[5] = { 3, 1, 5, 2, 4 };
    int p_size = 5;

    cout << "исходная стопка: ";
    for (int i = 0; i < p_size; i++) {
        cout << pancakes[i] << " ";
    }
    cout << "\n";

    // сортируем стопку оладий
    for (int i = 0; i < p_size - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < p_size; j++) {
            if (pancakes[j] > pancakes[max_idx]) {
                max_idx = j;
            }
        }

        if (max_idx != i) {
            // переворачиваем часть стопки
            for (int k = 0; k < (max_idx - i + 1) / 2; k++) {
                int temp = pancakes[i + k];
                pancakes[i + k] = pancakes[max_idx - k];
                pancakes[max_idx - k] = temp;
            }
        }
    }

    cout << "отсортированная стопка: ";
    for (int i = 0; i < p_size; i++) {
        cout << pancakes[i] << " ";
    }
    cout << "\n\n";

    // задание 4
    cout << "задание 4: сравнение сортировок\n";

    int bubble_total = 0;
    int select_total = 0;

    for (int test = 0; test < 10; test++) {
        int a1[1000], a2[1000];

        for (int i = 0; i < 1000; i++) {
            a1[i] = rand() % 1000;
            a2[i] = a1[i];
        }

        // пузырьковая сортировка
        bool swapped_b;
        int bubble_swaps = 0;
        for (int i = 0; i < 999; i++) {
            swapped_b = false;
            for (int j = 0; j < 999 - i; j++) {
                if (a1[j] > a1[j + 1]) {
                    int temp = a1[j];
                    a1[j] = a1[j + 1];
                    a1[j + 1] = temp;
                    bubble_swaps++;
                    swapped_b = true;
                }
            }
            if (!swapped_b) break;
        }
        bubble_total += bubble_swaps;

        // сортировка выбором
        int select_swaps = 0;
        for (int i = 0; i < 999; i++) {
            int min_idx = i;
            for (int j = i + 1; j < 1000; j++) {
                if (a2[j] < a2[min_idx]) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                int temp = a2[i];
                a2[i] = a2[min_idx];
                a2[min_idx] = temp;
                select_swaps++;
            }
        }
        select_total += select_swaps;

        cout << "тест " << test + 1 << ": пузырек=" << bubble_swaps << ", выбор=" << select_swaps << "\n";
    }

    cout << "среднее число перестановок:\n";
    cout << "пузырьковая: " << bubble_total / 10.0 << "\n";
    cout << "выбором: " << select_total / 10.0 << "\n";

    return 0;
}