'''
class Node:
    def __init__(self, val=1):
        self.val = val
        self.left = None
        self.right = None
'''


def min_diff(root):
    inorder_vals = []

    def inorder(node):
        if not node:
            return
        inorder(node.left)
        inorder_vals.append(node.val)
        inorder(node.right)

    inorder(root)

    min_diff = float('inf')
    for i in range(1, len(inorder_vals)):
        diff = inorder_vals[i] - inorder_vals[i - 1]
        min_diff = min(min_diff, diff)

    return min_diff
