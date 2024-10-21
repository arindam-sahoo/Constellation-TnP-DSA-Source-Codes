class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Function for creating a New Node
def create(data):
    return Node(data)

# Function for inserting a Left Child
def insL(parent, data):
    parent.left = create(data)
    return parent.left

# Function for inserting a Right Child
def insR(parent, data):
    parent.right = create(data)
    return parent.right

# Preorder Traversal
def PreorderTraversal(root):
    if root is None:
        return
    print(root.data, end=" ")   # root
    PreorderTraversal(root.left)  # left
    PreorderTraversal(root.right) # right

# Inorder Traversal
def InorderTraversal(root):
    if root is None:
        return
    InorderTraversal(root.left)   # left
    print(root.data, end=" ")     # root
    InorderTraversal(root.right)  # right

# Postorder Traversal
def PostorderTraversal(root):
    if root is None:
        return
    PostorderTraversal(root.left)  # left
    PostorderTraversal(root.right) # right
    print(root.data, end=" ")      # root

# Searching the Node
def search(root, v):
    if root is None or root.data == v:
        return root

    leftRes = search(root.left, v)
    if leftRes is not None:
        return leftRes

    return search(root.right, v)

# Searching the Node in Binary Search Tree
def Bsearch(root, v):
    if root is None or root.data == v:
        return root
    elif v < root.data:
        leftRes = search(root.left, v)
        if leftRes is not None:
            return leftRes
    return search(root.right, v)

if __name__ == "__main__":
    root = create(40)
    insL(root, 20)
    insR(root, 60)
    insL(root.left, 10)
    insR(root.left, 30)
    insL(root.right, 50)
    insR(root.right, 70)

    print("Traversing the Tree")
    print("\nPreorder Traversal : ", end="")
    PreorderTraversal(root)
    print("\nInorder Traversal : ", end="")
    InorderTraversal(root)
    print("\nPostorder Traversal : ", end="")
    PostorderTraversal(root)

    value = 50
    # r = search(root, value)
    r = Bsearch(root, value)
    if r is not None:
        print(f"\nThe node value {value} is there in the tree.")
    else:
       
