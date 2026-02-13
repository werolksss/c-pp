#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

class Elevator {
private:
    int minFloor;       // Минимальный этаж
    int maxFloor;       // Максимальный этаж
    int currentFloor;   // Текущий этаж
    bool isPowered;     // Состояние питания (включен/выключен)
    bool isMoving;      // Движется ли лифт
    int targetFloor;    // Целевой этаж

    // Вспомогательная функция для имитации движения
    void moveOneStep() {
        if (!isPowered || currentFloor == targetFloor) {
            isMoving = false;
            return;
        }

        if (currentFloor < targetFloor) {
            currentFloor++;
            cout << "   Лифт поднимается на этаж " << currentFloor << endl;
        }
        else if (currentFloor > targetFloor) {
            currentFloor--;
            cout << "   Лифт опускается на этаж " << currentFloor << endl;
        }

        if (currentFloor == targetFloor) {
            isMoving = false;
            cout << "   Лифт прибыл на этаж " << currentFloor << endl;
        }
    }

public:
    // Конструктор по умолчанию
    Elevator() : minFloor(1), maxFloor(10), currentFloor(1),
        isPowered(false), isMoving(false), targetFloor(1) {
    }

    // Конструктор с параметрами
    Elevator(int minF, int maxF) : minFloor(minF), maxFloor(maxF),
        currentFloor(minF), isPowered(false),
        isMoving(false), targetFloor(minF) {
        if (minFloor > maxFloor) {
            cout << "Ошибка: минимальный этаж не может быть больше максимального!\n";
            cout << "Установлены значения по умолчанию (1-10)\n";
            minFloor = 1;
            maxFloor = 10;
            currentFloor = 1;
            targetFloor = 1;
        }
    }

    // Установка диапазона движения
    void setRange(int minF, int maxF) {
        if (minF > maxF) {
            cout << "Ошибка: минимальный этаж не может быть больше максимального!\n";
            return;
        }

        minFloor = minF;
        maxFloor = maxF;

        // Корректируем текущую позицию, если она выходит за новый диапазон
        if (currentFloor < minFloor) {
            currentFloor = minFloor;
            cout << "Текущий этаж скорректирован до " << currentFloor << endl;
        }
        else if (currentFloor > maxFloor) {
            currentFloor = maxFloor;
            cout << "Текущий этаж скорректирован до " << currentFloor << endl;
        }

        cout << "Диапазон движения установлен: " << minFloor << " - " << maxFloor << " этажи\n";
    }

    // Включение лифта
    void turnOn() {
        isPowered = true;
        cout << "Лифт включен. Текущий этаж: " << currentFloor << endl;
    }

    // Выключение лифта
    void turnOff() {
        isPowered = false;
        isMoving = false;
        cout << "Лифт выключен\n";
    }

    // Получение состояния питания
    bool getPowerStatus() const {
        return isPowered;
    }

    // Получение текущего этажа
    int getCurrentFloor() const {
        return currentFloor;
    }

    // Проверка, движется ли лифт
    bool isMovingNow() const {
        return isMoving;
    }

    // Обработка вызова лифта
    void callElevator(int floor) {
        if (!isPowered) {
            cout << "Ошибка: лифт выключен. Сначала включите лифт!\n";
            return;
        }

        if (floor < minFloor || floor > maxFloor) {
            cout << "Ошибка: этаж " << floor << " вне диапазона движения (";
            cout << minFloor << " - " << maxFloor << ")\n";
            return;
        }

        if (isMoving) {
            cout << "Лифт уже движется на этаж " << targetFloor << ". ";
            cout << "Дождитесь остановки.\n";
            return;
        }

        if (floor == currentFloor) {
            cout << "Лифт уже находится на этаже " << floor << endl;
            return;
        }

        targetFloor = floor;
        isMoving = true;
        cout << "Вызов лифта на этаж " << floor << "...\n";

        // Имитация движения
        while (isMoving) {
            Sleep(500); // Задержка для наглядности
            moveOneStep();
        }
    }

    // Информация о состоянии лифта
    void showStatus() const {
        cout << "\nСОСТОЯНИЕ ЛИФТА\n";
        cout << "Диапазон этажей: " << minFloor << " - " << maxFloor << endl;
        cout << "Питание: " << (isPowered ? "ВКЛЮЧЕН" : "ВЫКЛЮЧЕН") << endl;
        cout << "Текущий этаж: " << currentFloor << endl;
        cout << "Движение: " << (isMoving ? "ДА" : "НЕТ") << endl;
        if (isMoving) {
            cout << "Целевой этаж: " << targetFloor << endl;
        }
    }
};

