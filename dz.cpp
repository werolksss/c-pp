#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
using namespace std;

//1
class ThreadGuard {
    thread t;

public:
    template <typename Func>
    ThreadGuard(Func func) : t(func) {}

    // запрет копирования
    ThreadGuard(const ThreadGuard&) = delete;
    ThreadGuard& operator=(const ThreadGuard&) = delete;

    ~ThreadGuard() {
        if (t.joinable())
            t.join();
    }
};

// 2
class AtomicCounter {
    int value;
    mutex mtx;

public:
    AtomicCounter(int v = 0) : value(v) {}

    void increment() {
        lock_guard<mutex> lock(mtx);
        value++;
    }

    void decrement() {
        lock_guard<mutex> lock(mtx);
        value--;
    }

    int get() {
        lock_guard<mutex> lock(mtx);
        return value;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    ThreadGuard t1([]() {
        cout << "Поток 1 работает\n";
        });

    ThreadGuard t2([]() {
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Поток 2 с задержкой\n";
        });

    AtomicCounter counter(0);
    vector<thread> threads;

    for (int i = 0; i < 5; i++) {
        threads.push_back(thread([&]() {
            for (int j = 0; j < 10000; j++)
                counter.increment();
            }));

        threads.push_back(thread([&]() {
            for (int j = 0; j < 10000; j++)
                counter.decrement();
            }));
    }

    for (auto& t : threads)
        t.join();

    cout << "Итоговое значение: " << counter.get() << endl;

    return 0;
}