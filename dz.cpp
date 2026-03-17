#include <iostream>
using namespace std;

class Circle {
public:
    double r;

    Circle(double r) : r(r) {}

    // ==
    bool operator==(const Circle& other) const {
        return r == other.r;
    }

    // >
    bool operator>(const Circle& other) const {
        return r > other.r;
    }
    // +=
    Circle& operator+=(double x) {
        r += x;
        return *this;
    }

    // -=
    Circle& operator-=(double x) {
        r -= x;
        return *this;
    }
};

int main() {
    Circle a(5), b(3);

    cout << (a == b) << endl;
    cout << (a > b) << endl;

    a += 2;
    a -= 1;

    return 0;
}