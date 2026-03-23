#include <iostream>
#include <locale>
using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
    Node(int v) : data(v) {}
};

struct List {
    Node* head = nullptr;

    void push_front(int v) {
        Node* n = new Node(v);
        n->next = head;
        head = n;
    }

    void push_back(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; return; }
        Node* c = head; while (c->next) c = c->next;
        c->next = n;
    }

    void pop_front() {
        if (head) { Node* t = head; head = head->next; delete t; }
    }

    void print() {
        Node* c = head;
        while (c) { cout << c->data << " "; c = c->next; }
        cout << "\n";
    }
};

int main() {
    setlocale(LC_ALL, "");

    List l;
    l.push_front(1);
    l.push_back(2);
    l.push_front(0);

    cout << "Список: "; l.print();
    l.pop_front();
    cout << "После удаления первого элемента: "; l.print();
}