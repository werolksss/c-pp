#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <windows.h>

using namespace std;

class Subject {
private:
    string name;

public:
    Subject() : name("") {}
    Subject(const string& n) : name(n) {}

    string getName() const { return name; }
    void setName(const string& n) { name = n; }
    void print() const { cout << name; }
};

class Student {
private:
    string fullName;
    vector<int> grades;

public:
    Student() : fullName("") {}
    Student(const string& name) : fullName(name) {}

    string getName() const { return fullName; }
    int getGrade(int subjectIndex) const {
        if (subjectIndex >= 0 && subjectIndex < grades.size()) {
            return grades[subjectIndex];
        }
        return 0;
    }
    const vector<int>& getGrades() const { return grades; }
    void setName(const string& name) { fullName = name; }
    void addGrade(int grade) { grades.push_back(grade); }
    void setGrade(int index, int grade) {
        if (index >= 0 && index < grades.size()) {
            grades[index] = grade;
        }
    }
    int getGradeCount() const { return grades.size(); }
    double getAverageGrade() const {
        if (grades.empty()) return 0.0;
        double sum = 0;
        for (int grade : grades) sum += grade;
        return sum / grades.size();
    }
    void print() const { cout << fullName; }
};

class Group {
private:
    string name;
    vector<Student> students;
    vector<Subject> subjects;

public:
    Group() : name("") {}
    Group(const string& n) : name(n) {}

    string getName() const { return name; }
    Student& getStudent(int index) { return students[index]; }
    const Student& getStudent(int index) const { return students[index]; }
    Subject& getSubject(int index) { return subjects[index]; }
    const Subject& getSubject(int index) const { return subjects[index]; }
    int getStudentCount() const { return students.size(); }
    int getSubjectCount() const { return subjects.size(); }
    void setName(const string& n) { name = n; }
    void addStudent(const Student& student) { students.push_back(student); }
    void addSubject(const Subject& subject) {
        subjects.push_back(subject);
        for (auto& student : students) {
            while (student.getGradeCount() < subjects.size()) {}
        }
    }

    double getSubjectAverage(int subjectIndex) const {
        if (students.empty() || subjectIndex < 0 || subjectIndex >= subjects.size()) {
            return 0.0;
        }
        double sum = 0;
        for (const auto& student : students) sum += student.getGrade(subjectIndex);
        return sum / students.size();
    }

    double getGroupAverage() const {
        if (students.empty() || subjects.empty()) return 0.0;
        double totalSum = 0;
        int totalGrades = 0;
        for (const auto& student : students) {
            for (int grade : student.getGrades()) {
                totalSum += grade;
                totalGrades++;
            }
        }
        return (totalGrades > 0) ? totalSum / totalGrades : 0.0;
    }

    void findMaxGradeForSubject(int subjectIndex, int& maxGrade, vector<int>& studentIndices) const {
        maxGrade = -1;
        studentIndices.clear();
        if (subjectIndex < 0 || subjectIndex >= subjects.size()) return;
        for (int i = 0; i < students.size(); i++) {
            int grade = students[i].getGrade(subjectIndex);
            if (grade > maxGrade) {
                maxGrade = grade;
                studentIndices.clear();
                studentIndices.push_back(i);
            }
            else if (grade == maxGrade) {
                studentIndices.push_back(i);
            }
        }
    }

    void findMinGradeForSubject(int subjectIndex, int& minGrade, vector<int>& studentIndices) const {
        minGrade = 101;
        studentIndices.clear();
        if (subjectIndex < 0 || subjectIndex >= subjects.size()) return;
        for (int i = 0; i < students.size(); i++) {
            int grade = students[i].getGrade(subjectIndex);
            if (grade < minGrade) {
                minGrade = grade;
                studentIndices.clear();
                studentIndices.push_back(i);
            }
            else if (grade == minGrade) {
                studentIndices.push_back(i);
            }
        }
    }

