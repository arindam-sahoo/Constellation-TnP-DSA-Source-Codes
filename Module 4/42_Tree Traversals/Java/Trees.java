class Node {
    int data;
    Node left, right;

    public Node(int data) {
        this.data = data;
        left = right = null;
    }
}

public class Trees {
    // Function for creating a New Node
    public static Node create(int data) {
        return new Node(data);
    }

    // Function for inserting a Left Child
    public static Node insL(Node parent, int data) {
        parent.left = create(data);
        return parent.left;
    }

    // Function for inserting a Right Child
    public static Node insR(Node parent, int data) {
        parent.right = create(data);
        return parent.right;
    }

    // Preorder Traversal
    public static void PreorderTraversal(Node root) {
        if (root == null)
            return;
        System.out.print(root.data + " ");   // root
        PreorderTraversal(root.left);        // left
        PreorderTraversal(root.right);       // right
    }

    // Inorder Traversal
    public static void InorderTraversal(Node root) {
        if (root == null)
            return;
        InorderTraversal(root.left);         // left
        System.out.print(root.data + " ");   // root
        InorderTraversal(root.right);        // right
    }

    // Postorder Traversal
    public static void PostorderTraversal(Node root) {
        if (root == null)
            return;
        PostorderTraversal(root.left);       // left
        PostorderTraversal(root.right);      // right
        System.out.print(root.data + " ");   // root
    }

    // Searching the Node
    public static Node search(Node root, int v) {
        if (root == null || root.data == v) {
            return root;
        }

        Node leftRes = search(root.left, v);
        if (leftRes != null)
            return leftRes;

        return search(root.right, v);
    }

    // Searching the Node in Binary Search Tree
    public static Node Bsearch(Node root, int v) {
        if (root == null || root.data == v) {
            return root;
        } else if (v < root.data) {
            Node leftRes = search(root.left, v);
            if (leftRes != null)
                return leftRes;
        }
        return search(root.right, v);
    }

    public static void main(String[] args) {
        Node root = create(40);
        insL(root, 20);
        insR(root, 60);
        insL(root.left, 10);
        insR(root.left, 30);
        insL(root.right, 50);
        insR(root.right, 70);

        System.out.println("Traversing the Tree");
        System.out.print("Preorder Traversal : ");
        PreorderTraversal(root);
        System.out.print("\nInorder Traversal : ");
        InorderTraversal(root);
        System.out.print("\nPostorder Traversal : ");
        PostorderTraversal(root);

        int value = 50;
        // Node r = search(root, value);
        Node r = Bsearch(root, value);
        if (r != null)
            System.out.println("\nThe node value " + value + " is there in the tree.");
        else
            System.out.println("\nThe node value " + value + " is not there in the tree.");
    }
}
