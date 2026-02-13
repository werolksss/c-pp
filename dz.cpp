#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>

using namespace std;

class Abonent {
private:
    char* fullName;
    char* homePhone;
    char* workPhone;
    char* mobilePhone;
    char* additionalInfo;

    // Вспомогательная функция для копирования строки
    inline char* copyString(const char* source) const {
        if (source == nullptr) return nullptr;

        char* destination = new char[strlen(source) + 1];
        strcpy_s(destination, strlen(source) + 1, source);
        return destination;
    }

public:
    // Конструктор по умолчанию с инициализаторами
    Abonent() : fullName(nullptr), homePhone(nullptr), workPhone(nullptr),
        mobilePhone(nullptr), additionalInfo(nullptr) {
    }

    // Конструктор с параметрами
    Abonent(const char* name, const char* home, const char* work,
        const char* mobile, const char* info)
        : fullName(nullptr), homePhone(nullptr), workPhone(nullptr),
        mobilePhone(nullptr), additionalInfo(nullptr) {

        if (name != nullptr) {
            fullName = new char[strlen(name) + 1];
            strcpy_s(fullName, strlen(name) + 1, name);
        }

        if (home != nullptr) {
            homePhone = new char[strlen(home) + 1];
            strcpy_s(homePhone, strlen(home) + 1, home);
        }

        if (work != nullptr) {
            workPhone = new char[strlen(work) + 1];
            strcpy_s(workPhone, strlen(work) + 1, work);
        }

        if (mobile != nullptr) {
            mobilePhone = new char[strlen(mobile) + 1];
            strcpy_s(mobilePhone, strlen(mobile) + 1, mobile);
        }

        if (info != nullptr) {
            additionalInfo = new char[strlen(info) + 1];
            strcpy_s(additionalInfo, strlen(info) + 1, info);
        }
    }

    // Конструктор копирования
    Abonent(const Abonent& other)
        : fullName(copyString(other.fullName)),
        homePhone(copyString(other.homePhone)),
        workPhone(copyString(other.workPhone)),
        mobilePhone(copyString(other.mobilePhone)),
        additionalInfo(copyString(other.additionalInfo)) {
    }

    // Деструктор
    ~Abonent() {
        delete[] fullName;
        delete[] homePhone;
        delete[] workPhone;
        delete[] mobilePhone;
        delete[] additionalInfo;
    }

    // Геттеры (inline)
    inline const char* getFullName() const { return fullName ? fullName : ""; }
    inline const char* getHomePhone() const { return homePhone ? homePhone : ""; }
    inline const char* getWorkPhone() const { return workPhone ? workPhone : ""; }
    inline const char* getMobilePhone() const { return mobilePhone ? mobilePhone : ""; }
    inline const char* getAdditionalInfo() const { return additionalInfo ? additionalInfo : ""; }

    // Сеттеры
    inline void setFullName(const char* name) {
        delete[] fullName;
        if (name != nullptr) {
            fullName = new char[strlen(name) + 1];
            strcpy_s(fullName, strlen(name) + 1, name);
        }
        else {
            fullName = nullptr;
        }
    }

    inline void setHomePhone(const char* phone) {
        delete[] homePhone;
        if (phone != nullptr) {
            homePhone = new char[strlen(phone) + 1];
            strcpy_s(homePhone, strlen(phone) + 1, phone);
        }
        else {
            homePhone = nullptr;
        }
    }

    inline void setWorkPhone(const char* phone) {
        delete[] workPhone;
        if (phone != nullptr) {
            workPhone = new char[strlen(phone) + 1];
            strcpy_s(workPhone, strlen(phone) + 1, phone);
        }
        else {
            workPhone = nullptr;
        }
    }

    inline void setMobilePhone(const char* phone) {
        delete[] mobilePhone;
        if (phone != nullptr) {
            mobilePhone = new char[strlen(phone) + 1];
            strcpy_s(mobilePhone, strlen(phone) + 1, phone);
        }
        else {
            mobilePhone = nullptr;
        }
    }

