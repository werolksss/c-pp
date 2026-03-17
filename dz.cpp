#include <iostream>
#include <utility>

class IntArray {
private:
    int* data;
    size_t size;

public:
    // Конструктор по умолчанию
    IntArray() : data(nullptr), size(0) {
        std::cout << "Default constructor\n";
    }

    // Конструктор с размером
    IntArray(size_t n) : size(n) {
        data = new int[n](); // нули
        std::cout << "Size constructor\n";
    }

    // Копирующий конструктор
    IntArray(const IntArray& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; i++)
            data[i] = other.data[i];
        std::cout << "Copy constructor\n";
    }

    // Перемещающий конструктор
    IntArray(IntArray&& other) noexcept {
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move constructor\n";
    }

    // Деструктор
    ~IntArray() {
        delete[] data;
        std::cout << "Destructor\n";
    }

    // Копирующее присваивание
    IntArray& operator=(const IntArray& other) {
        std::cout << "Copy assignment\n";
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (size_t i = 0; i < size; i++)
                data[i] = other.data[i];
        }
        return *this;
    }

    // Перемещающее присваивание
    IntArray& operator=(IntArray&& other) noexcept {
        std::cout << "Move assignment\n";
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    void print() {
        for (size_t i = 0; i < size; i++)
            std::cout << data[i] << " ";
        std::cout << "\n";
    }
};

int main() {
    IntArray a(3);          // обычный
    IntArray b = a;         // копия
    IntArray c = IntArray(5); // временный → move
    IntArray d = std::move(a); // move

    b = c;                 // copy assignment
    d = std::move(c);      // move assignment

    return 0;
}