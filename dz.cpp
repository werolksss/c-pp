#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

class Set {
private:
    int* elements;
    int size;
    int capacity;

    void resize(int newCapacity) {
        int* newElements = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }

    bool contains(int value) const {
        for (int i = 0; i < size; i++) {
            if (elements[i] == value) return true;
        }
        return false;
    }

public:
    Set() : elements(nullptr), size(0), capacity(0) {}

    Set(int* arr, int n) : elements(nullptr), size(0), capacity(0) {
        for (int i = 0; i < n; i++) {
            add(arr[i]);
        }
    }

    Set(const Set& other) : elements(nullptr), size(0), capacity(0) {
        for (int i = 0; i < other.size; i++) {
            add(other.elements[i]);
        }
    }

    ~Set() {
        delete[] elements;
    }

    Set& operator=(const Set& other) {
        if (this != &other) {
            delete[] elements;
            elements = nullptr;
            size = 0;
            capacity = 0;

            for (int i = 0; i < other.size; i++) {
                add(other.elements[i]);
            }
        }
        return *this;
    }

    bool add(int value) {
        if (contains(value)) return false;

        if (size >= capacity) {
            int newCapacity = capacity == 0 ? 4 : capacity * 2;
            resize(newCapacity);
        }

        elements[size++] = value;
        return true;
    }

    bool remove(int value) {
        for (int i = 0; i < size; i++) {
            if (elements[i] == value) {
                for (int j = i; j < size - 1; j++) {
                    elements[j] = elements[j + 1];
                }
                size--;
                return true;
            }
        }
        return false;
    }

    bool belongs(int value) const {
        return contains(value);
    }

    int getSize() const {
        return size;
    }

    Set operator+(int value) const {
        Set result = *this;
        result.add(value);
        return result;
    }

    Set& operator+=(int value) {
        add(value);
        return *this;
    }

    Set operator+(const Set& other) const {
        Set result = *this;
        for (int i = 0; i < other.size; i++) {
            result.add(other.elements[i]);
        }
        return result;
    }

    Set& operator+=(const Set& other) {
        for (int i = 0; i < other.size; i++) {
            add(other.elements[i]);
        }
        return *this;
    }

    Set operator-(int value) const {
        Set result = *this;
        result.remove(value);
        return result;
    }

    Set& operator-=(int value) {
        remove(value);
        return *this;
    }

    Set operator-(const Set& other) const {
        Set result;
        for (int i = 0; i < size; i++) {
            if (!other.contains(elements[i])) {
                result.add(elements[i]);
            }
        }
        return result;
    }

    Set& operator-=(const Set& other) {
        Set result;
        for (int i = 0; i < size; i++) {
            if (!other.contains(elements[i])) {
                result.add(elements[i]);
            }
        }
        *this = result;
        return *this;
    }

    Set operator*(const Set& other) const {
        Set result;
        for (int i = 0; i < size; i++) {
            if (other.contains(elements[i])) {
                result.add(elements[i]);
            }
        }
        return result;
    }

    Set& operator*=(const Set& other) {
        Set result;
        for (int i = 0; i < size; i++) {
            if (other.contains(elements[i])) {
                result.add(elements[i]);
            }
        }
        *this = result;
        return *this;
    }

    bool operator==(const Set& other) const {
        if (size != other.size) return false;

        for (int i = 0; i < size; i++) {
            if (!other.contains(elements[i])) return false;
        }
        return true;
    }

    bool operator!=(const Set& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const Set& s) {
        os << "{";
        for (int i = 0; i < s.size; i++) {
            os << s.elements[i];
            if (i < s.size - 1) os << ", ";
        }
        os << "}";
        return os;
    }

    friend istream& operator>>(istream& is, Set& s) {
        int n, value;
        cout << "Введите количество элементов: ";
        is >> n;

        s = Set();
        cout << "Введите элементы: ";
        for (int i = 0; i < n; i++) {
            is >> value;
            s.add(value);
        }
        return is;
    }

    void print() const {
        cout << *this;
    }

    void println() const {
        print();
        cout << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Множество целых чисел\n\n";

    int arr1[] = { 3, 8, 46, 5, 11 };
    int arr2[] = { 18, 8, 90, 11, 2 };

    Set A(arr1, 5);
    Set B(arr2, 5);

    cout << "Множество A = "; A.println();
    cout << "Множество B = "; B.println();

    cout << "\n1. Добавление и удаление элементов:\n";
    Set C = A + 4;
    cout << "A + 4 = "; C.println();

    Set D = A + 3;
    cout << "A + 3 = "; D.println();

    Set E = A - 8;
    cout << "A - 8 = "; E.println();

    A += 7;
    cout << "A += 7 -> "; A.println();

    A -= 46;
    cout << "A -= 46 -> "; A.println();

    cout << "\n2. Проверка принадлежности:\n";
    cout << "8 принадлежит A? " << (A.belongs(8) ? "Да" : "Нет") << endl;
    cout << "100 принадлежит A? " << (A.belongs(100) ? "Да" : "Нет") << endl;

    cout << "\n3. Объединение множеств:\n";
    Set Union = A + B;
    cout << "A U B = "; Union.println();

    A = Set(arr1, 5);
    B = Set(arr2, 5);
    Set Union2 = A + B;
    cout << "A U B (оригинальные) = "; Union2.println();

    A += B;
    cout << "A += B -> "; A.println();

    cout << "\n4. Пересечение множеств:\n";
    A = Set(arr1, 5);
    Set Intersection = A * B;
    cout << "A ∩ B = "; Intersection.println();

    A *= B;
    cout << "A *= B -> "; A.println();

    cout << "\n5. Разность множеств:\n";
    A = Set(arr1, 5);
    Set Difference = A - B;
    cout << "A \\ B = "; Difference.println();

    Set Diff2 = B - A;
    cout << "B \\ A = "; Diff2.println();

    A -= B;
    cout << "A -= B -> "; A.println();

    cout << "\n6. Сравнение множеств:\n";
    Set X(arr1, 5);
    Set Y(arr1, 5);
    Set Z(arr2, 5);

    cout << "X = "; X.println();
    cout << "Y = "; Y.println();
    cout << "Z = "; Z.println();

    cout << "X == Y? " << (X == Y ? "Да" : "Нет") << endl;
    cout << "X == Z? " << (X == Z ? "Да" : "Нет") << endl;
    cout << "X != Z? " << (X != Z ? "Да" : "Нет") << endl;

    cout << "\n7. Конструктор копирования и присваивание:\n";
    Set Copy = X;
    cout << "Copy (копия X) = "; Copy.println();

    Set Assign;
    Assign = Z;
    cout << "Assign = Z -> "; Assign.println();

    cout << "\n8. Потоковый ввод:\n";
    Set Input;
    cin >> Input;
    cout << "Введенное множество: "; Input.println();

    cout << "\n9. Демонстрация уникальности:\n";
    Set Unique;
    Unique.add(5);
    Unique.add(10);
    Unique.add(5);
    Unique.add(7);
    Unique.add(10);
    cout << "После добавления 5,10,5,7,10: "; Unique.println();

    return 0;
}