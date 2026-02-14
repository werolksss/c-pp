#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

class Point {
private:
    double x, y, z;
    static int objectCount;  // Статический счетчик объектов

public:
    // Конструктор по умолчанию (инициализация нулями)
    Point() : Point(0, 0, 0) {
        cout << "Конструктор по умолчанию\n";
    }

    // Конструктор с двумя координатами (третья = 0)
    Point(double x, double y) : Point(x, y, 0) {
        cout << "Конструктор с двумя координатами\n";
    }

    // Конструктор с одной координатой (остальные = 0)
    Point(double x) : Point(x, 0, 0) {
        cout << "Конструктор с одной координатой\n";
    }

    // Полный конструктор со всеми координатами
    Point(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
        objectCount++;
        cout << "Полный конструктор\n";
    }

    // Конструктор копирования
    Point(const Point& other) {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        objectCount++;
        cout << "Конструктор копирования\n";
    }

    // Деструктор
    ~Point() {
        objectCount--;
        cout << "Деструктор для точки (" << x << ", " << y << ", " << z << ")\n";
    }

    // Ввод данных
    void input() {
        cout << "Введите координату X: ";
        cin >> x;
        cout << "Введите координату Y: ";
        cin >> y;
        cout << "Введите координату Z: ";
        cin >> z;
    }

    // Вывод данных
    void print() {
        cout << "Координаты точки: ("
            << x << ", "
            << y << ", "
            << z << ")" << endl;
    }

    // Аксессоры
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }

    void setX(double newX) { x = newX; }
    void setY(double newY) { y = newY; }
    void setZ(double newZ) { z = newZ; }

    // Сохранение в файл
    void saveToFile(string filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << x << " " << y << " " << z;
            file.close();
            cout << "Данные успешно сохранены в файл.\n";
        }
        else {
            cout << "Ошибка при открытии файла!\n";
        }
    }

    // Загрузка из файла
    void loadFromFile(string filename) {
        ifstream file(filename);
        if (file.is_open()) {
            file >> x >> y >> z;
            file.close();
            cout << "Данные успешно загружены из файла.\n";
        }
        else {
            cout << "Ошибка при открытии файла!\n";
        }
    }

    // Статический метод для получения количества объектов
    static int getObjectCount() {
        return objectCount;
    }
};

// Инициализация статического члена класса
int Point::objectCount = 0;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Начальное количество объектов: " << Point::getObjectCount() << "\n\n";

    cout << "Создание точки p1 (конструктор по умолчанию)\n";
    Point p1;
    cout << "Объектов: " << Point::getObjectCount() << "\n\n";

    cout << "Создание точки p2 (конструктор с двумя координатами)\n";
    Point p2(5.5, 3.2);
    p2.print();
    cout << "Объектов: " << Point::getObjectCount() << "\n\n";

    cout << "Создание точки p3 (конструктор с одной координатой)\n";
    Point p3(10.0);
    p3.print();
    cout << "Объектов: " << Point::getObjectCount() << "\n\n";

    cout << "Создание точки p4 (полный конструктор)\n";
    Point p4(1.1, 2.2, 3.3);
    p4.print();
    cout << "Объектов: " << Point::getObjectCount() << "\n\n";

    cout << "Создание точки p5 (копия p4)\n";
    Point p5(p4);
    p5.print();
    cout << "Объектов: " << Point::getObjectCount() << "\n\n";

    cout << "Ввод данных для точки p1:\n";
    p1.input();
    p1.print();

    cout << "\nСохранение точки p1 в файл\n";
    p1.saveToFile("point.txt");

    cout << "\nЗагрузка данных из файла в новую точку p6\n";
    Point p6;
    p6.loadFromFile("point.txt");
    p6.print();
    cout << "Объектов: " << Point::getObjectCount() << "\n\n";

    cout << "\nВсего создано объектов: " << Point::getObjectCount() << endl;
    cout << "Завершение программы (деструкторы будут вызваны автоматически)\n";

    return 0;
}