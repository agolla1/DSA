#include <iostream>
using namespace std;

#define MAX_SIZE 128

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void push(int x) {
        if (rear == MAX_SIZE - 1) {
            cout << "Queue overflow" << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            arr[++rear] = x;
            cout << "Inserted " << x << " at position " << rear << endl;
        }
    }

    void pop() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow" << endl;
            front = rear = -1; 
        } else {
            cout << "Removing " << arr[front] << " from position " << front << endl;
            front++;
        }
    }

    int f_front() {
        if (front != -1)
            return arr[front];
        else
            cout<<"Queue is empty" << endl;
    }

    int r_rear() {
        if (rear != -1)
            return arr[rear];
        else
            cout<<"Queue is empty" << endl;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    int size() {
        if (isEmpty()) {
            return 0;
        } else {
            return rear - front + 1;
        }
    }
};

int main() {
    Queue* que = new Queue();
    que->pop();

    for (int i = 0; i < 10; i++) {
        que->push(i);
    }

    while (!que->isEmpty()) {
        cout << "Front element: " << que->f_front() << endl;
        que->pop();
    }

    cout << "Queue size: " << que->size() << endl;
    cout << "Is queue empty? " << (que->isEmpty()) << endl;

    delete que;
    return 0;
}