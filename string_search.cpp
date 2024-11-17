#include <iostream>

using namespace std;

char* search(const char* string, char charac) {
    // Loop through the string to find the character
    while (*string != '\0') {
        if (*string == charac) {
            return (char*)string; // Return the position of the first occurrence
        }
        string++;
    }
    return NULL; // Character not found
}

int main() {
    char* string = new char[100]; // You can adjust the size as needed

    // Prompt the user for input
    cout << "Enter a string: ";
    cin.getline(string, 100); // Read the string including spaces

    char charac;
    cout << "Enter the character to search for: ";
    cin >> charac;

    // Search for the character in the string
    char* position = search(string, charac);

    if (position != NULL) {
        cout << "The character '" << charac << "' found at position: " << (position - string) << endl;
    } else {
        cout << "NULL   --The character '" << charac   << position  << "' was not found in the string--"  << endl;
    }

    // Free dynamically allocated memory
    delete[] string;

    return 0;
}