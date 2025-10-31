// Doubly Linked List Implementation in Java

class Node {
    int data;
    Node prev, next;

    Node(int data) {
        this.data = data;
        prev = null;
        next = null;
    }
}

class DoublyLinkedList {
    Node head;

    // Insert at the end
    void append(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node last = head;
        while (last.next != null)
            last = last.next;

        last.next = newNode;
        newNode.prev = last;
    }

    // Insert at the front
    void push(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        if (head != null)
            head.prev = newNode;
        head = newNode;
    }

    // Delete a node by value
    void delete(int key) {
        Node temp = head;
        while (temp != null && temp.data != key)
            temp = temp.next;
        if (temp == null)
            return; // Not found

        if (temp.prev != null)
            temp.prev.next = temp.next;
        else
            head = temp.next;
        if (temp.next != null)
            temp.next.prev = temp.prev;
    }

    // Print the list
    void printList() {
        Node temp = head;
        System.out.print("Doubly Linked List: ");
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        DoublyLinkedList dll = new DoublyLinkedList();
        dll.append(10);
        dll.push(20); // Add to front
        dll.append(30);
        dll.printList();

        dll.delete(20);
        dll.printList();
    }
}
