#include <iostream>
#include <exception>
using namespace std;

class DivisionByZeroException : public exception {
public:
    const char* what() const noexcept override {
        return "Division by zero!";
    }
};

class SafeDivision {
public:
    static double divide(double a, double b) {
        if (b == 0)
            throw DivisionByZeroException();

        return a / b;
    }
};

int main() {
    try {
        cout << SafeDivision::divide(10, 2) << endl;
        cout << SafeDivision::divide(5, 0) << endl; // ошибка
    }
    catch (DivisionByZeroException& e) {
        cout << e.what() << endl;
    }
}