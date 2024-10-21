#include <iostream>
#define MAX 5 // Defining the Maximum Size of the Queue

using namespace std;

// Queue Class
class Queue {
    int items[MAX];
    int front;
    int rear;

public:
    // Constructor
    Queue() {
        front = -1;
        rear = -1;
    }

    // Operation: isFull
    bool isFull() {
        return rear == MAX - 1;
    }

    // Operation: Enqueue
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue Overflow: Cannot Enqueue Element " << item << ".\n";
            return;
        } else {
            if (front == -1) {
                front = 0;
            }
            items[++rear] = item;
            cout << "Enqueue Operation Successful: Element " << item << " has been enqueued.\n";
        }
    }

    // Operation: isEmpty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Operation: Dequeue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow: No Element to Dequeue.\n";
            return -1;
        } else {
            int item = items[front++];
            if (front > rear) {
                front = rear = -1;
            }
            return item;
        }
    }

    // Operation: Peek
    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty.\n";
            return -1;
        }
        return items[front];
    }

    // Printing the Whole Queue
    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty.\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(100);
    q.printQueue();
    q.enqueue(200);
    q.printQueue();
    q.enqueue(300);
    q.printQueue();
    q.enqueue(400);
    q.printQueue();
    q.enqueue(500);
    q.printQueue();

    cout << "The Top of the Queue is " << q.peek() << ".\n";

    cout << "Dequeueing Element: " << q.dequeue() << ".\n";
    q.printQueue();

    cout << "The Top of the Queue is " << q.peek() << ".\n";

    cout << "Dequeueing Element: " << q.dequeue() << ".\n";
    q.printQueue();

    return 0;
}
