/*

LEETCODE PROBLEM 641 IMPLEMENTED

*/

#include <vector>
using namespace std;

class MyCircularDeque {
public:
    int maxSize;          // Maximum size of the deque
    vector<int> dq;      // Vector to store the elements of the deque
    int front;           // Index of the front element
    int rear;            // Index of the rear element

    // Constructor to initialize the deque with size k
    MyCircularDeque(int k) {
        front = -1;      // Initialize front index as -1 (indicating empty)
        rear = -1;       // Initialize rear index as -1 (indicating empty)
        maxSize = k;     // Set maximum size
        dq.resize(maxSize); // Resize the vector to hold maxSize elements
    }
    
    // Function to insert an element at the front
    bool insertFront(int value) {
        if (isFull()) {
            return false; // Return false if the deque is full
        } else if (front == -1) {
            // If the deque is empty, set front and rear to 0 and insert the value
            front = 0;
            rear = 0;
            dq[front] = value; // Insert value at the front
            return true; // Insertion successful
        } else {
            // Move front index backward and insert the value
            front = (front + 1) % maxSize; // Wrap around if necessary
            dq[front] = value; // Insert value at the new front
            return true; // Insertion successful
        }
    }
    
    // Function to insert an element at the rear
    bool insertLast(int value) {
        if (isFull()) {
            return false; // Return false if the deque is full
        } else if (rear == -1) {
            // If the deque is empty, set front and rear to 0 and insert the value
            front = 0;
            rear = 0;
            dq[rear] = value; // Insert value at the rear
            return true; // Insertion successful
        } else {
            // Move rear index backward and insert the value
            rear = (rear - 1 + maxSize) % maxSize; // Wrap around if necessary
            dq[rear] = value; // Insert value at the new rear
            return true; // Insertion successful
        }
    }
    
    // Function to delete the front element
    bool deleteFront() {
        if (isEmpty()) {
            return false; // Return false if the deque is empty
        } else if (front == rear) {
            // If there's only one element, reset front and rear
            front = -1;
            rear = -1;
            return true; // Deletion successful
        } else {
            // Move front index backward
            front = (front - 1 + maxSize) % maxSize; // Wrap around if necessary
            return true; // Deletion successful
        }
    }
    
    // Function to delete the last element
    bool deleteLast() {
        if (isEmpty()) {
            return false; // Return false if the deque is empty
        } else if (rear == front) {
            // If there's only one element, reset front and rear
            front = -1;
            rear = -1;
            return true; // Deletion successful
        } else {
            // Move rear index forward
            rear = (rear + 1) % maxSize; // Wrap around if necessary
            return true; // Deletion successful
        }
    }
    
    // Function to get the front element
    int getFront() {
        if (isEmpty()) {
            return -1; // Return -1 if the deque is empty
        } else {
            return dq[front]; // Return the front element
        }
    }
    
    // Function to get the last element
    int getRear() {
        if (isEmpty()) {
            return -1; // Return -1 if the deque is empty
        } else {
            return dq[rear]; // Return the rear element
        }
    }
    
    // Function to check if the deque is empty
    bool isEmpty() {
        return rear == -1; // Return true if rear is -1 (indicating empty)
    }
    
    // Function to check if the deque is full
    bool isFull() {
        return (front + 1) % maxSize == rear; // Return true if next front position equals rear
    }
};
