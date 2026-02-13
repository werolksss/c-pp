#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <windows.h>
#include <limits>

using namespace std;

// Класс "РулонОбоев"
class WallpaperRoll {
private:
    string name;        // Название обоев
    double width;       // Ширина рулона (м)
    double length;      // Длина рулона (м)
    double price;       // Цена за рулон (руб)

public:
    // Конструкторы с инициализаторами
    WallpaperRoll() : name("Неизвестные обои"), width(0.53), length(10.05), price(0) {}

    WallpaperRoll(const string& n, double w, double l, double p)
        : name(n), width(w), length(l), price(p) {
        // Валидация данных
        if (width <= 0) width = 0.53;
        if (length <= 0) length = 10.05;
        if (price < 0) price = 0;
    }

    // Конструктор копирования
    WallpaperRoll(const WallpaperRoll& other)
        : name(other.name), width(other.width),
        length(other.length), price(other.price) {
    }

    // Деструктор
    ~WallpaperRoll() {}

    // Геттеры
    string getName() const { return name; }
    double getWidth() const { return width; }
    double getLength() const { return length; }
    double getPrice() const { return price; }
    double getArea() const { return width * length; }

    // Сеттеры
    void setName(const string& n) { name = n; }
    void setWidth(double w) { if (w > 0) width = w; }
    void setLength(double l) { if (l > 0) length = l; }
    void setPrice(double p) { if (p >= 0) price = p; }

    // Ввод данных
    void input() {
        cout << "  Название обоев: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        cout << "  Ширина рулона (м): ";
        cin >> width;
        while (width <= 0) {
            cout << "  Ошибка! Ширина должна быть > 0. Повторите: ";
            cin >> width;
        }

        cout << "  Длина рулона (м): ";
        cin >> length;
        while (length <= 0) {
            cout << "  Ошибка! Длина должна быть > 0. Повторите: ";
            cin >> length;
        }

        cout << "  Цена за рулон (руб): ";
        cin >> price;
        while (price < 0) {
            cout << "  Ошибка! Цена не может быть отрицательной. Повторите: ";
            cin >> price;
        }
    }

    // Вывод данных
    void print() const {
        cout << left << "  " << setw(25) << name
            << fixed << setprecision(2)
            << setw(10) << width << " м"
            << setw(10) << length << " м"
            << setw(10) << price << " руб"
            << setw(10) << getArea() << " м2" << endl;  // Заменил ² на 2
    }
};

// Класс "Комната"
class Room {
private:
    string name;        // Название комнаты
    double width;       // Ширина комнаты (м)
    double length;      // Длина комнаты (м)
    double height;      // Высота потолков (м)
    bool hasCeiling;    // Клеить потолок?

public:
    // Конструкторы с инициализаторами
    Room() : name("Комната"), width(4.0), length(5.0), height(2.5), hasCeiling(false) {}

    Room(const string& n, double w, double l, double h, bool ceiling)
        : name(n), width(w), length(l), height(h), hasCeiling(ceiling) {
        if (width <= 0) width = 4.0;
        if (length <= 0) length = 5.0;
        if (height <= 0) height = 2.5;
    }

    // Конструктор копирования
    Room(const Room& other)
        : name(other.name), width(other.width),
        length(other.length), height(other.height),
        hasCeiling(other.hasCeiling) {
    }

    // Деструктор
    ~Room() {}

    // Геттеры
    string getName() const { return name; }
    double getWidth() const { return width; }
    double getLength() const { return length; }
    double getHeight() const { return height; }
    bool isCeiling() const { return hasCeiling; }

    // Вычисление периметра
    double getPerimeter() const { return 2 * (width + length); }

    // Площадь стен
    double getWallsArea() const { return getPerimeter() * height; }

    // Площадь потолка
    double getCeilingArea() const { return width * length; }

    // Общая площадь для оклейки
    double getTotalArea() const {
        return getWallsArea() + (hasCeiling ? getCeilingArea() : 0);
    }

    // Сеттеры
    void setName(const string& n) { name = n; }
    void setWidth(double w) { if (w > 0) width = w; }
    void setLength(double l) { if (l > 0) length = l; }
    void setHeight(double h) { if (h > 0) height = h; }
    void setCeiling(bool c) { hasCeiling = c; }

    // Ввод данных
    void input() {
        cout << "  Название комнаты: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        cout << "  Ширина комнаты (м): ";
        cin >> width;
        while (width <= 0) {
            cout << "  Ошибка! Ширина должна быть > 0. Повторите: ";
            cin >> width;
        }

        cout << "  Длина комнаты (м): ";
        cin >> length;
        while (length <= 0) {
            cout << "  Ошибка! Длина должна быть > 0. Повторите: ";
            cin >> length;
        }

        cout << "  Высота потолков (м): ";
        cin >> height;
        while (height <= 0) {
            cout << "  Ошибка! Высота должна быть > 0. Повторите: ";
            cin >> height;
        }

        char choice;
        cout << "  Клеить потолок? (y/n): ";
        cin >> choice;
        hasCeiling = (choice == 'y' || choice == 'Y');
    }

