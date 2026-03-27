#include <iostream>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
    string name;
    double balance;

public:
    BankAccount(string n, double b) {
        if (b < 0)
            throw invalid_argument("Negative start balance");

        name = n;
        balance = b;
    }

    void withdraw(double amount) {
        if (amount < 0)
            throw invalid_argument("Negative amount");

        if (amount > balance)
            throw runtime_error("Not enough money");

        balance -= amount;
    }

    void show() {
        cout << name << " balance: " << balance << endl;
    }
};

int main() {
    try {
        BankAccount acc("Alex", 100);

        acc.withdraw(50);
        acc.show();

        acc.withdraw(200); // ошибка
    }
    catch (invalid_argument& e) {
        cout << "Invalid argument: " << e.what() << endl;
    }
    catch (runtime_error& e) {
        cout << "Runtime error: " << e.what() << endl;
    }
}