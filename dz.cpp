#include <iostream>
using namespace std;

//1
int stepen(int a, int b)
{
    int c = 1;
    for (int i = 0; i < b; i++)
    {
        c = c * a;
    }
    return c;
}

//2
int summa(int a, int b)
{
    int c = 0;
    int min, max;

    if (a < b)
    {
        min = a;
        max = b;
    }
    else
    {
        min = b;
        max = a;
    }

    for (int i = min + 1; i < max; i++)
    {
        c = c + i;
    }

    return c;
}

//3
void sovershennie(int a, int b)
{
    cout << "совершенные числа от " << a << " до " << b << ":\n";

    for (int i = a; i <= b; i++)
    {
        int sum = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                sum = sum + j;
            }
        }
        if (sum == i)
        {
            cout << i << " ";
        }
    }
    cout << "\n\n";
}

//4
void karta(int nomer)
{
    cout << " ------ \n";

    //номер карты
    if (nomer == 1) cout << "|A     |\n";
    else if (nomer == 11) cout << "|J     |\n";
    else if (nomer == 12) cout << "|Q     |\n";
    else if (nomer == 13) cout << "|K     |\n";
    else cout << "|" << nomer << "     |\n";

    cout << "|      |\n";
    cout << "|      |\n";
    cout << "|      |\n";

    if (nomer == 1) cout << "|     A|\n";
    else if (nomer == 11) cout << "|     J|\n";
    else if (nomer == 12) cout << "|     Q|\n";
    else if (nomer == 13) cout << "|     K|\n";
    else cout << "|     " << nomer << "|\n";

    cout << " ------ \n\n";
}

//5
bool schastlivoe(int a)
{
    if (a < 100000 || a > 999999) return false;

    int b1 = a / 100000;
    int b2 = (a / 10000) % 10;
    int b3 = (a / 1000) % 10;
    int b4 = (a / 100) % 10;
    int b5 = (a / 10) % 10;
    int b6 = a % 10;

    int sum1 = b1 + b2 + b3;
    int sum2 = b4 + b5 + b6;

    return sum1 == sum2;
}

int main()
{
    setlocale(LC_ALL, "ru");

    int x, y, a, b, nomer, chislo;

    //1
    cout << "задание 1 - степень числа:\n";
    cout << "введите основание: ";
    cin >> x;
    cout << "введите показатель: ";
    cin >> y;
    cout << x << " в степени " << y << " = " << stepen(x, y) << "\n\n";

    //2
    cout << "задание 2 - сумма в диапазоне:\n";
    cout << "введите первое число: ";
    cin >> a;
    cout << "введите второе число: ";
    cin >> b;
    cout << "сумма между " << a << " и " << b << " = " << summa(a, b) << "\n\n";

    //3
    cout << "задание 3 - совершенные числа:\n";
    cout << "введите начало диапазона: ";
    cin >> a;
    cout << "введите конец диапазона: ";
    cin >> b;
    sovershennie(a, b);

    //4
    cout << "задание 4 - игральная карта:\n";
    cout << "введите номер карты (1-13): ";
    cin >> nomer;
    karta(nomer);

    //5
    cout << "задание 5 - счастливое число:\n";
    cout << "введите шестизначное число: ";
    cin >> chislo;
    if (schastlivoe(chislo)) cout << chislo << " - счастливое число\n\n";
    else cout << chislo << " - не счастливое число\n\n";

    return 0;
}