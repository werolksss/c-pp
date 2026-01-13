#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // 1.1
    int a, b;
    cout << "сложение\n";
    cout << "введите числа: ";
    cin >> a >> b;
    cout << a << "+" << b << "=" << a + b << "\n\n";

    // 1.2
    float c, f;
    cout << "перевод в фаренгейт\n";
    cout << "введите цельсия: ";
    cin >> c;
    f = c * 9 / 5 + 32;
    cout << c << "c=" << f << "f\n\n";

    // 2.1
    int n1;
    cout << "четное или нет\n";
    cout << "введите число: ";
    cin >> n1;
    if (n1 % 2 == 0) {
        cout << n1 << " четное\n\n";
    }
    else {
        cout << n1 << " нечетное\n\n";
    }

    // 2.2
    int g;
    cout << "високосный год\n";
    cout << "введите год: ";
    cin >> g;
    if ((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) {
        cout << g << " високосный\n\n";
    }
    else {
        cout << g << " не високосный\n\n";
    }

    // 3.1
    int n;
    cout << "сумма от 1 до n\n";
    cout << "введите n: ";
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s = s + i;
    }
    cout << "сумма=" << s << "\n\n";

    // 3.2
    int t;
    cout << "таблица умножения\n";
    cout << "введите число: ";
    cin >> t;
    for (int i = 1; i <= 10; i++) {
        cout << t << "x" << i << "=" << t * i << "\n";
    }
    cout << "\n";

    // 4.1
    int m[10];
    cout << "минимальный элемент\n";
    cout << "введите 10 чисел: ";
    for (int i = 0; i < 10; i++) {
        cin >> m[i];
    }
    int min = m[0];
    for (int i = 1; i < 10; i++) {
        if (m[i] < min) {
            min = m[i];
        }
    }
    cout << "минимум=" << min << "\n\n";

    // 4.2
    int mat[3][3];
    cout << "сумма строк матрицы\n";
    cout << "введите 9 чисел: ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum = sum + mat[i][j];
        }
        cout << "строка " << i + 1 << ": " << sum << "\n";
    }
    cout << "\n";

    // 5.1
    int x, y;
    cout << "наибольшее число\n";
    cout << "введите числа: ";
    cin >> x >> y;
    if (x > y) {
        cout << "наибольшее=" << x << "\n\n";
    }
    else {
        cout << "наибольшее=" << y << "\n\n";
    }

    // 5.2
    int p;
    cout << "простое число\n";
    cout << "введите число: ";
    cin >> p;
    bool pr = true;
    if (p < 2) pr = false;
    for (int i = 2; i < p; i++) {
        if (p % i == 0) {
            pr = false;
            break;
        }
    }
    if (pr) {
        cout << p << " простое\n\n";
    }
    else {
        cout << p << " не простое\n\n";
    }

    // 6.1
    int v1, v2;
    cout << "обмен через указатели\n";
    cout << "введите числа: ";
    cin >> v1 >> v2;
    cout << "до: " << v1 << " " << v2 << "\n";
    int* ptr1 = &v1, * ptr2 = &v2;
    int tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
    cout << "после: " << v1 << " " << v2 << "\n\n";

    // 6.2
    int arr[5];
    cout << "сумма через указатели\n";
    cout << "введите 5 чисел: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    int* ptr = arr;
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total = total + *(ptr + i);
    }
    cout << "сумма=" << total << "\n\n";

    // 7.1
    char str[100];
    cout << "длина строки\n";
    cout << "введите строку: ";
    cin.ignore();
    cin.getline(str, 100);
    int l = 0;
    while (str[l] != '\0') {
        l++;
    }
    cout << "длина=" << l << "\n\n";

    // 8.1
    int a1[5];
    cout << "среднее\n";
    cout << "введите 5 чисел: ";
    for (int i = 0; i < 5; i++) {
        cin >> a1[i];
    }
    float av = 0;
    for (int i = 0; i < 5; i++) {
        av = av + a1[i];
    }
    av = av / 5;
    cout << "среднее=" << av << "\n\n";

    // 8.2
    int pal[5];
    cout << "палиндром\n";
    cout << "введите 5 чисел: ";
    for (int i = 0; i < 5; i++) {
        cin >> pal[i];
    }
    bool pl = true;
    for (int i = 0; i < 2; i++) {
        if (pal[i] != pal[4 - i]) {
            pl = false;
            break;
        }
    }
    if (pl) {
        cout << "палиндром\n";
    }
    else {
        cout << "не палиндром\n";
    }

    return 0;
}