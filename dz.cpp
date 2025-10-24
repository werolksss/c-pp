#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    //1 задание
    cout << "задание 1\n";
    int a;
    cout << "введите число: ";
    cin >> a;

    int massiv1[3][3];
    int b = a;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            massiv1[i][j] = b;
            b = b * 2; 
        }
    }

    cout << "полученный массив:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << massiv1[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    //2 задание
    cout << "задание 2\n";
    int c;
    cout << "введите число: ";
    cin >> c;

    int massiv2[3][3]; 
    int d = c;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            massiv2[i][j] = d;
            d = d + 1;
        }
    }

  
    cout << "полученный массив:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << massiv2[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    //3
    cout << "задание 3\n";
    srand(time(0)); 

    int massiv3[2][6]; 
    cout << "исходный массив:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            massiv3[i][j] = rand() % 10; 
            cout << massiv3[i][j] << " ";
        }
        cout << "\n";
    }

    int sdvig;
    cout << "введите количество сдвигов: ";
    cin >> sdvig;

    int napravlenie;
    cout << "выберите направление (1-влево, 2-вправо, 3-вверх, 4-вниз): ";
    cin >> napravlenie;
    int temp[2][6];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            temp[i][j] = massiv3[i][j];
        }
    }
    if (napravlenie == 1) {
        for (int s = 0; s < sdvig; s++) {
            for (int i = 0; i < 2; i++) {
                int first = temp[i][0];
                for (int j = 0; j < 5; j++) {
                    temp[i][j] = temp[i][j + 1];
                }
                temp[i][5] = first;
            }
        }
    }
    else if (napravlenie == 2) {
        for (int s = 0; s < sdvig; s++) {
            for (int i = 0; i < 2; i++) {
                int last = temp[i][5];
                for (int j = 5; j > 0; j--) {
                    temp[i][j] = temp[i][j - 1];
                }
                temp[i][0] = last;
            }
        }
    }
    else if (napravlenie == 3) {
        for (int s = 0; s < sdvig; s++) {
            int first_row[6];
            for (int j = 0; j < 6; j++) {
                first_row[j] = temp[0][j];
            }
            for (int i = 0; i < 1; i++) {
                for (int j = 0; j < 6; j++) {
                    temp[i][j] = temp[i + 1][j];
                }
            }
            for (int j = 0; j < 6; j++) {
                temp[1][j] = first_row[j];
            }
        }
    }
    else if (napravlenie == 4) { 
        for (int s = 0; s < sdvig; s++) {
            int last_row[6];
            for (int j = 0; j < 6; j++) {
                last_row[j] = temp[1][j];
            }
            for (int i = 1; i > 0; i--) {
                for (int j = 0; j < 6; j++) {
                    temp[i][j] = temp[i - 1][j];
                }
            }
            for (int j = 0; j < 6; j++) {
                temp[0][j] = last_row[j];
            }
        }
    }
    cout << "Массив после сдвига:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            cout << temp[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}