#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;

class Array {
private:
    int* data;
    int size;

public:
    Array() : data(nullptr), size(0) {}

    Array(int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = rand() % 100;
        }
    }

    Array(const Array& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~Array() {
        delete[] data;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Ошибка: индекс вне диапазона!" << endl;
            static int dummy = 0;
            return dummy;
        }
        return data[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            cout << "Ошибка: индекс вне диапазона!" << endl;
            static int dummy = 0;
            return dummy;
        }
        return data[index];
    }

    void operator()(int value) {
        for (int i = 0; i < size; i++) {
            data[i] += value;
        }
    }

    operator int() const {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += data[i];
        }
        return sum;
    }

    operator char* () const {
        if (size == 0) {
            char* empty = new char[2];
            strcpy(empty, "");
            return empty;
        }

        int totalLen = 0;
        char temp[20];
        for (int i = 0; i < size; i++) {
            sprintf(temp, "%d ", data[i]);
            totalLen += strlen(temp);
        }
        totalLen += 1;

        char* result = new char[totalLen];
        result[0] = '\0';

        for (int i = 0; i < size; i++) {
            sprintf(temp, "%d ", data[i]);
            strcat(result, temp);
        }

        return result;
    }

    int getSize() const { return size; }

    void print() const {
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]";
    }

    void fillRandom() {
        for (int i = 0; i < size; i++) {
            data[i] = rand() % 100;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    cout << "Демонстрация класса Array\n\n";

    Array arr(5);
    cout << "Исходный массив: ";
    arr.print();
    cout << endl;

    cout << "\n1. Оператор []:\n";
    cout << "arr[2] = " << arr[2] << endl;
    arr[2] = 99;
    cout << "После arr[2] = 99: ";
    arr.print();
    cout << endl;

    cout << "\n2. Оператор ():\n";
    arr(10);
    cout << "После arr(10): ";
    arr.print();
    cout << endl;

    cout << "\n3. Преобразование в int:\n";
    int sum = arr;
    cout << "Сумма элементов (int) = " << sum << endl;
    cout << "Явное преобразование: " << (int)arr << endl;

    cout << "\n4. Преобразование в char*:\n";
    char* str = (char*)arr;
    cout << "Строковое представление: \"" << str << "\"" << endl;
    delete[] str;

    cout << "\nДополнительные тесты\n";

    Array emptyArr;
    cout << "Пустой массив: ";
    emptyArr.print();
    cout << endl;
    cout << "Преобразование пустого массива в char*: \"";
    char* emptyStr = (char*)emptyArr;
    cout << emptyStr << "\"" << endl;
    delete[] emptyStr;

    Array bigArr(10);
    bigArr.fillRandom();
    cout << "\nБольшой массив (10 элементов):\n";
    bigArr.print();
    cout << endl;

    bigArr(5);
    cout << "После увеличения на 5, сумма = " << (int)bigArr << endl;

    char* bigStr = (char*)bigArr;
    cout << "Строка: " << bigStr << endl;
    delete[] bigStr;

    cout << "\nКонстантный доступ\n";
    const Array constArr(3);
    cout << "Константный массив: ";
    constArr.print();
    cout << endl;
    cout << "constArr[1] = " << constArr[1] << endl;

    return 0;
}