#include <iostream>
using namespace std;

class Complex {
    double re, im;

public:
    Complex() : re(0), im(0) {}
    Complex(double r, double i) : re(r), im(i) {}

    // +
    Complex operator+(const Complex& c) const {
        return Complex(re + c.re, im + c.im);
    }

    // -
    Complex operator-(const Complex& c) const {
        return Complex(re - c.re, im - c.im);
    }

    // ==
    bool operator==(const Complex& c) const {
        return re == c.re && im == c.im;
    }

    // !=
    bool operator!=(const Complex& c) const {
        return !(*this == c);
    }

    // ()
    double operator()() const {
        return re * re + im * im;
    }

    // << (дружественная)
    friend ostream& operator<<(ostream& out, const Complex& c) {
        return out << c.re << "+" << c.im << "i";
    }

    // >> (дружественная)
    friend istream& operator>>(istream& in, Complex& c) {
        return in >> c.re >> c.im;
    }
};
int main() {
    Complex a(1, 2), b(3, 4), c;

    cin >> c;              // ввод
    cout << c << endl;     // вывод

    cout << (a + b) << endl;
    cout << (a - b) << endl;

    cout << (a == b) << endl;
    cout << (a != b) << endl;

    cout << a() << endl;   // модуль (квадрат)

    return 0;
}