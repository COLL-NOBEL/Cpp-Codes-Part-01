#include <iostream>

using namespace std;

void concat(char* destination, const char* source) {
    // Find the end of the destination string
    while (*destination != '\0') {
        destination++;
    }

    // Copy the source string to the end of the destination
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;

    }

    // Add the null terminator to the end of the concatenated string
    *destination = '\0';
}