#include <iostream>
using namespace std;

//1
void pryamougolnik(int n, int k)
{
    cout << "прямоугольник " << n << "x" << k << ":\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    cout << "\n";
}

//2
int factorial(int a)
{
    int b = 1;

    for (int i = 1; i <= a; i++)
    {
        b = b * i;
    }

    return b;
}

//3
bool prostoe(int a)
{
    if (a < 2) return false;

    for (int i = 2; i < a; i++)
    {
        if (a % i == 0) return false;
    }

    return true;
}

//4
int kub(int a)
{
    return a * a * a;
}

//5
int maximum(int a, int b)
{
    if (a > b) return a;
    else return b;
}

//6
bool polojitelnoe(int a)
{
    if (a > 0) return true;
    else return false;
}

int main()
{
setlocale(LC_ALL, "ru");
    int a, b;

    //1
    cout << "задание 1 - прямоугольник:\n";
    cout << "введите высоту: ";
    cin >> a;
    cout << "введите ширину: ";
    cin >> b;
    pryamougolnik(a, b);

    //2
    cout << "задание 2 - факториал:\n";
    cout << "введите число: ";
    cin >> a;
    cout << "факториал " << a << " = " << factorial(a) << "\n\n";

    //3
    cout << "задание 3 - простое число:\n";
    cout << "введите число: ";
    cin >> a;
    if (prostoe(a)) cout << a << " - простое число\n\n";
    else cout << a << " - не простое число\n\n";

    //4
    cout << "задание 4 - куб числа:\n";
    cout << "введите число: ";
    cin >> a;
    cout << "куб числа " << a << " = " << kub(a) << "\n\n";

    //5
    cout << "задание 5 - наибольшее число:\n";
    cout << "введите первое число: ";
    cin >> a;
    cout << "введите второе число: ";
    cin >> b;
    cout << "наибольшее из " << a << " и " << b << " = " << maximum(a, b) << "\n\n";

    //6
    cout << "задание 6 - положительное или отрицательное:\n";
    cout << "введите число: ";
    cin >> a;
    if (polojitelnoe(a)) cout << a << " - положительное\n\n";
    else cout << a << " отрицательное\n\n";

    return 0;
}