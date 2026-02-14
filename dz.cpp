#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

class String {
private:
    char* str;
    size_t length;
    static int objectCount;

public:
    String() : String(80) {
        cout << "Конструктор по умолчанию (80 символов)\n";
    }

    explicit String(size_t size) : length(size), str(new char[size + 1]) {
        str[0] = '\0';
        objectCount++;
        cout << "Конструктор с размером (" << size << " символов)\n";
    }

    String(const char* userStr) {
        length = strlen(userStr);
        str = new char[length + 1];
        strcpy_s(str, length + 1, userStr);
        objectCount++;
        cout << "Конструктор с инициализацией строкой\n";
    }

    String(const String& other) : length(other.length), str(new char[other.length + 1]) {
        strcpy_s(str, other.length + 1, other.str);
        objectCount++;
        cout << "Конструктор копирования\n";
    }

    ~String() {
        cout << "Деструктор для строки \"" << str << "\"\n";
        delete[] str;
        objectCount--;
    }

    void input() {
        cout << "Введите строку: ";
        char buffer[1000];
        cin.ignore();
        cin.getline(buffer, 1000);

        delete[] str;
        length = strlen(buffer);
        str = new char[length + 1];
        strcpy_s(str, length + 1, buffer);
    }

    void print() const {
        cout << "Строка: \"" << str << "\" (длина: " << length << ")\n";
    }

    const char* getString() const {
        return str;
    }

    size_t getLength() const {
        return length;
    }

    static int getObjectCount() {
        return objectCount;
    }

    void setString(const char* newStr) {
        delete[] str;
        length = strlen(newStr);
        str = new char[length + 1];
        strcpy_s(str, length + 1, newStr);
    }
};

int String::objectCount = 0;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Демонстрация работы класса String\n\n";
    cout << "Начальное количество объектов: " << String::getObjectCount() << "\n\n";

    cout << "Создание s1 (конструктор по умолчанию)\n";
    String s1;
    s1.print();
    cout << "Объектов: " << String::getObjectCount() << "\n\n";

    cout << "Создание s2 (конструктор с размером 20)\n";
    String s2(20);
    s2.print();
    cout << "Объектов: " << String::getObjectCount() << "\n\n";

    cout << "Создание s3 (конструктор с инициализацией)\n";
    String s3("Привет, мир!");
    s3.print();
    cout << "Объектов: " << String::getObjectCount() << "\n\n";

    cout << "Ввод строки для s1\n";
    s1.input();
    s1.print();
    cout << "Объектов: " << String::getObjectCount() << "\n\n";

    cout << "Создание копии s4 (копия s3)\n";
    String s4(s3);
    s4.print();
    cout << "Объектов: " << String::getObjectCount() << "\n\n";

    cout << "Изменение строки s2\n";
    s2.setString("Новая строка");
    s2.print();
    cout << "Объектов: " << String::getObjectCount() << "\n\n";

    cout << "Программа завершается\n";
    cout << "Текущее количество объектов: " << String::getObjectCount() << "\n";
    cout << "Уничтожение объектов:\n";

    return 0;
}