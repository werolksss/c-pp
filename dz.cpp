#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    //1
    cout << "задание 1\n";
    int m, n;
    cout << "размер массива a: ";
    cin >> m;
    cout << "размер массива b: ";
    cin >> n;

    // создаем массивы
    int* a = new int[m];
    int* b = new int[n];

    cout << "\nвведите элементы массива a:\n";
    for (int i = 0; i < m; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    cout << "\nвведите элементы массива b:\n";
    for (int i = 0; i < n; i++) {
        cout << "b[" << i << "] = ";
        cin >> b[i];
    }
    int count1 = 0;
    for (int i = 0; i < m; i++) {
        bool estb = false;
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                estb = true;
                break;
            }
        }
        if (!estb) {
            bool duplikat = false;
            for (int k = 0; k < i; k++) {
                if (a[i] == a[k]) {
                    duplikat = true;
                    break;
                }
            }
            if (!duplikat) count1++;
        }
    }

    int* c = new int[count1];
    int index1 = 0;
    for (int i = 0; i < m; i++) {
        bool estb = false;
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                estb = true;
                break;
            }
        }
        if (!estb) {
            bool duplikat = false;
            for (int k = 0; k < i; k++) {
                if (a[i] == a[k]) {
                    duplikat = true;
                    break;
                }
            }
            if (!duplikat) {
                c[index1] = a[i];
                index1++;
            }
        }
    }
    cout << "массив c: ";
    if (count1 == 0) cout << "пуст";
    else for (int i = 0; i < count1; i++) cout << c[i] << " ";
    cout << "\n";

    //2
    cout << "\nзадание 2\n";
    int count2 = 0;

    for (int i = 0; i < m; i++) {
        bool estb = false;
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                estb = true;
                break;
            }
        }
        if (!estb) {
            bool duplikat = false;
            for (int k = 0; k < i; k++) {
                if (a[i] == a[k]) {
                    duplikat = true;
                    break;
                }
            }
            if (!duplikat) count2++;
        }
    }

    for (int i = 0; i < n; i++) {
        bool esta = false;
        for (int j = 0; j < m; j++) {
            if (b[i] == a[j]) {
                esta = true;
                break;
            }
        }
        if (!esta) {
            bool duplikat = false;
            for (int k = 0; k < i; k++) {
                if (b[i] == b[k]) {
                    duplikat = true;
                    break;
                }
            }
            if (!duplikat) count2++;
        }
    }

    int* d = new int[count2];
    int index2 = 0;

    for (int i = 0; i < m; i++) {
        bool estb = false;
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                estb = true;
                break;
            }
        }
        if (!estb) {
            bool duplikat = false;
            for (int k = 0; k < i; k++) {
                if (a[i] == a[k]) {
                    duplikat = true;
                    break;
                }
            }
            if (!duplikat) {
                d[index2] = a[i];
                index2++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        bool esta = false;
        for (int j = 0; j < m; j++) {
            if (b[i] == a[j]) {
                esta = true;
                break;
            }
        }
        if (!esta) {
            bool duplikat = false;
            for (int k = 0; k < i; k++) {
                if (b[i] == b[k]) {
                    duplikat = true;
                    break;
                }
            }
            if (!duplikat) {
                d[index2] = b[i];
                index2++;
            }
        }
    }

    cout << "массив d: ";
    if (count2 == 0) cout << "пуст";
    else for (int i = 0; i < count2; i++) cout << d[i] << " ";
    cout << "\n";
    delete[] a;
    delete[] b;
    delete[] c;
    delete[] d;

    return 0;
}