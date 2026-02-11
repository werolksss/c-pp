#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

class Point {
private:
    double x, y, z;

public:
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
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Point p;

    p.input();
    p.print();

    p.saveToFile("point.txt");

    cout << "\nЗагрузка данных из файла...\n";
    p.loadFromFile("point.txt");
    p.print();

    return 0;
}
