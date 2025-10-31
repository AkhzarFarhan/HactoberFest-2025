// Palindrome Partitioning:
//
// Given a string "s", partition "s" such that every substring of the partition is a palindrome.
// Return and print all possible palindrome partitioning combinations.
//
// Use backtracking to explore all possible partitions.  
// At each step, check if the current substring is a palindrome.  
// If yes, include it and recursively check for the remaining part of the string.
//
// Example:
// Input: s = "aab"
// Output:
// [a, a, b]
// [aa, b]
//
// Explanation:
// - "a|a|b" → all parts are palindromes
// - "aa|b"  → both "aa" and "b" are palindromes

#include <iostream>
#include <vector>
using namespace std;

// Utility function to check if a string is a palindrome
bool isPalindrome(string s, int start, int end)
{
    while (start < end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

// Recursive utility function for partitioning
void partitionUtil(int index, string &s, vector<string> &path, vector<vector<string>> &res)
{
    // Base case: reached end of string
    if (index == s.size())
    {
        res.push_back(path);
        return;
    }

    // Explore all possible substrings
    for (int i = index; i < s.size(); i++)
    {
        if (isPalindrome(s, index, i))
        {
            // Choose current substring
            path.push_back(s.substr(index, i - index + 1));

            // Recurse for remaining string
            partitionUtil(i + 1, s, path, res);

            // Backtrack
            path.pop_back();
        }
    }
}

// Main function to generate palindrome partitions
void partition(string s)
{
    vector<vector<string>> res;
    vector<string> path;

    partitionUtil(0, s, path, res);

    cout << "All possible palindrome partitions of \"" << s << "\":\n";
    for (auto &vec : res)
    {
        cout << "[ ";
        for (string word : vec)
            cout << word << " ";
        cout << "]\n";
    }
}

// Driver Code
int main()
{
    string s = "aab";
    partition(s);
    return 0;
}
