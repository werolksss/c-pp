#include <iostream>
#include <cmath>
using namespace std;

// 1. Среднее массива
template <typename T>
T avg(T arr[], int n) {
    T sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum / n;
}

// 2. Линейное уравнение
template <typename T>
T solve(T a, T b) {
    return -b / a;
}

// 2. Квадратное уравнение
template <typename T>
void solve(T a, T b, T c) {
    T d = b * b - 4 * a * c;

    if (d > 0) {
        T x1 = (-b + sqrt(d)) / (2 * a);
        T x2 = (-b - sqrt(d)) / (2 * a);
        cout << "Корни: " << x1 << " " << x2 << endl;
    }
    else if (d == 0) {
        cout << "Один корень: " << -b / (2 * a) << endl;
    }
    else {
        cout << "Корней нет\n";
    }
}

// 3. Максимум
template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

// 4. Минимум
template <typename T>
T myMin(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    setlocale(LC_ALL, "ru");

    int arr[] = { 1,2,3,4,5 };

    cout << "Среднее массива: " << avg(arr, 5) << endl;

    cout << "Решение линейного уравнения: " << solve(2.0, 4.0) << endl;

    cout << "Решение квадратного уравнения: ";
    solve(1.0, -3.0, 2.0);

    cout << "Максимум: " << myMax(3, 7) << endl;
    cout << "Минимум: " << myMin(3, 7) << endl;

    return 0;
}