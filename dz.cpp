#include <iostream>
#include <vector>
#include <string>
#include <locale>
using namespace std;
class Employee {
protected:
    string name;
public:
    Employee(const string& n) : name(n) {}
    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const { cout << "Сотрудник: " << name << "\n"; }
    virtual ~Employee() = default;
};
class Manager : public Employee {
    double fixedSalary;
public:
    Manager(const string& n, double s) : Employee(n), fixedSalary(s) {}
    double calculateSalary() const override { return fixedSalary; }
    void displayInfo() const override { cout << "Менеджер: " << name << "\n"; }
};
class Engineer : public Employee {
    double hourlyRate;
    int hours;
public:
    Engineer(const string& n, double rate, int h) : Employee(n), hourlyRate(rate), hours(h) {}
    double calculateSalary() const override { return hourlyRate * hours; }
    void displayInfo() const override { cout << "Инженер: " << name << " (" << hours << " часов по $" << hourlyRate << "/час)\n"; }
};
class SalesPerson : public Employee {
    double baseSalary, salesAmount, commissionRate;
public:
    SalesPerson(const string& n, double b, double s, double c) : Employee(n), baseSalary(b), salesAmount(s), commissionRate(c) {}
    double calculateSalary() const override { return baseSalary + salesAmount * commissionRate; }
    void displayInfo() const override {
        cout << "Продавец: " << name << " (базовая зарплата $" << baseSalary
            << " + " << commissionRate * 100 << "% от $" << salesAmount << ")\n";
    }
};
int main() {
    setlocale(LC_ALL, "");
    vector<Employee*> employees;
    employees.push_back(new Manager("Алиса", 5000));
    employees.push_back(new Engineer("Боб", 30, 160));
    employees.push_back(new SalesPerson("Чарли", 2000, 50000, 0.05));
    double total = 0;
    for (auto e : employees) {
        e->displayInfo();
        cout << "Зарплата: $" << e->calculateSalary() << "\n\n";
        total += e->calculateSalary();
    }
    cout << "Общая сумма зарплат: $" << total << "\n";
    for (auto e : employees) delete e;
}