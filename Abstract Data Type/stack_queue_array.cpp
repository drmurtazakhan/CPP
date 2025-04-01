// Stack implementation using Array
#include <iostream>
#define SIZE 100
using namespace std;

class StackArray {
    int top;
    int arr[SIZE];
public:
    StackArray() { top = -1; }
    bool isFull() { return top == SIZE - 1; }
    bool isEmpty() { return top == -1; }
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = value;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }
    int peek() {
        return isEmpty() ? -1 : arr[top];
    }
};

// Queue implementation using Array
class QueueArray {
    int front, rear, arr[SIZE];
public:
    QueueArray() { front = rear = -1; }
    bool isFull() { return rear == SIZE - 1; }
    bool isEmpty() { return front == -1 || front > rear; }
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (isEmpty()) front = 0;
        arr[++rear] = value;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return arr[front++];
    }
    int peek() {
        return isEmpty() ? -1 : arr[front];
    }
};

int main() {
    StackArray stack;
    stack.push(10);
    stack.push(20);
    cout << "Stack top: " << stack.peek() << endl;
    cout << "Popped: " << stack.pop() << endl;

    QueueArray queue;
    queue.enqueue(30);
    queue.enqueue(40);
    cout << "Queue front: " << queue.peek() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;

    return 0;
}
