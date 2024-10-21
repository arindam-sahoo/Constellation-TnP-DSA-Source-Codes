public class Queue {
    private static final int MAX = 5;
    private int[] items = new int[MAX];
    private int front, rear;

    // Constructor
    public Queue() {
        front = -1;
        rear = -1;
    }

    // Operation: isFull
    public boolean isFull() {
        return rear == MAX - 1;
    }

    // Operation: Enqueue
    public void enqueue(int item) {
        if (isFull()) {
            System.out.println("Queue Overflow: Cannot Enqueue Element " + item + ".");
            return;
        } else {
            if (front == -1) {
                front = 0;
            }
            items[++rear] = item;
            System.out.println("Enqueue Operation Successful: Element " + item + " has been enqueued.");
        }
    }

    // Operation: isEmpty
    public boolean isEmpty() {
        return front == -1 || front > rear;
    }

    // Operation: Dequeue
    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue Underflow: No Element to Dequeue.");
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
    public int peek() {
        if (isEmpty()) {
            System.out.println("Queue is Empty.");
            return -1;
        }
        return items[front];
    }

    // Printing the Whole Queue
    public void printQueue() {
        if (isEmpty()) {
            System.out.println("Queue is Empty.");
            return;
        }
        for (int i = front; i <= rear; i++) {
            System.out.print(items[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Queue q = new Queue();

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

        System.out.println("The Top of the Queue is " + q.peek() + ".");

        System.out.println("Dequeueing Element: " + q.dequeue() + ".");
        q.printQueue();

        System.out.println("The Top of the Queue is " + q.peek() + ".");

        System.out.println("Dequeueing Element: " + q.dequeue() + ".");
        q.printQueue();
    }
}
