#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Worker {
private:
    string fio;
    string dolgnost;
    int god;
    double zp;

public:
    explicit Worker(string f, string d, int g, double z) {
        fio = f;
        dolgnost = d;
        god = g;
        zp = z;
    }
    string getFIO() const {
        return fio;
    }
    string getDolgnost() const {
        return dolgnost;
    }

    int getGod() const {
        return god;
    }

    double getZp() const {
        return zp;
    }

    int getStag() const {
        return 2026 - god;
    }

    void show() const {
        cout << "ФИО: " << fio << endl;
        cout << "Должность: " << dolgnost << endl;
        cout << "Год поступления: " << god << endl;
        cout << "Зарплата: " << zp << " руб." << endl;
        cout << "Стаж: " << getStag() << " лет" << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int SIZE = 5;
    Worker workers[SIZE] = {
        Worker("Иванов И.И.", "Инженер", 2020, 50000),
        Worker("Петров П.П.", "Программист", 2018, 80000),
        Worker("Сидоров С.С.", "Инженер", 2022, 45000),
        Worker("Смирнова А.А.", "Бухгалтер", 2015, 60000),
        Worker("Козлов К.К.", "Программист", 2019, 75000)
    };

    int vibor;

    do {
        cout << "1. список по стажу" << endl;
        cout << "2. список по зарплате" << endl;
        cout << "3. список по должности" << endl;
        cout << "4. выход" << endl;
        cout << "выберите: ";
        cin >> vibor;

        if (vibor == 1) {
            int let;
            cout << "Введите стаж: ";
            cin >> let;

            cout << "\nРаботники со стажем больше " << let << " лет:" << endl;
            bool naiden = false;

            for (int i = 0; i < SIZE; i++) {
                if (workers[i].getStag() > let) {
                    workers[i].show();
                    naiden = true;
                }
            }

            if (!naiden) {
                cout << "Таких работников нет" << endl;
            }
        }
        else if (vibor == 2) {
            double summa;
            cout << "Введите зарплату: ";
            cin >> summa;

            cout << "\nРаботники с зарплатой больше " << summa << " руб.:" << endl;
            bool naiden = false;

            for (int i = 0; i < SIZE; i++) {
                if (workers[i].getZp() > summa) {
                    workers[i].show();
                    naiden = true;
                }
            }

            if (!naiden) {
                cout << "Таких работников нет" << endl;
            }
        }
        else if (vibor == 3) {
            string dolgn;
            cout << "Введите должность: ";
            cin >> dolgn;

            cout << "\nРаботники с должностью \"" << dolgn << "\":" << endl;
            bool naiden = false;

            for (int i = 0; i < SIZE; i++) {
                if (workers[i].getDolgnost() == dolgn) {
                    workers[i].show();
                    naiden = true;
                }
            }

            if (!naiden) {
                cout << "Таких работников нет" << endl;
            }
        }

    } while (vibor != 4);

    cout << "Программа завершена" << endl;
    return 0;
}