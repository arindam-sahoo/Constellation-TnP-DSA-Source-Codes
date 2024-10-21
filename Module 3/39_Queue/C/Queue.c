#include <stdio.h>
#include <stdlib.h>

#define MAX 5         // Defining the Maximum Size of the Queue

// Queue Structure
struct Queue
{
    int items[MAX];
    int front;
    int rear;
};

// Creating an Empty Queue
struct Queue* create() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue -> front = -1;
    queue -> rear = -1;

    return queue;
}

// Operation: isFull
int isFull(struct Queue* queue) {
    return queue -> rear == MAX - 1;
}

// Operation: Enqueue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue Overflow: Cannot Enqueue Element %d.\n", item);
        return;
    }
    else {
        if (queue -> front == -1) {
            queue -> front = 0;
        }
        queue -> rear++;
        queue -> items[queue -> rear] = item;
        printf("Enqueue Operation Successful: Element %d has been enqueued.\n", item);
    }
}

// Operartion: isEmpty
int isEmpty(struct Queue* queue) {
    return queue -> front == -1 || queue -> front > queue -> rear;
}

// Operation: Dequeue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow: No Element to Dequeue.\n");
        return -1;
    }
    else {
        int item = queue -> items[queue -> front];
        queue -> front++;
        if (queue -> front > queue -> rear) {
            queue -> front = -1;
            queue -> rear = -1;
        }
        return item;
    }   
}

// Operation: Peek
int peek(struct Queue* queue) {
   if (isEmpty(queue)) {
        printf("Queue is Empty.\n");
        return -1;
    }
    return queue -> items[queue -> front];
}

// Printing the Whole Queue
void printQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty.\n");
        return;
    }
    for(int i= queue -> front; i<= queue -> rear; i++)
        printf("%d ", queue -> items[i]);
    printf("\n");
}

void main() {
    struct Queue* q = create();

    enqueue(q, 100);
    printQueue(q);
    enqueue(q, 200);
    printQueue(q);
    enqueue(q, 300);
    printQueue(q);
    enqueue(q, 400);
    printQueue(q);
    enqueue(q, 500);
    printQueue(q);

    printQueue(q);

    // Used for checking whether an element is enqueueed even if the queue is full
    // enqueue(q, 600);

    printf("The Top of the Queue is %d.\n", peek(q));

    printf("Dequeueing Element: %d.\n", dequeue(q));

    printQueue(q);

    printf("The Top of the Queue is %d.\n", peek(q));

    printf("Dequeueing Element: %d.\n", dequeue(q));

    printQueue(q);
}