    inline void setAdditionalInfo(const char* info) {
        delete[] additionalInfo;
        if (info != nullptr) {
            additionalInfo = new char[strlen(info) + 1];
            strcpy_s(additionalInfo, strlen(info) + 1, info);
        }
        else {
            additionalInfo = nullptr;
        }
    }

    // Ввод данных абонента
    void input() {
        char buffer[256];

        cout << "Введите ФИО: ";
        cin.ignore();
        cin.getline(buffer, 256);
        setFullName(buffer);

        cout << "Введите домашний телефон: ";
        cin.getline(buffer, 256);
        setHomePhone(buffer);

        cout << "Введите рабочий телефон: ";
        cin.getline(buffer, 256);
        setWorkPhone(buffer);

        cout << "Введите мобильный телефон: ";
        cin.getline(buffer, 256);
        setMobilePhone(buffer);

        cout << "Введите дополнительную информацию: ";
        cin.getline(buffer, 256);
        setAdditionalInfo(buffer);
    }

    // Вывод данных абонента
    inline void print() const {
        cout << "\n";
        cout << " ФИО: " << getFullName() << endl;
        cout << " Домашний тел.: " << getHomePhone() << endl;
        cout << " Рабочий тел.: " << getWorkPhone() << endl;
        cout << " Мобильный тел.: " << getMobilePhone() << endl;
        cout << " Доп. инфо: " << getAdditionalInfo() << endl;
        cout << "\n";
    }

    // Сохранение в файл
    void saveToFile(ofstream& file) const {
        if (file.is_open()) {
            file << getFullName() << endl;
            file << getHomePhone() << endl;
            file << getWorkPhone() << endl;
            file << getMobilePhone() << endl;
            file << getAdditionalInfo() << endl;
            file << "---" << endl; // Разделитель записей
        }
    }

    // Загрузка из файла
    bool loadFromFile(ifstream& file) {
        char buffer[256];

        if (!file.getline(buffer, 256)) return false;
        setFullName(buffer);

        if (!file.getline(buffer, 256)) return false;
        setHomePhone(buffer);

        if (!file.getline(buffer, 256)) return false;
        setWorkPhone(buffer);

        if (!file.getline(buffer, 256)) return false;
        setMobilePhone(buffer);

        if (!file.getline(buffer, 256)) return false;
        setAdditionalInfo(buffer);

        // Пропускаем разделитель
        file.getline(buffer, 256);

        return true;
    }

    // Оператор присваивания
    Abonent& operator=(const Abonent& other) {
        if (this != &other) {
            setFullName(other.getFullName());
            setHomePhone(other.getHomePhone());
            setWorkPhone(other.getWorkPhone());
            setMobilePhone(other.getMobilePhone());
            setAdditionalInfo(other.getAdditionalInfo());
        }
        return *this;
    }

    // Сравнение по ФИО
    inline bool compareByName(const char* name) const {
        if (fullName == nullptr || name == nullptr) return false;
        return strcmp(fullName, name) == 0;
    }
};

class PhoneBook {
private:
    Abonent* abonents;
    int size;
    int capacity;

    // Увеличение capacity при необходимости
    void expand() {
        capacity *= 2;
        Abonent* newAbonents = new Abonent[capacity];
        for (int i = 0; i < size; i++) {
            newAbonents[i] = abonents[i];
        }
        delete[] abonents;
        abonents = newAbonents;
    }

public:
    // Конструктор по умолчанию
    PhoneBook() : abonents(new Abonent[10]), size(0), capacity(10) {}

    // Деструктор
    ~PhoneBook() {
        delete[] abonents;
    }

    // Добавление абонента
    void addAbonent() {
        if (size >= capacity) {
            expand();
        }

        cout << "\nДобавление нового абонента\n";
        abonents[size].input();
        size++;
        cout << "Абонент успешно добавлен!\n";
    }

    // Удаление абонента по индексу
    void removeAbonent(int index) {
        if (index < 0 || index >= size) {
            cout << "Неверный индекс!\n";
            return;
        }

        for (int i = index; i < size - 1; i++) {
            abonents[i] = abonents[i + 1];
        }
        size--;
        cout << "Абонент удален!\n";
    }

