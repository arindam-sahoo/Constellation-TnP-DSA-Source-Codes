class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

# Printing the List
def print_linked_list(head):
    if head is None:
        print("The Linked List is Empty")
        return
    current = head
    while True:
        print(current.data, end=" ")
        current = current.next
        if current == head:
            break
    print()

# Inserting at the Beginning
def insert_front(head, new_node_data):
    new_node = Node(new_node_data)

    if head is None:
        new_node.next = new_node
        new_node.prev = new_node
        return new_node
    else:
        last = head.prev

        new_node.next = head
        new_node.prev = last
        head.prev = new_node
        last.next = new_node

        return new_node

# Inserting at a Given Position
def insert_pos(head, new_node_data, pos):
    new_node = Node(new_node_data)

    if pos == 1:
        return insert_front(head, new_node_data)

    temp = head
    for i in range(1, pos - 1):
        if temp.next == head:
            break
        temp = temp.next

    new_node.next = temp.next
    new_node.prev = temp
    temp.next.prev = new_node
    temp.next = new_node

    return head

# Inserting at the End
def insert_end(head, new_node_data):
    new_node = Node(new_node_data)

    if head is None:
        new_node.next = new_node
        new_node.prev = new_node
        return new_node
    else:
        last = head.prev

        new_node.next = head
        new_node.prev = last
        last.next = new_node
        head.prev = new_node

        return head

# Deleting the First Node
def delete_front(head):
    if head is None:
        print("The Doubly Circular Linked List is Empty")
        return None

    temp = head

    if head.next == head:
        head = None
        return None

    last = head.prev

    head = head.next
    head.prev = last
    last.next = head

    temp = None
    return head

# Deleting a Node at a Given Position
def delete_pos(head, pos):
    if head is None:
        print("The Doubly Circular Linked List is Empty")
        return None

    if pos == 1:
        return delete_front(head)

    temp = head

    for i in range(1, pos):
        if temp.next == head:
            break
        temp = temp.next

    if temp.next == head:
        print("The position is out of bounds")
        return head

    temp.prev.next = temp.next
    temp.next.prev = temp.prev

    temp = None
    return head

# Deleting the Last Node
def delete_end(head):
    if head is None:
        print("The Doubly Circular Linked List is Empty")
        return None

    last = head.prev

    if head.next == head:
        head = None
        return None

    last.prev.next = head
    head.prev = last.prev

    last = None
    return head

# Searching for a Node
def search_node(head, target):
    if head is None:
        return False

    current = head
    while True:
        if current.data == target:
            return True
        current = current.next
        if current == head:
            break

    return False

# Finding the Length of the List
def find_length(head):
    if head is None:
        return 0

    count = 0
    current = head
    while True:
        count += 1
        current = current.next
        if current == head:
            break

    return count

# Reversing the List
def reverse_list(head):
    if head is None or head.next == head:
        return head

    current = head
    temp = None

    while True:
        temp = current.prev
        current.prev = current.next
        current.next = temp
        current = current.prev
        if current == head:
            break

    head = temp.prev
    return head

# Updating a Node
def update_node(head, pos, val):
    if head is None:
        print("The Circular Linked List is Empty")
        return None

    current = head

    for i in range(1, pos):
        if current.next == head:
            break
        current = current.next

    if current.next == head and pos > find_length(head):
        print("The position is out of bounds")
        return head

    current.data = val
    return head


# Driver Code
if __name__ == "__main__":
    head = None

    # Insertion Operations
    head = insert_front(head, 50)
    head = insert_front(head, 40)
    head = insert_front(head, 30)
    head = insert_front(head, 20)
    head = insert_front(head, 10)

    print("The Linked List goes like: ")
    print_linked_list(head)

    # Inserting at a Position
    head = insert_pos(head, 200, 3)

    print("After Inserting at a Position: ")
    print_linked_list(head)

    # Inserting at the End
    head = insert_end(head, 300)

    print("After Inserting at the End: ")
    print_linked_list(head)

    # Deleting the First Node
    head = delete_front(head)

    print("After Deleting the First Node: ")
    print_linked_list(head)

    # Deleting at a Position
    head = delete_pos(head, 4)

    print("After Deleting at a Position: ")
    print_linked_list(head)

    # Deleting the Last Node
    head = delete_end(head)

    print("After Deleting the Last Node: ")
    print_linked_list(head)

    # Searching for a Node
    target = 30
    if search_node(head, target):
        print(f"{target} is in the Linked List")
    else:
        print(f"{target} is not in the Linked List")

    target = 303
    if search_node(head, target):
        print(f"{target} is in the Linked List")
    else:
        print(f"{target} is not in the Linked List")

    # Finding the Length of the List
    print("Length of the Linked List:", find_length(head))

    # Reversing the Linked List
    head = reverse_list(head)

    print("After Reversing: ")
    print_linked_list(head)

    # Updating a Node
    head = update_node(head, 3, 250)

    print("After Updating: ")
    print_linked_list(head)
