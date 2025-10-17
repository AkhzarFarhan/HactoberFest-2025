class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def get_intersection_node(headA, headB):
    """
    If two linked lists intersect, return the node where they intersect.
    Otherwise, return None.
    """
    if not headA or not headB:
        return None

    a, b = headA, headB

    while a != b:
        a = a.next if a else headB
        b = b.next if b else headA

    return a


def print_list(head):
    temp = head
    while temp:
        print(temp.val, end=" -> ")
        temp = temp.next
    print("None")


if __name__ == "__main__":

    intersect_node = Node(2)
    intersect_node.next = Node(4)

    headA = Node(1)
    headA.next = Node(9)
    headA.next.next = Node(1)
    headA.next.next.next = intersect_node
https://github.com/learnsomethingtoday/Simple-DSA/tree/main
    headB = Node(3)
    headB.next = intersect_node 

    print("List A:")
    print_list(headA)
    print("List B:")
    print_list(headB)

    intersection = get_intersection_node(headA, headB)
    if intersection:
        print(f" Intersection found at node with value: {intersection.val}")
    else:
        print(" No intersection found.")
