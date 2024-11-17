#include <iostream>

using namespace std;

void copy(char* destination, const char* source) {
    while (*source != '\0') {
        *destination = *source; // Copy each string in source to the destnation
        destination++;
        source++;
    }

    *destination = '\0';  // Copy the null terminator
}