    // Вывод данных
    void print() const {
        cout << left << "  " << setw(20) << name
            << fixed << setprecision(2)
            << setw(8) << width << " м"
            << setw(8) << length << " м"
            << setw(8) << height << " м"
            << setw(12) << (hasCeiling ? "Да" : "Нет")
            << setw(12) << getWallsArea() << " м2"   // Заменил ² на 2
            << setw(12) << getTotalArea() << " м2" << endl;  // Заменил ² на 2
    }
};

// Класс "Квартира"
class Apartment {
private:
    vector<Room> rooms;                 // Список комнат
    vector<WallpaperRoll> wallpapers;   // Список доступных обоев

public:
    // Конструктор
    Apartment() {}

    // Деструктор
    ~Apartment() {}

    // Добавление комнаты
    void addRoom() {
        cout << "\n--- Добавление новой комнаты ---\n";
        Room newRoom;
        newRoom.input();
        rooms.push_back(newRoom);
        cout << "  + Комната успешно добавлена!\n";
    }

    // Добавление нескольких комнат
    void addMultipleRooms(int count) {
        for (int i = 0; i < count; i++) {
            cout << "\n--- Комната #" << i + 1 << " ---\n";
            addRoom();
        }
    }

    // Удаление комнаты
    bool removeRoom(int index) {
        if (index >= 0 && index < (int)rooms.size()) {
            string name = rooms[index].getName();
            rooms.erase(rooms.begin() + index);
            cout << "  - Комната \"" << name << "\" удалена.\n";
            return true;
        }
        cout << "  X Ошибка: неверный индекс комнаты!\n";
        return false;
    }

    // Добавление вида обоев
    void addWallpaper() {
        cout << "\n--- Добавление нового вида обоев ---\n";
        WallpaperRoll newWallpaper;
        newWallpaper.input();
        wallpapers.push_back(newWallpaper);
        cout << "  + Обои \"" << newWallpaper.getName() << "\" добавлены!\n";
    }

    // Добавление нескольких видов обоев
    void addMultipleWallpapers(int count) {
        for (int i = 0; i < count; i++) {
            cout << "\n--- Вид обоев #" << i + 1 << " ---\n";
            addWallpaper();
        }
    }

    // Удаление вида обоев
    bool removeWallpaper(int index) {
        if (index >= 0 && index < (int)wallpapers.size()) {
            string name = wallpapers[index].getName();
            wallpapers.erase(wallpapers.begin() + index);
            cout << "  - Обои \"" << name << "\" удалены.\n";
            return true;
        }
        cout << "  X Ошибка: неверный индекс обоев!\n";
        return false;
    }

    // Показать все комнаты
    void showRooms() const {
        if (rooms.empty()) {
            cout << "\n  Список комнат пуст.\n";
            return;
        }

        cout << "\n--- СПИСОК КОМНАТ ---\n";
        cout << left << setw(5) << "N"   // Заменил № на N
            << setw(20) << "Название"
            << setw(10) << "Ширина"
            << setw(10) << "Длина"
            << setw(10) << "Высота"
            << setw(13) << "Потолок"
            << setw(14) << "Площ. стен"
            << "Общая площ." << endl;
        cout << string(95, '-') << endl;

        for (size_t i = 0; i < rooms.size(); i++) {
            cout << "  " << setw(3) << i + 1 << " ";
            rooms[i].print();
        }
        cout << string(95, '-') << endl;
    }

    // Показать все виды обоев
    void showWallpapers() const {
        if (wallpapers.empty()) {
            cout << "\n  Список обоев пуст.\n";
            return;
        }

        cout << "\n--- ВИДЫ ОБОЕВ ---\n";
        cout << left << setw(5) << "N"   // Заменил № на N
            << setw(25) << "Название"
            << setw(12) << "Ширина"
            << setw(12) << "Длина"
            << setw(12) << "Цена"
            << "Площадь" << endl;
        cout << string(80, '-') << endl;

        for (size_t i = 0; i < wallpapers.size(); i++) {
            cout << "  " << setw(3) << i + 1 << " ";
            wallpapers[i].print();
        }
        cout << string(80, '-') << endl;
    }

