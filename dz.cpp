#include <iostream>
#include <string> // строки
#include <sstream>     // Для строковых потоков (stringstream)
#include <algorithm>   // Для алгоритмов (например, transform)
#include <cctype>      // Для функций работы с символами (isalpha, tolower и др.)
#include <locale>      // Для локализации

using namespace std;

// 1 
string reverseString1(string a) {
    string b = a;
    reverse(b.begin(), b.end()); // используем алгоритм reverse
    return b;
}
string reverseString2(string a) {
    string b = "";
    for (int i = a.length() - 1; i >= 0; i--) {
        b += a[i];
    }
    return b;
}
// 2 
struct CountResult {
    int letters;
    int digits;
    int spaces;
    int others;
};
CountResult countCharacters(string a) {
    CountResult result = { 0, 0, 0, 0 };

    for (char c : a) {
        if (isalpha(c)) { // буква
            result.letters++;
        }
        else if (isdigit(c)) { // цифра
            result.digits++;
        }
        else if (isspace(c)) { // пробел
            result.spaces++;
        }
        else { // остальное
            result.others++;
        }
    }

    return result;
}
// 3
string removeDuplicates(string a) {
    string b = "";

    for (int i = 0; i < a.length(); i++) {
        bool found = false;
        // проверяем, был ли этот символ уже
        for (int j = 0; j < i; j++) {
            if (a[j] == a[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            b += a[i];
        }
    }

    return b;
}
// 4 
bool startsWith(string a, string prefix) {
    if (prefix.length() > a.length()) return false;

    for (int i = 0; i < prefix.length(); i++) {
        if (a[i] != prefix[i]) {
            return false;
        }
    }
    return true;
}
bool endsWith(string a, string suffix) {
    if (suffix.length() > a.length()) return false;

    int start = a.length() - suffix.length();
    for (int i = 0; i < suffix.length(); i++) {
        if (a[start + i] != suffix[i]) {
            return false;
        }
    }
    return true;
}
// 5
string formatName(string fullName) {
    stringstream ss(fullName);
    string part;
    string parts[10];
    int count = 0;

    // разбиваем строку на части
    while (ss >> part) {
        parts[count] = part;
        count++;
    }

    if (count == 0) return "";

    string result = parts[0]; // фамилия

    if (count > 1) {
        result += " " + string(1, parts[1][0]) + ".";
    }

    if (count > 2) {
        result += string(1, parts[2][0]) + ".";
    }

    return result;
}
// 6
string formatPhoneNumber(string phone) {
    string digits = "";

    // оставляем только цифры
    for (char c : phone) {
        if (isdigit(c)) {
            digits += c;
        }
    }

    if (digits.length() == 11) {
        if (digits[0] == '8') {
            digits[0] = '7';
        }
        return "+7 (" + digits.substr(1, 3) + ") " +
            digits.substr(4, 3) + "-" +
            digits.substr(7, 2) + "-" +
            digits.substr(9, 2);
    }
    else if (digits.length() == 10) {
        return "+7 (" + digits.substr(0, 3) + ") " +
            digits.substr(3, 3) + "-" +
            digits.substr(6, 2) + "-" +
            digits.substr(8, 2);
    }
    else {
        return phone;
    }
}
// 7 задание: Текстовый анализатор (упрощенная версия)
void analyzeText(string text) {
    // приводим к нижнему регистру
    transform(text.begin(), text.end(), text.begin(), ::tolower);

    // убираем знаки препинания
    for (char& c : text) {
        if (ispunct(c)) {
            c = ' ';
        }
    }
    stringstream ss(text);
    string word;
    int totalWords = 0;
    string longest = "";
    string shortest = "";

    while (ss >> word) {
        totalWords++;

        if (longest.empty() || word.length() > longest.length()) {
            longest = word;
        }

        if (shortest.empty() || word.length() < shortest.length()) {
            shortest = word;
        }
    }
    cout << "Всего слов: " << totalWords << "\n";
    if (!longest.empty()) {
        cout << "Самое длинное слово: \"" << longest << "\" (" << longest.length() << " букв)\n";
    }
    if (!shortest.empty()) {
        cout << "Самое короткое слово: \"" << shortest << "\" (" << shortest.length() << " букв)\n";
    }
}
int main() {
    setlocale(LC_ALL, "ru");

    string input, input2, input3;

    cout << "Задание 1: Реверс строки\n";
    cout << "Введите строку для реверса: ";
    getline(cin, input);
    cout << "Оригинал: " << input << "\n";
    cout << "Реверс алгоритмом: " << reverseString1(input) << "\n";
    cout << "Реверс циклом: " << reverseString2(input) << "\n\n";

    cout << "Задание 2: Подсчет символов\n";
    cout << "Введите строку для подсчета символов: ";
    getline(cin, input);
    CountResult counts = countCharacters(input);
    cout << "Результат:\n";
    cout << "Букв: " << counts.letters << "\n";
    cout << "Цифр: " << counts.digits << "\n";
    cout << "Пробелов: " << counts.spaces << "\n";
    cout << "Других: " << counts.others << "\n\n";

    cout << "Задание 3: Удаление дубликатов\n";
    cout << "Введите строку для удаления дубликатов: ";
    getline(cin, input);
    cout << "Оригинал: " << input << "\n";
    cout << "Без дубликатов: " << removeDuplicates(input) << "\n\n";

    cout << "Задание 4: Проверка префикса/суффикса\n";
    cout << "Введите строку: ";
    getline(cin, input);
    cout << "Введите префикс для проверки: ";
    getline(cin, input2);
    cout << "Начинается с '" << input2 << "': "
        << (startsWith(input, input2) ? "true" : "false") << "\n";

    cout << "Введите суффикс для проверки: ";
    getline(cin, input2);
    cout << "Заканчивается на '" << input2 << "': "
        << (endsWith(input, input2) ? "true" : "false") << "\n\n";

    cout << "Задание 5: Форматирование имени \n";
    cout << "Введите полное имя (например: Иванов Иван Петрович): ";
    getline(cin, input);
    cout << "Полное имя: " << input << "\n";
    cout << "Форматированное: " << formatName(input) << "\n\n";

    cout << "Задание 6: Форматирование телефонного номера\n";
    cout << "Введите телефонный номер: ";
    getline(cin, input);
    cout << "Исходный: " << input << "\n";
    cout << "Форматированный: " << formatPhoneNumber(input) << "\n\n";

    cout << "Задание 7: Текстовый анализатор \n";
    cout << "Введите текст для анализа:\n";
    string text = "";
    string line;

    while (true) {
        getline(cin, line);
        if (line == "конец") break;
        if (!text.empty()) text += " ";
        text += line;
    }

    cout << "\nРезультат анализа:\n";
    analyzeText(text);

    cout << "\nВсе задания выполнены!\n";

    return 0;
}