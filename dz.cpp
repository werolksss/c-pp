#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    //1
    cout << "1. среднее арифметическое массива:\n";
    const int size1 = 10;
    int a[size1];
    int sum = 0;
    for (int i = 0; i < size1; i++) {
        a[i] = rand() % 100 + 1;
        cout << a[i] << " ";
        sum += a[i];
    }
    cout << "\nсреднее арифметическое: " << (float)sum / size1 << "\n";

    //2
    cout << "\n2. частота символов a, b, c:\n";
    const int size2 = 15;
    char b[size2];
    int countA = 0, countB = 0, countC = 0;
    for (int i = 0; i < size2; i++) {
        int r = rand() % 3;
        if (r == 0) b[i] = 'A';
        else if (r == 1) b[i] = 'B';
        else b[i] = 'C';
        cout << b[i] << " ";

        if (b[i] == 'A') countA++;
        else if (b[i] == 'B') countB++;
        else countC++;
    }
    cout << "\na: " << countA << ", b: " << countB << ", c: " << countC << "\n";

    //3
    cout << "\n3. сортировка вещественных чисел:\n";
    const int size3 = 20;
    float c[size3];
    cout << "исходный массив: ";
    for (int i = 0; i < size3; i++) {
        c[i] = (rand() % 2001 - 1000) / 500.0;
        cout << c[i] << " ";
    }
    for (int i = 0; i < size3 - 1; i++) {
        for (int j = 0; j < size3 - i - 1; j++) {
            if (c[j] < c[j + 1]) {
                float temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
    cout << "\nпосле сортировки: ";
    for (int i = 0; i < size3; i++) {
        cout << c[i] << " ";
    }
    cout << "\n";

    //4
    cout << "\n4. удаление нечетных чисел:\n";
    const int size4 = 20;
    int d[size4];
    cout << "исходный массив: ";
    for (int i = 0; i < size4; i++) {
        d[i] = rand() % 50 + 1;
        cout << d[i] << " ";
    }
    cout << "\nбез нечетных: ";
    for (int i = 0; i < size4; i++) {
        if (d[i] % 2 == 0) {
            cout << d[i] << " ";
        }
    }
    cout << "\n";

    //5
    cout << "\n5. проверка на палиндром:\n";
    const int size5 = 10;
    char e[size5];
    cout << "последовательность: ";
    for (int i = 0; i < size5; i++) {
        e[i] = 'A' + rand() % 26;
        cout << e[i] << " ";
    }
    bool palindrom = true;
    for (int i = 0; i < size5 / 2; i++) {
        if (e[i] != e[size5 - 1 - i]) {
            palindrom = false;
            break;
        }
    }
    if (palindrom) cout << "\nэто палиндром!\n";
    else cout << "\nэто не палиндром\n";

    //6
    cout << "\n6. главная диагональ матрицы 5x5:\n";
    const int size6 = 5;
    int f[size6][size6];
    for (int i = 0; i < size6; i++) {
        for (int j = 0; j < size6; j++) {
            f[i][j] = rand() % 10 + 1;
            cout << f[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "главная диагональ: ";
    for (int i = 0; i < size6; i++) {
        cout << f[i][i] << " ";
    }
    cout << "\n";

    //7
    cout << "\n7. сумма первой строки матрицы 4x4:\n";
    const int size7 = 4;
    int g[size7][size7];
    int sum7 = 0;
    for (int i = 0; i < size7; i++) {
        for (int j = 0; j < size7; j++) {
            g[i][j] = rand() % 101;
            cout << g[i][j] << " ";
            if (i == 0) sum7 += g[i][j];
        }
        cout << "\n";
    }
    cout << "сумма первой строки: " << sum7 << "\n";

    //8
    cout << "\n8. матрица где элемент = i+j:\n";
    const int size8 = 4;
    int h[size8][size8];
    for (int i = 0; i < size8; i++) {
        for (int j = 0; j < size8; j++) {
            h[i][j] = i + j;
            cout << h[i][j] << " ";
        }
        cout << "\n";
    }

    //9
    cout << "\n9. симметричная матрица 6x6:\n";
    const int size9 = 6;
    int k[size9][size9];
    for (int i = 0; i < size9; i++) {
        for (int j = 0; j < size9; j++) {
            if (j >= i) {
                k[i][j] = rand() % 20 + 1;
                k[j][i] = k[i][j];
            }
            cout << k[i][j] << " ";
        }
        cout << "\n";
    }

    //10
    cout << "\n10. минимальный элемент таблицы 3x3:\n";
    const int size10 = 3;
    int l[size10][size10];
    int min_val = 10;
    int min_i = 0, min_j = 0;
    for (int i = 0; i < size10; i++) {
        for (int j = 0; j < size10; j++) {
            l[i][j] = rand() % 9 + 1;
            cout << l[i][j] << " ";
            if (l[i][j] < min_val) {
                min_val = l[i][j];
                min_i = i;
                min_j = j;
            }
        }
        cout << "\n";
    }
    cout << "минимальный элемент: " << min_val << " в позиции (" << min_i << "," << min_j << ")\n";

    //11
    cout << "\n11. заполнение массива случайными числами:\n";
    const int size11 = 10;
    int m[size11];
    for (int i = 0; i < size11; i++) {
        m[i] = rand() % 100 + 1;
        cout << m[i] << " ";
    }
    cout << "\n";

    //12
    cout << "\n12. поиск максимального элемента:\n";
    const int size12 = 15;
    int n[size12];
    int max12 = 0;
    int index12 = 0;
    for (int i = 0; i < size12; i++) {
        n[i] = rand() % 50 + 1;
        cout << n[i] << " ";
        if (n[i] > max12) {
            max12 = n[i];
            index12 = i;
        }
    }
    cout << "\nмаксимальный элемент: " << max12 << " с индексом: " << index12 << "\n";

    //13
    cout << "\n13. фильтрация положительных чисел:\n";
    const int size13 = 20;
    int o[size13];
    cout << "исходный массив: ";
    for (int i = 0; i < size13; i++) {
        o[i] = rand() % 101 - 50;
        cout << o[i] << " ";
    }
    cout << "\nтолько положительные: ";
    for (int i = 0; i < size13; i++) {
        if (o[i] > 0) {
            cout << o[i] << " ";
        }
    }
    cout << "\n";

    //14
    cout << "\n14. подсчет простых чисел:\n";
    const int size14 = 15;
    int p[size14];
    int count14 = 0;
    cout << "массив: ";
    for (int i = 0; i < size14; i++) {
        p[i] = rand() % 100 + 1;
        cout << p[i] << " ";

        bool simple = true;
        if (p[i] < 2) simple = false;
        for (int j = 2; j * j <= p[i]; j++) {
            if (p[i] % j == 0) {
                simple = false;
                break;
            }
        }
        if (simple) count14++;
    }
    cout << "\nколичество простых чисел: " << count14 << "\n";

    //15
    cout << "\n15. минимальное расстояние между массивами:\n";
    const int size15 = 5;
    int q[size15], r[size15];
    cout << "первый массив: ";
    for (int i = 0; i < size15; i++) {
        q[i] = rand() % 100;
        cout << q[i] << " ";
    }
    cout << "\nвторой массив: ";
    for (int i = 0; i < size15; i++) {
        r[i] = rand() % 100;
        cout << r[i] << " ";
    }

    int min_dist = 1000;
    for (int i = 0; i < size15; i++) {
        for (int j = 0; j < size15; j++) {
            int dist = abs(q[i] - r[j]);
            if (dist < min_dist) {
                min_dist = dist;
            }
        }
    }
    cout << "\nминимальное расстояние: " << min_dist << "\n";

    return 0;
}