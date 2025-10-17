#include <iostream>
#include <cstring>
using namespace std;

#define OUT 0 
#define IN 1 

// Function to count the number of words in a string
int countWords(char* str, int n) {
  if (n == 0) {
    return 0;
  }
  int wordCount = 0;
  int state = OUT; // Initial state is OUT

  // Traverse all characters of the input string
  for (int i = 0; i < n; i++) {
    // Check for backslash first
    if (str[i] == '\\') {
      i++; // Skip next character (after backslash)
      continue;
    }

    // If the current character is a word character
    if (isalnum(str[i])) {
      // If previous state was OUT, increment word count and change state to IN
      if (state == OUT) {
        wordCount++;
        state = IN;
      }
    }
    // If the current character is not a word character
    else {
      // Change state to OUT
      state = OUT;
    }
  }

  return wordCount;
}


// Driver code
int main() { 
    char str[] ="abc\\p\""; // Input string
    cout << "No of words: " << countWords(str, strlen(str)) << endl; // Count words
    return 0; 
}
// This code is contributed by kislay__kumar
