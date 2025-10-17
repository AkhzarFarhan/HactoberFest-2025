#include <iostream>
using namespace std;

bool isSneaky(int num) {
    // Define the condition for a number to be "sneaky" 
    // (e.g., a number with unique digits, sum of digits = 10, etc.)
    // Replace with actual condition based on problem statement
    int sum = 0, n = num;
    bool digits[10] = {false};
    
    while (n > 0) {
        int digit = n % 10;
        if (digits[digit]) return false; // If digit repeats, it's not sneaky
        digits[digit] = true;
        sum += digit;
        n /= 10;
    }
    return sum == 10; // Example condition
}

int main() {
    int limit = 100; // Set appropriate limit based on problem constraints

    cout << "The two sneaky numbers in Digitville are:" << endl;

    // Finding two sneaky numbers
    for (int i = 10; i < limit; i++) {
        for (int j = i + 1; j < limit; j++) {
            if (isSneaky(i) && isSneaky(j)) {
                cout << i << " and " << j << endl;
                return 0;
            }
        }
    }

    cout << "No sneaky numbers found in given range." << endl;
    return 0;
}
