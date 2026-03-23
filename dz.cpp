#include <iostream>
#include <string>
#include <locale>
using namespace std;
struct Stack {
    char arr[100];
    int top = -1;
    void push(char c) { arr[++top] = c; }
    void pop() { if (top >= 0) top--; }
    char peek() { return arr[top]; }
    bool empty() { return top == -1; }
};
int main() {
    setlocale(LC_ALL, "");
    Stack s;
    string str = "abba";
    for (char c : str) s.push(c);
    bool pal = true;
    for (char c : str) {
        if (s.peek() != c) pal = false;
        s.pop();
    }
    cout << "\"" << str << "\" " << (pal ? "является палиндромом" : "не является палиндромом") << "\n";
}