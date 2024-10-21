#include <iostream>
#define MAX 5  // Defining the Maximum Size of the Stack

// Stack Structure
class Stack {
public:
    int items[MAX];
    int top;

    // Constructor to initialize stack
    Stack() {
        top = -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Push an element onto the stack
    void push(int item) {
        if (isFull()) {
            std::cout << "Stack Overflow: Cannot Push Element " << item << ".\n";
            return;
        }
        items[++top] = item;
        std::cout << "Stack Push Operation Successful: Element " << item << " has been pushed.\n";
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow: No Element to Pop.\n";
            return -1;
        }
        return items[top--];
    }

    // Peek at the top element of the stack
    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is Empty.\n";
            return -1;
        }
        return items[top];
    }

    // Print the whole stack
    void printStack() {
        if (isEmpty()) {
            std::cout << "Stack is Empty.\n";
            return;
        }
        for (int i = 0; i <= top; i++)
            std::cout << items[i] << " ";
        std::cout << "\n";
    }
};

int main() {
    Stack stk;

    stk.push(100);
    stk.push(200);
    stk.push(300);
    stk.push(400);
    stk.push(500);

    stk.printStack();

    // Check if push works when stack is full
    // stk.push(600);

    std::cout << "The Top of the Stack is " << stk.peek() << ".\n";

    std::cout << "Popping Element: " << stk.pop() << ".\n";

    stk.printStack();

    return 0;
}
