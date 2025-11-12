#include <iostream>
using namespace std;

void perevod(int a, int b) {
    char result[100];
    int i = 0;

    while (a > 0) {
        int c = a % b;

        if (c < 10) {
            result[i] = '0' + c;
        }
        else {
            result[i] = 'A' + (c - 10);
        }

        a = a / b;
        i++;
    }

    cout << "результат: ";
    for (int j = i - 1; j >= 0; j--) {
        cout << result[j];
    }
    cout << endl;
}

void kubiki() {
    int chel = 0;
    int comp = 0;
    int hod;

    cout << "кто ходит первым? (1-человек, 2-компьютер): ";
    cin >> hod;

    for (int i = 0; i < 5; i++) {
        int a, b;

        if (hod == 1) {
            cout << "введите два числа от 1 до 6: ";
            cin >> a >> b;
            chel += a + b;
            cout << "кубики: [" << a << "] [" << b << "]\n";
            hod = 2;
        }
        else {
            a = rand() % 6 + 1;
            b = rand() % 6 + 1;
            comp += a + b;
            cout << "компьютер бросил: [" << a << "] [" << b << "]\n";
            hod = 1;
        }
    }

    cout << "сумма человека: " << chel << endl;
    cout << "сумма компьютера: " << comp << endl;
    cout << "среднее человека: " << chel / 5.0 << endl;
    cout << "среднее компьютера: " << comp / 5.0 << endl;
}

void pryamougolnik(int n, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int faktorial(int a) {
    int result = 1;
    for (int i = 1; i <= a; i++) {
        result *= i;
    }
    return result;
}

bool prostoe(int a) {
    if (a < 2) return false;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

void minmax(int arr[], int size) {
    int min = arr[0];
    int max = arr[0];
    int min_index = 0;
    int max_index = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
    }

    cout << "минимум: " << min << " на позиции " << min_index << endl;
    cout << "максимум: " << max << " на позиции " << max_index << endl;
}

void obratno(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    int a, b;

    cout << "1. перевод числа:\n";
    cout << "введите число: ";
    cin >> a;
    cout << "введите систему счисления: ";
    cin >> b;
    perevod(a, b);

    cout << "\n2. игра в кубики:\n";
    kubiki();

    cout << "\n3. прямоугольник:\n";
    cout << "введите высоту: ";
    cin >> a;
    cout << "введите ширину: ";
    cin >> b;
    pryamougolnik(a, b);

    cout << "\n4. факториал:\n";
    cout << "введите число: ";
    cin >> a;
    cout << "факториал " << a << " = " << faktorial(a) << endl;

    cout << "\n5. простое число:\n";
    cout << "введите число: ";
    cin >> a;
    cout << a << " - " << (prostoe(a) ? "простое" : "не простое") << endl;

    cout << "\n6. минимум и максимум:\n";
    int arr[5];
    cout << "введите 5 чисел: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    minmax(arr, 5);

    cout << "\n7. обратный порядок:\n";
    obratno(arr, 5);
    cout << "массив в обратном порядке: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}