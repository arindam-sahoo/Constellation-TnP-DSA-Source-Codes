class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Create Node Function
def create(nodeData):
    return Node(nodeData)

# Printing Function
def printLinkedList(head):
    if head is None:
        return
    current = head
    while True:
        print(current.data, end=" ")
        current = current.next
        if current == head:
            break
    print()

# Inserting a New Node at the Beginning of the Linked List
def insertFront(head, newNodeData):
    newNode = create(newNodeData)

    if head is None:
        newNode.next = newNode
        return newNode
    else:
        temp = head
        while temp.next != head:
            temp = temp.next
        newNode.next = head
        temp.next = newNode
        return head

# Inserting a New Node at a Given Position
def insertPos(head, newNodeData, pos):
    newNode = create(newNodeData)

    if pos == 1:
        return insertFront(head, newNodeData)

    temp = head
    for i in range(1, pos - 1):
        if temp.next == head:
            break
        temp = temp.next

    newNode.next = temp.next
    temp.next = newNode

    return head

# Inserting a New Node at the End
def insertEnd(head, newNodeData):
    newNode = create(newNodeData)

    if head is None:
        newNode.next = newNode
        return newNode
    else:
        temp = head
        while temp.next != head:
            temp = temp.next
        temp.next = newNode
        newNode.next = head
        return head

# Deleting a Node from the Beginning
def deleteFront(head):
    if head is None:
        print("The Circular Linked List is Empty")
        return None

    temp = head
    if temp.next == head:
        return None

    while temp.next != head:
        temp = temp.next

    temp.next = head.next
    return head.next

# Deleting a Node from the Given Position
def deletePos(head, pos):
    if head is None:
        print("The Circular Linked List is Empty")
        return None

    if pos == 1:
        return deleteFront(head)

    temp = head
    for i in range(1, pos - 1):
        if temp.next == head:
            break
        temp = temp.next

    if temp.next == head:
        print("The position is out of bounds")
        return head

    temp.next = temp.next.next

    return head

# Deleting the Last Node
def deleteEnd(head):
    if head is None:
        print("The Circular Linked List is Empty")
        return None

    temp = head
    if temp.next == head:
        return None

    prev = None
    while temp.next != head:
        prev = temp
        temp = temp.next

    prev.next = head

    return head

# Search Operation
def searchNode(head, target):
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

# Finding Length
def findLength(head):
    if head is None:
        return 0

    c = 0
    current = head
    while True:
        c += 1
        current = current.next
        if current == head:
            break

    return c

# Reversing the Linked List
def reverseList(head):
    if head is None or head.next == head:
        return head

    prev = None
    current = head
    nextNode = None
    tail = head

    while True:
        nextNode = current.next
        current.next = prev
        prev = current
        current = nextNode
        if current == head:
            break

    tail.next = prev
    return prev

# Updating
def updateNode(head, pos, val):
    if head is None:
        print("The Circular Linked List is Empty")
        return None

    current = head
    for i in range(1, pos):
        current = current.next
        if current == head:
            break

    current.data = val
    return head

# Main Function
def main():
    head = None

    # Insertion Operations
    head = insertFront(head, 50)
    head = insertFront(head, 40)
    head = insertFront(head, 30)
    head = insertFront(head, 20)
    head = insertFront(head, 10)

    print("\nThe Linked List goes like")
    printLinkedList(head)

    head = insertPos(head, 200, 3)

    print("\nAfter Inserting a New Node at a given position, the Linked List goes like")
    printLinkedList(head)

    head = insertEnd(head, 300)

    print("\nAfter Inserting a New Node at the End, the Linked List goes like")
    printLinkedList(head)

    head = deleteFront(head)

    print("\nAfter Deleting the Head Node, the Linked List goes like")
    printLinkedList(head)

    head = deletePos(head, 4)

    print("\nAfter Deleting a Node from the given position, the Linked List goes like")
    printLinkedList(head)

    head = deleteEnd(head)

    print("\nAfter Deleting the Last Node, the Linked List goes like")
    printLinkedList(head)

    target = 30
    if searchNode(head, target):
        print(f"\n{target} is there in the Linked List")
    else:
        print(f"\n{target} is not there in the Linked List")

    target = 303
    if searchNode(head, target):
        print(f"\n{target} is there in the Linked List")
    else:
        print(f"\n{target} is not there in the Linked List")

    print(f"\nThe Length of the Linked List is {findLength(head)}")

    head = reverseList(head)

    print("\nAfter Reversing, the Linked List goes like")
    printLinkedList(head)

    head = updateNode(head, 3, 20)

    print("\nAfter Updating a Node, the Linked List goes like")
    printLinkedList(head)

if __name__ == "__main__":
    main()
