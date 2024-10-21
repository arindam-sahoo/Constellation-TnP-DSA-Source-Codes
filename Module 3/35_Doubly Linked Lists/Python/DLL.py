class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

# Create Node Function
def create(node_data):
    return Node(node_data)

# Forward Traversal (Iterative)
def forward_traversal_iterative(head):
    current = head
    while current:
        print(current.data, end=' ')
        current = current.next

# Forward Traversal (Recursive)
def forward_traversal_recursive(head):
    if head is None:
        return
    print(head.data, end=' ')
    forward_traversal_recursive(head.next)

# Backward Traversal (Iterative)
def backward_traversal_iterative(head):
    current = head
    while current:
        print(current.data, end=' ')
        current = current.prev

# Backward Traversal (Recursive)
def backward_traversal_recursive(head):
    if head is None:
        return
    print(head.data, end=' ')
    backward_traversal_recursive(head.prev)

# Iterative Key Search Function
def search_iterative(head, key):
    current = head
    while current:
        if current.data == key:
            return True
        current = current.next
    return False

# Recursive Key Search Function
def search_recursive(head, key):
    if head is None:
        return False
    if head.data == key:
        return True
    return search_recursive(head.next, key)

# Finding out the Length of Doubly Linked List
def length_dll(head):
    count = 0
    current = head
    while current:
        count += 1
        current = current.next
    return count

# Inserting a New Node at the Beginning
def insert_front(head, new_node_data):
    new_node = create(new_node_data)
    new_node.next = head
    if head:
        head.prev = new_node
    return new_node

# Inserting a New Node at the End
def insert_last(head, new_node_data):
    new_node = create(new_node_data)
    if head is None:
        return new_node
    current = head
    while current.next:
        current = current.next
    current.next = new_node
    new_node.prev = current
    return head

# Inserting after a given node
def insert_after(head, new_node_data, key):
    current = head
    while current:
        if current.data == key:
            break
        current = current.next
    if current is None:
        return head
    new_node = create(new_node_data)
    new_node.prev = current
    new_node.next = current.next
    current.next = new_node
    if new_node.next:
        new_node.next.prev = new_node
    return head

# Inserting before a given node
def insert_before(head, new_node_data, key):
    current = head
    while current:
        if current.data == key:
            break
        current = current.next
    if current is None:
        return head
    new_node = create(new_node_data)
    new_node.prev = current.prev
    new_node.next = current
    if new_node.prev:
        new_node.prev.next = new_node
    else:
        head = new_node
    current.prev = new_node
    return head

# Inserting at a given position
def insert_pos(head, new_node_data, pos):
    new_node = create(new_node_data)
    if pos == 1:
        new_node.next = head
        if head:
            head.prev = new_node
        return new_node
    current = head
    for _ in range(1, pos - 1):
        if current is None:
            print("The position given is out of bounds.")
            return head
        current = current.next
    new_node.prev = current
    new_node.next = current.next
    current.next = new_node
    if new_node.next:
        new_node.next.prev = new_node
    return head

# Deleting the first node
def delete_first(head):
    if head is None:
        return None
    temp = head
    head = head.next
    if head:
        head.prev = None
    return head

# Deleting the last node
def delete_last(head):
    if head is None:
        return None
    if head.next is None:
        return None
    current = head
    while current.next:
        current = current.next
    current.prev.next = None
    return head

# Deleting a node at a specific position
def delete_pos(head, pos):
    if head is None:
        return head
    current = head
    for _ in range(1, pos):
        if current is None:
            print("Position is out of range.")
            return head
        current = current.next
    if current.prev:
        current.prev.next = current.next
    if current.next:
        current.next.prev = current.prev
    if head == current:
        head = current.next
    return head

# Deleting a node after a specific node
def delete_after(head, key):
    current = head
    while current:
        if current.data == key:
            break
        current = current.next
    if current is None or current.next is None:
        return head
    nt_del = current.next
    current.next = nt_del.next
    if nt_del.next:
        nt_del.next.prev = current
    return head

# Deleting a node before a specific node
def delete_before(head, key):
    current = head
    while current:
        if current.data == key:
            break
        current = current.next
    if current is None or current.prev is None:
        return head
    nt_del = current.prev
    current.prev = nt_del.prev
    if nt_del.prev:
        nt_del.prev.next = current
    else:
        head = current
    return head

# Main Execution
if __name__ == "__main__":
    head = create(10)
    second_node = create(20)
    third_node = create(30)
    fourth_node = create(40)
    fifth_node = create(50)

    head.next = second_node
    second_node.prev = head
    second_node.next = third_node
    third_node.prev = second_node
    third_node.next = fourth_node
    fourth_node.prev = third_node
    fourth_node.next = fifth_node
    fifth_node.prev = fourth_node

    print("\nForward Traversal (Iterative)")
    forward_traversal_iterative(head)

    print("\nForward Traversal (Recursive)")
    forward_traversal_recursive(head)

    print("\nBackward Traversal (Iterative)")
    backward_traversal_iterative(fifth_node)

    print("\nBackward Traversal (Recursive)")
    backward_traversal_recursive(fifth_node)

    print("\nSearch Operation Ahead")
    k = 40

    if search_recursive(head, k):
        print(f"{k} is there in the Linked List.")
    else:
        print(f"{k} is not there in the Linked List.")

    k = 42

    if search_iterative(head, k):
        print(f"{k} is there in the Linked List.")
    else:
        print(f"{k} is not there in the Linked List.")

    print("Length of the Linked List:", length_dll(head))

    print("\nInserting a New Node at the Beginning")
    head = insert_front(head, 200)
    forward_traversal_iterative(head)

    print("\nInserting a New Node at the End")
    head = insert_last(head, 300)
    forward_traversal_iterative(head)

    print("\nInserting a New Node after a given Node")
    head = insert_after(head, 150, 40)
    forward_traversal_iterative(head)

    print("\nInserting a New Node before a given Node")
    head = insert_before(head, 160, 30)
    forward_traversal_iterative(head)

    print("\nInserting a New Node at a given Position")
    head = insert_pos(head, 170, 2)
    forward_traversal_iterative(head)

    print("\nDeleting the First Node")
    head = delete_first(head)
    forward_traversal_iterative(head)

    print("\nDeleting the Last Node")
    head = delete_last(head)
    forward_traversal_iterative(head)

    print("\nDeleting a Node after a given Node")
    head = delete_after(head, 40)
    forward_traversal_iterative(head)

    print("\nDeleting a Node before a given Node")
    head = delete_before(head, 30)
    forward_traversal_iterative(head)

    print("\nDeleting a Node at a given Position")
    head = delete_pos(head, 2)
    forward_traversal_iterative(head)
