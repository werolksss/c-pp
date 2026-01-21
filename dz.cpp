#include <iostream>
#include <locale>
using namespace std;

// структура видеомагазина
struct video
{
    char n[50]; // название
    char r[50]; // режиссер
    char g[30]; // жанр
    int p;      // популярность
    int c;      // цена
};

//1 показ всех
void show(video a[], int b)
{
    for (int i = 0; i < b; i++)
    {
        cout << "Фильм: " << a[i].n << "\n";
        cout << "Режиссер: " << a[i].r << "\n";
        cout << "Жанр: " << a[i].g << "\n";
        cout << "Рейтинг: " << a[i].p << "\n";
        cout << "Цена: " << a[i].c << "\n\n";
    }
}

//2 поиск по названию
void find_n(video a[], int b)
{
    char x[50];
    cout << "Введите название:\n";
    cin >> x;
    for (int i = 0; i < b; i++)
        if (strcmp(a[i].n, x) == 0)
            cout << "Найден: " << a[i].n << "\n\n";
}

//3 поиск по жанру
void find_g(video a[], int b)
{
    char x[30];
    cout << "Введите жанр:\n";
    cin >> x;
    for (int i = 0; i < b; i++)
        if (strcmp(a[i].g, x) == 0)
            cout << a[i].n << "\n";
    cout << "\n";
}

//4 поиск по режиссеру
void find_r(video a[], int b)
{
    char x[50];
    cout << "Введите режиссера:\n";
    cin >> x;
    for (int i = 0; i < b; i++)
        if (strcmp(a[i].r, x) == 0)
            cout << a[i].n << "\n";
    cout << "\n";
}

//5 самый популярный в жанре
void top(video a[], int b)
{
    char x[30];
    int m = -1, k = 0;
    cout << "Введите жанр:\n";
    cin >> x;
    for (int i = 0; i < b; i++)
        if (strcmp(a[i].g, x) == 0 && a[i].p > m)
        {
            m = a[i].p;
            k = i;
        }
    cout << "Самый популярный: " << a[k].n << "\n\n";
}

//6 добавление
void add(video a[], int& b)
{
    cout << "Название:\n";
    cin >> a[b].n;
    cout << "Режиссер:\n";
    cin >> a[b].r;
    cout << "Жанр:\n";
    cin >> a[b].g;
    cout << "Рейтинг:\n";
    cin >> a[b].p;
    cout << "Цена:\n";
    cin >> a[b].c;
    b++;
}

int main()
{
    setlocale(LC_ALL, "ru");

    video a[10] = {
        {"Matrix","Wach","Sci",9,300},
        {"Avatar","Cam","Sci",8,350}
    };
    int b = 2, c;

    while (true)
    {
        cout << "1-показ\n2-название\n3-жанр\n4-режиссер\n5-топ\n6-добавить\n0-выход\n";
        cin >> c;

        if (c == 1) show(a, b);
        if (c == 2) find_n(a, b);
        if (c == 3) find_g(a, b);
        if (c == 4) find_r(a, b);
        if (c == 5) top(a, b);
        if (c == 6) add(a, b);
        if (c == 0) break;
    }

    return 0;
}
