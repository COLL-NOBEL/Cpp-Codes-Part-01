#include <iostream>
#include <cstring>
/* The below code prmpts a user to enter a string, and a character they want o remove from the string, then replaces the character with a whitespace */
using namespace std;

void delete_char(char *my_string, char my_char) {
    // Loop through the String
    for (size_t i = 0; i < strlen(my_string); ++i) {
        // If the current character matches the character to remove
        if (my_string[i] == my_char) {
            my_string[i] = ' '; // Replace it with a space
        }
    }
}

int main() {
    // The input string must contain a maximum of 100 characters
    const int MAX_LENGTH = 100;
    char input_string[MAX_LENGTH];

    // Prompt the user for input
    cout << "Enter a String: ";
    cin.getline(input_string, MAX_LENGTH);

    // Prompt the user for the character to delete
    char char_to_delete;
    cout << "Enter a character to delete: ";
    cin >> char_to_delete;

    // Call the delete_char function
    delete_char(input_string, char_to_delete);

    // Output the modified my_string
    cout << "Modified my_string: " << input_string << endl;

    return 0;
}