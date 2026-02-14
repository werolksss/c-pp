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

    static int objectCount;  // Статический счетчик объектов

public:
    // Конструктор по умолчанию (делегирует конструктору с параметрами)
    Student() : Student("", "", "", "", "", "", "", "", "") {
        cout << "Конструктор по умолчанию\n";
    }

    // Конструктор с основными данными (делегирует полному конструктору)
    Student(string fio, string group) : Student(fio, "", "", "", "", "", "", "", group) {
        cout << "Конструктор с ФИО и группой\n";
    }

    // Полный конструктор со всеми параметрами
    Student(string fio, string birthDate, string phone, string city, string country,
        string university, string universityCity, string universityCountry, string groupNumber) {
        this->fio = fio;
        this->birthDate = birthDate;
        this->phone = phone;
        this->city = city;
        this->country = country;
        this->university = university;
        this->universityCity = universityCity;
        this->universityCountry = universityCountry;
        this->groupNumber = groupNumber;
        objectCount++;
        cout << "Полный конструктор\n";
    }

    // Конструктор копирования
    Student(const Student& other) {
        this->fio = other.fio;
        this->birthDate = other.birthDate;
        this->phone = other.phone;
        this->city = other.city;
        this->country = other.country;
        this->university = other.university;
        this->universityCity = other.universityCity;
        this->universityCountry = other.universityCountry;
        this->groupNumber = other.groupNumber;
        objectCount++;
        cout << "Конструктор копирования\n";
    }

    // Деструктор
    ~Student() {
        objectCount--;
        cout << "Деструктор для студента " << fio << "\n";
    }

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

    // Статический метод для получения количества объектов
    static int getObjectCount() {
        return objectCount;
    }
};

// Инициализация статического члена класса
int Student::objectCount = 0;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Начальное количество объектов: " << Student::getObjectCount() << "\n\n";

    cout << "Создание студента s1 (конструктор по умолчанию)\n";
    Student s1;
    cout << "Объектов: " << Student::getObjectCount() << "\n\n";

    cout << "Ввод данных студента s1:\n";
    s1.input();
    s1.print();

    cout << "\nСоздание студента s2 (конструктор с ФИО и группой)\n";
    Student s2("Иванов Иван Иванович", "ИС-21");
    cout << "Объектов: " << Student::getObjectCount() << "\n\n";

    cout << "Создание студента s3 (копия s2)\n";
    Student s3(s2);
    cout << "Объектов: " << Student::getObjectCount() << "\n\n";

    cout << "\nВсего создано объектов: " << Student::getObjectCount() << endl;
    cout << "Завершение программы (деструкторы будут вызваны автоматически)\n";

    return 0;
}