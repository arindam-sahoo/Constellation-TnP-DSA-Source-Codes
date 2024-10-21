public class CLL {
    static class Node {
        int data;
        Node next;
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // Create Node Function
    public static Node create(int nodeData) {
        return new Node(nodeData);
    }

    // Printing Function
    public static void printLinkedList(Node head) {
        if (head == null) return;
        Node current = head;
        do {
            System.out.print(current.data + " ");
            current = current.next;
        } while (current != head);
        System.out.println();
    }

    // Inserting a New Node at the Beginning of the Linked List
    public static Node insertFront(Node head, int newNodeData) {
        Node newNode = create(newNodeData);

        if (head == null) {
            newNode.next = newNode;
            return newNode;
        } else {
            Node temp = head;
            while (temp.next != head) {
                temp = temp.next;
            }
            newNode.next = head;
            temp.next = newNode;
            return head;
        }
    }

    // Inserting a New Node at a Given Position
    public static Node insertPos(Node head, int newNodeData, int pos) {
        Node newNode = create(newNodeData);

        if (pos == 1) {
            return insertFront(head, newNodeData);
        }

        Node temp = head;
        for (int i = 1; i < pos - 1 && temp.next != head; i++) {
            temp = temp.next;
        }

        newNode.next = temp.next;
        temp.next = newNode;

        return head;
    }

    // Inserting a New Node at the End
    public static Node insertEnd(Node head, int newNodeData) {
        Node newNode = create(newNodeData);

        if (head == null) {
            newNode.next = newNode;
            return newNode;
        } else {
            Node temp = head;
            while (temp.next != head) {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.next = head;
            return head;
        }
    }

    // Deleting a Node from the Beginning
    public static Node deleteFront(Node head) {
        if (head == null) {
            System.out.println("The Circular Linked List is Empty");
            return null;
        }

        Node temp = head;
        if (temp.next == head) {
            return null;
        }

        while (temp.next != head) {
            temp = temp.next;
        }

        temp.next = head.next;
        return head.next;
    }

    // Deleting a Node from the Given Position
    public static Node deletePos(Node head, int pos) {
        if (head == null) {
            System.out.println("The Circular Linked List is Empty");
            return null;
        }

        if (pos == 1) {
            return deleteFront(head);
        }

        Node temp = head;
        for (int i = 1; i < pos - 1 && temp.next != head; i++) {
            temp = temp.next;
        }

        if (temp.next == head) {
            System.out.println("The position is out of bounds");
            return head;
        }

        temp.next = temp.next.next;

        return head;
    }

    // Deleting the Last Node
    public static Node deleteEnd(Node head) {
        if (head == null) {
            System.out.println("The Circular Linked List is Empty");
            return null;
        }

        Node temp = head;
        if (temp.next == head) {
            return null;
        }

        Node prev = null;
        while (temp.next != head) {
            prev = temp;
            temp = temp.next;
        }

        prev.next = head;

        return head;
    }

    // Search Operation
    public static boolean searchNode(Node head, int target) {
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

    // Finding Length
    public static int findLength(Node head) {
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
    public static Node reverseList(Node head) {
        if (head == null || head.next == head) {
            return head;
        }

        Node prev = null;
        Node current = head;
        Node nextNode = null;
        Node tail = head;

        do {
            nextNode = current.next;
            current.next = prev;
            prev = current;
            current = nextNode;
        } while (current != head);

        tail.next = prev;
        return prev;
    }

    // Updating
    public static Node updateNode(Node head, int pos, int val) {
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

        System.out.println("The Linked List goes like");
        printLinkedList(head);

        head = insertPos(head, 200, 3);

        System.out.println("After Inserting a New Node at a given position, the Linked List goes like");
        printLinkedList(head);

        head = insertEnd(head, 300);

        System.out.println("After Inserting a New Node at the End, the Linked List goes like");
        printLinkedList(head);

        head = deleteFront(head);

        System.out.println("After Deleting the Head Node, the Linked List goes like");
        printLinkedList(head);

        head = deletePos(head, 4);

        System.out.println("After Deleting a Node from the given position, the Linked List goes like");
        printLinkedList(head);

        head = deleteEnd(head);

        System.out.println("After Deleting the Last Node, the Linked List goes like");
        printLinkedList(head);

        int target = 30;
        if (searchNode(head, target)) {
            System.out.println(target + " is there in the Linked List");
        } else {
            System.out.println(target + " is not there in the Linked List");
        }

        target = 303;
        if (searchNode(head, target)) {
            System.out.println(target + " is there in the Linked List");
        } else {
            System.out.println(target + " is not there in the Linked List");
        }

        System.out.println("The Length of the Linked List is " + findLength(head));

        head = reverseList(head);

        System.out.println("After Reversing, the Linked List goes like");
        printLinkedList(head);

        head = updateNode(head, 3, 20);

        System.out.println("After Updating a Node, the Linked List goes like");
        printLinkedList(head);
    }
}
