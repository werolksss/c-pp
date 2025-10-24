#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    srand(123);

    //1
    cout << "Задание 1\n";
    int a[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int sum = 0;
    int min = a[0][0];
    int max = a[0][0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += a[i][j];
            if (a[i][j] < min) min = a[i][j];
            if (a[i][j] > max) max = a[i][j];
        }
    }
    cout << "Сумма всех элементов: " << sum << "\n";
    cout << "Среднее арифметическое: " << sum / 9.0 << "\n";
    cout << "Минимальный элемент: " << min << "\n";
    cout << "Максимальный элемент: " << max << "\n\n";

    // 2
    cout << "Задание 2\n";
    int b[3][4] = { {3, 5, 6, 7}, {12, 1, 1, 1}, {0, 7, 12, 1} };
    int rowSum[3] = { 0 };
    int colSum[4] = { 0 };
    int totalSum = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            rowSum[i] += b[i][j];
            colSum[j] += b[i][j];
            totalSum += b[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << b[i][j] << "\t";
        }
        cout << rowSum[i] << "\n";
    }

    for (int j = 0; j < 4; j++) {
        cout << colSum[j] << "\t";
    }
    cout << totalSum << "\n\n";

    //3
    cout << "Задание 3\n";
    int c[5][10];  
    int d[5][5];  
    cout << "Первый массив:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            c[i][j] = rand() % 51; 
            cout << c[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\nВторой массив:\n";
    int index = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            d[i][j] = c[i][index] + c[i][index + 1];
            index += 2;
            cout << d[i][j] << "\t";
        }
        index = 0;
        cout << "\n";
    }

    return 0;
}
