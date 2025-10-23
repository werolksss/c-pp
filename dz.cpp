#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    // 1
    cout << "Задание 1\n";
    int size = 8;
    double arr1[8] = { -5.7, 6.0, 2, 0, -4.7, 6, 8.1, -4 };
    double pos = 0; 
    double neg = 0; 
    for (int a = size - 1; a >= 0; a--)
    {
        if (arr1[a] > 0)
        {
            pos = arr1[a];
            break;
        }
    }
    for (int b = 0; b < size; b++)
    {
        if (arr1[b] < 0)
        {
            neg = arr1[b];
            break;
        }
    }
    cout << "Последнее положительное: " << pos << "\n";
    cout << "Первое отрицательное: " << neg << "\n\n";

    // 2
    cout << "Задание 2\n";
    int arr2[10];
    cout << "Введите количество жильцов в 10 квартирах:\n";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr2[i];
    }
    // а)
    int q;
    cout << "Введите номер квартиры (1-10): ";
    cin >> q;
    q--;
    cout << "Жильцов: " << arr2[q] << "\n";
    if (q % 2 == 0) cout << "Сосед: квартира " << q + 2 << " жильцов: " << arr2[q + 1] << "\n";
    else cout << "Сосед: квартира " << q << " жильцов: " << arr2[q - 1] << "\n";
    // б)
    cout << "\nСумма жильцов по подъездам:\n";
    int pod = 0;
    int k = 0;
    for (int i = 0; i < 10; i++)
    {
        pod += arr2[i];
        k++;
        if (k == 2)
        {
            cout << pod << "\n";
            pod = 0;
            k = 0;
        }
    }

    // в)
    cout << "\nМногодетные семьи:\n";
    for (int i = 0; i < 10; i++)
    {
        if (arr2[i] > 5)
        {
            cout << "Квартира: " << i + 1 << "\n";
        }
    }
    cout << "\n";

    //3
    cout << "Задание 3\n";
    int arr3[10];
    cout << "Введите температуру за 10 дней января:\n";
    for (int i = 0; i < 10; i++)
        cin >> arr3[i];
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum += arr3[i];
    cout << "Средняя температура: " << sum / 10.0 << "\n";
    int t, cnt = 0;
    cout << "Введите метку температуры: ";
    cin >> t;
    for (int i = 0; i < 10; i++)
        if (arr3[i] < t) cnt++;
    cout << "Температура опускалась ниже " << t << ": " << cnt << " раз\n\n";
   
    //4
    cout << "Задание 4\n";
    int arr4[10];
    cout << "Введите стоимость 10 авто:\n";
    for (int i = 0; i < 10; i++)
        cin >> arr4[i];

    int max = arr4[0];
    for (int i = 1; i < 10; i++)
        if (arr4[i] > max) max = arr4[i];

    cout << "Максимальная стоимость: " << max << "\n";
    // а) первый
    for (int i = 0; i < 10; i++)
        if (arr4[i] == max)
        {
            cout << "Первый номер: " << i + 1 << "\n";
            break;
        }
    // б) последний
    for (int i = 9; i >= 0; i--)
        if (arr4[i] == max)
        {
            cout << "Последний номер: " << i + 1 << "\n";
            break;
        }
    cout << "\n";

    //5
    cout << "Задание 5\n";
    int arr5[10];
    cout << "Введите 10 чисел:\n";
    for (int i = 0; i < 10; i++)
        cin >> arr5[i];
    cout << "Повторяющиеся элементы:\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (arr5[i] == arr5[j])
            {
                cout << arr5[i] << "\n";
                break;
            }
        }
    }
    cout << "\n";
    //6
    cout << "Задание 6\n";
    int A[10], B[10], X[20];
    cout << "Введите массив A:\n";
    for (int i = 0; i < 10; i++) cin >> A[i];
    cout << "Введите массив B:\n";
    for (int i = 0; i < 10; i++) cin >> B[i];
    // а) чередование
    cout << "Массив X (чередование):\n";
    int z = 0;
    for (int i = 0; i < 10; i++)
    {
        X[z++] = A[i];
        X[z++] = B[i];
    }
    for (int i = 0; i < 20; i++) cout << X[i] << " ";
    cout << "\n";
    // б) следование
    cout << "Массив X (следование):\n";
    for (int i = 0; i < 10; i++) X[i] = A[i];
    for (int i = 0; i < 10; i++) X[i + 10] = B[i];
    for (int i = 0; i < 20; i++) cout << X[i] << " ";
    cout << "\n";
    return 0;
}