    // Поиск абонента по ФИО
    void searchByName() {
        if (size == 0) {
            cout << "Телефонная книга пуста!\n";
            return;
        }

        char searchName[256];
        cout << "Введите ФИО для поиска: ";
        cin.ignore();
        cin.getline(searchName, 256);

        bool found = false;
        for (int i = 0; i < size; i++) {
            if (abonents[i].compareByName(searchName)) {
                cout << "\nНайден абонент (индекс " << i << "):\n";
                abonents[i].print();
                found = true;
            }
        }

        if (!found) {
            cout << "Абонент с ФИО \"" << searchName << "\" не найден.\n";
        }
    }

    // Показ всех абонентов
    void showAll() const {
        if (size == 0) {
            cout << "Телефонная книга пуста!\n";
            return;
        }

        cout << "\nТЕЛЕФОННАЯ КНИГА\n";
        for (int i = 0; i < size; i++) {
            cout << "Абонент #" << i + 1 << ":\n";
            abonents[i].print();
        }
        cout << "Всего абонентов: " << size << "\n\n";
    }

    // Сохранение в файл
    void saveToFile() {
        if (size == 0) {
            cout << "Нет данных для сохранения!\n";
            return;
        }

        char filename[256];
        cout << "Введите имя файла для сохранения: ";
        cin.ignore();
        cin.getline(filename, 256);

        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Ошибка открытия файла для записи!\n";
            return;
        }

        file << size << endl; // Сохраняем количество абонентов
        for (int i = 0; i < size; i++) {
            abonents[i].saveToFile(file);
        }

        file.close();
        cout << "Данные успешно сохранены в файл " << filename << endl;
    }

    // Загрузка из файла
    void loadFromFile() {
        char filename[256];
        cout << "Введите имя файла для загрузки: ";
        cin.ignore();
        cin.getline(filename, 256);

        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Ошибка открытия файла для чтения!\n";
            return;
        }

        int newSize;
        file >> newSize;
        file.ignore(); // Пропускаем символ новой строки

        // Очищаем текущие данные
        delete[] abonents;
        capacity = (newSize > 10) ? newSize : 10;
        abonents = new Abonent[capacity];
        size = 0;

        // Загружаем новые данные
        for (int i = 0; i < newSize; i++) {
            if (size >= capacity) expand();
            if (abonents[size].loadFromFile(file)) {
                size++;
            }
            else {
                cout << "Ошибка загрузки абонента #" << i + 1 << endl;
                break;
            }
        }

        file.close();
        cout << "Данные успешно загружены из файла " << filename << endl;
        cout << "Загружено абонентов: " << size << endl;
    }

    // Получение размера (inline)
    inline int getSize() const { return size; }
};

// Функция для отображения меню (inline)
inline void showMenu() {
    cout << "\nТЕЛЕФОННАЯ КНИГА\n";
    cout << "1. Добавить абонента\n";
    cout << "2. Удалить абонента\n";
    cout << "3. Найти абонента по ФИО\n";
    cout << "4. Показать всех абонентов\n";
    cout << "5. Сохранить в файл\n";
    cout << "6. Загрузить из файла\n";
    cout << "0. Выход\n";
    cout << "Выберите действие: ";
}

int main() {
    // Настройка кодировки для русского языка
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    PhoneBook phoneBook;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            phoneBook.addAbonent();
            break;

        case 2: {
            if (phoneBook.getSize() == 0) {
                cout << "Телефонная книга пуста!\n";
                break;
            }
            int index;
            cout << "Введите номер абонента для удаления (1-" << phoneBook.getSize() << "): ";
            cin >> index;
            phoneBook.removeAbonent(index - 1);
            break;
        }

        case 3:
            phoneBook.searchByName();
            break;

        case 4:
            phoneBook.showAll();
            break;

        case 5:
            phoneBook.saveToFile();
            break;

        case 6:
            phoneBook.loadFromFile();
            break;

        case 0:
            cout << "Программа завершена.\n";
            break;

        default:
            cout << "Неверный выбор! Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}