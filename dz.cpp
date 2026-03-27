#include <iostream>
#include <string>
#include <locale>
using namespace std;

//Point
class Point {
    double x, y;
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    friend ostream& operator<<(ostream& os, const Point& p) {
        return os << "(" << p.x << ";" << p.y << ")";
    }
};

//Vehicle
class Vehicle {
protected:
    string model;
    int year;
    Point position;

public:
    static int totalVehicles;

    Vehicle(string m, int y, Point p)
        : model(m), year(y), position(p) {
        totalVehicles++;
    }

    explicit Vehicle(string m)
        : model(m), year(2020), position(Point()) {
        totalVehicles++;
    }

    virtual ~Vehicle() {}

    virtual double getMaxSpeed() const = 0;

    virtual void print() const {
        cout << "Модель: " << model << ", год: " << year
            << ", позиция: " << position << "\n";
    }

    void move(const Point& p) { position = p; }
};

int Vehicle::totalVehicles = 0;

//Car
class Car : public Vehicle {
    int doors;
public:
    Car(string m, int y, Point p, int d)
        : Vehicle(m, y, p), doors(d) {}

    double getMaxSpeed() const override { return 180; }

    void print() const override {
        cout << "Машина: " << model
            << ", год: " << year
            << ", позиция: " << position
            << ", двери: " << doors << "\n";
    }

    Car& operator++() { doors++; return *this; }      // ++c
    Car operator++(int) { Car t = *this; doors++; return t; } // c++
};

//Bike
class Bike : public Vehicle {
    string type;
public:
    Bike(string m, int y, Point p, string t)
        : Vehicle(m, y, p), type(t) {}

    double getMaxSpeed() const override { return 60; }

    void print() const override {
        cout << "Мотоцикл: " << model
            << ", год: " << year
            << ", позиция: " << position
            << ", тип: " << type << "\n";
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Car c("BMW", 2022, Point(1, 1), 4);
    Bike b("Yamaha", 2020, Point(0, 0), "sport");

    c.print();
    cout << "Скорость: " << c.getMaxSpeed() << "\n\n";

    b.print();
    cout << "Скорость: " << b.getMaxSpeed() << "\n\n";

    ++c; 
    cout << "После ++:\n";
    c.print();

    cout << "\nВсего транспортных средств: " << Vehicle::totalVehicles << "\n";
}