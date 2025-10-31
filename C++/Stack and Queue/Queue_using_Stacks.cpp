/*
* C++ Solution for "Implement Queue using Stacks" (LeetCode 232)
*
* Problem: Implement a first in first out (FIFO) queue 
* using only two stacks. The implemented queue should 
* support all the functions of a normal queue (push, pop, peek, empty).
*
* This solution uses two stacks, s1 and s2.
* - 'push' is O(1) by pushing to s1.
* - 'pop' and 'peek' are Amortized O(1).
*
* Contributor: Priyanka Anand
* Submitted for Hacktoberfest 2025
*/

#include <iostream>
#include <stack>

class MyQueue {
private:
    std::stack<int> s1; // For push operations
    std::stack<int> s2; // For pop/peek operations

public:
    MyQueue() {
        // Constructor
    }

    // Push element x to the back of the queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from the front of the queue and returns it.
    int pop() {
        // Ensure s2 has the correct front element
        peek(); 
        int front = s2.top();
        s2.pop();
        return front;
    }

    // Get the front element.
    int peek() {
        // If s2 is empty, move all elements from s1 to s2
        // This reverses the order, so s1's bottom is now s2's top
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    // Returns whether the queue is empty.
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

// Main function to test the implementation
int main() {
    MyQueue q;
    q.push(1);
    q.push(2);

    std::cout << "Front element is: " << q.peek() << std::endl; // Expected: 1

    std::cout << "Popped element: " << q.pop() << std::endl; // Expected: 1

    q.push(3);

    std::cout << "Front element is: " << q.peek() << std::endl; // Expected: 2

    std::cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << std::endl; // Expected: No

    std::cout << "Popped element: " << q.pop() << std::endl; // Expected: 2
    std::cout << "Popped element: " << q.pop() << std::endl; // Expected: 3

    std::cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << std::endl; // Expected: Yes

    return 0;
}