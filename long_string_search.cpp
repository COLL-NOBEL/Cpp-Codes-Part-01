#include <iostream>

using namespace std;

char word_search() {
    char* phrase = new char[1000];
    char* word = new char[50]; 

    // Prompt the user for input
    cout << "Enter a phrase: ";
    cin.getline(phrase, 1000);

    cout << "Enter a word to search for: ";
    cin.getline(word, 50);

    int position = -1;

    // Calculate the length of the word manually
    int word_length = 0;
    while (word[word_length] != '\0') {
        word_length++;
    }

    // Search for the complete word in the phrase
    for (int i = 0; phrase[i] != '\0'; ++i) {
        bool match = true;
        for (int j = 0; j < word_length; ++j) {

            if (phrase[i + j] != word[j]) {
                match = false;
                break;
            }
        }
        
        // If a match is found, check the boundary and set position
        if (match && (phrase[i + word_length] == ' ' || phrase[i + word_length] == '\0')) {
            position = i;
            break;
        }
    }

    // Output the result
    if (position != -1) {
        cout << "The word '" << word << "' first occurs at position: " << position << endl;
    } else {
        cout << "The word '" << word << "' was not found in the phrase." << endl;
    }

    delete[] phrase;
    delete[] word;

    return word[0];
}

int main() {
    word_search(); // Calling the word_search function
    return 0;
}