#include <iostream>
#include <string>

using namespace std;

// базовый класс Cat
class Cat {
protected:
    string name;
    int age;
    string color;

    static int count;

public:
    // конструктор с параметрами
    Cat(const string& name, int age, const string& color)
        : name(name), age(age), color(color) {
        count++; // Увеличиваем счётчик при создании объекта
        cout << "Cat constructor: " << name << endl;
    }

    // деструктор
    virtual ~Cat() {
        count--;
        cout << "Cat destructor: " << name << " destroyed" << endl;
    }

    // вывод информации о кошке
    void printInfo() const {
        cout << "Name: " << name << ", Age: " << age << ", Color: " << color;
    }

    // вывод для звука кошк
    void sound() const {
        cout << "Cat makes a sound: Meow!" << endl;
    }

    // геттеры
    string getName() const { return name; }
    int getAge() const { return age; }
    string getColor() const { return color; }

    // статический метод для получения количества кошек
    static int getCount() {
        return count;
    }
};

int Cat::count = 0;

//производный класс HouseCat
class HouseCat : public Cat {
private:
    string ownerName;

public:
    HouseCat(const string& name, int age, const string& color, const string& owner)
        : Cat(name, age, color), ownerName(owner) {
        cout << "HouseCat constructor: " << name << endl;
    }

    // деструктор
    ~HouseCat() {
        cout << "HouseCat destructor: " << name << " destroyed" << endl;
    }

    // переопределение метода
    void sound() const {
        cout << name << " purrs: Mrrr-mrrr" << endl;
    }

    void printInfo() const {
        Cat::printInfo(); 
        cout << ", Owner: " << ownerName << endl;
    }

    // собственный метод
    void play() const {
        cout << name << " plays with a ball" << endl;
    }
};

// производный класс WildCat
class WildCat : public Cat {
private:
    string habitat;

public:
    // конструктор
    WildCat(const string& name, int age, const string& color, const string& habitat)
        : Cat(name, age, color), habitat(habitat) {
        cout << "WildCat constructor: " << name << endl;
    }

    // деструктор
    ~WildCat() {
        cout << "WildCat destructor: " << name << " destroyed" << endl;
    }

    // переопределение метода=
    void sound() const {
        cout << name << " growls: Rrrr!" << endl;
    }

    // переопределение метода
    void printInfo() const {
        Cat::printInfo();
        cout << ", Habitat: " << habitat << endl;
    }

    //собственный метод
    void hunt() const {
        cout << name << " is hunting" << endl;
    }
};

// производный класс PersianCat
class PersianCat : public Cat {
private:
    int woolLength;

public:
    // конструктор
    PersianCat(const string& name, int age, const string& color, int woolLength)
        : Cat(name, age, color), woolLength(woolLength) {
        cout << "PersianCat constructor: " << name << endl;
    }

    // деструктор
    ~PersianCat() {
   
            cout << "PersianCat destructor: " << name << " destroyed" << endl;
    }

    // переопределение метода
    void sound() const {
        cout << name << " says softly: Meow" << endl;
    }

    // переопределение метода
    void printInfo() const {
        Cat::printInfo();
        cout << ", Wool length: " << woolLength << " cm" << endl;
    }

    // собственный метод
    void groom() const {
        cout << name << " needs grooming" << endl;
    }
};

// функция для вызовов через указатель на базовый класс
void demonstratePolymorphism(Cat* cat) {
    cout << "\nDemonstrating polymorphism" << endl;
    cat->printInfo();
    cat->sound(); 
}

int main() {
    cout << "Program start\n" << endl;

    // создание объектов разных типов
    cout << "Creating objects:\n";

    HouseCat houseCat("Murka", 3, "gray", "Anna");
    WildCat wildCat("Simba", 5, "golden", "savanna");
    PersianCat persianCat("Fluffy", 2, "white", 10);

    // дополнительный объект для демонстрации
    HouseCat anotherHouseCat("Barsik", 1, "black", "Petr");

    // вывод текущего количества кошек через статический метод
    cout << "\nTotal cats count: " << Cat::getCount() << endl;

    cout << "\nDirect method calls\n";

    // вызов методов через объекты производных классов
    cout << "\nHouseCat methods:\n";
    houseCat.printInfo();
    houseCat.sound();
    houseCat.play();

    cout << "\nWildCat methods:\n";
    wildCat.printInfo();
    wildCat.sound();
    wildCat.hunt();

    cout << "\nPersianCat methods:\n";
    persianCat.printInfo();
    persianCat.sound();
    persianCat.groom();

    cout << "\nCalls via pointers/references to base class\n";

    // демонстрация вызовов через указатели на базовый класс
    Cat* ptr1 = &houseCat;
    Cat* ptr2 = &wildCat;
    Cat* ptr3 = &persianCat;

    cout << "Calling printInfo() via Cat*:\n";
    ptr1->printInfo();
    ptr2->printInfo(); 
    ptr3->printInfo();

    // демонстрация вызова через ссылку
    cout << "\nCall via reference:\n";
    Cat& ref = anotherHouseCat;
    ref.printInfo();

    return 0;
} 