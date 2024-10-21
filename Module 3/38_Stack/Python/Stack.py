# Defining the Maximum Size of the Stack
MAX = 5

# Stack Class
class Stack:
    def __init__(self):
        self.items = [None] * MAX
        self.top = -1

    # Check if the stack is full
    def is_full(self):
        return self.top == MAX - 1

    # Check if the stack is empty
    def is_empty(self):
        return self.top == -1

    # Push an element onto the stack
    def push(self, item):
        if self.is_full():
            print(f"Stack Overflow: Cannot Push Element {item}.")
            return
        self.top += 1
        self.items[self.top] = item
        print(f"Stack Push Operation Successful: Element {item} has been pushed.")

    # Pop an element from the stack
    def pop(self):
        if self.is_empty():
            print("Stack Underflow: No Element to Pop.")
            return -1
        item = self.items[self.top]
        self.top -= 1
        return item

    # Peek at the top element of the stack
    def peek(self):
        if self.is_empty():
            print("Stack is Empty.")
            return -1
        return self.items[self.top]

    # Print the whole stack
    def print_stack(self):
        if self.is_empty():
            print("Stack is Empty.")
            return
        for i in range(self.top + 1):
            print(self.items[i], end=" ")
        print()


if __name__ == "__main__":
    stk = Stack()

    stk.push(100)
    stk.push(200)
    stk.push(300)
    stk.push(400)
    stk.push(500)

    stk.print_stack()

    # Check if push works when stack is full
    # stk.push(600)

    print(f"The Top of the Stack is {stk.peek()}.")

    print(f"Popping Element: {stk.pop()}.")

    stk.print_stack()
