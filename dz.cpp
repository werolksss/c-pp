#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Book {
private:
    string author;
    string title;
    string publisher;
    int year;
    int pages;

public:
    explicit Book(string a, string t, string p, int y, int pg) {
        author = a;
        title = t;
        publisher = p;
        year = y;
        pages = pg;
    }

    string getAuthor() const {
        return author;
    }
    string getTitle() const {
        return title;
    }
    string getPublisher() const {
        return publisher;
    }
    int getYear() const {
        return year;
    }
    int getPages() const {
        return pages;
    }

    void show() const {
        cout << "Автор: " << author << endl;
        cout << "Название: " << title << endl;
        cout << "Издательство: " << publisher << endl;
        cout << "Год: " << year << endl;
        cout << "Страниц: " << pages << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Book books[5] = {
        Book("Пушкин", "Евгений Онегин", "Эксмо", 2005, 320),
        Book("Пушкин", "Капитанская дочка", "Азбука", 2010, 280),
        Book("Толстой", "Война и мир", "Эксмо", 2008, 1300),
        Book("Достоевский", "Преступление и наказание", "Просвещение", 2015, 540),
        Book("Толстой", "Анна Каренина", "Азбука", 2020, 800)
    };

    int vibor;
    string poisk;
    int god;

    do {
        cout << "1. книги автора" << endl;
        cout << "2. книги издательства" << endl;
        cout << "3. книги после года" << endl;
        cout << "4. выход" << endl;
        cout << "ваш выбор: ";
        cin >> vibor;

        if (vibor == 1) {
            cout << "Введите автора: ";
            cin >> poisk;

            cout << "\nРезультат:" << endl;
            for (int i = 0; i < 5; i++) {
                if (books[i].getAuthor() == poisk) {
                    books[i].show(); 
                }
            }
        }
        else if (vibor == 2) {
            cout << "Введите издательство: ";
            cin >> poisk;

            cout << "\nРезультат:" << endl;
            for (int i = 0; i < 5; i++) {
                if (books[i].getPublisher() == poisk) {
                    books[i].show(); 
                }
            }
        }
        else if (vibor == 3) {
            cout << "Введите год: ";
            cin >> god;

            cout << "\nРезультат:" << endl;
            for (int i = 0; i < 5; i++) {
                if (books[i].getYear() > god) {
                    books[i].show();
                }
            }
        }

    } while (vibor != 4);
    return 0;
}