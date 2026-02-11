#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Student {
private:
    string fio;
    string birthDate;
    string phone;
    string city;
    string country;
    string university;
    string universityCity;
    string universityCountry;
    string groupNumber;

public:
    // Ввод данных
    void input() {
        cout << "Введите ФИО: ";
        getline(cin, fio);

        cout << "Введите дату рождения: ";
        getline(cin, birthDate);

        cout << "Введите контактный телефон: ";
        getline(cin, phone);

        cout << "Введите город проживания: ";
        getline(cin, city);

        cout << "Введите страну проживания: ";
        getline(cin, country);

        cout << "Введите название учебного заведения: ";
        getline(cin, university);

        cout << "Введите город учебного заведения: ";
        getline(cin, universityCity);

        cout << "Введите страну учебного заведения: ";
        getline(cin, universityCountry);

        cout << "Введите номер группы: ";
        getline(cin, groupNumber);
    }

    // Вывод данных
    void print() {
        cout << "\nДанные студента:\n";
        cout << "ФИО: " << fio << endl;
        cout << "Дата рождения: " << birthDate << endl;
        cout << "Телефон: " << phone << endl;
        cout << "Город: " << city << endl;
        cout << "Страна: " << country << endl;
        cout << "Учебное заведение: " << university << endl;
        cout << "Город учебного заведения: " << universityCity << endl;
        cout << "Страна учебного заведения: " << universityCountry << endl;
        cout << "Номер группы: " << groupNumber << endl;
    }

    // Аксессоры (get)
    string getFio() { return fio; }
    string getPhone() { return phone; }

    // Мутаторы (set)
    void setPhone(string newPhone) {
        phone = newPhone;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Student s;

    cout << "Ввод данных студента:\n";
    s.input();

    s.print();

    return 0;
}
