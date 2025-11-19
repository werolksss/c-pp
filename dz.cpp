#include <iostream>
using namespace std;

int stepen(int a, int b)
{
    if (b == 0)
        return 1;
    else
        return a * stepen(a, b - 1);
}

void zvezdi(int n)
{
    if (n > 0)
    {
        cout << "*";
        zvezdi(n - 1);
    }
}

int summa(int a, int b)
{
    if (a > b)
        return 0;
    if (a == b)
        return a;
    else
        return a + summa(a + 1, b);
}

int findMinSum(int arr[], int size, int k, int& minSum, int& startIndex, int currentIndex)
{
    if (currentIndex > size - k)
        return startIndex;

    int currentSum = 0;
    for (int i = 0; i < k; i++)
    {
        currentSum += arr[currentIndex + i];
    }

    if (currentSum < minSum)
    {
        minSum = currentSum;
        startIndex = currentIndex;
    }

    return findMinSum(arr, size, k, minSum, startIndex, currentIndex + 1);
}

int findMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int findMax(int arr[][3], int rows, int cols)
{
    int max = arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }
    return max;
}

int findMax(int arr[][2][2], int x, int y, int z)
{
    int max = arr[0][0][0];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                if (arr[i][j][k] > max)
                    max = arr[i][j][k];
            }
        }
    }
    return max;
}

int findMax(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int findMax(int a, int b, int c)
{
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    return max;
}

int main()
{
    setlocale(LC_ALL, "ru");

    cout << "1. степень числа\n";
    int num, pow;
    cout << "введите число: ";
    cin >> num;
    cout << "введите степень: ";
    cin >> pow;
    cout << num << " в степени " << pow << " = " << stepen(num, pow) << "\n\n";

    cout << "2. звезды в ряд\n";
    int n;
    cout << "введите количество звезд: ";
    cin >> n;
    cout << "результат: ";
    zvezdi(n);
    cout << "\n\n";

    cout << "3. сумма чисел в диапазоне\n";
    int a, b;
    cout << "введите начало диапазона (a): ";
    cin >> a;
    cout << "введите конец диапазона (b): ";
    cin >> b;
    cout << "сумма чисел от " << a << " до " << b << " = " << summa(a, b) << "\n\n";

    cout << "4. поиск минимальной суммы\n";
    int arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 100;
    }

    int minSum = 1000;
    int startIndex = 0;
    int k = 10;

    int result = findMinSum(arr, 100, k, minSum, startIndex, 0);
    cout << "начало последовательности с минимальной суммой: " << result << "\n";
    cout << "минимальная сумма: " << minSum << "\n\n";

    cout << "5. перегруженные функции\n";

    int arr1D[5] = { 3, 7, 2, 9, 1 };
    cout << "максимум в одномерном массиве: " << findMax(arr1D, 5) << "\n";

    int arr2D[2][3] = { {3, 7, 2}, {9, 1, 5} };
    cout << "максимум в двумерном массиве: " << findMax(arr2D, 2, 3) << "\n";

    int arr3D[2][2][2] = { {{3, 7}, {2, 9}}, {{1, 5}, {8, 4}} };
    cout << "максимум в трехмерном массиве: " << findMax(arr3D, 2, 2, 2) << "\n";

    cout << "максимум из 5 и 3: " << findMax(5, 3) << "\n";
    cout << "максимум из 5, 3 и 8: " << findMax(5, 3, 8) << "\n";

    return 0;
}