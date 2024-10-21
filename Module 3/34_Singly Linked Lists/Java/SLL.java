class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class SLL {
    public static Node create(int nodeData) {
        return new Node(nodeData);
    }

    public static void printLinkedList(Node head) {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static boolean searchIterative(Node head, int key) {
        Node current = head;
        while (current != null) {
            if (current.data == key)
                return true;
            current = current.next;
        }
        return false;
    }

    public static boolean searchRecursive(Node head, int key) {
        if (head == null)
            return false;
        if (head.data == key)
            return true;
        return searchRecursive(head.next, key);
    }

    public static Node insertFront(Node head, int newNodeData) {
        Node newNode = create(newNodeData);
        newNode.next = head;
        return newNode;
    }

    public static Node insertAfterNode(Node head, int newNodeData, int key) {
        Node current = head;
        while (current != null) {
            if (current.data == key)
                break;
            current = current.next;
        }

        if (current == null)
            return head;

        Node newNode = create(newNodeData);
        newNode.next = current.next;
        current.next = newNode;
        return head;
    }

    public static Node insertBack(Node head, int newNodeData) {
        Node newNode = create(newNodeData);
        if (head == null) {
            return newNode;
        }

        Node lastNode = head;
        while (lastNode.next != null) {
            lastNode = lastNode.next;
        }

        lastNode.next = newNode;
        return head;
    }

    public static Node reverseLinkedList(Node head) {
        Node current = head, previous = null, next;
        while (current != null) {
            next = current.next;
            current.next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }

    public static Node deleteHead(Node head) {
        if (head == null) {
            return null;
        }
        Node temp = head;
        head = head.next;
        return head;
    }

    public static Node deleteNode(Node head, int pos) {
        if (head == null) {
            return head;
        }

        if (pos == 1) {
            Node temp = head;
            head = head.next;
            return head;
        }

        Node previous = null;
        Node temp = head;
        for (int i = 1; temp != null && i < pos; i++) {
            previous = temp;
            temp = temp.next;
        }

        if (temp != null) {
            previous.next = temp.next;
        } else {
            System.out.println("Node is not there in the Singly Linked List.");
        }

        return head;
    }

    public static Node deleteTail(Node head) {
        if (head == null) {
            return null;
        }

        if (head.next == null) {
            return null;
        }

        Node secondLast = head;
        while (secondLast.next.next != null) {
            secondLast = secondLast.next;
        }

        secondLast.next = null;
        return head;
    }

    public static void main(String[] args) {
        Node head = create(10);
        head.next = create(20);
        head.next.next = create(30);
        head.next.next.next = create(40);
        head.next.next.next.next = create(50);
        // 10 -> 20 -> 30 -> 40 -> 50

        System.out.println("\nThe Linked List goes like:");
        printLinkedList(head);

        System.out.println("\n\nSearch Operation Ahead");
        int k = 40;

        if (searchRecursive(head, k))
            System.out.println(k + " is there in the Linked List.");
        else
            System.out.println(k + " is not there in the Linked List.");

        k = 42;
        if (searchIterative(head, k))
            System.out.println(k + " is there in the Linked List.");
        else
            System.out.println(k + " is not there in the Linked List.");

        System.out.println("\nInserting a New Node at the Beginning of the Singly Linked List");
        int d = 200;
        head = insertFront(head, d);
        System.out.println("The Linked List goes like this now:");
        printLinkedList(head);

        System.out.println("\nInserting a New Node after a Given Node of the Singly Linked List");
        k = 20;
        d = 150;
        head = insertAfterNode(head, d, k);
        System.out.println("The Linked List goes like this now:");
        printLinkedList(head);

        System.out.println("\nInserting a New Node at the End of the Singly Linked List");
        d = 300;
        head = insertBack(head, d);
        System.out.println("The Linked List goes like this now:");
        printLinkedList(head);

        System.out.println("\nReversing the Singly Linked List");
        head = reverseLinkedList(head);
        System.out.println("The Linked List goes like this now:");
        printLinkedList(head);

        System.out.println("\nDeleting the Head Node of the Singly Linked List");
        head = deleteHead(head);
        System.out.println("The Linked List goes like this now:");
        printLinkedList(head);

        System.out.println("\nDeleting a Node at a given position of the Singly Linked List");
        head = deleteNode(head, 4);
        System.out.println("The Linked List goes like this now:");
        printLinkedList(head);

        System.out.println("\nDeleting the Last Node of the Singly Linked List");
        head = deleteTail(head);
        System.out.println("The Linked List goes like this now:");
        printLinkedList(head);
    }
}
