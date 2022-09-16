// Jeff McMillan 9-15-22 C++ Palindrome Project
// This program will take user input, filter that input to only be lowercase alphabet characters,
// then check the string against a reversed version of itself to determine whether or not
// it is a palindrome. It will print the result to the console.

#include <cstring>
#include <iostream>

using namespace std;


int main() {
	// Constants
	const char alphaboth[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const int letters = strlen(alphaboth) / 2; // should be 26.

	// cout << strlen(alphaboth) << ": " << alphaboth << endl;
	
	const int inputLimit = 81; // allow for null-terminating character after 80 characters
	
	// User input
	char rawInput[inputLimit] = { };
	cout << "Enter string: ";
	cin.get(rawInput, inputLimit);

	// cout << "Length: " << strlen(rawInput) << endl;

	// Filter the user's input using alphabet array.
	char filterInput[inputLimit] = { };
	int j = 0;
	for (int i=0;i<strlen(rawInput);i++) {
		for (int k=0;k<strlen(alphaboth);k++) {
			if (rawInput[i] == alphaboth[k]) {
				filterInput[j++] = alphaboth[k % letters]; // Append to filtered array if match is found, mod half the array because 2nd half is uppercase.
				break; // Break once match found.
			}
		}
	}

	// Create flipped copy of the array.
	char backwardsInput[inputLimit] = { };
	j = strlen(filterInput) - 1;
	for (int i=0;i<strlen(filterInput);i++) {
		backwardsInput[j-i] = filterInput[i];
	}

	// Print results
	// cout << "Filter length: " << strlen(filterInput) << endl;
	cout << filterInput << endl << backwardsInput << endl;
	int result = strcmp(filterInput, backwardsInput);
	// strcmp(...) will return 0 if strings are equal.
	if (result == 0) {
		cout << "This is a palindrome." << endl;
	} else {	
		cout << "Not a palindrome!" << endl;
	}

	return 0;
}
