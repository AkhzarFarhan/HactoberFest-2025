// C++ program to find the longest palindromic substring in a given string.
#include <iostream>
using namespace std;

string longestPalin(string s) {
	// Initialize variables to keep track of the 
	// longest palindrome and its length.
	int count = -1;
	string ans = "";

	// Get the length of the input string.
	int n = s.length();

	// Create a boolean 2D array to store palindrome information.
	bool dp[n][n];

	// Iterate through different substring lengths.
	for (int g = 0; g < n; g++) {
		for (int i = 0, j = g; j < n; i++, j++) {
			// Check if the substring is of length 1 (base case).
			if (g == 0) {
				dp[i][j] = true;
			} else if (g == 1) {
				// Check if the substring is of length 2 (base case).
				dp[i][j] = (s[i] == s[j]);
			} else {
				// Check if the current substring is a 
				// palindrome based on its ends.
				dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
			}

			// Update the longest palindrome and its length if found.
			if (dp[i][j] && count < j - i + 1) {
				ans = s.substr(i, j - i + 1);
				count = ans.length();
			}
		}
	}
	return ans;
}

int main() {
	// Input string
	string str = "forgeeksskeegfor";
	
	// Print the longest palindromic substring.
	cout << longestPalin(str) << endl;
	return 0;
}
