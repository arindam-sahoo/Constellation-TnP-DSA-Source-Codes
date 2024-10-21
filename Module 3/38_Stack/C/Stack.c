#include <stdio.h>
#include <stdlib.h>

#define MAX 5         // Defining the Maximum Size of the Stack

// Stack Structure
struct Stack
{
    int items[MAX];
    int top;
};

// Creating an Empty Stack
struct Stack* create() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack -> top = -1;

    return stack;
}

int isFull(struct Stack* stack) {
    return stack -> top == MAX - 1;
}

// Operation: Push
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot Push Element %d.\n", item);
        return;
    }
    stack -> items[++stack -> top] = item;
    printf("Stack Push Operation Successful: Element %d has been pushed.\n", item);
}

int isEmpty(struct Stack* stack) {
    return stack -> top == -1;
}

// Operation: Pop
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: No Element to Pop.\n");
        return -1;
    }
    return stack -> items[stack->top--];
}

int peek(struct Stack* stack) {
   if (isEmpty(stack)) {
        printf("Stack is Empty.\n");
        return -1;
    }
    return stack -> items[stack -> top];
}

// Printing the Whole Stack
void printStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is Empty.\n");
        return;
    }
    for(int i=0; i<=stack->top; i++)
        printf("%d ", stack -> items[i]);
    printf("\n");
}

void main() {
    struct Stack* stk = create();

    push(stk, 100);
    push(stk, 200);
    push(stk, 300);
    push(stk, 400);
    push(stk, 500);

    printStack(stk);

    // Used for checking whether an element is pushed even if the stack is full
    // push(stk, 600);

    printf("The Top of the Stack is %d.\n", peek(stk));

    printf("Popping Element: %d.\n", pop(stk));

    printStack(stk);
}