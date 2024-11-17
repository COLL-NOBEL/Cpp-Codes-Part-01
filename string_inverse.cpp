#include <iostream>

using namespace std;

void inverse() {
    // Dynamically allocate memory for the input string
    char* string = new char[100]; // You can adjust the size as needed

    // Prompt the user for input
    cout << "Enter a string: ";
    cin.getline(string, 100); // Read the string including spaces

    // Find the length of the string manually
    int length = 0;
    while (string[length] != '\0') {
        length++; // Increment length until the null terminator is found
    }

    // Inverse the string
    cout << "Inverted string: ";
    for (int i = length - 1; i >= 0; --i) {
        cout << string[i]; // Print characters in reverse order
    }
    cout << endl;

    // Free dynamically allocated memory
    delete[] string;
}

int main() {
    inverse(); // Call the inverse function
    return 0;
}