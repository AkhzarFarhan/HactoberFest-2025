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

    def print_list(self):
        temp = self.head
        while temp:
            print(temp.val, end=" -> ")
            temp = temp.next
        print("None")

def reverse_k_group(head, k):
    """
    Reverses nodes of the linked list in groups of k.
    If the number of nodes is not a multiple of k, 
    the remaining nodes at the end stay as is.
    """
    dummy = Node(0)
    dummy.next = head
    prev_group_end = dummy

    while True:
        kth_node = prev_group_end
        for _ in range(k):
            kth_node = kth_node.next
            if not kth_node:
                return dummy.next 

        group_start = prev_group_end.next
        next_group_start = kth_node.next

        prev, curr = next_group_start, group_start
        while curr != next_group_start:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt

        temp = prev_group_end.next
        prev_group_end.next = kth_node
        prev_group_end = temp


if __name__ == "__main__":
    ll = LinkedList()
    for val in [1, 2, 3, 4, 5, 6, 7, 8]:
        ll.append(val)

    print("Original Linked List:")
    ll.print_list()

    k = 3
    ll.head = reverse_k_group(ll.head, k)

    print(f"\nLinked List after reversing in groups of {k}:")
