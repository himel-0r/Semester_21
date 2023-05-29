class AVLNode():
    def __init__(self, value):
        # Variable identity:
        #   value -> int    : keeps the values of the node
        #   left -> *point  : left subtree of the AVL tree
        #   right -> *point : right subtree of the AVL tree
        #   height -> int   : height of the node (maximum distance of a node and its children)
        self.value = value
        self.left = None
        self.right = None
        self.height = 1


class AVL():
    def __init__(self):
        # Variable identity:
        #   root -> *point  : the root of the AVL tree
        self.root = None
    
    def __init__(self, list=None):
        self.root = None
        if list is not None:
            for el in list:
                self.add_element(el)

    def add_element(self, value):
        self.root = self._add_element(self.root, value)

    def remove_element(self, value):
        self.root = self._remove_element(self.root, value)

    def _remove_element(self, root, key):
        # Step 1 - Perform standard BST delete
        if not root:
            return root

        elif key < root.value:
            root.left = self._remove_element(root.left, key)

        elif key > root.value:
            root.right = self._remove_element(root.right, key)

        else:
            if root.left is None:
                temp = root.right
                root = None
                return temp

            elif root.right is None:
                temp = root.left
                root = None
                return temp

            temp = self.getMinValueNode(root.right)
            root.value = temp.value
            root.right = self._remove_element(root.right, temp.value)

        # If the tree has only one node, simply return it
        if root is None:
            return root

        # Step 2 - Balance the tree and return the root
        return self._balance(root)

    def _add_element(self, node, value):
        # Step 1 - Add the new element
        if not node:
            return AVLNode(value)
        elif value < node.value:
            node.left = self._add_element(node.left, value)
        else:
            node.right = self._add_element(node.right, value)
        # Step 2 - Balance the AVL tree and return the root
        return self._balance(node)

    def _balance(self, node):
        # calculate the height of all nodes.
        self.refresh_height(node)

        # Get the balance factor
        balance = self.get_balance(node)

        # If the node is unbalanced, then try out the 4 cases
        # From slides, understand why and how these rotation works
        
        # Case 1 - Left Left
        if balance > 1 and self.get_balance(node.left) >= 0:
            return self.rRotate(node)

        # Case 2 - Right Right
        if balance < -1 and self.get_balance(node.right) <= 0:
            return self.lRotate(node)

        # Case 3 - Left Right
        if balance > 1 and self.get_balance(node.left) < 0:
            node.left = self.lRotate(node.left)
            return self.rRotate(node)

        # Case 4 - Right Left
        if balance < -1 and self.get_balance(node.right) > 0:
            node.right = self.rRotate(node.right)
            return self.lRotate(node)

        return node

    def lRotate(self, node):
        node_right = node.right if node else None

        if node_right:
            node_right_left = node_right.left if node_right else None
            node_right.left = node
            node.right = node_right_left

        self.refresh_height(node)
        self.refresh_height(node_right)

        return node_right

    def rRotate(self, node):
        node_left = node.left if node else None

        if node_left:
            node_left_right = node_left.right
            node_left.right = node
            node.left = node_left_right

        self.refresh_height(node)
        self.refresh_height(node_left)

        return node_left

    def refresh_height(self, node):
        # Calculating the heights of all nodes
        # Complexity: O(n)
        # why taking the max? YouKnowWhy :)
        if node:
            node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))

    def get_height(self, node):
        if node is None:
            return 0
        return node.height

    def get_balance(self, node):
        # The definition of "Balance Factor" says everything 
        if node is None:
            return 0
        return self.get_height(node.left) - self.get_height(node.right)

    def getMinValueNode(self, root):
        if root is None or root.left is None:
            return root

        return self.getMinValueNode(root.left)


# avl = AVL()
# coll = tools.generate_collection(40)
# for i in coll:
# 	avl.add_element(i)
# avl.show()
# for i in coll[:10]:
# 	avl.remove_element(i)
# avl.show()
