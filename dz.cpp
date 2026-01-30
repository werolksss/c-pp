#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Структура для сотрудника
struct Sotrudnik {
    string fam; // фамилия
    string im;  // имя
    int voz;    // возраст
    string dol; // должность
};

vector<Sotrudnik> baza; // база сотрудников

// Функция загрузки
void zagruzka() {
    string f;
    cout << "Введите имя файла: ";
    cin >> f;

    ifstream file(f);
    if (!file) {
        cout << "Файл не найден\n";
        return;
    }

    baza.clear();
    Sotrudnik s;
    while (file >> s.fam >> s.im >> s.voz >> s.dol) {
        baza.push_back(s);
    }
    file.close();
    cout << "Загружено: " << baza.size() << endl;
}

// Функция сохранения
void sohranenie() {
    string f;
    cout << "Введите имя файла: ";
    cin >> f;

    ofstream file(f);
    for (int i = 0; i < baza.size(); i++) {
        file << baza[i].fam << " "
            << baza[i].im << " "
            << baza[i].voz << " "
            << baza[i].dol << endl;
    }
    file.close();
    cout << "Сохранено\n";
}

// Добавить
void dobavit() {
    Sotrudnik n;
    cout << "Фамилия: ";
    cin >> n.fam;
    cout << "Имя: ";
    cin >> n.im;
    cout << "Возраст: ";
    cin >> n.voz;
    cout << "Должность: ";
    cin >> n.dol;
    baza.push_back(n);
    cout << "Добавлено\n";
}

// Показать всех
void pokazat() {
    if (baza.empty()) {
        cout << "База пуста\n";
        return;
    }
    for (int i = 0; i < baza.size(); i++) {
        cout << baza[i].fam << " "
            << baza[i].im << " "
            << baza[i].voz << " "
            << baza[i].dol << endl;
    }
}

// Найти по фамилии
void naiti() {
    string f;
    cout << "Введите фамилию: ";
    cin >> f;

    bool est = false;
    for (int i = 0; i < baza.size(); i++) {
        if (baza[i].fam == f) {
            cout << baza[i].fam << " "
                << baza[i].im << " "
                << baza[i].voz << " "
                << baza[i].dol << endl;
            est = true;
        }
    }
    if (!est) cout << "Не найдено\n";
}

// Редактировать
void izmenit() {
    string f;
    cout << "Фамилия для изменения: ";
    cin >> f;

    for (int i = 0; i < baza.size(); i++) {
        if (baza[i].fam == f) {
            cout << "Новое имя: ";
            cin >> baza[i].im;
            cout << "Новый возраст: ";
            cin >> baza[i].voz;
            cout << "Новая должность: ";
            cin >> baza[i].dol;
            cout << "Изменено\n";
            return;
        }
    }
    cout << "Не найдено\n";
}

// Удалить
void udalit() {
    string f;
    cout << "Фамилия для удаления: ";
    cin >> f;

    for (int i = 0; i < baza.size(); i++) {
        if (baza[i].fam == f) {
            baza.erase(baza.begin() + i);
            cout << "Удалено\n";
            return;
        }
    }
    cout << "Не найдено\n";
}

// По возрасту
void poVozrastu() {
    int v;
    cout << "Введите возраст: ";
    cin >> v;

    bool est = false;
    for (int i = 0; i < baza.size(); i++) {
        if (baza[i].voz == v) {
            cout << baza[i].fam << " "
                << baza[i].im << " "
                << baza[i].voz << " "
                << baza[i].dol << endl;
            est = true;
        }
    }
    if (!est) cout << "Не найдено\n";
}

// По букве
void poBukve() {
    char b;
    cout << "Введите букву: ";
    cin >> b;

    bool est = false;
    for (int i = 0; i < baza.size(); i++) {
        if (!baza[i].fam.empty() && tolower(baza[i].fam[0]) == tolower(b)) {
            cout << baza[i].fam << " "
                << baza[i].im << " "
                << baza[i].voz << " "
                << baza[i].dol << endl;
            est = true;
        }
    }
    if (!est) cout << "Не найдено\n";
}

// Главная функция
int main() {
    setlocale(LC_ALL, "ru");

    zagruzka();

    int v; // выбор
    do {
        cout << "\n1. Добавить\n";
        cout << "2. Показать всех\n";
        cout << "3. Найти по фамилии\n";
        cout << "4. Изменить\n";
        cout << "5. Удалить\n";
        cout << "6. По возрасту\n";
        cout << "7. По букве\n";
        cout << "8. Сохранить\n";
        cout << "0. Выход\n";
        cout << "Выберите: ";
        cin >> v;

        switch (v) {
        case 1: dobavit(); break;
        case 2: pokazat(); break;
        case 3: naiti(); break;
        case 4: izmenit(); break;
        case 5: udalit(); break;
        case 6: poVozrastu(); break;
        case 7: poBukve(); break;
        case 8: sohranenie(); break;
        case 0: break;
        default: cout << "Ошибка\n";
        }
    } while (v != 0);

    // Автосохранение
    cout << "Автосохранение...\n";
    sohranenie();

    return 0;
}