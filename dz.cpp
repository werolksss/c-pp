#include <iostream>
using namespace std;

// создание массива
int** createArray(int rows, int cols) {
    int** a = new int* [rows];
    for (int i = 0; i < rows; i++) {
        a[i] = new int[cols];
    }
    return a;
}

// удаление массива
void deleteArray(int** a, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] a[i];
    }
    delete[] a;
}

// вывод массива
void printArray(int** a, int rows, int cols) {
    cout << "\nмассив:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

// 1 задание - добавить строку в конец
int** addRowEnd(int** a, int& rows, int cols) {
    int** b = new int* [rows + 1];

    for (int i = 0; i < rows; i++) {
        b[i] = a[i];
    }

    b[rows] = new int[cols];
    for (int j = 0; j < cols; j++) {
        b[rows][j] = 0;
    }

    rows++;
    delete[] a;
    return b;
}

// 2 задание - добавить строку в начало
int** addRowBegin(int** a, int& rows, int cols) {
    int** b = new int* [rows + 1];

    for (int i = 0; i < rows; i++) {
        b[i + 1] = a[i];
    }

    b[0] = new int[cols];
    for (int j = 0; j < cols; j++) {
        b[0][j] = 0;
    }

    rows++;
    delete[] a;
    return b;
}

// 3 задание - добавить строку в указанную позицию
int** addRowAt(int** a, int& rows, int cols, int pos) {
    if (pos < 0 || pos > rows) {
        cout << "\nнеправильная позиция!\n";
        return a;
    }

    int** b = new int* [rows + 1];

    for (int i = 0; i < pos; i++) {
        b[i] = a[i];
    }

    b[pos] = new int[cols];
    for (int j = 0; j < cols; j++) {
        b[pos][j] = 0;
    }

    for (int i = pos; i < rows; i++) {
        b[i + 1] = a[i];
    }

    rows++;
    delete[] a;
    return b;
}

// 4 задание - удалить строку по указанному номеру
int** deleteRow(int** a, int& rows, int cols, int pos) {
    if (pos < 0 || pos >= rows) {
        cout << "\nнеправильная позиция!\n";
        return a;
    }

    if (rows == 1) {
        cout << "\nнельзя удалить последнюю строку!\n";
        return a;
    }

    int** b = new int* [rows - 1];

    for (int i = 0; i < pos; i++) {
        b[i] = a[i];
    }

    for (int i = pos + 1; i < rows; i++) {
        b[i - 1] = a[i];
    }

    delete[] a[pos];
    rows--;
    delete[] a;

    return b;
}

int main() {
    setlocale(LC_ALL, "ru");
    int rows = 3;
    int cols = 4;

    int** arr = createArray(rows, cols);

    // заполняем массив числами
    int num = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = num++;
        }
    }

    cout << "начальный массив:";
    printArray(arr, rows, cols);

    // тест 1 задания
    cout << "\n\n1 задание - добавляем строку в конец:";
    arr = addRowEnd(arr, rows, cols);
    printArray(arr, rows, cols);

    // тест 2 задания
    cout << "\n\n2 задание - добавляем строку в начало:";
    arr = addRowBegin(arr, rows, cols);
    printArray(arr, rows, cols);

    // тест 3 задания
    cout << "\n\n3 задание - добавляем строку в позицию 2:";
    arr = addRowAt(arr, rows, cols, 2);
    printArray(arr, rows, cols);

    // тест 4 задания
    cout << "\n\n4 задание - удаляем строку в позиции 2:";
    arr = deleteRow(arr, rows, cols, 2);
    printArray(arr, rows, cols);

    deleteArray(arr, rows);

    cout << "\nпрограмма завершена.\n";

    return 0;
}