#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <locale>
using namespace std;

//1.1
int sum(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divi(int a, int b) { return b == 0 ? 0 : a / b; }

//1.2
int compareStrings(const char* a, const char* b) { return strcmp(a, b); }

//2.1
bool up(int a, int b) { return a > b; }
bool down(int a, int b) { return a < b; }
void sort(int a[], int n, bool (*comp)(int, int)) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (comp(a[j], a[j + 1]))
                swap(a[j], a[j + 1]);
}

//2.2
double f1(double a) { return sin(a); }
double f2(double a) { return a * a; }
double integrate(double a, double b, int n, double (*func)(double)) {
    double h = (b - a) / n, s = 0;
    for (int i = 0; i < n; i++) s += func(a + i * h) * h;
    return s;
}

//3.1
void m1() { cout << "Открыть файл\n"; }
void m2() { cout << "Сохранить файл\n"; }
void m3() { cout << "Выход\n"; }

//5.1
template <class T, class U>
auto add(T a, U b) -> decltype(a + b) { return a + b; }

//5.2
double func2(int a) { return a * 1.5; }
double (*getFunc())(int) { return func2; }
auto getFunc2() -> double(*)(int) { return func2; }

int main() {
    setlocale(LC_ALL, "ru");

    //1.1
    int a, b; char c;
    cout << "Введите два числа:\n";
    cin >> a >> b;
    cout << "Введите операцию (+ - * /):\n";
    cin >> c;

    int (*operation)(int, int) = nullptr;
    if (c == '+') operation = sum;
    else if (c == '-') operation = sub;
    else if (c == '*') operation = mul;
    else if (c == '/') operation = divi;

    if (operation) cout << "Результат: " << operation(a, b) << "\n\n";

    //1.2
    char s1[100], s2[100];
    cout << "Введите первую строку:\n"; cin >> s1;
    cout << "Введите вторую строку:\n"; cin >> s2;

    int r = compareStrings(s1, s2);
    if (r > 0) cout << "Первая больше\n\n";
    else if (r == 0) cout << "Равны\n\n";
    else cout << "Вторая больше\n\n";

    //2.1
    int mas[5] = { 5,2,4,1,3 };
    sort(mas, 5, up);
    cout << "По возрастанию:\n";
    for (int i = 0; i < 5; i++) cout << mas[i] << " ";
    cout << "\n\n";

    sort(mas, 5, down);
    cout << "По убыванию:\n";
    for (int i = 0; i < 5; i++) cout << mas[i] << " ";
    cout << "\n\n";

    //2.2
    cout << "Интеграл sin(x): " << integrate(0, 3.14, 1000, f1) << "\n";
    cout << "Интеграл x*x: " << integrate(0, 3, 1000, f2) << "\n\n";

    //3.1
    void (*menu[])() = { m1, m2, m3 };
    int k;
    cout << "Меню:\n1\n2\n3\n"; cin >> k;
    if (k >= 1 && k <= 3) menu[k - 1]();

    //4.1
    vector<int> v = { 1,2,3,4,5 };
    for (auto i = v.begin(); i != v.end(); i++) cout << *i << " ";
    cout << "\n\n";

    //4.2
    int x = 5; double y = 3.14;
    decltype(x * y) z1;
    auto z2 = x * y;

    //5.1
    cout << add(2, 3.5) << "\n";

    //5.2
    double (*p)(int) = getFunc2();
    cout << p(4) << "\n";

    return 0;
}