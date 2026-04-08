class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
        self.size += 1

    def insert_at_end(self, data):
        new_node = Node(data)

        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node

        self.size += 1

    def insert_at_position(self, data, position):
        if position < 0 or position > self.size:
            raise IndexError("Position out of range")

        if position == 0:
            self.insert_at_beginning(data)
            return

        new_node = Node(data)
        current = self.head

        for _ in range(position - 1):
            current = current.next

        new_node.next = current.next
        current.next = new_node
        self.size += 1

    def delete_from_beginning(self):
        if not self.head:
            raise IndexError("List is empty")

        self.head = self.head.next
        self.size -= 1

    def delete_from_end(self):
        if not self.head:
            raise IndexError("List is empty")

        if not self.head.next:
            self.head = None
        else:
            current = self.head
            while current.next.next:
                current = current.next
            current.next = None

        self.size -= 1

    def delete_by_value(self, data):
        if not self.head:
            raise IndexError("List is empty")

        # If head contains the value
        if self.head.data == data:
            self.head = self.head.next
            self.size -= 1
            return

        current = self.head

        while current.next:
            if current.next.data == data:
                current.next = current.next.next
                self.size -= 1
                return
            current = current.next

        raise ValueError("Value not found")

    def search(self, data):
        current = self.head
        while current:
            if current.data == data:
                return True
            current = current.next
        return False

    def reverse(self):
        prev = None
        current = self.head

        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node

        self.head = prev

    def __len__(self):
        return self.size

    def __iter__(self):
        current = self.head
        while current:
            yield current.data
            current = current.next

    def __str__(self):
        return " -> ".join(map(str, self)) + " -> None"


# Example usage
ll = LinkedList()
ll.insert_at_end(10)
ll.insert_at_end(20)
ll.insert_at_beginning(5)
ll.insert_at_position(15, 2)

print(ll)          # 5 -> 10 -> 15 -> 20 -> None

ll.reverse()
print(ll)          # 20 -> 15 -> 10 -> 5 -> None

print(len(ll))     # 4

ll.delete_by_value(15)
print(ll)          # 20 -> 10 -> 5 -> None