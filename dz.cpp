#include <iostream>

class Buffer {
private:
    int* data;
    size_t size;

public:
    Buffer(size_t n) : size(n) {
        data = new int[n];
    }

    // Копирование
    Buffer(const Buffer& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; i++)
            data[i] = other.data[i];
        std::cout << "Copy\n";
    }

    // Перемещение
    Buffer(Buffer&& other) noexcept {
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move\n";
    }

    // Перемещающее присваивание
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        std::cout << "Move assign\n";
        return *this;
    }

    ~Buffer() {
        delete[] data;
    }
};

int main() {
    Buffer a(10);
    Buffer b = std::move(a); // теперь move, а не copy
}