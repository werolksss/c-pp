#include <iostream>
#include <stdexcept>
using namespace std;

class IntArray {
private:
    int* arr;
    int size;

public:
    IntArray(int s) {
        size = s;
        arr = new int[size];
    }

    int& at(int index) {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range");

        return arr[index];
    }

    ~IntArray() {
        delete[] arr;
    }
};

int main() {
    try {
        IntArray a(3);

        a.at(0) = 10;
        a.at(1) = 20;

        cout << a.at(1) << endl;

        cout << a.at(5); // ошибка
    }
    catch (out_of_range& e) {
        cout << e.what() << endl;
    }
}