#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}
    Date(const Date&) = default;

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    void print() const {
        printf("%02d.%02d.%d", day, month, year);
    }

    Date& operator=(const Date&) = default;
};

class Person {
private:
    int id;
    char* surname{ nullptr };
    char* name{ nullptr };
    char* patronymic{ nullptr };
    Date birthDate;
    static int objectCount;

    void copyStrings(const char* s, const char* n, const char* p) {
        surname = new char[strlen(s) + 1]; strcpy(surname, s);
        name = new char[strlen(n) + 1]; strcpy(name, n);
        patronymic = new char[strlen(p) + 1]; strcpy(patronymic, p);
    }

public:
    Person(int id, const char* s, const char* n, const char* p, int d, int m, int y)
        : id(id), birthDate(d, m, y) {
        copyStrings(s, n, p); objectCount++;
    }

    Person() : Person(0, "Неизвестно", "Неизвестно", "Неизвестно", 1, 1, 2000) {}

    Person(const Person& o) : id(o.id), birthDate(o.birthDate) {
        copyStrings(o.surname, o.name, o.patronymic); objectCount++;
    }

    Person(Person&& o) noexcept : id(o.id), birthDate(o.birthDate),
        surname(o.surname), name(o.name), patronymic(o.patronymic) {
        o.surname = o.name = o.patronymic = nullptr; objectCount++;
    }

    ~Person() { delete[] surname; delete[] name; delete[] patronymic; objectCount--; }

    Person& operator=(const Person& o) {
        if (this != &o) {
            delete[] surname; delete[] name; delete[] patronymic;
            id = o.id; birthDate = o.birthDate;
            copyStrings(o.surname, o.name, o.patronymic);
        }
        return *this;
    }

    Person& operator=(Person&& o) noexcept {
        if (this != &o) {
            delete[] surname; delete[] name; delete[] patronymic;
            id = o.id; birthDate = o.birthDate;
            surname = o.surname; name = o.name; patronymic = o.patronymic;
            o.surname = o.name = o.patronymic = nullptr;
        }
        return *this;
    }

    int getId() const { return id; }
    const char* getSurname() const { return surname; }
    const char* getName() const { return name; }
    const char* getPatronymic() const { return patronymic; }
    Date getBirthDate() const { return birthDate; }

    void setSurname(const char* s) { delete[] surname; surname = new char[strlen(s) + 1]; strcpy(surname, s); }
    void setName(const char* n) { delete[] name; name = new char[strlen(n) + 1]; strcpy(name, n); }
    void setPatronymic(const char* p) { delete[] patronymic; patronymic = new char[strlen(p) + 1]; strcpy(patronymic, p); }
    void setBirthDate(int d, int m, int y) { birthDate = Date(d, m, y); }

    static int getObjectCount() { return objectCount; }

    void print() const {
        printf("  ID: %d, ФИО: %s %s %s, Дата: ", id, surname, name, patronymic);
        birthDate.print();
    }

    void printShort() const {
        printf("%s %c.%c.", surname, name[0], patronymic[0]);
    }
};
int Person::objectCount = 0;

class Apartment {
private:
    int apartmentNumber;
    Person* residents{ nullptr };
    int residentCount{ 0 };
    int maxResidents;

public:
    Apartment(int num = 0, int max = 5) : apartmentNumber(num), maxResidents(max) {
        residents = new Person[maxResidents];
    }

    Apartment(const Apartment& o) : apartmentNumber(o.apartmentNumber),
        residentCount(o.residentCount), maxResidents(o.maxResidents) {
        residents = new Person[maxResidents];
        for (int i = 0; i < residentCount; i++) residents[i] = o.residents[i];
    }

    Apartment(Apartment&& o) noexcept : apartmentNumber(o.apartmentNumber),
        residentCount(o.residentCount), maxResidents(o.maxResidents), residents(o.residents) {
        o.residents = nullptr; o.residentCount = o.maxResidents = 0;
    }

    ~Apartment() { delete[] residents; }

    Apartment& operator=(const Apartment& o) {
        if (this != &o) {
            delete[] residents;
            apartmentNumber = o.apartmentNumber;
            residentCount = o.residentCount;
            maxResidents = o.maxResidents;
            residents = new Person[maxResidents];
            for (int i = 0; i < residentCount; i++) residents[i] = o.residents[i];
        }
        return *this;
    }

    Apartment& operator=(Apartment&& o) noexcept {
        if (this != &o) {
            delete[] residents;
            apartmentNumber = o.apartmentNumber;
            residentCount = o.residentCount;
            maxResidents = o.maxResidents;
            residents = o.residents;
            o.residents = nullptr; o.residentCount = o.maxResidents = 0;
        }
        return *this;
    }

    int getNumber() const { return apartmentNumber; }
    int getResidentCount() const { return residentCount; }

    bool addResident(const Person& p) {
        if (residentCount >= maxResidents) return false;
        residents[residentCount++] = p;
        return true;
    }

    bool removeResident(int idx) {
        if (idx < 0 || idx >= residentCount) return false;
        for (int i = idx; i < residentCount - 1; i++) residents[i] = residents[i + 1];
        residentCount--;
        return true;
    }

