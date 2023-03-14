class Treenode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, val):
        if not self.root:
            self.root = Treenode(val)
        else:
            self._insert(val, self.root)

    def _insert(self, val, node):
        if val < node.val:
            if node.left:
                self._insert(val, node.left)
            else:
                node.left = Treenode(val)
        else:
            if node.right:
                self._insert(val, node.right)
            else:
                node.right = Treenode(val)
    
    def search(self, val):
        return self._search(val, self.root)
    
    def _search(self, val, node):
        if not node:
            return False
        elif node.val == val:
            return True
        elif val < node.val:
            return self._search(val, node.left)
        else:
            return self._search(val, node.right)
        
    def findPosition(self, val):
        if self.root.val == val:
            return self.root
        else:
            return self._findPosition(val, self.root)
        
    def _findPosition(self, val, node):
        if not node:
            return None
        elif node.val == val:
            return node
        elif val < node.val:
            return self._findPosition(val, node.left)
        else:
            return self._findPosition(val, node.right)
        
    def _find_min (self, node):
        while node.left:
            node = node.left
        return node
    
    def _find_max (self, node):
        while node.right:
            node = node.right
        return node
    
    def delete (self, val):
        self.root = self._delete (val, self.root)
        
    def _delete (self, val, node):
        if not node:
            return node
        
        if val < node.val:
            node.left = self._delete(val, node.left)
        elif val > node.val:
            node.right = self._delete(val, node.right)
        else:
            # Case 1: No children
            if not node.left and not node.right:
                node = None
            # Case 2: One child
            elif not node.right:
                node = node.right
            elif not node.left:
                node = node.left
            # Case 3: Two children
            else:
                successor = self._find_min(node.right)
                node.val = successor.val
                node.right = self._delete(successor.val, node.right)
                # predecessor = self._find_max(node.left)
                # node.val = predecessor.val
                # node.left = self._delete(predecessor.val, node.left)
        return node
    
    # Traversal Functions
    def inorder(self):
        self._inorder(self.root)
    
    def _inorder (self, node):
        if node.left:
            self._inorder(node.left)
        print(node.val)
        if self.right:
            self._inorder(node.right)
            
    def preorder(self):
        self._preorder(self.root)
        
    def _preorder (self, node):
        print(node.val)
        if node.left:
            self._preorder(node.left)
        if node.right:
            self._preorder(node.right)
            
    def postorder(self):
        self._postorder(self.root)
        
    def _postorder(self, node):
        if node.left:
            self._postorder(node.left)
        if node.right:
            self._postorder(node.right)
        print(node.val)