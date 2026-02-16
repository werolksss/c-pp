#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

class Date {
private:
    int day, month, year;

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

    Date& operator=(const Date& other) {
        if (this != &other) {
            day = other.day;
            month = other.month;
            year = other.year;
        }
        return *this;
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
        strcpy(surname, personSurname);
        name = new char[strlen(personName) + 1];
        strcpy(name, personName);
        patronymic = new char[strlen(personPatronymic) + 1];
        strcpy(patronymic, personPatronymic);
        objectCount++;
    }

    Person() : Person(0, "Неизвестно", "Неизвестно", "Неизвестно", 1, 1, 2000) {}

    Person(const Person& other)
        : id(other.id), birthDate(other.birthDate) {

        surname = new char[strlen(other.surname) + 1];
        strcpy(surname, other.surname);
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        patronymic = new char[strlen(other.patronymic) + 1];
        strcpy(patronymic, other.patronymic);
        objectCount++;
    }

    ~Person() {
        delete[] surname;
        delete[] name;
        delete[] patronymic;
        objectCount--;
    }

    Person& operator=(const Person& other) {
        if (this != &other) {
            id = other.id;
            birthDate = other.birthDate;
            delete[] surname; delete[] name; delete[] patronymic;
            surname = new char[strlen(other.surname) + 1];
            strcpy(surname, other.surname);
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            patronymic = new char[strlen(other.patronymic) + 1];
            strcpy(patronymic, other.patronymic);
        }
        return *this;
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
        strcpy(surname, newSurname);
    }
    void setName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }
    void setPatronymic(const char* newPatronymic) {
        delete[] patronymic;
        patronymic = new char[strlen(newPatronymic) + 1];
        strcpy(patronymic, newPatronymic);
    }
    void setBirthDate(int d, int m, int y) {
        birthDate.setDay(d); birthDate.setMonth(m); birthDate.setYear(y);
    }

    static int getObjectCount() { return objectCount; }

    void print() const {
        cout << "  ID: " << id << ", ФИО: " << surname << " " << name << " " << patronymic << ", Дата: ";
        birthDate.print();
    }

    void printShort() const {
        cout << surname << " " << name[0] << "." << patronymic[0] << ".";
    }
};

int Person::objectCount = 0;

class Apartment {
private:
    int apartmentNumber;
    Person* residents;
    int residentCount;
    int maxResidents;

public:
    Apartment(int number, int maxRes = 5)
        : apartmentNumber(number), residentCount(0), maxResidents(maxRes) {
        residents = new Person[maxResidents];
    }

    Apartment() : Apartment(0, 5) {}

    Apartment(const Apartment& other)
        : apartmentNumber(other.apartmentNumber),
        residentCount(other.residentCount),
        maxResidents(other.maxResidents) {
        residents = new Person[maxResidents];
        for (int i = 0; i < residentCount; i++)
            residents[i] = other.residents[i];
    }

    ~Apartment() { delete[] residents; }

    Apartment& operator=(const Apartment& other) {
        if (this != &other) {
            apartmentNumber = other.apartmentNumber;
            residentCount = other.residentCount;
            maxResidents = other.maxResidents;
            delete[] residents;
            residents = new Person[maxResidents];
            for (int i = 0; i < residentCount; i++)
                residents[i] = other.residents[i];
        }
        return *this;
    }

    int getNumber() const { return apartmentNumber; }
    int getResidentCount() const { return residentCount; }

    bool addResident(const Person& person) {
        if (residentCount < maxResidents) {
            residents[residentCount] = person;
            residentCount++;
            return true;
        }
        return false;
    }

    bool removeResident(int index) {
        if (index >= 0 && index < residentCount) {
            for (int i = index; i < residentCount - 1; i++)
                residents[i] = residents[i + 1];
            residentCount--;
            return true;
        }
        return false;
    }

    bool removeResidentById(int id) {
        for (int i = 0; i < residentCount; i++)
            if (residents[i].getId() == id)
                return removeResident(i);
        return false;
    }

    Person getResident(int index) const {
        if (index >= 0 && index < residentCount)
            return residents[index];
        return Person();
    }

    void print() const {
        cout << "Кв.№" << apartmentNumber << " (" << residentCount << "):\n";
        if (residentCount == 0)
            cout << "  Свободна\n";
        else
            for (int i = 0; i < residentCount; i++) {
                cout << "  "; residents[i].print(); cout << "\n";
            }
    }
};

