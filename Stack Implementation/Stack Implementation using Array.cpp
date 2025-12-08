#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int top;
    int capacity;
    
public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }
    
    ~Stack() {
        delete[] arr;
    }
    
    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }
    
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }
    
    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    int size() {
        return top + 1;
    }
};

int main() {
    Stack st(5);
    st.push(10);
    st.push(20);
    cout << st.peek() << endl; 
    st.pop();
    cout << st.peek() << endl; 
    cout << st.isEmpty() << endl;
    return 0;
}
