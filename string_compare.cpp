#include <iostream>

using namespace std;

int compare(const char* string_1, const char* string_2) {
    // Compare characters until the end of one string is reached
    while (*string_1 != '\0' && *string_2 != '\0') {
        if (*string_1 < *string_2) {
            return -1; // string_1 is smaller
        } else if (*string_1 > *string_2) {
            return 1;  // string_1 is greater
        }
        string_1++;
        string_2++;
    }
    // If one string ends before the other
    if (*string_1 == '\0' && *string_2 == '\0') {
        return 0; // Both strings are equal
    } else if (*string_1 == '\0') {
        return -1; // string_1 is smaller
    } else {
        return 1;  // string_1 is greater
    }
}

int main() {
    char string_1[100], string_2[100];

    // Prompt the user for input
    cout << "Enter the first string: ";
    cin >> string_1;
    cout << "Enter the second string: ";
    cin >> string_2;

    // Compare the strings and store the result
    int result = compare(string_1, string_2);

    // Output the result
    if (result == 0) {
        cout << "Both strings are equal." << endl;
    } else if (result < 0) {
        cout << result  << "    The first string is smaller than the second string." << endl;
    } else {
        cout << result  << "    The first string is greater than the second string." << endl;
    }

    return 0;
}