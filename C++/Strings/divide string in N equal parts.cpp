// C program to divide a string
// in n equal parts
#include <stdio.h>
#include <string.h>

// Function to print n equal parts of str
void divideString(char* str, int n)
{
	int str_size = strlen(str);
	int i;
	int part_size;

	// Check if string can be divided in
	// n equal parts
	if (str_size % n != 0) {
		printf("Invalid Input: String size");
		printf(" is not divisible by n");
		return;
	}

	// Calculate the size of parts to
	// find the division points
	part_size = str_size / n;
	for (i = 0; i < str_size; i++) {
		if (i % part_size == 0)
			printf("\n");
		printf("%c", str[i]);
	}
}

int main()
{
	// length of string is 28
	char* str = "a_simple_divide_string_quest";

	// Print 4 equal parts of the string
	divideString(str, 4);

	getchar();
	return 0;
}
