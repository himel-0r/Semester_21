class DoublyNode:
    def __init__(self, data=None, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev


class DoublyLL:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_front(self, data):
        new_node = DoublyNode(data, self.head, None)
        if self.head:
            self.head.prev = new_node
        self.head = new_node
        if not self.tail:
            self.tail = self.head

    def insert_back(self, data):
        new_node = DoublyNode(data, None, self.tail)
        if self.tail:
            self.tail.next = new_node
        self.tail = new_node
        if not self.head:
            self.head = self.tail

    def insert_middle(self, data, position):
        new_node = DoublyNode(data)
        current = self.head
        for i in range(position - 1):
            current = current.next
            if current is None:
                return
        new_node.next = current.next
        new_node.prev = current
        if current.next:
            current.next.prev = new_node
        current.next = new_node

    def display(self):
        current = self.head
        while current.next:
            print(current.data, end=" ")
            current = current.next

    def delete_front(self):
        if self.head is None:
            return
        if self.head.next is None:
            self.head = None
            self.tail = None
            return
        self.head = self.head.next
        self.head.prev = None

    def delete_back(self):
        if self.head is None:
            return
        if self.head.next is None:
            self.head = None
            self.tail = None
            return
        self.tail = self.tail.prev
        self.tail.next = None

    def delete_at_pos(self, position):
        if position == 0:
            self.delete_front()
            return
        current = self.head
        for i in range(position - 1):
            current = current.next
        current.next = current.next.next
        current.next.prev = current


# Driver code
dll = DoublyLL()
dll.insert_front(23)
dll.display()