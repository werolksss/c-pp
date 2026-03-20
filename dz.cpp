#include <iostream>
using namespace std;
class Processor {
public:
    string model;
    Processor(string m) {
        model = m;
        cout << "Создан процессор: " << model << endl;
    }
    ~Processor() {
        cout << "Уничтожен процессор: " << model << endl;
    }
};
class Computer {
private:
    Processor* cpu;
public:
    Computer(string cpuModel) {
        cpu = new Processor(cpuModel);
        cout << "Компьютер собран" << endl;
    }
    Computer(const Computer&) = delete;
    Computer& operator=(const Computer&) = delete;
    ~Computer() {
        delete cpu;
        cout << "Компьютер уничтожен" << endl;
    }
    void showInfo() {
        cout << "В компьютере установлен: " << cpu->model << endl;
    }
};
int main() {
    setlocale(LC_ALL, "ru");
    cout << "Создаём компьютер\n";
    Computer myPC("Intel i5");
    myPC.showInfo();
    cout << "\nКомпьютер завершает работу\n";
    return 0;
}