#include <iostream>
#include <string>
#include <cwctype> 
using namespace std;

int main() {
    setlocale(LC_ALL, "");

    // 1
    {
        wstring a;
        wcout << L"Введите строку\n";
        getline(wcin, a);

        for (int i = 0; i < (int)a.size(); i++) {
            if (a[i] == L' ') a[i] = L'\t';
        }

        wcout << L"Результат:\n" << a << L"\n\n";
    }

    // 2 
    {
        wstring b;
        wcout << L"Количество символов\n";
        getline(wcin, b);

        int buk = 0, cif = 0, ost = 0;
        for (int i = 0; i < (int)b.size(); i++) {
            wchar_t ch = b[i];
            if (iswalpha(ch)) buk++;
            else if (iswdigit(ch)) cif++;
            else ost++;
        }

        wcout << L"Букв: " << buk << L"\n";
        wcout << L"Цифр: " << cif << L"\n";
        wcout << L"Остальных символов: " << ost << L"\n\n";
    }

    // 3 
    {
        wstring c;
        wcout << L"Количество слов в предложении\n";
        getline(wcin, c);

        int slova = 0;
        bool f = false;
        for (int i = 0; i < (int)c.size(); i++) {
            if (c[i] != L' ' && !f) {
                f = true;
                slova++;
            }
            if (c[i] == L' ') f = false;
        }

        wcout << L"Количество слов: " << slova << L"\n\n";
    }

    // 4
    {
        wstring d;
        wcout << L"Проверка на палиндром\n";
        getline(wcin, d);

        int n = d.size();
        bool pal = true;
        for (int i = 0; i < n / 2; i++) {
            if (d[i] != d[n - i - 1]) {
                pal = false;
                break;
            }
        }

        if (pal) wcout << L"Палиндром\n";
        else wcout << L"Не палиндром\n";
    }

    return 0;
}
