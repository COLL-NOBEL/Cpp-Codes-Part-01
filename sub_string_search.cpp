#include <iostream>
#include <cstring>
/* The below code prmpts a user to enter a string, enter a start index, enter a length for the extraction of a sub string from the string. Initially, it sets the sub string to empty, then replaces the empty substring with the desired substring value depending on the value set in length and index */
using namespace std;

void new_string(const char *source_string, char *sub_string, int start_index, int length) {
    // Check if start_index or length is out of bounds
    if (start_index < 0 || length < 0 || start_index >= strlen(source_string)) {
        cout << "Invalid start position or length." << endl;
        sub_string[0] = '\0'; // Set "sub_string" to empty string
        return;
    }

    // Adjust length if it exceeds the remaining characters
    if (start_index + length > strlen(source_string)) {
        length = strlen(source_string) - start_index;
    }

    // Copy the substring to the sub_string
    for (int i = 0; i < length; i++) {
        sub_string[i] = source_string[start_index + i];
    }
    sub_string[length] = '\0'; // Null-terminate the "sub_string" string
}

int main() {
    const int MAX_LENGTH = 100; // Imposing a maximum length for the strings
    char source_string[MAX_LENGTH];
    char sub_string[MAX_LENGTH];

    // Prompt user for input
    cout << "Enter a string: ";
    cin.getline(source_string, MAX_LENGTH);

    int start_index, length;
    cout << "Enter the starting position (0-based index): ";
    cin >> start_index;
    cout << "Enter the length of the substring: ";
    cin >> length;

    // Call the sub_string function
    new_string(source_string, sub_string, start_index, length);

    cout << "Extracted substring: " << sub_string << endl;

    return 0;
}