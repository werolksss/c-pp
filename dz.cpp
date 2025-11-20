#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
T srednee(T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return sum / size;
}

template <typename T>
void uravnenie(T a, T b) {
    if (a == 0) cout << (b == 0 ? "бесконечно много решений\n" : "нет решений\n");
    else cout << "корень: x = " << -b / a << "\n";
}

template <typename T>
void uravnenie(T a, T b, T c) {
    if (a == 0) { uravnenie(b, c); return; }

    T d = b * b - 4 * a * c;
    if (d > 0) cout << "два корня: x1 = " << (-b + sqrt(d)) / (2 * a) << ", x2 = " << (-b - sqrt(d)) / (2 * a) << "\n";
    else if (d == 0) cout << "один корень: x = " << -b / (2 * a) << "\n";
    else cout << "действительных корней нет\n";
}

double okruglenie(double chislo, int znakov) {
    return round(chislo * pow(10, znakov)) / pow(10, znakov);
}

template <typename T>
T maximum(T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; i++) if (arr[i] > max) max = arr[i];
    return max;
}

template <typename T>
T maximum(T arr[][10], int rows, int cols) {
    T max = arr[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] > max) max = arr[i][j];
    return max;
}

template <typename T>
T maximum(T arr[][10][10], int x, int y, int z) {
    T max = arr[0][0][0];
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < z; k++)
                if (arr[i][j][k] > max) max = arr[i][j][k];
    return max;
}

int maximum(int a, int b) { return a > b ? a : b; }
int maximum(int a, int b, int c) { return maximum(maximum(a, b), c); }

int main() {
    setlocale(LC_ALL, "ru");

    cout << "1 задание: среднее арифметическое массива\n";
    int arr1[] = { 1, 2, 3, 4, 5 };
    cout << "среднее: " << srednee(arr1, 5) << "\n\n";

    cout << "2 задание: решение уравнений\n";
    cout << "2x + 4 = 0: "; uravnenie(2.0, 4.0);
    cout << "x^2 - 5x + 6 = 0: "; uravnenie(1.0, -5.0, 6.0);
    cout << "\n";

    cout << "3 задание: округление числа\n";
    cout << "3.14159 до 2 знаков: " << okruglenie(3.14159, 2) << "\n\n";

    cout << "4 задание: максимальное значение в массивах\n";
    int odnomerniy[] = { 1, 8, 3, 6, 2 };
    int dvumerniy[3][10] = { {1, 2, 3}, {9, 5, 6}, {7, 8, 4} };
    int trehmerniy[2][10][10] = { {{1, 2}, {3, 4}}, {{15, 6}, {7, 8}} };

    cout << "в одномерном: " << maximum(odnomerniy, 5) << "\n";
    cout << "в двумерном: " << maximum(dvumerniy, 3, 3) << "\n";
    cout << "в трехмерном: " << maximum(trehmerniy, 2, 2, 2) << "\n\n";

    cout << "5 задание: максимальное значение целых чисел\n";
    cout << "из 5 и 10: " << maximum(5, 10) << "\n";
    cout << "из 3, 7 и 2: " << maximum(3, 7, 2) << "\n";

    return 0;
}