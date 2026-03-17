#include <iostream>
using namespace std;

class Airplane {
public:
    int passengers;
    int max_passengers;

    Airplane(int p, int max_p) : passengers(p), max_passengers(max_p) {}

    // ==
    bool operator==(const Airplane& other) const {
        return max_passengers == other.max_passengers;
    }


    // ++ (префикс)
    Airplane& operator++() {
        passengers++;
        return *this;
    }

    // -- (префикс)
    Airplane& operator--() {
        passengers--;
        return *this;
    }

    // >

    bool operator>(const Airplane& other) const {
        return max_passengers > other.max_passengers;
    }
};

int main() {
    Airplane a(100, 200), b(80, 150);

    cout << (a == b) << endl;
    cout << (a > b) << endl;

    ++a;
    --a;

    return 0;
}