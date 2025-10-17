class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, val):
        new_node = Node(val)
        if not self.head:
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node

    def create_cycle(self, pos):
        if pos == -1:
            return 
        cycle_node = None
        temp = self.head
        index = 0
        last = None
        while temp:
            if index == pos:
                cycle_node = temp
            last = temp
            temp = temp.next
            index += 1
        if last and cycle_node:
            last.next = cycle_node 


def is_cycle_found(head):
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False

if __name__ == "__main__":
    ll = LinkedList()
    for val in [1, 2, 5, -4]:
        ll.append(val)

    ll.is_cycle_found(1) 

    if has_cycle(ll.head):
        print("Cycle detected")
    else:
        print("No cycle detected")
        
