#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

class Point {
private:
    double x, y, z;

public:
    // Конструктор по умолчанию с инициализатором
    Point() : x(0.0), y(0.0), z(0.0) {
        cout << "Вызван конструктор по умолчанию\n";
    }

    // Конструктор с параметрами (инициализатор)
    Point(double x_val, double y_val, double z_val) : x(x_val), y(y_val), z(z_val) {
        cout << "Вызван конструктор с параметрами\n";
    }

    // Конструктор копирования
    Point(const Point& other) : x(other.x), y(other.y), z(other.z) {
        cout << "Вызван конструктор копирования\n";
    }

    // Деструктор
    ~Point() {
        cout << "Вызван деструктор для точки (" << x << ", " << y << ", " << z << ")\n";
    }

    // Ввод данных (inline)
    inline void input() {
        cout << "Введите координату X: ";
        cin >> x;
        cout << "Введите координату Y: ";
        cin >> y;
        cout << "Введите координату Z: ";
        cin >> z;
    }

    // Вывод данных (inline)
    inline void print() const {
        cout << "Координаты точки: ("
            << x << ", "
            << y << ", "
            << z << ")" << endl;
    }

    // Аксессоры (inline геттеры)
    inline double getX() const { return x; }
    inline double getY() const { return y; }
    inline double getZ() const { return z; }

    // Аксессоры (inline сеттеры)
    inline void setX(double newX) { x = newX; }
    inline void setY(double newY) { y = newY; }
    inline void setZ(double newZ) { z = newZ; }

    // Метод для установки всех координат сразу
    inline void setCoordinates(double x_val, double y_val, double z_val) {
        x = x_val;
        y = y_val;
        z = z_val;
    }

    // Метод для получения модуля вектора (расстояние от начала координат)
    inline double getMagnitude() const {
        return sqrt(x * x + y * y + z * z);
    }

    // Метод для проверки равенства точек
    inline bool equals(const Point& other) const {
        return (x == other.x && y == other.y && z == other.z);
    }

    // Сохранение в файл
    void saveToFile(string filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << x << " " << y << " " << z;
            file.close();
            cout << "Данные успешно сохранены в файл\n";
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
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Тест конструкторов\n";

    // Тест конструктора по умолчанию
    Point p1;
    p1.print();

    // Тест конструктора с параметрами
    Point p2(5.5, 7.8, 3.2);
    p2.print();

    // Тест конструктора копирования
    Point p3(p2);
    p3.print();

    cout << "\nТест inline методов\n";

    // Тест сеттеров
    p1.setCoordinates(1.1, 2.2, 3.3);
    cout << "После setCoordinates: ";
    p1.print();

    // Тест геттеров
    cout << "Значение X у p2: " << p2.getX() << endl;

    // Тест дополнительных методов
    cout << "Модуль вектора p2: " << p2.getMagnitude() << endl;
    cout << "p2 и p3 " << (p2.equals(p3) ? "равны" : "не равны") << endl;

    cout << "\nТест файловых операций\n";

    // Тест сохранения и загрузки
    p1.saveToFile("point.txt");
    Point p4;
    p4.loadFromFile("point.txt");
    cout << "Загруженная точка: ";
    p4.print();

    cout << "\nДемонстрация работы деструкторов\n";
    cout << "Программа завершается, объекты будут уничтожены:\n";

    return 0;
}
