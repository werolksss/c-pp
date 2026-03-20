#include <iostream>
using namespace std;

class Time {
    int h, m, s;

public:
    Time() : h(0), m(0), s(0) {}
    Time(int h, int m, int s) : h(h), m(m), s(s) {}

    // ++
    Time& operator++() {
        s++;
        if (s >= 60) { s = 0; m++; }
        if (m >= 60) { m = 0; h++; }
        return *this;
    }

    // --
    Time& operator--() {
        s--;
        if (s < 0) { s = 59; m--; }
        if (m < 0) { m = 59; h--; }
        return *this;
    }

    // ==
    bool operator==(const Time& t) const {
        return h == t.h && m == t.m && s == t.s;
    }

    // !=
    bool operator!=(const Time& t) const {
        return !(*this == t);
    }

    // >
    bool operator>(const Time& t) const {
        return h * 3600 + m * 60 + s > t.h * 3600 + t.m * 60 + t.s;
    }

    // <
    bool operator<(const Time& t) const {
        return !(*this > t) && !(*this == t);
    }

    // +=
    Time& operator+=(int sec) {
        s += sec;
        return *this;
    }

    // -=
    Time& operator-=(int sec) {
        s -= sec;
        return *this;
    }

    // ()
    int operator()() const {
        return h * 3600 + m * 60 + s;
    }

    // <<
    friend ostream& operator<<(ostream& out, const Time& t) {
        return out << t.h << ":" << t.m << ":" << t.s;
    }

    // >>
    friend istream& operator>>(istream& in, Time& t) {
        return in >> t.h >> t.m >> t.s;
    }
};
int main() {
    Time t1(1, 2, 3), t2;

    cin >> t2;
    cout << t2 << endl;

    ++t1;
    --t1;

    cout << (t1 == t2) << endl;
    cout << (t1 != t2) << endl;
    cout << (t1 > t2) << endl;
    cout << (t1 < t2) << endl;

    t1 += 10;
    t1 -= 5;

    cout << t1() << endl; // в секундах

    return 0;
}