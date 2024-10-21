public class DLL {
    static class Node {
        int data;
        Node next;
        Node prev;

        Node(int data) {
            this.data = data;
            this.next = null;
            this.prev = null;
        }
    }

    // Create Node Function
    static Node create(int nodeData) {
        return new Node(nodeData);
    }

    // Forward Traversal (Iterative)
    static void forwardTraversalIterative(Node head) {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
    }

    // Forward Traversal (Recursive)
    static void forwardTraversalRecursive(Node head) {
        if (head == null)
            return;
        System.out.print(head.data + " ");
        forwardTraversalRecursive(head.next);
    }

    // Backward Traversal (Iterative)
    static void backwardTraversalIterative(Node head) {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.prev;
        }
    }

    // Backward Traversal (Recursive)
    static void backwardTraversalRecursive(Node head) {
        if (head == null)
            return;
        System.out.print(head.data + " ");
        backwardTraversalRecursive(head.prev);
    }

    // Iterative Key Search Function
    static boolean searchIterative(Node head, int key) {
        Node current = head;
        while (current != null) {
            if (current.data == key)
                return true;
            current = current.next;
        }
        return false;
    }

    // Recursive Key Search Function
    static boolean searchRecursive(Node head, int key) {
        if (head == null)
            return false;
        if (head.data == key)
            return true;
        return searchRecursive(head.next, key);
    }

    // Finding out the Length of Doubly Linked List
    static int lengthDLL(Node head) {
        int count = 0;
        Node current = head;
        while (current != null) {
            count++;
            current = current.next;
        }
        return count;
    }

    // Inserting a New Node at the Beginning
    static Node insertFront(Node head, int newNodeData) {
        Node newNode = create(newNodeData);
        newNode.next = head;
        if (head != null)
            head.prev = newNode;
        return newNode;
    }

    // Inserting a New Node at the End
    static Node insertLast(Node head, int newNodeData) {
        Node newNode = create(newNodeData);
        if (head == null) {
            return newNode;
        } else {
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
            newNode.prev = current;
            return head;
        }
    }

    // Inserting after a given node
    static Node insertAfter(Node head, int newNodeData, int key) {
        Node current = head;
        while (current != null) {
            if (current.data == key)
                break;
            current = current.next;
        }

        if (current == null)
            return head;

        Node newNode = create(newNodeData);
        newNode.prev = current;
        newNode.next = current.next;
        current.next = newNode;

        if (newNode.next != null) {
            newNode.next.prev = newNode;
        }

        return head;
    }

    // Inserting before a given node
    static Node insertBefore(Node head, int newNodeData, int key) {
        Node current = head;
        while (current != null) {
            if (current.data == key)
                break;
            current = current.next;
        }

        if (current == null)
            return head;

        Node newNode = create(newNodeData);
        newNode.prev = current.prev;
        newNode.next = current;

        if (newNode.prev != null) {
            newNode.prev.next = newNode;
        } else {
            head = newNode;
        }

        current.prev = newNode;

        return head;
    }

    // Inserting at a given position
    static Node insertPos(Node head, int newNodeData, int pos) {
        Node newNode = create(newNodeData);

        if (pos == 1) {
            newNode.next = head;
            if (head != null)
                head.prev = newNode;
            return newNode;
        }

        Node current = head;
        for (int i = 1; i < pos - 1 && current != null; i++) {
            current = current.next;
        }

        if (current == null) {
            System.out.println("The position given is out of bounds.");
            return head;
        }

        newNode.prev = current;
        newNode.next = current.next;
        current.next = newNode;

        if (newNode.next != null) {
            newNode.next.prev = newNode;
        }

        return head;
    }

    // Deleting the first node
    static Node deleteFirst(Node head) {
        if (head == null)
            return null;

        Node temp = head;
        head = head.next;

        if (head != null)
            head.prev = null;

        return head;
    }

    // Deleting the last node
    static Node deleteLast(Node head) {
        if (head == null)
            return null;

        if (head.next == null) {
            return null;
        }

        Node current = head;
        while (current.next != null) {
            current = current.next;
        }

        current.prev.next = null;
        return head;
    }

    // Deleting a node at a specific position
    static Node deletePos(Node head, int pos) {
        if (head == null)
            return head;

        Node current = head;
        for (int i = 1; current != null && i < pos; i++) {
            current = current.next;
        }

        if (current == null) {
            System.out.println("Position is out of range.");
            return head;
        }

        if (current.prev != null)
            current.prev.next = current.next;

        if (current.next != null)
            current.next.prev = current.prev;

        if (head == current)
            head = current.next;

        return head;
    }

    // Deleting a node after a specific node
    static Node deleteAfter(Node head, int key) {
        Node current = head;
        while (current != null) {
            if (current.data == key)
                break;
            current = current.next;
        }

        if (current == null || current.next == null) {
            return head;
        }

        Node ntDel = current.next;
        current.next = ntDel.next;

        if (ntDel.next != null) {
            ntDel.next.prev = current;
        }

        return head;
    }

    // Deleting a node before a specific node
    static Node deleteBefore(Node head, int key) {
        Node current = head;
        while (current != null) {
            if (current.data == key)
                break;
            current = current.next;
        }

        if (current == null || current.prev == null) {
            return head;
        }

        Node ntDel = current.prev;
        current.prev = ntDel.prev;

        if (ntDel.prev != null) {
            ntDel.prev.next = current;
        } else {
            head = current;
        }

        return head;
    }

    public static void main(String[] args) {
        Node head = create(10);
        Node secondNode = create(20);
        Node thirdNode = create(30);
        Node fourthNode = create(40);
        Node fifthNode = create(50);

        head.next = secondNode;
        secondNode.prev = head;
        secondNode.next = thirdNode;
        thirdNode.prev = secondNode;
        thirdNode.next = fourthNode;
        fourthNode.prev = thirdNode;
        fourthNode.next = fifthNode;
        fifthNode.prev = fourthNode;

        System.out.println("\nForward Traversal (Iterative)");
        forwardTraversalIterative(head);

        System.out.println("\nForward Traversal (Recursive)");
        forwardTraversalRecursive(head);

        System.out.println("\nBackward Traversal (Iterative)");
        backwardTraversalIterative(fifthNode);

        System.out.println("\nBackward Traversal (Recursive)");
        backwardTraversalRecursive(fifthNode);

        System.out.println("\nSearch Operation Ahead");

        // Key that we are searching in the linked list
        int k = 40;

        if (searchRecursive(head, k))
            System.out.println(k + " is present in the Linked List.");
        else
            System.out.println(k + " is not present in the Linked List.");

        k = 42;

        if (searchIterative(head, k))
            System.out.println(k + " is present in the Linked List.");
        else
            System.out.println(k + " is not present in the Linked List.");

        System.out.println("Length of the Linked List: " + lengthDLL(head));

        System.out.println("\nInserting a New Node at the Beginning");
        head = insertFront(head, 200);
        forwardTraversalIterative(head);

        System.out.println("\nInserting a New Node at the End");
        head = insertLast(head, 300);
        forwardTraversalIterative(head);

        System.out.println("\nInserting a New Node after a given Node");
        head = insertAfter(head, 150, 40);
        forwardTraversalIterative(head);

        System.out.println("\nInserting a New Node before a given Node");
        head = insertBefore(head, 160, 30);
        forwardTraversalIterative(head);

        System.out.println("\nInserting a New Node at a given Position");
        head = insertPos(head, 170, 2);
        forwardTraversalIterative(head);

        System.out.println("\nDeleting the First Node");
        head = deleteFirst(head);
        forwardTraversalIterative(head);

        System.out.println("\nDeleting the Last Node");
        head = deleteLast(head);
        forwardTraversalIterative(head);

        System.out.println("\nDeleting a Node after a given Node");
        head = deleteAfter(head, 40);
        forwardTraversalIterative(head);

        System.out.println("\nDeleting a Node before a given Node");
        head = deleteBefore(head, 30);
        forwardTraversalIterative(head);

        System.out.println("\nDeleting a Node at a given Position");
        head = deletePos(head, 2);
        forwardTraversalIterative(head);
    }
}
