class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def insert_at_beginning(self, data):
        """Insert a node at the beginning of the list."""
        if data is None:
            raise ValueError("Data cannot be None")
        new_node = Node(data)
        if self.head:
            new_node.next = self.head
            self.head = new_node
        else:
            self.head = new_node
            self.tail = new_node
        self.size += 1

    def insert_at_end(self, data):
        """Insert a node at the end of the list."""
        if data is None:
            raise ValueError("Data cannot be None")
        new_node = Node(data)
        if self.head:
            self.tail.next = new_node
            self.tail = new_node
        else:
            self.head = new_node
            self.tail = new_node
        self.size += 1

    def insert_at_position(self, data, position):
        """Insert a node at a specific position."""
        if data is None:
            raise ValueError("Data cannot be None")
        if position < 0 or position > self.size:
            raise IndexError("Position out of range")
        if position == 0:
            self.insert_at_beginning(data)
        elif position == self.size:
            self.insert_at_end(data)
        else:
            new_node = Node(data)
            current = self.head
            for _ in range(position - 1):
                current = current.next
            new_node.next = current.next
            current.next = new_node
            self.size += 1

    def delete_from_beginning(self):
        """Delete the node at the beginning of the list."""
        if not self.head:
            raise IndexError("List is empty")
        data = self.head.data
        self.head = self.head.next
        if not self.head:
            self.tail = None
        self.size -= 1
        return data

    def delete_from_end(self):
        """Delete the node at the end of the list."""
        if not self.head:
            raise IndexError("List is empty")
        if self.head == self.tail:
            data = self.head.data
            self.head = self.tail = None
        else:
            current = self.head
            while current.next != self.tail:
                current = current.next
            data = self.tail.data
            current.next = None
            self.tail = current
        self.size -= 1
        return data

    def delete_by_value(self, data):
        """Delete the first node with the given value."""
        if not self.head:
            raise IndexError("List is empty")
        if self.head.data == data:
            return self.delete_from_beginning()
        current = self.head
        while current.next:
            if current.next.data == data:
                deleted_data = current.next.data
                current.next = current.next.next
                if not current.next:
                    self.tail = current
                self.size -= 1
                return deleted_data
            current = current.next
        raise ValueError("Value not found in the list")

    def search(self, data):
        """Search for a node with the given data."""
        current = self.head
        while current:
            if current.data == data:
                return True
            current = current.next
        return False

    def reverse(self):
        """Reverse the linked list."""
        prev = None
        current = self.head
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        self.head, self.tail = self.tail, self.head

    def __iter__(self):
        """Make the linked list iterable."""
        current = self.head
        while current:
            yield current.data
            current = current.next

    def __str__(self):
        """Return a string representation of the linked list."""
        return " -> ".join(map(str, self)) + " -> None"

    def __len__(self):
        """Return the size of the linked list."""
        return self.size

# Example:
ll = LinkedList()
ll.insert_at_end(10)
ll.insert_at_end(20)
ll.insert_at_beginning(5)
ll.insert_at_position(15, 2)
print(ll)  # Output: 5 -> 10 -> 15 -> 20 -> None
ll.reverse()
print(ll)  # Output: 20 -> 15 -> 10 -> 5 -> None
print(len(ll))  # Output: 4
ll.delete_by_value(15)
print(ll)  # Output: 20 -> 10 -> 5 -> None