#include <iostream>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // 1 задание: подсчет слов, начинающихся с заданного символа
    {
        ifstream file1("file1.txt");
        if (!file1.is_open()) {
            cout << "не удалось открыть file1.txt\n";
            return 1;
        }

        char a;
        cout << "введите символ для поиска: ";
        cin >> a;

        int b = 0;
        string c;

        while (file1 >> c) {
            if (!c.empty() && c[0] == a) {
                b++;
            }
        }

        cout << "слов, начинающихся с '" << a << "': " << b << "\n";
        file1.close();
    }

    // 2 задание: замена 0 на 1 и 1 на 0
    {
        ifstream file2("file2.txt");
        ofstream file2_new("file2_new.txt");

        if (!file2.is_open() || !file2_new.is_open()) {
            cout << "не удалось открыть файлы для 2 задания\n";
            return 1;
        }

        string d;
        while (getline(file2, d)) {
            for (char& e : d) {
                if (e == '0') {
                    e = '1';
                }
                else if (e == '1') {
                    e = '0';
                }
            }
            file2_new << d << "\n";
        }

        file2.close();
        file2_new.close();
        cout << "файл преобразован и сохранен как file2_new.txt\n";
    }

    // 3 задание: запись массива строк в файл
    {
        string f[] = { "первая строка", "вторая строка", "третья строка" };
        ofstream file3("file3.txt");

        if (!file3.is_open()) {
            cout << "не удалось создать file3.txt\n";
            return 1;
        }

        for (const string& g : f) {
            file3 << g << "\n";
        }

        file3.close();
        cout << "массив строк записан в file3.txt\n";
    }

    // 4 задание: подсчет символов в файле
    {
        ifstream file4("file4.txt");
        if (!file4.is_open()) {
            cout << "не удалось открыть file4.txt\n";
            return 1;
        }

        int h = 0;
        char i;

        while (file4.get(i)) {
            h++;
        }

        file4.close();
        cout << "количество символов в файле: " << h << "\n";
    }

    // 5 задание: подсчет строк в файле
    {
        ifstream file5("file5.txt");
        if (!file5.is_open()) {
            cout << "не удалось открыть file5.txt\n";
            return 1;
        }

        int j = 0;
        string k;

        while (getline(file5, k)) {
            j++;
        }

        file5.close();
        cout << "количество строк в файле: " << j << "\n";
    }

    return 0;
}