#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

class String {
private:
    size_t length;
    char* str;

public:
    String(const char* userStr) {
        length = strlen(userStr);
        str = new char[length + 1];
        strcpy(str, userStr);
        cout << "Конструктор с параметром: \"" << str << "\"\n";
    }

    explicit String(size_t size) : length(size), str(new char[size + 1]) {
        str[0] = '\0';
        cout << "Конструктор с длиной: " << size << "\n";
    }

    String(const String& other) : length(other.length), str(new char[other.length + 1]) {
        strcpy(str, other.str);
        cout << "Конструктор копирования: \"" << str << "\"\n";
    }

    ~String() {
        cout << "Деструктор для: \"" << str << "\"\n";
        delete[] str;
    }

    void print() const {
        cout << "Строка: \"" << str << "\" (длина: " << length << ")\n";
    }

    void setString(const char* newStr) {
        size_t newLength = strlen(newStr);

        if (newLength > length) {
            delete[] str;
            length = newLength;
            str = new char[length + 1];
            cout << "Память перевыделена\n";
        }

        strcpy(str, newStr);
        length = newLength;
    }

    const char* getString() const { return str; }
    size_t getLength() const { return length; }
    size_t getCapacity() const { return length; }

    void input() {
        char buffer[1000];
        cin.ignore();
        cin.getline(buffer, 1000);
        setString(buffer);
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Демонстрация класса String\n\n";

    cout << "Создание s1\n";
    String s1("Привет, мир!");
    s1.print();
    cout << "Вместимость: " << s1.getCapacity() << "\n\n";

    cout << "Создание s2\n";
    String s2(10);
    s2.print();
    cout << "Вместимость: " << s2.getCapacity() << "\n\n";

    cout << "Создание копии s3\n";
    String s3(s1);
    s3.print();
    cout << "Вместимость: " << s3.getCapacity() << "\n\n";

    cout << "Тест сеттера для s2\n";
    s2.setString("Строка, длиннее текущей вместимости");
    s2.print();
    cout << "Вместимость: " << s2.getCapacity() << "\n\n";

    cout << "Тест сеттера для s1\n";
    s1.setString("Короткая строка");
    s1.print();
    cout << "Вместимость: " << s1.getCapacity() << "\n\n";

    cout << "Тест input()\n";
    String s4(50);
    s4.input();
    s4.print();
    cout << "Вместимость: " << s4.getCapacity() << "\n\n";

    cout << "Создание s5\n";
    String s5("Еще одна строка");
    s5.print();
    cout << "Вместимость: " << s5.getCapacity() << "\n\n";

    cout << "Программа завершается\n\n";

    return 0;
}