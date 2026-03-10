#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

class Student {
private:
    char* name;
    int* grades;
    int count;
    int id;
    static int nextId;

public:
    Student() : name(nullptr), grades(nullptr), count(0), id(nextId++) {}

    Student(const char* n, const int* g, int c) : count(c), id(nextId++) {
        if (n) {
            name = new char[strlen(n) + 1];
            strcpy_s(name, strlen(n) + 1, n);
        }
        else {
            name = nullptr;
        }

        if (g && c > 0) {
            grades = new int[c];
            for (int i = 0; i < c; i++) {
                grades[i] = g[i];
            }
        }
        else {
            grades = nullptr;
        }
    }

    Student(const Student& other) : count(other.count), id(nextId++) {
        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy_s(name, strlen(other.name) + 1, other.name);
        }
        else {
            name = nullptr;
        }

        if (other.grades && count > 0) {
            grades = new int[count];
            for (int i = 0; i < count; i++) {
                grades[i] = other.grades[i];
            }
        }
        else {
            grades = nullptr;
        }
    }

    Student(Student&& other) noexcept
        : name(other.name), grades(other.grades),
        count(other.count), id(nextId++) {
        other.name = nullptr;
        other.grades = nullptr;
        other.count = 0;
    }

    ~Student() {
        delete[] name;
        delete[] grades;
    }

    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] name;
            delete[] grades;

            count = other.count;

            if (other.name) {
                name = new char[strlen(other.name) + 1];
                strcpy_s(name, strlen(other.name) + 1, other.name);
            }
            else {
                name = nullptr;
            }

            if (other.grades && count > 0) {
                grades = new int[count];
                for (int i = 0; i < count; i++) {
                    grades[i] = other.grades[i];
                }
            }
            else {
                grades = nullptr;
            }
        }
        return *this;
    }

    Student& operator=(Student&& other) noexcept {
        if (this != &other) {
            delete[] name;
            delete[] grades;

            name = other.name;
            grades = other.grades;
            count = other.count;

            other.name = nullptr;
            other.grades = nullptr;
            other.count = 0;
        }
        return *this;
    }

    void print() const {
        cout << "ID: " << id << ", Имя: " << (name ? name : "не указано") << ", Оценки: ";
        if (grades && count > 0) {
            for (int i = 0; i < count; i++) {
                cout << grades[i] << " ";
            }
        }
        else {
            cout << "нет оценок";
        }
        cout << endl;
    }
};

int Student::nextId = 1;

Student createTestStudent() {
    int grades[] = { 5, 4, 5 };
    return Student("Тест", grades, 3);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Демонстрация конструктора переноса" << endl << endl;

    int g1[] = { 5, 4, 5 };
    Student s1("Иван", g1, 3);
    s1.print();

    Student s2 = s1;
    s2.print();

    cout << endl << "Конструктор переноса" << endl;
    Student s3 = move(s1);
    s3.print();
    cout << "s1 после переноса: ";
    s1.print();

    cout << endl << "Автоматический перенос" << endl;
    Student s4 = createTestStudent();
    s4.print();

    return 0;
}