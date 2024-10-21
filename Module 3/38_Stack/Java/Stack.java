public class Stack {
    static final int MAX = 5; // Maximum Size of the Stack
    int[] items = new int[MAX];
    int top;

    // Constructor to initialize stack
    Stack() {
        top = -1;
    }

    // Check if the stack is full
    boolean isFull() {
        return top == MAX - 1;
    }

    // Check if the stack is empty
    boolean isEmpty() {
        return top == -1;
    }

    // Push an element onto the stack
    void push(int item) {
        if (isFull()) {
            System.out.println("Stack Overflow: Cannot Push Element " + item + ".");
            return;
        }
        items[++top] = item;
        System.out.println("Stack Push Operation Successful: Element " + item + " has been pushed.");
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            System.out.println("Stack Underflow: No Element to Pop.");
            return -1;
        }
        return items[top--];
    }

    // Peek at the top element of the stack
    int peek() {
        if (isEmpty()) {
            System.out.println("Stack is Empty.");
            return -1;
        }
        return items[top];
    }

    // Print the whole stack
    void printStack() {
        if (isEmpty()) {
            System.out.println("Stack is Empty.");
            return;
        }
        for (int i = 0; i <= top; i++) {
            System.out.print(items[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Stack stk = new Stack();

        stk.push(100);
        stk.push(200);
        stk.push(300);
        stk.push(400);
        stk.push(500);

        stk.printStack();

        // Check if push works when stack is full
        // stk.push(600);

        System.out.println("The Top of the Stack is " + stk.peek() + ".");

        System.out.println("Popping Element: " + stk.pop() + ".");

        stk.printStack();
    }
}
