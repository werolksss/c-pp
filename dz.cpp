#include <iostream>
#include <locale>
using namespace std;
struct Queue {
    int arr[100];
    int front = 0, back = 0;
    void enqueue(int v) { arr[back++] = v; }
    void dequeue() { if (front < back) front++; }
    int peek() { return arr[front]; }
    bool empty() { return front == back; }
};
int main() {
    setlocale(LC_ALL, "");
    Queue q;
    for (int i = 1; i <= 5; i++) q.enqueue(i);
    cout << "Порядок обработки очереди: ";
    while (!q.empty()) { cout << q.peek() << " "; q.dequeue(); }
    cout << "\n";
}