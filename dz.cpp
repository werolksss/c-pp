#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class MyString {
private:
    string str;

public:
    MyString() : str("") {}
    MyString(const string& s) : str(s) {}
    MyString(const char* s) : str(s) {}

    string getString() const {
        return str;
    }

    void setString(const string& s) {
        str = s;
    }

    MyString operator*(const MyString& other) const {
        string result = "";

        for (int i = 0; i < str.length(); i++) {
            char currentChar = str[i];

            bool foundInSecond = false;
            for (int j = 0; j < other.str.length(); j++) {
                if (other.str[j] == currentChar) {
                    foundInSecond = true;
                    break;
                }
            }

            if (foundInSecond) {
                bool alreadyInResult = false;
                for (int k = 0; k < result.length(); k++) {
                    if (result[k] == currentChar) {
                        alreadyInResult = true;
                        break;
                    }
                }

                if (!alreadyInResult) {
                    result += currentChar;
                }
            }
        }

        return MyString(result);
    }

    friend ostream& operator<<(ostream& os, const MyString& ms) {
        os << ms.str;
        return os;
    }

    friend istream& operator>>(istream& is, MyString& ms) {
        is >> ms.str;
        return is;
    }

    int length() const {
        return str.length();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Пересечение строк" << endl;

    MyString s1("sdqcg");
    MyString s2("rgfas34");

    cout << "Строка 1: " << s1 << endl;
    cout << "Строка 2: " << s2 << endl;

    MyString result = s1 * s2;
    cout << "Пересечение (общие символы): " << result << endl;
    cout << "Ожидаемый результат: sg" << endl;


    MyString a("hello world");
    MyString b("world hello");
    cout << "Строка A: " << a << endl;
    cout << "Строка B: " << b << endl;
    cout << "Пересечение: " << (a * b) << endl;

    MyString c("programming");
    MyString d("c++ language");
    cout << "\nСтрока C: " << c << endl;
    cout << "Строка D: " << d << endl;
    cout << "Пересечение: " << (c * d) << endl;

    cout << "\nВведите свои строки" << endl;

    MyString user1, user2;
    cout << "Введите первую строку: ";
    cin >> user1;
    cout << "Введите вторую строку: ";
    cin >> user2;

    cout << "\nВаши строки:" << endl;
    cout << "1: " << user1 << endl;
    cout << "2: " << user2 << endl;

    MyString userResult = user1 * user2;
    cout << "Общие символы: " << userResult << endl;

    return 0;
}