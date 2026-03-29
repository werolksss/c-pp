#include <iostream>
#include <string>
using namespace std;

// 1
namespace Geometry {
    const double PI = 3.14159;

    double circleArea(double r) {
        return PI * r * r;
    }

    double rectangleArea(double w, double h) {
        return w * h;
    }

    namespace Shapes {
        class Circle {
            double radius;
        public:
            Circle(double r) : radius(r) {}

            double area() {
                return Geometry::circleArea(radius);
            }
        };
    }
}

// 2
namespace Logger {
    enum LogLevel { INFO, WARNING, ERROR };

    void log(LogLevel level, const string& msg) {
        if (level == INFO) cout << "[INFO] ";
        else if (level == WARNING) cout << "[WARNING] ";
        else cout << "[ERROR] ";

        cout << msg << endl;
    }

    namespace FileLogger {
        void logToFile(const string& file, const string& msg) {
            cout << "Запись в файл " << file << ": " << msg << endl;
        }
    }
}

// 3

// анонимное пространство
namespace {
    int counter = 0;

    void normalize(double& v) {
        if (v < 0) v = 0;
        if (v > 1) v = 1;
        counter++;
    }
}

namespace Utils {
    double clamp(double val, double min, double max) {
        if (val < min) val = min;
        if (val > max) val = max;

        normalize(val); // используем скрытую функцию
        return val;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    //1
    cout << "Площадь круга: " << Geometry::circleArea(5) << endl;

    using Geometry::rectangleArea;
    cout << "Площадь прямоугольника: " << rectangleArea(4, 6) << endl;

    Geometry::Shapes::Circle c(3);
    cout << "Площадь (класс): " << c.area() << endl;

    //2
    using namespace Logger;

    log(INFO, "Программа запущена");
    log(WARNING, "Предупреждение");
    log(ERROR, "Ошибка");

    FileLogger::logToFile("log.txt", "Тест");

    //3
    double x = 1.5;
    cout << "Clamp: " << Utils::clamp(x, 0, 1) << endl;

    return 0;
}