// Функция для тестирования
void testElevator() {
    cout << "\nТЕСТИРОВАНИЕ КЛАССА ЛИФТ \n\n";

    // Создаем лифт с диапазоном 1-5
    cout << "1. Создание лифта с диапазоном 1-5:\n";
    Elevator elevator(1, 5);
    elevator.showStatus();

    // Пытаемся вызвать лифт при выключенном питании
    cout << "\n2. Попытка вызова при выключенном лифте:\n";
    elevator.callElevator(3);

    // Включаем лифт
    cout << "\n3. Включение лифта:\n";
    elevator.turnOn();

    // Вызываем на 3 этаж
    cout << "\n4. Вызов на 3 этаж:\n";
    elevator.callElevator(3);

    // Пытаемся вызвать на несуществующий этаж
    cout << "\n5. Попытка вызова на несуществующий этаж (6):\n";
    elevator.callElevator(6);

    // Вызываем на 1 этаж
    cout << "\n6. Вызов на 1 этаж:\n";
    elevator.callElevator(1);

    // Проверка текущего состояния
    cout << "\n7. Текущее состояние после перемещений:\n";
    cout << "Лифт на этаже: " << elevator.getCurrentFloor() << endl;
    cout << "Лифт " << (elevator.getPowerStatus() ? "включен" : "выключен") << endl;

    // Изменяем диапазон
    cout << "\n8. Изменение диапазона на 2-7:\n";
    elevator.setRange(2, 7);
    elevator.showStatus();

    // Пытаемся вызвать на этажи из нового диапазона
    cout << "\n9. Вызов на этаж 7:\n";
    elevator.callElevator(7);

    // Выключаем лифт
    cout << "\n10. Выключение лифта:\n";
    elevator.turnOff();
    elevator.showStatus();

    // Пытаемся вызвать после выключения
    cout << "\n11. Попытка вызова после выключения:\n";
    elevator.callElevator(4);
}

// Интерактивный режим
void interactiveMode() {
    Elevator elevator;
    int choice, floor, minF, maxF;

    cout << "\nИНТЕРАКТИВНЫЙ РЕЖИМ\n";
    cout << "Сначала настройте диапазон движения лифта:\n";
    cout << "Введите минимальный этаж: ";
    cin >> minF;
    cout << "Введите максимальный этаж: ";
    cin >> maxF;
    elevator.setRange(minF, maxF);

    do {
        cout << "\nМЕНЮ УПРАВЛЕНИЯ ЛИФТОМ\n";
        cout << "1. Включить лифт\n";
        cout << "2. Выключить лифт\n";
        cout << "3. Вызвать лифт на этаж\n";
        cout << "4. Изменить диапазон движения\n";
        cout << "5. Показать состояние лифта\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            elevator.turnOn();
            break;

        case 2:
            elevator.turnOff();
            break;

        case 3:
            if (!elevator.getPowerStatus()) {
                cout << "Сначала включите лифт!\n";
                break;
            }
            cout << "Введите номер этажа для вызова: ";
            cin >> floor;
            elevator.callElevator(floor);
            break;

        case 4:
            cout << "Введите минимальный этаж: ";
            cin >> minF;
            cout << "Введите максимальный этаж: ";
            cin >> maxF;
            elevator.setRange(minF, maxF);
            break;

        case 5:
            elevator.showStatus();
            break;

        case 0:
            cout << "Выход из программы...\n";
            break;

        default:
            cout << "Неверный выбор! Попробуйте снова.\n";
        }
    } while (choice != 0);
}

int main() {
    // Настройка кодировки для русского языка
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int mode;
    cout << "МОДЕЛИРОВАНИЕ РАБОТЫ ЛИФТА\n";
    cout << "Выберите режим работы:\n";
    cout << "1. Автоматическое тестирование\n";
    cout << "2. Интерактивный режим\n";
    cout << "Ваш выбор: ";
    cin >> mode;

    if (mode == 1) {
        testElevator();
    }
    else if (mode == 2) {
        interactiveMode();
    }
    else {
        cout << "Неверный выбор. Запускаю интерактивный режим по умолчанию.\n";
        interactiveMode();
    }

    return 0;
}