#include <iostream>
#include <vector>
using namespace std;

//1
class Shape {
public:
    virtual void draw() {
        cout << "Фигура\n";
    }
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Рисуем круг\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Рисуем прямоугольник\n";
    }
};

void identifyAndDraw(Shape* s) {
    if (dynamic_cast<Circle*>(s)) {
        cout << "Это Circle: ";
        s->draw();
    }
    else if (dynamic_cast<Rectangle*>(s)) {
        cout << "Это Rectangle: ";
        s->draw();
    }
}

//2
class DataHolder {
    int data[3] = { 1, 2, 3 };

public:
    const int* getData() const {
        return data;
    }

    void print() const {
        for (int x : data) cout << x << " ";
        cout << endl;
    }
};

void modifyData(const DataHolder& dh) {
    int* ptr = const_cast<int*>(dh.getData());
    ptr[0] = 100;
}

int main() {
    setlocale(LC_ALL, "ru");

    vector<Shape*> shapes;
    shapes.push_back(new Circle());
    shapes.push_back(new Rectangle());

    for (auto s : shapes)
        identifyAndDraw(s);

    for (auto s : shapes)
        delete s;

    DataHolder d;
    d.print();

    modifyData(d);

    d.print();

    return 0;
}