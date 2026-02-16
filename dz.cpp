#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() : day(1), month(1), year(2000) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}
    ~Date() {}

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    void print() const {
        cout << (day < 10 ? "0" : "") << day << "."
            << (month < 10 ? "0" : "") << month << "."
            << year;
    }
};

class Person {
private:
    int id;
    char* surname;
    char* name;
    char* patronymic;
    Date birthDate;
    static int objectCount;

public:
    Person(int personId, const char* personSurname,
        const char* personName, const char* personPatronymic,
        int d, int m, int y)
        : id(personId), birthDate(d, m, y) {

        surname = new char[strlen(personSurname) + 1];
        strcpy_s(surname, strlen(personSurname) + 1, personSurname);

        name = new char[strlen(personName) + 1];
        strcpy_s(name, strlen(personName) + 1, personName);

        patronymic = new char[strlen(personPatronymic) + 1];
        strcpy_s(patronymic, strlen(personPatronymic) + 1, personPatronymic);

        objectCount++;
        cout << "Создан человек. Всего: " << objectCount << endl;
    }

    Person() : Person(0, "Неизвестно", "Неизвестно", "Неизвестно", 1, 1, 2000) {
        cout << "Делегирование (по умолчанию)\n";
    }

    Person(const Person& other)
        : id(other.id), birthDate(other.birthDate) {

        surname = new char[strlen(other.surname) + 1];
        strcpy_s(surname, strlen(other.surname) + 1, other.surname);

        name = new char[strlen(other.name) + 1];
        strcpy_s(name, strlen(other.name) + 1, other.name);

        patronymic = new char[strlen(other.patronymic) + 1];
        strcpy_s(patronymic, strlen(other.patronymic) + 1, other.patronymic);

        objectCount++;
        cout << "Создана копия. Всего: " << objectCount << endl;
    }

    ~Person() {
        cout << "Удаление: " << surname << " " << name << endl;
        delete[] surname;
        delete[] name;
        delete[] patronymic;
        objectCount--;
        cout << "Осталось: " << objectCount << endl;
    }

    int getId() const { return id; }
    const char* getSurname() const { return surname; }
    const char* getName() const { return name; }
    const char* getPatronymic() const { return patronymic; }
    Date getBirthDate() const { return birthDate; }

    void setId(int newId) { id = newId; }
    void setSurname(const char* newSurname) {
        delete[] surname;
        surname = new char[strlen(newSurname) + 1];
        strcpy_s(surname, strlen(newSurname) + 1, newSurname);
    }
    void setName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy_s(name, strlen(newName) + 1, newName);
    }
    void setPatronymic(const char* newPatronymic) {
        delete[] patronymic;
        patronymic = new char[strlen(newPatronymic) + 1];
        strcpy_s(patronymic, strlen(newPatronymic) + 1, newPatronymic);
    }
    void setBirthDate(int d, int m, int y) {
        birthDate.setDay(d); birthDate.setMonth(m); birthDate.setYear(y);
    }
    void setBirthDate(const Date& newDate) { birthDate = newDate; }

    static int getObjectCount() { return objectCount; }

    void print() const {
        cout << "\nИнформация:\n";
        cout << "ID: " << id << endl;
        cout << surname << " " << name << " " << patronymic << endl;
        cout << "Дата рождения: "; birthDate.print(); cout << "\n";
    }

    void input() {
        char buffer[100];
        cout << "ID: "; cin >> id;
        cout << "Фамилия: "; cin.ignore(); cin.getline(buffer, 100); setSurname(buffer);
        cout << "Имя: "; cin.getline(buffer, 100); setName(buffer);
        cout << "Отчество: "; cin.getline(buffer, 100); setPatronymic(buffer);
        int d, m, y;
        cout << "День рождения: "; cin >> d;
        cout << "Месяц: "; cin >> m;
        cout << "Год: "; cin >> y;
        setBirthDate(d, m, y);
    }
};

int Person::objectCount = 0;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Класс Человек\n\n";

    Person p1(1, "Иванов", "Иван", "Иванович", 15, 5, 1990);
    p1.print();

    cout << "\nВсего: " << Person::getObjectCount() << endl;

    return 0;
}