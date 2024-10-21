public class CDLL {

    // Node Definition
    static class Node {
        int data;
        Node next;
        Node prev;
        
        Node(int d) {
            data = d;
            next = prev = null;
        }
    }

    // Printing the List
    static void printLinkedList(Node head) {
        if (head == null) {
            System.out.println("The Linked List is Empty");
            return;
        }
        Node current = head;
        do {
            System.out.print(current.data + " ");
            current = current.next;
        } while (current != head);
        System.out.println();
    }

    // Inserting at the Beginning
    static Node insertFront(Node head, int newNodeData) {
        Node newNode = new Node(newNodeData);

        if (head == null) {
            newNode.next = newNode;
            newNode.prev = newNode;
            return newNode;
        } else {
            Node last = head.prev;

            newNode.next = head;
            newNode.prev = last;
            head.prev = newNode;
            last.next = newNode;

            return newNode;
        }
    }

    // Inserting at a Given Position
    static Node insertPos(Node head, int newNodeData, int pos) {
        Node newNode = new Node(newNodeData);

        if (pos == 1) {
            return insertFront(head, newNodeData);
        }

        Node temp = head;
        for (int i = 1; i < pos - 1 && temp.next != head; i++) {
            temp = temp.next;
        }

        newNode.next = temp.next;
        newNode.prev = temp;
        temp.next.prev = newNode;
        temp.next = newNode;

        return head;
    }

    // Inserting at the End
    static Node insertEnd(Node head, int newNodeData) {
        Node newNode = new Node(newNodeData);

        if (head == null) {
            newNode.next = newNode;
            newNode.prev = newNode;
            return newNode;
        } else {
            Node last = head.prev;

            newNode.next = head;
            newNode.prev = last;
            last.next = newNode;
            head.prev = newNode;

            return head;
        }
    }

    // Deleting the First Node
    static Node deleteFront(Node head) {
        if (head == null) {
            System.out.println("The Doubly Circular Linked List is Empty");
            return null;
        }

        Node temp = head;

        if (head.next == head) {
            head = null;
            return null;
        }

        Node last = head.prev;

        head = head.next;
        head.prev = last;
        last.next = head;

        temp = null;
        return head;
    }

    // Deleting a Node at a Given Position
    static Node deletePos(Node head, int pos) {
        if (head == null) {
            System.out.println("The Doubly Circular Linked List is Empty");
            return null;
        }

        if (pos == 1) {
            return deleteFront(head);
        }

        Node temp = head;

        for (int i = 1; i < pos && temp.next != head; i++) {
            temp = temp.next;
        }

        if (temp.next == head) {
            System.out.println("The position is out of bounds");
            return head;
        }

        temp.prev.next = temp.next;
        temp.next.prev = temp.prev;

        temp = null;

        return head;
    }

    // Deleting the Last Node
    static Node deleteEnd(Node head) {
        if (head == null) {
            System.out.println("The Doubly Circular Linked List is Empty");
            return null;
        }

        Node last = head.prev;

        if (head.next == head) {
            head = null;
            return null;
        }

        last.prev.next = head;
        head.prev = last.prev;

        last = null;

        return head;
    }

    // Searching for a Node
    static boolean searchNode(Node head, int target) {
        if (head == null) {
            return false;
        }

        Node current = head;
        do {
            if (current.data == target) {
                return true;
            }
            current = current.next;
        } while (current != head);

        return false;
    }

    // Finding the Length of the List
    static int findLength(Node head) {
        if (head == null) return 0;

        int c = 0;
        Node current = head;

        do {
            c++;
            current = current.next;
        } while (current != head);

        return c;
    }

    // Reversing the Linked List
    static Node reverseList(Node head) {
        if (head == null || head.next == head) {
            return head;
        }

        Node current = head;
        Node temp = null;

        do {
            temp = current.prev;
            current.prev = current.next;
            current.next = temp;
            current = current.prev;
        } while (current != head);

        head = temp.prev;

        return head;
    }

    // Updating a Node
    static Node updateNode(Node head, int pos, int val) {
        if (head == null) {
            System.out.println("The Circular Linked List is Empty");
            return null;
        }

        Node current = head;

        for (int i = 1; i < pos && current.next != head; i++) {
            current = current.next;
        }

        if (current.next == head && pos > findLength(head)) {
            System.out.println("The position is out of bounds");
            return head;
        }

        current.data = val;
        return head;
    }

    public static void main(String[] args) {
        Node head = null;

        // Insertion Operations
        head = insertFront(head, 50);
        head = insertFront(head, 40);
        head = insertFront(head, 30);
        head = insertFront(head, 20);
        head = insertFront(head, 10);

        System.out.print("The Linked List goes like: ");
        printLinkedList(head);

        // Inserting at a Position
        head = insertPos(head, 200, 3);

        System.out.print("After Inserting at a Position: ");
        printLinkedList(head);

        // Inserting at the End
        head = insertEnd(head, 300);

        System.out.print("After Inserting at the End: ");
        printLinkedList(head);

        // Deleting the First Node
        head = deleteFront(head);

        System.out.print("After Deleting the First Node: ");
        printLinkedList(head);

        // Deleting at a Position
        head = deletePos(head, 4);

        System.out.print("After Deleting at a Position: ");
        printLinkedList(head);

        // Deleting the Last Node
        head = deleteEnd(head);

        System.out.print("After Deleting the Last Node: ");
        printLinkedList(head);

        // Searching for a Node
        int target = 30;
        if (searchNode(head, target)) {
            System.out.println(target + " is in the Linked List");
        } else {
            System.out.println(target + " is not in the Linked List");
        }

        target = 303;
        if (searchNode(head, target)) {
            System.out.println(target + " is in the Linked List");
        } else {
            System.out.println(target + " is not in the Linked List");
        }

        // Finding Length
        System.out.println("Length of the Linked List: " + findLength(head));

        // Reversing the Linked List
        head = reverseList(head);

        System.out.print("After Reversing: ");
        printLinkedList(head);

        // Updating a Node
        head = updateNode(head, 3, 250);

        System.out.print("After Updating: ");
        printLinkedList(head);
    }
}
