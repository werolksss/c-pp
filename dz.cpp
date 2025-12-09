#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void udalit_po_nom(string& a, int n) {            
    if (n >= 0 && n < a.size()) a.erase(n, 1);
}

void udalit_vhozh(string& a, char b) {            
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b) {
            a.erase(i, 1);
            i--;
        }
    }
}

void vstavit(string& a, int pos, char b) {        
    if (pos >= 0 && pos <= a.size()) {
        a.insert(pos, 1, b);
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    // 1 
    {
        string a;
        int n;
        cout << "удаление символа с заданным номером\n";
        getline(cin, a);
        cout << "введите номер символа для удаления:\n";
        cin >> n;
        cin.ignore();
        udalit_po_nom(a, n);
        cout << "результат:\n" << a << "\n\n";
    }

    // 2 
    {
        string a;
        char b;
        cout << "Удаление всех вхождений заданного символа\n";
        getline(cin, a);
        cout << "Введите символ для удаления:\n";
        cin >> b;
        cin.ignore();
        udalit_vhozh(a, b);
        cout << "Результат:\n" << a << "\n\n";
    }

    // 3 
    {
        string a;
        char b;
        int pos;
        cout << "Вставка символа в указанную позицию:\n";
        getline(cin, a);
        cout << "Введите позицию для вставки:\n";
        cin >> pos;
        cout << "Введите символ:\n";
        cin >> b;
        cin.ignore();
        vstavit(a, pos, b);
        cout << "Результат:\n" << a << "\n\n";
    }

    // 4 
    {
        string a;
        cout << "Замена всех точек на восклицательные знаки\n";
        getline(cin, a);

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '.') a[i] = '!';
        }

        cout << "Результат:\n" << a << "\n\n";
    }

    // 5 
    {
        string a;
        char b;
        cout << "Подсчет вхождений символа\n";
        getline(cin, a);
        cout << "Введите искомый символ:\n";
        cin >> b;
        cin.ignore();

        int k = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b) k++;
        }

        cout << "Количество встреч: " << k << "\n\n";
    }

    // 6 
    {
        string a;
        cout << "Подсчет букв, цифр и других символов\n";
        getline(cin, a);

        int buk = 0, cif = 0, ost = 0;

        for (int i = 0; i < a.size(); i++) {
            if (isalpha((unsigned char)a[i])) buk++;
            else if (isdigit((unsigned char)a[i])) cif++;
            else ost++;
        }

        cout << "Букв: " << buk << "\n";
        cout << "Цифр: " << cif << "\n";
        cout << "Остальных символов: " << ost << "\n\n";
    }

    return 0;
}
