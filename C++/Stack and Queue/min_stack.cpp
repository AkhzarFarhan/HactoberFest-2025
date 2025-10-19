/*
Author: Mujeeb Arshad
Program: Min_stack
Purpose: Hacktoberfest 2025 contribution
*/
#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> mainStack;
    stack<int> minStack; // Keeps track of minimum values

public:
    void push(int value)
    {
        mainStack.push(value);
        if (minStack.empty() || value <= minStack.top())
        {
            minStack.push(value);
        }
    }

    void pop()
    {
        if (mainStack.empty())
        {
            cout << "Stack is empty!\n";
            return;
        }
        if (mainStack.top() == minStack.top())
        {
            minStack.pop();
        }
        cout << mainStack.top() << " popped from stack\n";
        mainStack.pop();
    }

    int top()
    {
        if (mainStack.empty())
        {
            cout << "Stack is empty!\n";
            return -1;
        }
        return mainStack.top();
    }

    int getMin()
    {
        if (minStack.empty())
        {
            cout << "Stack is empty!\n";
            return -1;
        }
        return minStack.top();
    }

    bool isEmpty()
    {
        return mainStack.empty();
    }
};

int main()
{
    MinStack s;
    s.push(5);
    s.push(2);
    s.push(8);
    s.push(1);

    cout << "Current Min: " << s.getMin() << endl; // 1
    s.pop();
    cout << "Current Min: " << s.getMin() << endl; // 2
    s.pop();
    cout << "Top Element: " << s.top() << endl;    // 2
    cout << "Current Min: " << s.getMin() << endl; // 2

    return 0;
}
