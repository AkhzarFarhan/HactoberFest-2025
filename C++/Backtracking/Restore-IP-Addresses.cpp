// Restore IP Addresses:
//
// Given a string s containing only digits, return all possible valid IP addresses
// that can be formed by inserting dots ('.') into s.
//
// A valid IP address consists of exactly four integers (each between 0 and 255),
// separated by single dots, with no leading zeros (except for "0" itself).
//
// Use backtracking to generate all combinations by placing dots and validating each segment.
//
// Example:
// Input: s = "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]
//
// Explanation:
// Possible placements of dots are checked recursively ensuring
// each segment is a valid number (0–255) and formatted correctly.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if a segment is a valid IP part
bool isValid(const string &segment)
{
    if (segment.empty() || segment.size() > 3)
        return false;
    if (segment[0] == '0' && segment.size() > 1)
        return false; // leading zero
    int val = stoi(segment);
    return val >= 0 && val <= 255;
}

// Backtracking function to generate IPs
void backtrack(string &s, int start, int dots, string current, vector<string> &result)
{
    if (dots == 3)
    {
        string last = s.substr(start);
        if (isValid(last))
            result.push_back(current + last);
        return;
    }

    for (int len = 1; len <= 3 && start + len < s.size(); len++)
    {
        string part = s.substr(start, len);
        if (isValid(part))
            backtrack(s, start + len, dots + 1, current + part + ".", result);
    }
}

// Function to restore IP addresses
vector<string> restoreIpAddresses(string s)
{
    vector<string> result;
    backtrack(s, 0, 0, "", result);
    return result;
}

// Driver Code
int main()
{
    string s = "25525511135";
    vector<string> ips = restoreIpAddresses(s);

    cout << "Valid IP Addresses:\n";
    for (auto &ip : ips)
        cout << ip << endl;

    return 0;
}
