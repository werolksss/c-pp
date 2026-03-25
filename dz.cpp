#include <iostream>
#include <vector>
#include <locale>
using namespace std;
// Базовый класс
class Animal {
public:
    virtual void speak() const { cout << "I am an animal\n"; }
};
// Производные классы
class Dog : public Animal {
public:
    void speak() const override { cout << "Woof! Woof!\n"; }
};
class Cat : public Animal {
public:
    void speak() const override { cout << "Meow!\n"; }
};
class Cow : public Animal {
public:
    void speak() const override { cout << "Moo!\n"; }
};
class Horse : public Animal {
public:
    void speak() const override { cout << "Neigh!\n"; }
};
// Дополнительное задание
class Bird : public Animal {
public:
    void speak() const override { cout << "Chirik!\n"; }
};
int main() {
    setlocale(LC_ALL, "");
    vector<Animal*> animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Cow());
    animals.push_back(new Horse());
    animals.push_back(new Bird()); // Дополнительно
    cout << "Голоса животных:\n";
    for (auto a : animals) a->speak();
    // Освобождаем память
    for (auto a : animals) delete a;
}