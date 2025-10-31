/*Generate Balanced Parentheses:

Given an integer N representing the number of pairs of parentheses,
generate and print all possible valid combinations of balanced parentheses.

A valid parentheses string is one where every opening '(' has a corresponding
closing ')' and parentheses are properly nested.

Use backtracking to build all combinations by keeping track of the count of
open and close brackets used so far.

Constraints:
- You can only add '(' if the count of '(' is less than N.
- You can only add ')' if the count of ')' is less than the count of '('.

Example:
Input: N = 3
Output:
((()))
(()())
(())()
()(())
()()()*/

#include <iostream>
#include <string>
#include <vector>

void generateParenthesisUtil(std::vector<std::string>& result, std::string& currentString, int open, int close, int n) {
    // Base case: if the string is complete
    if (currentString.length() == 2 * n) {
        result.push_back(currentString);
        return;
    }

    // Recursive case for adding an opening bracket
    if (open < n) {
        currentString.push_back('(');
        generateParenthesisUtil(result, currentString, open + 1, close, n);
        currentString.pop_back(); // Backtrack
    }

    // Recursive case for adding a closing bracket
    if (close < open) {
        currentString.push_back(')');
        generateParenthesisUtil(result, currentString, open, close + 1, n);
        currentString.pop_back(); // Backtrack
    }
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    std::string currentString = "";
    generateParenthesisUtil(result, currentString, 0, 0, n);
    return result;
}

int main() {
    int n = 3;
    std::cout << "All combinations of balanced parentheses for n = " << n << ":\n";
    
    std::vector<std::string> combinations = generateParenthesis(n);
    
    for (const std::string& s : combinations) {
        std::cout << s << std::endl;
    }

    return 0;
}
