#include <iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int capacity;
    int* arr;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        size = 0;
        rear = capacity - 1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.dequeue() << "\n"; 
    cout << q.getFront() << "\n"; 
    cout << q.getRear() << "\n"; 
    return 0;
}
