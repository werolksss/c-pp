#include <iostream>
#include <string>
using namespace std;

// 1 задание
struct Complex {
    double a; 
    double b; 
};

Complex sum(Complex x, Complex y) {
    Complex result;
    result.a = x.a + y.a;
    result.b = x.b + y.b;
    return result;
}

Complex diff(Complex x, Complex y) {
    Complex result;
    result.a = x.a - y.a;
    result.b = x.b - y.b;
    return result;
}

Complex mult(Complex x, Complex y) {
    Complex result;
    result.a = x.a * y.a - x.b * y.b;
    result.b = x.a * y.b + x.b * y.a;
    return result;
}

Complex div(Complex x, Complex y) {
    Complex result;
    double z = y.a * y.a + y.b * y.b;
    result.a = (x.a * y.a + x.b * y.b) / z;
    result.b = (x.b * y.a - x.a * y.b) / z;
    return result;
}

void printComplex(Complex c) {
    cout << c.a;
    if (c.b >= 0) cout << "+";
    cout << c.b << "i\n";
}

// 2 задание
struct Car {
    double length;          // длина
    double clearance;       // клиренс
    double engineVolume;    // объем двигателя
    double enginePower;     // мощность двигателя
    double wheelDiameter;   // диаметр колес
    string color;           // цвет
    string gearbox;         // тип коробки передач
};

void setCar(Car& car) {
    cout << "Введите длину автомобиля: ";
    cin >> car.length;

    cout << "Введите клиренс: ";
    cin >> car.clearance;

    cout << "Введите объем двигателя: ";
    cin >> car.engineVolume;

    cout << "Введите мощность двигателя: ";
    cin >> car.enginePower;

    cout << "Введите диаметр колес: ";
    cin >> car.wheelDiameter;

    cout << "Введите цвет: ";
    cin >> car.color;

    cout << "Введите тип коробки передач: ";
    cin >> car.gearbox;
}

void showCar(Car car) {
    cout << "Длина: " << car.length << "\n";
    cout << "Клиренс: " << car.clearance << "\n";
    cout << "Объем двигателя: " << car.engineVolume << "\n";
    cout << "Мощность двигателя: " << car.enginePower << "\n";
    cout << "Диаметр колес: " << car.wheelDiameter << "\n";
    cout << "Цвет: " << car.color << "\n";
    cout << "Коробка передач: " << car.gearbox << "\n\n";
}

void findColor(Car cars[], int size) {
    string col;
    cout << "Введите цвет для поиска: ";
    cin >> col;

    cout << "Автомобили цвета " << col << ":\n";
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (cars[i].color == col) {
            showCar(cars[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Не найдено\n";
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    // 1 задание
    cout << "Комплексные числа\n\n";

    Complex c1, c2;

    cout << "Введите первое комплексное число:\n";
    cout << "Действительная часть: ";
    cin >> c1.a;
    cout << "Мнимая часть: ";
    cin >> c1.b;

    cout << "\nВведите второе комплексное число:\n";
    cout << "Действительная часть: ";
    cin >> c2.a;
    cout << "Мнимая часть: ";
    cin >> c2.b;

    cout << "\n";
    cout << "c1 = "; printComplex(c1);
    cout << "c2 = "; printComplex(c2);

    cout << "\nРезультаты операций:\n";
    cout << "Сумма: "; printComplex(sum(c1, c2));
    cout << "Разность: "; printComplex(diff(c1, c2));
    cout << "Умножение: "; printComplex(mult(c1, c2));
    cout << "Деление: "; printComplex(div(c1, c2));

    cout << "\n\n";

    // 2 задание
    cout << "Автомобили\n\n";

    int n;
    cout << "Сколько автомобилей добавить? ";
    cin >> n;

    Car* garage = new Car[n];

    for (int i = 0; i < n; i++) {
        cout << "\nАвтомобиль " << i + 1 << ":\n";
        setCar(garage[i]);
    }

    cout << "\nВесь гараж:\n";
    for (int i = 0; i < n; i++) {
        cout << "Автомобиль " << i + 1 << ":\n";
        showCar(garage[i]);
    }

    char search;
    cout << "Хотите найти автомобиль по цвету? (y/n): ";
    cin >> search;

    if (search == 'y' || search == 'Y') {
        findColor(garage, n);
    }

    delete[] garage;

    return 0;
}