    bool loadFromFiles(const string& studentsFile, const string& subjectsFile, const string& gradesFile) {
        ifstream sFile(studentsFile);
        if (!sFile.is_open()) {
            cout << "Ошибка открытия файла со студентами!\n";
            return false;
        }

        students.clear();
        string line;
        while (getline(sFile, line)) {
            if (!line.empty()) students.push_back(Student(line));
        }
        sFile.close();
        cout << "Загружено студентов: " << students.size() << endl;

        ifstream subjFile(subjectsFile);
        if (!subjFile.is_open()) {
            cout << "Ошибка открытия файла с предметами!\n";
            return false;
        }

        subjects.clear();
        while (getline(subjFile, line)) {
            if (!line.empty()) subjects.push_back(Subject(line));
        }
        subjFile.close();
        cout << "Загружено предметов: " << subjects.size() << endl;

        ifstream gFile(gradesFile);
        if (!gFile.is_open()) {
            cout << "Ошибка открытия файла с оценками!\n";
            return false;
        }

        int studentIndex = 0;
        while (getline(gFile, line) && studentIndex < students.size()) {
            size_t pos = 0;
            int gradeIndex = 0;

            while (pos < line.length() && gradeIndex < subjects.size()) {
                while (pos < line.length() && line[pos] == ' ') pos++;
                if (pos >= line.length()) break;

                size_t endPos = pos;
                while (endPos < line.length() && line[endPos] != ' ') endPos++;

                string gradeStr = line.substr(pos, endPos - pos);
                if (!gradeStr.empty()) {
                    int grade = stoi(gradeStr);
                    students[studentIndex].addGrade(grade);
                    gradeIndex++;
                }
                pos = endPos;
            }

            while (students[studentIndex].getGradeCount() < subjects.size()) {
                students[studentIndex].addGrade(0);
            }
            studentIndex++;
        }
        gFile.close();

        cout << "Загружены оценки для " << studentIndex << " студентов\n";
        return true;
    }

    void printGradeTable() const {
        if (students.empty() || subjects.empty()) {
            cout << "Нет данных для отображения!\n";
            return;
        }

        cout << "\nТАБЛИЦА ОЦЕНОК ГРУППЫ \"" << name << "\"\n";
        cout << left << setw(30) << "Студент";
        for (const auto& subject : subjects) {
            cout << " | " << setw(10) << subject.getName().substr(0, 10);
        }
        cout << " | " << setw(10) << "Средний" << endl;

        for (const auto& student : students) {
            cout << left << setw(30) << student.getName().substr(0, 28);
            for (int grade : student.getGrades()) {
                cout << " | " << setw(10) << grade;
            }
            cout << " | " << setw(10) << fixed << setprecision(2) << student.getAverageGrade() << endl;
        }
    }

    void printStudentAverages() const {
        if (students.empty()) {
            cout << "Нет студентов!\n";
            return;
        }

        cout << "\nСРЕДНИЕ ОЦЕНКИ СТУДЕНТОВ:\n";
        cout << left << setw(30) << "Студент" << " | " << setw(10) << "Средний балл" << endl;

        for (const auto& student : students) {
            cout << left << setw(30) << student.getName().substr(0, 28)
                << " | " << setw(10) << fixed << setprecision(2) << student.getAverageGrade() << endl;
        }
    }

    void printSubjectAverages() const {
        if (subjects.empty()) {
            cout << "Нет предметов!\n";
            return;
        }

        cout << "\nСРЕДНИЕ ОЦЕНКИ ПО ПРЕДМЕТАМ:\n";
        cout << left << setw(30) << "Предмет" << " | " << setw(10) << "Средний балл" << endl;

        for (int i = 0; i < subjects.size(); i++) {
            cout << left << setw(30) << subjects[i].getName().substr(0, 28)
                << " | " << setw(10) << fixed << setprecision(2) << getSubjectAverage(i) << endl;
        }
    }

    void printGroupAverage() const {
        cout << "\nСРЕДНИЙ БАЛЛ ГРУППЫ: " << fixed << setprecision(2) << getGroupAverage() << endl;
    }

