#include <iostream>
using namespace std;

void initMatrix(int m[][10], int s) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            m[i][j] = rand() % 100;
        }
    }
}

void printMatrix(int m[][10], int s) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void findDiagonal(int m[][10], int s, int& max, int& min) {
    max = m[0][0];
    min = m[0][0];
    for (int i = 0; i < s; i++) {
        if (m[i][i] > max) max = m[i][i];
        if (m[i][i] < min) min = m[i][i];
    }
}

void sortRow(int r[], int s) {
    for (int i = 0; i < s - 1; i++) {
        for (int j = 0; j < s - i - 1; j++) {
            if (r[j] > r[j + 1]) {
                int t = r[j];
                r[j] = r[j + 1];
                r[j + 1] = t;
            }
        }
    }
}

void sortMatrix(int m[][10], int s) {
    for (int i = 0; i < s; i++) {
        sortRow(m[i], s);
    }
}

int nod(int a, int b) {
    if (b == 0) return a;
    return nod(b, a % b);
}

void checkNumber(int s[], int a[], int p, int& b, int& c) {
    if (p >= 4) return;

    if (a[p] == s[p]) {
        b++;
    }
    else {
        for (int i = 0; i < 4; i++) {
            if (a[p] == s[i]) {
                c++;
                break;
            }
        }
    }

    checkNumber(s, a, p + 1, b, c);
}

void game(int s[], int t) {
    int n;
    cout << "попытка " << t << ": ";
    cin >> n;

    int a[4];
    a[0] = n / 1000;
    a[1] = (n / 100) % 10;
    a[2] = (n / 10) % 10;
    a[3] = n % 10;

    int b = 0, c = 0;
    checkNumber(s, a, 0, b, c);

    cout << "быки: " << b << ", коровы: " << c << endl;

    if (b == 4) {
        cout << "угадал за " << t << " попыток!" << endl;
        return;
    }

    game(s, t + 1);
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    cout << "1. матрицы\n";
    int m[10][10];
    int s = 4;

    initMatrix(m, s);
    printMatrix(m, s);

    int max, min;
    findDiagonal(m, s, max, min);
    cout << "макс: " << max << ", мин: " << min << endl;

    sortMatrix(m, s);
    cout << "после сортировки:\n";
    printMatrix(m, s);
    cout << endl;

    cout << "2. нод\n";
    int a, b;
    cin >> a >> b;
    cout << "НОД: " << nod(a, b) << endl << endl;

    cout << "3. быки и коровы\n";
    int secret[4];
    secret[0] = rand() % 9 + 1;
    for (int i = 1; i < 4; i++) {
        secret[i] = rand() % 10;
    }

    game(secret, 1);

    return 0;
}