    // Расчет необходимого количества рулонов
    void calculate() {
        if (rooms.empty()) {
            cout << "\n  X Нет комнат для расчета!\n";
            return;
        }

        if (wallpapers.empty()) {
            cout << "\n  X Нет видов обоев для расчета!\n";
            return;
        }

        cout << "\n================================================";
        cout << "\n========== РЕЗУЛЬТАТЫ РАСЧЕТА =================";
        cout << "\n================================================\n";

        double totalCost = 0;
        double totalArea = 0;

        // Вектор для хранения количества рулонов каждого вида
        vector<int> rollsNeeded(wallpapers.size(), 0);

        // Расчет для каждой комнаты
        for (size_t i = 0; i < rooms.size(); i++) {
            const Room& room = rooms[i];
            double area = room.getTotalArea();
            totalArea += area;

            cout << "\n--- Комната: " << room.getName() << " ---\n";
            cout << "  Площадь оклейки: " << fixed << setprecision(2) << area << " м2\n";  // Заменил ² на 2

            // Выбор обоев для комнаты
            cout << "  Выберите вид обоев для этой комнаты:\n";
            showWallpapers();

            int choice;
            cout << "  Ваш выбор (1-" << wallpapers.size() << "): ";
            cin >> choice;

            while (choice < 1 || choice >(int)wallpapers.size()) {
                cout << "  Неверный выбор. Повторите: ";
                cin >> choice;
            }

            int wpIndex = choice - 1;
            const WallpaperRoll& wp = wallpapers[wpIndex];

            // Расчет количества рулонов (с запасом 10% на подгонку)
            double rollArea = wp.getArea();
            int rolls = static_cast<int>(ceil(area / rollArea * 1.1));

            rollsNeeded[wpIndex] += rolls;

            double roomCost = rolls * wp.getPrice();
            totalCost += roomCost;

            cout << "  Выбраны обои: " << wp.getName() << endl;
            cout << "  Площадь рулона: " << rollArea << " м2\n";  // Заменил ² на 2
            cout << "  Требуется рулонов: " << rolls << endl;
            cout << "  Стоимость для комнаты: " << roomCost << " руб\n";
        }

        // Итоговый расчет
        cout << "\n================================================";
        cout << "\n-------------------- ИТОГ ----------------------\n";
        cout << "  Общая площадь оклейки: " << fixed << setprecision(2)
            << totalArea << " м2\n\n";  // Заменил ² на 2

        cout << left << setw(25) << "  Вид обоев"
            << setw(15) << "Рулонов"
            << setw(15) << "Цена за рулон"
            << "Стоимость" << endl;
        cout << string(70, '-') << endl;

        for (size_t i = 0; i < wallpapers.size(); i++) {
            if (rollsNeeded[i] > 0) {
                double cost = rollsNeeded[i] * wallpapers[i].getPrice();
                cout << left << "  " << setw(23) << wallpapers[i].getName()
                    << setw(15) << rollsNeeded[i]
                    << setw(15) << wallpapers[i].getPrice()
                    << cost << " руб" << endl;
            }
        }

        cout << string(70, '-') << endl;
        cout << "  ОБЩАЯ СТОИМОСТЬ: " << totalCost << " руб\n";
        cout << "================================================\n";
    }

    // Геттеры для размеров
    size_t getRoomsCount() const { return rooms.size(); }
    size_t getWallpapersCount() const { return wallpapers.size(); }
};

// Функция очистки экрана
void clearScreen() {
    system("cls");
}

// Функция паузы
void pause() {
    cout << "\nНажмите Enter для продолжения...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    // Настройка кодировки для русского языка
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Apartment apartment;
    int choice;

    cout << "========================================\n";
    cout << "=== ПРОГРАММА РАСЧЕТА СТОИМОСТИ ОБОЕВ ===\n";
    cout << "========================================\n";

    // Ввод количества комнат
    int roomCount;
    cout << "\nВведите количество комнат для оклейки: ";
    cin >> roomCount;

    if (roomCount > 0) {
        apartment.addMultipleRooms(roomCount);
    }

    // Ввод количества видов обоев
    int wallpaperCount;
    cout << "\nВведите количество видов обоев: ";
    cin >> wallpaperCount;

    if (wallpaperCount > 0) {
        apartment.addMultipleWallpapers(wallpaperCount);
    }

    clearScreen();

    do {
        cout << "\n=============== ГЛАВНОЕ МЕНЮ ===============\n";
        cout << "1. Показать все комнаты\n";
        cout << "2. Показать все виды обоев\n";
        cout << "3. Добавить комнату\n";
        cout << "4. Добавить вид обоев\n";
        cout << "5. Удалить комнату\n";
        cout << "6. Удалить вид обоев\n";
        cout << "7. ВЫПОЛНИТЬ РАСЧЕТ\n";
        cout << "0. Выход\n";
        cout << "============================================\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            apartment.showRooms();
            break;

        case 2:
            apartment.showWallpapers();
            break;

        case 3:
            apartment.addRoom();
            break;

        case 4:
            apartment.addWallpaper();
            break;

        case 5: {
            if (apartment.getRoomsCount() == 0) {
                cout << "\n  Список комнат пуст!\n";
                break;
            }
            apartment.showRooms();
            cout << "Введите номер комнаты для удаления: ";
            int index;
            cin >> index;
            apartment.removeRoom(index - 1);
            break;
        }

        case 6: {
            if (apartment.getWallpapersCount() == 0) {
                cout << "\n  Список обоев пуст!\n";
                break;
            }
            apartment.showWallpapers();
            cout << "Введите номер обоев для удаления: ";
            int index;
            cin >> index;
            apartment.removeWallpaper(index - 1);
            break;
        }

        case 7:
            apartment.calculate();
            break;

        case 0:
            cout << "\nПрограмма завершена. Спасибо за использование!\n";
            break;

        default:
            cout << "\n  X Неверный выбор! Попробуйте снова.\n";
        }

        if (choice != 0) {
            pause();
            clearScreen();
        }

    } while (choice != 0);

    return 0;
}
