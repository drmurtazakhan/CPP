// Stack implementation using Linked List
#include <iostream>
using namespace std;

// Node structure for stack and queue
struct Node {
    int data;
    Node* next;
};

// Stack class using Linked List
class StackLinkedList {
    Node* top;
public:
    StackLinkedList() { top = nullptr; }
    bool isEmpty() { return top == nullptr; }
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }
    int peek() {
        return isEmpty() ? -1 : top->data;
    }
};

// Queue class using Linked List
class QueueLinkedList {
    Node* front, *rear;
public:
    QueueLinkedList() { front = rear = nullptr; }
    bool isEmpty() { return front == nullptr; }
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int dequeuedValue = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        return dequeuedValue;
    }
    int peek() {
        return isEmpty() ? -1 : front->data;
    }
};

int main() {
    // Stack operations
    StackLinkedList stack;
    stack.push(10);
    stack.push(20);
    cout << "Stack top: " << stack.peek() << endl;
    cout << "Popped: " << stack.pop() << endl;

    // Queue operations
    QueueLinkedList queue;
    queue.enqueue(30);
    queue.enqueue(40);
    cout << "Queue front: " << queue.peek() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;

    return 0;
}