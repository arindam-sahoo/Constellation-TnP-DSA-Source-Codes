class Queue:
    MAX = 5

    def __init__(self):
        self.items = [None] * Queue.MAX
        self.front = -1
        self.rear = -1

    # Operation: isFull
    def is_full(self):
        return self.rear == Queue.MAX - 1

    # Operation: Enqueue
    def enqueue(self, item):
        if self.is_full():
            print(f"Queue Overflow: Cannot Enqueue Element {item}.")
            return
        else:
            if self.front == -1:
                self.front = 0
            self.rear += 1
            self.items[self.rear] = item
            print(f"Enqueue Operation Successful: Element {item} has been enqueued.")

    # Operation: isEmpty
    def is_empty(self):
        return self.front == -1 or self.front > self.rear

    # Operation: Dequeue
    def dequeue(self):
        if self.is_empty():
            print("Queue Underflow: No Element to Dequeue.")
            return -1
        else:
            item = self.items[self.front]
            self.front += 1
            if self.front > self.rear:
                self.front = self.rear = -1
            return item

    # Operation: Peek
    def peek(self):
        if self.is_empty():
            print("Queue is Empty.")
            return -1
        return self.items[self.front]

    # Printing the Whole Queue
    def print_queue(self):
        if self.is_empty():
            print("Queue is Empty.")
            return
        for i in range(self.front, self.rear + 1):
            print(self.items[i], end=" ")
        print()

if __name__ == "__main__":
    q = Queue()

    q.enqueue(100)
    q.print_queue()
    q.enqueue(200)
    q.print_queue()
    q.enqueue(300)
    q.print_queue()
    q.enqueue(400)
    q.print_queue()
    q.enqueue(500)
    q.print_queue()

    print(f"The Top of the Queue is {q.peek()}.")

    print(f"Dequeueing Element: {q.dequeue()}.")
    q.print_queue()

    print(f"The Top of the Queue is {q.peek()}.")

    print(f"Dequeueing Element: {q.dequeue()}.")
    q.print_queue()
