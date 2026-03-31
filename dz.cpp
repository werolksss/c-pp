#include <iostream>
#include <memory>
#include <chrono>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

class Timer {
    chrono::steady_clock::time_point start;

public:
    Timer() {
        start = chrono::steady_clock::now();
        cout << "Таймер запущен\n";
    }

    ~Timer() {
        auto end = chrono::steady_clock::now();
        auto ms = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Прошло: " << ms.count() << " мс\n";
    }
};

unique_ptr<Timer> createTimer() {
    return make_unique<Timer>();
}


int main() {
    setlocale(LC_ALL, "Ru");

    {
        unique_ptr<Timer> t = createTimer();
    }

    vector<string> names = { "Ann", "Michael", "Tom", "Kate", "Alexander" };

    sort(names.begin(), names.end(),
        [](string a, string b) {
            return a.size() < b.size();
        });

    names.erase(remove_if(names.begin(), names.end(),
        [](string s) {
            return s.size() < 4;
        }), names.end());

    for_each(names.begin(), names.end(),
        [](string& s) {
            for (char& c : s)
                c = toupper(c);
        });


    cout << "Результат:\n";
    for (auto s : names)
        cout << s << endl;

    return 0;
}