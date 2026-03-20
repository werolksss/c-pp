#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    string name;

    Student(string n) : name(n) {}
};

class University {
public:
    vector<Student*> students;
    void addStudent(Student* s) {
        students.push_back(s);
    }

    void show() {
        for (auto s : students)
            cout << s->name << endl;
    }
};

int main() {
    Student s1("Alice");
    Student s2("Bob");

    University uni;

    uni.addStudent(&s1);
    uni.addStudent(&s2);

    uni.show();

    return 0;
}