#include <iostream>

using namespace std;

void to_upper() {
    // Dynamically allocate memory for the input string
    char* string = new char[1000];

    cout << "Enter a string: ";
    cin.getline(string, 1000);

    // Convert the string to uppercase
    cout << "Uppercase string: ";
    for (int i = 0; string[i] != '\0'; ++i) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = string[i] - ('a' - 'A'); // Convert to uppercase
        }
        cout << string[i]; // Print the character
    }
    cout << endl;

    // Free dynamically allocated memory
    delete[] string;
}

void to_lower() {
    char* string = new char[100];

    cout << "Enter a string: ";
    cin.getline(string, 100);

    cout << "Lowercase string: ";
    for (int i = 0; string[i] != '\0'; ++i) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = string[i] + ('a' - 'A'); // Convert to lowercase
        }
        cout << string[i]; // Print the character
    }
    cout << endl;

    // Free dynamically allocated memory
    delete[] string;
}

int main() {
    // Call the to_upper function
    to_upper();
    
    // Call the to_lower function
    to_lower();

    return 0;
}