class House {
private:
    string address;
    Apartment* apartments;
    int apartmentCount;
    int floorCount;

public:
    House(const char* houseAddress, int floors, int aptsPerFloor)
        : address(houseAddress), floorCount(floors) {
        apartmentCount = floors * aptsPerFloor;
        apartments = new Apartment[apartmentCount];
        for (int i = 0; i < apartmentCount; i++)
            apartments[i] = Apartment(i + 1, 4);
        cout << "Создан дом: " << address << "\n";
    }

    House() : House("Неизвестный адрес", 1, 1) {}

    House(const House& other)
        : address(other.address),
        apartmentCount(other.apartmentCount),
        floorCount(other.floorCount) {
        apartments = new Apartment[apartmentCount];
        for (int i = 0; i < apartmentCount; i++)
            apartments[i] = other.apartments[i];
    }

    ~House() { delete[] apartments; }

    House& operator=(const House& other) {
        if (this != &other) {
            address = other.address;
            apartmentCount = other.apartmentCount;
            floorCount = other.floorCount;
            delete[] apartments;
            apartments = new Apartment[apartmentCount];
            for (int i = 0; i < apartmentCount; i++)
                apartments[i] = other.apartments[i];
        }
        return *this;
    }

    string getAddress() const { return address; }
    int getApartmentCount() const { return apartmentCount; }
    int getFloorCount() const { return floorCount; }

    Apartment& getApartment(int index) {
        if (index >= 0 && index < apartmentCount)
            return apartments[index];
        return apartments[0];
    }

    bool addResidentToApartment(int apartmentIndex, const Person& person) {
        if (apartmentIndex >= 0 && apartmentIndex < apartmentCount)
            return apartments[apartmentIndex].addResident(person);
        return false;
    }

    void print() const {
        cout << "\nДом " << address << ", этажей: " << floorCount << ", квартир: " << apartmentCount << "\n\n";
        int total = 0;
        for (int i = 0; i < apartmentCount; i++) {
            apartments[i].print();
            total += apartments[i].getResidentCount();
            cout << "\n";
        }
        cout << "Всего жильцов: " << total << "\n";
    }

    void printShort() const {
        int total = 0, occupied = 0;
        for (int i = 0; i < apartmentCount; i++) {
            int cnt = apartments[i].getResidentCount();
            total += cnt;
            if (cnt > 0) occupied++;
        }
        cout << "Дом " << address << ": " << apartmentCount << " кв., "
            << occupied << " занято, " << total << " жильцов\n";
    }
};

Person createPerson(int id, const char* surname, const char* name,
    const char* patronymic, int d, int m, int y) {
    return Person(id, surname, name, patronymic, d, m, y);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "МНОГОКВАРТИРНЫЙ ДОМ\n\n";

    House myHouse("ул. Ленина, д. 42", 5, 4);
    myHouse.printShort();

    Person p1 = createPerson(101, "Иванов", "Иван", "Иванович", 15, 5, 1990);
    Person p2 = createPerson(102, "Петрова", "Мария", "Петровна", 23, 8, 1985);
    Person p3 = createPerson(103, "Сидоров", "Петр", "Сергеевич", 10, 3, 2000);
    Person p4 = createPerson(104, "Козлова", "Анна", "Павловна", 5, 12, 1995);
    Person p5 = createPerson(105, "Смирнов", "Алексей", "Викторович", 30, 1, 1980);
    Person p6 = createPerson(106, "Кузнецова", "Елена", "Дмитриевна", 17, 7, 1992);
    Person p7 = createPerson(107, "Попов", "Андрей", "Николаевич", 3, 9, 1988);
    Person p8 = createPerson(108, "Васильева", "Ольга", "Игоревна", 22, 4, 1998);

    cout << "Создано жильцов: " << Person::getObjectCount() << "\n\n";

    myHouse.addResidentToApartment(0, p1);
    myHouse.addResidentToApartment(0, p2);
    myHouse.addResidentToApartment(5, p3);
    myHouse.addResidentToApartment(5, p4);
    myHouse.addResidentToApartment(10, p5);
    myHouse.addResidentToApartment(10, p6);
    myHouse.addResidentToApartment(15, p7);
    myHouse.addResidentToApartment(15, p8);

    myHouse.print();

    House houseCopy = myHouse;
    Person p9 = createPerson(109, "Новиков", "Денис", "Александрович", 12, 3, 1993);
    houseCopy.addResidentToApartment(1, p9);

    cout << "Оригинал: "; myHouse.printShort();
    cout << "Копия: "; houseCopy.printShort(); cout << "\n";

    myHouse.getApartment(0).removeResidentById(102);
    cout << "После удаления: "; myHouse.printShort(); cout << "\n";

    cout << "Всего объектов Person: " << Person::getObjectCount() << "\n\n";

    return 0;
}