    bool removeResidentById(int id) {
        for (int i = 0; i < residentCount; i++)
            if (residents[i].getId() == id) return removeResident(i);
        return false;
    }

    Person getResident(int idx) const {
        return (idx >= 0 && idx < residentCount) ? residents[idx] : Person();
    }

    void print() const {
        printf("Кв.№%d (%d):\n", apartmentNumber, residentCount);
        if (!residentCount) printf("  Свободна\n");
        else for (int i = 0; i < residentCount; i++) {
            printf("  "); residents[i].print(); printf("\n");
        }
    }
};

class House {
private:
    string address;
    Apartment* apartments{ nullptr };
    int apartmentCount{ 0 };
    int floorCount{ 0 };

public:
    House(const char* addr, int floors, int aptsPerFloor)
        : address(addr), floorCount(floors), apartmentCount(floors* aptsPerFloor) {
        apartments = new Apartment[apartmentCount];
        for (int i = 0; i < apartmentCount; i++) apartments[i] = Apartment(i + 1, 4);
        cout << "Создан дом: " << address << "\n";
    }

    House() : House("Неизвестный адрес", 1, 1) {}

    House(const House& o) : address(o.address),
        apartmentCount(o.apartmentCount), floorCount(o.floorCount) {
        apartments = new Apartment[apartmentCount];
        for (int i = 0; i < apartmentCount; i++) apartments[i] = o.apartments[i];
    }

    House(House&& o) noexcept : address(move(o.address)),
        apartmentCount(o.apartmentCount), floorCount(o.floorCount), apartments(o.apartments) {
        o.apartments = nullptr; o.apartmentCount = o.floorCount = 0;
    }

    ~House() { delete[] apartments; }

    House& operator=(const House& o) {
        if (this != &o) {
            delete[] apartments;
            address = o.address;
            apartmentCount = o.apartmentCount;
            floorCount = o.floorCount;
            apartments = new Apartment[apartmentCount];
            for (int i = 0; i < apartmentCount; i++) apartments[i] = o.apartments[i];
        }
        return *this;
    }

    House& operator=(House&& o) noexcept {
        if (this != &o) {
            delete[] apartments;
            address = move(o.address);
            apartmentCount = o.apartmentCount;
            floorCount = o.floorCount;
            apartments = o.apartments;
            o.apartments = nullptr; o.apartmentCount = o.floorCount = 0;
        }
        return *this;
    }

    string getAddress() const { return address; }
    int getApartmentCount() const { return apartmentCount; }
    Apartment& getApartment(int idx) { return apartments[idx]; }

    bool addResidentToApartment(int aptIdx, const Person& p) {
        return (aptIdx >= 0 && aptIdx < apartmentCount) ? apartments[aptIdx].addResident(p) : false;
    }

    void print() const {
        printf("\nДом %s, этажей: %d, квартир: %d\n\n", address.c_str(), floorCount, apartmentCount);
        int total = 0;
        for (int i = 0; i < apartmentCount; i++) {
            apartments[i].print();
            total += apartments[i].getResidentCount();
            printf("\n");
        }
        printf("Всего жильцов: %d\n", total);
    }

    void printShort() const {
        int total = 0, occupied = 0;
        for (int i = 0; i < apartmentCount; i++) {
            int cnt = apartments[i].getResidentCount();
            total += cnt;
            if (cnt) occupied++;
        }
        printf("Дом %s: %d кв., %d занято, %d жильцов\n", address.c_str(), apartmentCount, occupied, total);
    }
};

Person createPerson(int id, const char* s, const char* n, const char* p, int d, int m, int y) {
    return Person(id, s, n, p, d, m, y);
}

int main() {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
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

    myHouse.addResidentToApartment(0, p1); myHouse.addResidentToApartment(0, p2);
    myHouse.addResidentToApartment(5, p3); myHouse.addResidentToApartment(5, p4);
    myHouse.addResidentToApartment(10, p5); myHouse.addResidentToApartment(10, p6);
    myHouse.addResidentToApartment(15, p7); myHouse.addResidentToApartment(15, p8);

    myHouse.print();

    cout << "\n=== Демонстрация конструкторов переноса ===\n";

    Person p9 = createPerson(109, "Новиков", "Денис", "Александрович", 12, 3, 1993);
    cout << "Создан p9\n";
    Person p10 = move(p9);
    cout << "p10 создан через move из p9\np9 после переноса: "; p9.printShort(); cout << "\np10: "; p10.printShort(); cout << "\n\n";

    Apartment apt1(50, 3);
    apt1.addResident(p1); apt1.addResident(p2);
    cout << "Создана apt1 с жильцами\n";
    Apartment apt2 = move(apt1);
    cout << "apt2 создана через move из apt1\napt1: "; apt1.print(); cout << "apt2: "; apt2.print(); cout << "\n";

    House house2 = move(myHouse);
    cout << "house2 создан через move из myHouse\nmyHouse: "; myHouse.printShort();
    cout << "house2: "; house2.printShort(); cout << "\n";

    cout << "Всего объектов Person: " << Person::getObjectCount() << "\n\n";
    return 0;
}