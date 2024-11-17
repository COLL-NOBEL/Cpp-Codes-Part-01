#include <iostream>
#include <cstring>
#include <cctype>
/* This function is used to count the number of words in a sentence. The sentence is converted to the C type string, the looped through to find everything that is alphabet or number, then counted when seperated by whitespace*/
using namespace std;

int word_count(const char *sentence) {
    // Check if the input sentence is empty
    if (sentence == nullptr || strlen(sentence) == 0) {
        return 0;
    }

    int wordCount = 0;
    bool a_word = false;

    // Loop through each character in the sentence
    for (size_t i = 0; i < strlen(sentence); ++i) {
        // Check if the current character is a letter or a digit
        if (isalpha(sentence[i]) || isdigit(sentence[i])) {
            if (!a_word) {
                wordCount++;
                a_word = true;
            }
        } else {
            // If the character is not a leter or digit, we are no longer in a word
            a_word = false;
        }
    }

    return wordCount; // Return the total word count
}

int main() {
    // Prompt the user for input
    cout << "Enter a sentence (input): ";
    string input;
    getline(cin, input);

    // Call the word_count function with the input sentence
    int no_of_words = word_count(input.c_str());
    cout << "Numbr of words: " << no_of_words << endl;

    return 0;
}