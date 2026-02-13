#include <iostream>
#include <string>
#include <cstring>  // для strcpy_s, strlen
#include <windows.h>
using namespace std;

class Student {
private:
    char* fio;  // Динамическое выделение под ФИО
    string birthDate;
    string phone;
    string city;
    string country;
    string university;
    string universityCity;
    string universityCountry;
    string groupNumber;

public:
    // Конструктор по умолчанию с инициализаторами
    Student() : fio(nullptr), birthDate(""), phone(""), city(""),
        country(""), university(""), universityCity(""),
        universityCountry(""), groupNumber("") {
        cout << "Конструктор по умолчанию вызван" << endl;
    }

    // Конструктор с параметрами (для ФИО)
    Student(const char* name) : fio(nullptr), birthDate(""), phone(""), city(""),
        country(""), university(""), universityCity(""),
        universityCountry(""), groupNumber("") {
        if (name) {
            fio = new char[strlen(name) + 1];
            // Используем безопасное копирование
            strcpy_s(fio, strlen(name) + 1, name);
        }
        cout << "Конструктор с параметрами вызван" << endl;
    }

    // Конструктор копирования (глубокое копирование)
    Student(const Student& other) : birthDate(other.birthDate), phone(other.phone),
        city(other.city), country(other.country),
        university(other.university),
        universityCity(other.universityCity),
        universityCountry(other.universityCountry),
        groupNumber(other.groupNumber) {
        if (other.fio) {
            fio = new char[strlen(other.fio) + 1];
            strcpy_s(fio, strlen(other.fio) + 1, other.fio);
        }
        else {
            fio = nullptr;
        }
        cout << "Конструктор копирования вызван" << endl;
    }

    // Деструктор
    ~Student() {
        delete[] fio;
        cout << "Деструктор вызван, память освобождена" << endl;
    }

    // Перегрузка оператора присваивания
    Student& operator=(const Student& other) {
        if (this != &other) {
            // Освобождаем старую память
            delete[] fio;

            // Копируем ФИО
            if (other.fio) {
                fio = new char[strlen(other.fio) + 1];
                strcpy_s(fio, strlen(other.fio) + 1, other.fio);
            }
            else {
                fio = nullptr;
            }

            // Копируем остальные поля
            birthDate = other.birthDate;
            phone = other.phone;
            city = other.city;
            country = other.country;
            university = other.university;
            universityCity = other.universityCity;
            universityCountry = other.universityCountry;
            groupNumber = other.groupNumber;
        }
        cout << "Оператор присваивания вызван" << endl;
        return *this;
    }

    // Ввод данных
    inline void input() {
        string tempFio;
        cout << "Введите ФИО: ";
        getline(cin, tempFio);

        // Освобождаем старую память и выделяем новую
        delete[] fio;
        fio = new char[tempFio.length() + 1];
        // Используем безопасное копирование
        strcpy_s(fio, tempFio.length() + 1, tempFio.c_str());

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

    // Вывод данных (inline)
    inline void print() const {
        cout << "\nДанные студента:\n";
        cout << "ФИО: " << (fio ? fio : "не указано") << endl;
        cout << "Дата рождения: " << birthDate << endl;
        cout << "Телефон: " << phone << endl;
        cout << "Город: " << city << endl;
        cout << "Страна: " << country << endl;
        cout << "Учебное заведение: " << university << endl;
        cout << "Город учебного заведения: " << universityCity << endl;
        cout << "Страна учебного заведения: " << universityCountry << endl;
        cout << "Номер группы: " << groupNumber << endl;
    }

    // Аксессоры (get) - inline
    inline const char* getFio() const { return fio ? fio : ""; }
    inline string getPhone() const { return phone; }

    // Мутаторы (set)
    inline void setPhone(const string& newPhone) {
        phone = newPhone;
    }

    inline void setFio(const char* newFio) {
        delete[] fio;
        if (newFio) {
            fio = new char[strlen(newFio) + 1];
            strcpy_s(fio, strlen(newFio) + 1, newFio);
        }
        else {
            fio = nullptr;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Создание объекта с конструктором по умолчанию" << endl;
    Student s1;

    cout << "\nВвод данных для s1" << endl;
    s1.input();
    s1.print();

    cout << "\nСоздание объекта с конструктором с параметрами" << endl;
    Student s2("Иванов Иван Иванович");
    s2.print();

    cout << "\nТест конструктора копирования" << endl;
    Student s3 = s1;  // конструктор копирования
    s3.print();

    cout << "\nТест оператора присваивания" << endl;
    s2 = s1;  // оператор присваивания
    s2.print();

    cout << "\nИзменение телефона через мутатор" << endl;
    s1.setPhone("+7-999-123-45-67");
    cout << "Новый телефон s1: " << s1.getPhone() << endl;

    cout << "\nИзменение ФИО через мутатор" << endl;
    s1.setFio("Петров Петр Петрович");
    cout << "Новое ФИО s1: " << s1.getFio() << endl;

    cout << "\nЗавершение программы, деструкторы будут вызваны автоматически" << endl;

    return 0;
}