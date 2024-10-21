class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Create Node Function
def create(node_data):
    return Node(node_data)

# Printing Function
def print_linked_list(head):
    current = head
    while current:
        print(current.data, end=" ")
        current = current.next
    print()

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

# Inserting a New node at the beginning/front of the Singly Linked List
def insert_front(head, new_node_data):
    new_node = create(new_node_data)
    new_node.next = head
    return new_node

# Inserting a New node after a Given Node of the Singly Linked List
def insert_after_node(head, new_node_data, key):
    current = head
    while current:
        if current.data == key:
            break
        current = current.next

    if current is None:
        return head

    new_node = create(new_node_data)
    new_node.next = current.next
    current.next = new_node
    return head

# Inserting a New node at the End of the Singly Linked List
def insert_back(head, new_node_data):
    new_node = create(new_node_data)
    if head is None:
        return new_node

    last_node = head
    while last_node.next:
        last_node = last_node.next

    last_node.next = new_node
    return head

# Reversing a Singly Linked List
def reverse_linked_list(head):
    current, previous = head, None
    while current:
        next = current.next
        current.next = previous
        previous = current
        current = next
    return previous

# Deleting the head node
def delete_head(head):
    if head is None:
        return None
    return head.next

# Deleting a Node at a given position
def delete_node(head, pos):
    if head is None:
        return head

    if pos == 1:
        return head.next

    temp = head
    for i in range(1, pos - 1):
        if temp is None:
            break
        temp = temp.next

    if temp is None or temp.next is None:
        print("Node is not there in the Singly Linked List.")
        return head

    temp.next = temp.next.next
    return head

# Deleting the Last Node
def delete_tail(head):
    if head is None:
        return None

    if head.next is None:
        return None

    second_last = head
    while second_last.next.next:
        second_last = second_last.next

    second_last.next = None
    return head

# Main Function
if __name__ == "__main__":
    head = create(10)
    head.next = create(20)
    head.next.next = create(30)
    head.next.next.next = create(40)
    head.next.next.next.next = create(50)
    # 10 -> 20 -> 30 -> 40 -> 50

    print("\nThe Linked List goes like:")
    print_linked_list(head)

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

    print("\nInserting a New Node at the Beginning")
    head = insert_front(head, 200)
    print("The Linked List goes like this now:")
    print_linked_list(head)

    print("\nInserting a New Node after a Given Node")
    head = insert_after_node(head, 150, 20)
    print("The Linked List goes like this now:")
    print_linked_list(head)

    print("\nInserting a New Node at the End")
    head = insert_back(head, 300)
    print("The Linked List goes like this now:")
    print_linked_list(head)

    print("\nReversing the Linked List")
    head = reverse_linked_list(head)
    print("The Linked List goes like this now:")
    print_linked_list(head)

    print("\nDeleting the Head Node")
    head = delete_head(head)
    print("The Linked List goes like this now:")
    print_linked_list(head)

    print("\nDeleting a Node at a Given Position")
    head = delete_node(head, 4)
    print("The Linked List goes like this now:")
    print_linked_list(head)

    print("\nDeleting the Last Node")
    head = delete_tail(head)
    print("The Linked List goes like this now:")
    print_linked_list(head)
