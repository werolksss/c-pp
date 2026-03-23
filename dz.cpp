#include <iostream>
using namespace std;

template <typename T>
class Array {
    T* data;
    int size, capacity;

public:
    Array() : data(nullptr), size(0), capacity(0) {}

    int GetSize() const { return size; }

    void Add(T val) {
        if (size >= capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            T* tmp = new T[capacity];
            for (int i = 0; i < size; i++)
                tmp[i] = data[i];
            delete[] data;
            data = tmp;
        }
        data[size++] = val;
    }

    T& operator[](int i) { return data[i]; }

    void InsertAt(int index, T val) {
        if (index < 0 || index > size) return;

        Add(val); // увеличили size

        for (int i = size - 1; i > index; i--)
            data[i] = data[i - 1];

        data[index] = val;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= size) return;

        for (int i = index; i < size - 1; i++)
            data[i] = data[i + 1];

        size--;
    }

    ~Array() { delete[] data; }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Array<int> arr;

    arr.Add(1);
    arr.Add(2);
    arr.Add(3);

    cout << "Массив: ";
    for (int i = 0; i < arr.GetSize(); i++)
        cout << arr[i] << " ";
    cout << endl;

    arr.InsertAt(1, 10);

    cout << "После вставки: ";
    for (int i = 0; i < arr.GetSize(); i++)
        cout << arr[i] << " ";
    cout << endl;

    arr.RemoveAt(2);

    cout << "После удаления: ";
    for (int i = 0; i < arr.GetSize(); i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}