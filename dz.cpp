#include <iostream>
#include <string>

using namespace std;

// 1. Ошибки
enum ErrorCode {
    GOOD,
    NO_FILE,
    NO_ACCESS,
    NO_MEMORY
};

ErrorCode checkError(bool f, bool a, bool m) {
    if (!f) return NO_FILE;
    if (!a) return NO_ACCESS;
    if (!m) return NO_MEMORY;
    return GOOD;
}

// 2. Дни недели
enum Day {
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};

string dayName(Day d) {
    if (d == MON) return "Понедельник";
    if (d == TUE) return "Вторник";
    if (d == WED) return "Среда";
    if (d == THU) return "Четверг";
    if (d == FRI) return "Пятница";
    if (d == SAT) return "Суббота";
    if (d == SUN) return "Воскресенье";
    return "???";
}

bool isWeekend(Day d) {
    return d == SAT || d == SUN;
}

// 4. Флаги отображения
enum DisplayFlags {
    BORDER = 1,
    GRID = 2,
    AXES = 4,
    LEGEND = 8
};

void showFlags(int flags) {
    cout << "Включено: ";
    if (flags & BORDER) cout << "границы ";
    if (flags & GRID) cout << "сетка ";
    if (flags & AXES) cout << "оси ";
    if (flags & LEGEND) cout << "легенда ";
    cout << endl;
}

// 6. Направления
enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

void move(int& x, int& y, Direction dir) {
    if (dir == UP) y++;
    else if (dir == RIGHT) x++;
    else if (dir == DOWN) y--;
    else if (dir == LEFT) x--;
}

string dirName(Direction dir) {
    if (dir == UP) return "вверх";
    else if (dir == RIGHT) return "вправо";
    else if (dir == DOWN) return "вниз";
    else if (dir == LEFT) return "влево";
    return "???";
}

// 9. Площади фигур
enum Shape {
    CIRCLE,
    SQUARE,
    RECTANGLE,
    TRIANGLE
};

double getArea(Shape s, double a, double b = 0) {
    if (s == CIRCLE) return 3.14 * a * a;
    else if (s == SQUARE) return a * a;
    else if (s == RECTANGLE) return a * b;
    else if (s == TRIANGLE) return 0.5 * a * b;
    return 0;
}

string shapeName(Shape s) {
    if (s == CIRCLE) return "круг";
    else if (s == SQUARE) return "квадрат";
    else if (s == RECTANGLE) return "прямоугольник";
    else if (s == TRIANGLE) return "треугольник";
    return "???";
}

int main() {
    setlocale(LC_ALL, "ru");

    // === 1. Ошибки ===
    bool file, access, memory;
    cout << "=== 1. Проверка ошибок ===" << endl;
    cout << "Файл существует? (1-да, 0-нет): ";
    cin >> file;
    cout << "Есть доступ? (1-да, 0-нет): ";
    cin >> access;
    cout << "Хватает памяти? (1-да, 0-нет): ";
    cin >> memory;

    ErrorCode err = checkError(file, access, memory);
    cout << "Результат: код " << err << " (";
    if (err == GOOD) cout << "Успех";
    else if (err == NO_FILE) cout << "Нет файла";
    else if (err == NO_ACCESS) cout << "Нет доступа";
    else if (err == NO_MEMORY) cout << "Нет памяти";
    cout << ")" << endl << endl;

    // === 2. Дни недели ===
    int dayNum;
    cout << "=== 2. Дни недели ===" << endl;
    cout << "Введите номер дня (1-понедельник, 7-воскресенье): ";
    cin >> dayNum;

    if (dayNum < 1 || dayNum > 7) {
        cout << "Неверный номер!" << endl;
    }
    else {
        Day d = (Day)(dayNum - 1);
        cout << "День: " << dayName(d) << endl;
        cout << "Выходной? " << (isWeekend(d) ? "Да" : "Нет") << endl;
    }
    cout << endl;

    // === 4. Флаги отображения ===
    int flags = 0;
    int flagChoice;
    cout << "=== 4. Флаги отображения ===" << endl;
    cout << "Выберите флаги (1-границы, 2-сетка, 3-оси, 4-легенда, 0-закончить):" << endl;

    while (true) {
        cout << "Введите номер флага (1-4) или 0 для выхода: ";
        cin >> flagChoice;
        if (flagChoice == 0) break;

        if (flagChoice == 1) flags |= BORDER;
        else if (flagChoice == 2) flags |= GRID;
        else if (flagChoice == 3) flags |= AXES;
        else if (flagChoice == 4) flags |= LEGEND;
        else cout << "Неверный выбор" << endl;
    }

    cout << "Комбинация флагов: " << flags << endl;
    showFlags(flags);
    cout << endl;

    // === 6. Движение по координатам ===
    int startX, startY;
    int dirChoice;
    cout << "=== 6. Движение по координатам ===" << endl;
    cout << "Введите начальные координаты:" << endl;
    cout << "X: "; cin >> startX;
    cout << "Y: "; cin >> startY;

    cout << "Выберите направление (1-вверх, 2-вправо, 3-вниз, 4-влево): ";
    cin >> dirChoice;

    if (dirChoice < 1 || dirChoice > 4) {
        cout << "Неверное направление!" << endl;
    }
    else {
        Direction dir = (Direction)(dirChoice - 1);
        int x = startX, y = startY;

        cout << "Начало: x=" << x << ", y=" << y << endl;
        move(x, y, dir);
        cout << "После движения " << dirName(dir) << ": x=" << x << ", y=" << y << endl;
    }
    cout << endl;

    // === 9. Площади фигур ===
    int shapeChoice;
    double a, b;
    cout << "=== 9. Площади фигур ===" << endl;
    cout << "Выберите фигуру:" << endl;
    cout << "1. Круг" << endl;
    cout << "2. Квадрат" << endl;
    cout << "3. Прямоугольник" << endl;
    cout << "4. Треугольник" << endl;
    cout << "Ваш выбор: ";
    cin >> shapeChoice;

    if (shapeChoice < 1 || shapeChoice > 4) {
        cout << "Неверный выбор!" << endl;
    }
    else {
        Shape s = (Shape)(shapeChoice - 1);

        if (s == CIRCLE) {
            cout << "Введите радиус: ";
            cin >> a;
            b = 0;
        }
        else if (s == SQUARE) {
            cout << "Введите сторону: ";
            cin >> a;
            b = 0;
        }
        else if (s == RECTANGLE) {
            cout << "Введите длину: ";
            cin >> a;
            cout << "Введите ширину: ";
            cin >> b;
        }
        else if (s == TRIANGLE) {
            cout << "Введите основание: ";
            cin >> a;
            cout << "Введите высоту: ";
            cin >> b;
        }

        double area = getArea(s, a, b);
        cout << "Площадь " << shapeName(s) << " = " << area << endl;
    }

    return 0;
}