    void printMinMaxGrades() const {
        if (subjects.empty() || students.empty()) {
            cout << "Нет данных для анализа!\n";
            return;
        }

        cout << "\nМАКС/МИН ОЦЕНКИ ПО ПРЕДМЕТАМ:\n";

        for (int i = 0; i < subjects.size(); i++) {
            cout << "\nПредмет: " << subjects[i].getName() << endl;

            int maxGrade;
            vector<int> maxStudents;
            findMaxGradeForSubject(i, maxGrade, maxStudents);

            cout << "Макс: " << maxGrade << " (";
            for (size_t j = 0; j < maxStudents.size(); j++) {
                if (j > 0) cout << ", ";
                cout << students[maxStudents[j]].getName();
            }
            cout << ")\n";

            int minGrade;
            vector<int> minStudents;
            findMinGradeForSubject(i, minGrade, minStudents);

            cout << "Мин: " << minGrade << " (";
            for (size_t j = 0; j < minStudents.size(); j++) {
                if (j > 0) cout << ", ";
                cout << students[minStudents[j]].getName();
            }
            cout << ")\n";
        }
    }

    void printFullReport() const {
        printGradeTable();
        printStudentAverages();
        printSubjectAverages();
        printGroupAverage();
        printMinMaxGrades();
    }
};

void createSampleFiles() {
    ofstream sFile("students.txt");
    sFile << "Иванов Иван Иванович\n";
    sFile << "Петров Петр Петрович\n";
    sFile << "Сидорова Анна Сергеевна\n";
    sFile << "Козлов Дмитрий Александрович\n";
    sFile << "Смирнова Елена Владимировна\n";
    sFile << "Васильев Алексей Игоревич\n";
    sFile.close();

    ofstream subjFile("subjects.txt");
    subjFile << "Математика\n";
    subjFile << "Физика\n";
    subjFile << "Программирование\n";
    subjFile << "История\n";
    subjFile << "Английский язык\n";
    subjFile.close();

    ofstream gFile("grades.txt");
    gFile << "5 4 5 4 5\n";
    gFile << "4 5 4 4 4\n";
    gFile << "5 5 5 5 5\n";
    gFile << "3 4 4 3 4\n";
    gFile << "4 4 5 5 4\n";
    gFile << "5 5 4 4 5\n";
    gFile.close();

    cout << "Созданы примерные файлы:\n";
    cout << "students.txt, subjects.txt, grades.txt\n\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "ПРОГРАММА 'ГРУППА СТУДЕНТОВ'\n\n";

    cout << "Создать примерные файлы? (1 - да, 0 - нет): ";
    int createFiles;
    cin >> createFiles;

    if (createFiles == 1) createSampleFiles();

    string studentsFile, subjectsFile, gradesFile, groupName;

    cout << "Название группы: ";
    cin.ignore();
    getline(cin, groupName);

    cout << "Файл со студентами: ";
    getline(cin, studentsFile);

    cout << "Файл с предметами: ";
    getline(cin, subjectsFile);

    cout << "Файл с оценками: ";
    getline(cin, gradesFile);

    Group group(groupName);

    cout << "\nЗагрузка данных...\n";
    if (!group.loadFromFiles(studentsFile, subjectsFile, gradesFile)) {
        cout << "Ошибка загрузки.\n";
        return 1;
    }

    group.printFullReport();

    int choice;
    do {
        cout << "\nМЕНЮ\n";
        cout << "1. Таблица оценок\n";
        cout << "2. Средние оценки студентов\n";
        cout << "3. Средние оценки по предметам\n";
        cout << "4. Средний балл группы\n";
        cout << "5. Макс/мин оценки\n";
        cout << "6. Полный отчет\n";
        cout << "0. Выход\n";
        cout << "Выберите: ";
        cin >> choice;

        switch (choice) {
        case 1: group.printGradeTable(); break;
        case 2: group.printStudentAverages(); break;
        case 3: group.printSubjectAverages(); break;
        case 4: group.printGroupAverage(); break;
        case 5: group.printMinMaxGrades(); break;
        case 6: group.printFullReport(); break;
        case 0: cout << "Программа завершена.\n"; break;
        default: cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}