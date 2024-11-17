// SIMPLE CONSOLE GAME. YOU GUESS THE LETTERS OF THE WORD AS THE ALGORITHM HELPS YOU THROUGH. YOU CAN CHANGE THE WORDS TO USE IN THE CODE BELOW.

#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

// Function for finding the number of words in our sentence
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


// Function for finding length
int length(const char* thestring){
    int len = 0;
    while (*thestring != '\0'){
        len = len + 1;
        thestring++;
    }

    return len;

}


// Function to display the number of underscores
void display_underscores(int underscore_count) {
    if (underscore_count < 0) {
        cout << "Underscore count must be a non-negative integer." << endl;
        return;
    }
    
    for (int i = 0; i < underscore_count; ++i) {
        cout << "_";
    }
    cout << endl; // Move to the next line after displaying underscores
}


// Function to search for the position of a player input in our game word
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

    // Declaring the sentence containing the words
    const string the_main_phrase = "coding language programming memory engineering software hardwork everyday";
    const int PHRASE_LENGTH = length(the_main_phrase.c_str());
    string game_word;  // This string carries the word the user has to guess
    int carry_length = 0;  // Control interger, to avoid an infinite while loop below

    // Intro to game.
    cout << "Hi, how many of the next "  << word_count(the_main_phrase.c_str()) << " words can you guess?? Let me help you." << endl;

    // Declare the position of a character in the phrase, so i_th is the index of a character in the_main_phrase.
    int I_th = 0;

    // Start our main while loop, that iterates every position in the_main_phrase, and will extract words separated by spaces. This is the main part of our code.
    while (I_th < PHRASE_LENGTH - carry_length) {  /*Here, we subtract the carry_length from the length of the phrase to avoid an infinite loop when the I_th value gets close to the phrase length but never reaching the phrase length. Carry_length permits this at the last word in our list of words*/
        if (the_main_phrase[I_th] == ' ') // If the character in the I_th index is a whitespace or comma,
        {
            I_th = I_th + 1; //Go to next index
        } else {
            for (size_t i = I_th; i < PHRASE_LENGTH; i++) //Continue through the_main_phrase till next whitespace.
            {
                if (the_main_phrase[i] != ' ')
                {
                    game_word += the_main_phrase[i];  // Building game word
                } else {
                    I_th = i;   // Setting new position for start of next game word
                    break;
                }
            }
            int word_length = length(game_word.c_str()); // Number of underscores to display.

            char player; // Players' entered character
            char player_low; // Lowercase of the user input
            string game_result;  // The game results 
            char* char_index;   // Position of player input in game word
            int failed_attempts = 0; // Total number of attempts

            if (word_length > 0)   // Setting initial game result to underscores
            {
                for (size_t i = 0; i < word_length; i++)
                {
                    game_result += "_";
                }
            }


            // Now, lets' begin
            cout << "The word to guess has " << word_length << " letters. You will be assisted after every failed attempt.  ";
            display_underscores(word_length);
            cout << endl;
            int anti_guess = 0; // This is the position of the letters in the string to be replaced by helping characters to player.
            cout << "Guess a letter in the word. You have " << word_length << " attempts: ";

            
            for (size_t i = 0; i < word_length ; i++)  // Main for loop that iterates through every game word. Engine of game.
            {
                cin >> player;  // Player input
                char_index = search(game_word.c_str(), player);  // Checking player input in game word
                char* game_char_index = search(game_result.c_str(), player);  // Checking player input in game result

                int game_result_number = 0;
                int game_word_number = 0;
                for (char ch : game_result) // Counting number of times character appears in the game result
                {
                    if (ch == player) 
                    {
                        game_result_number++; // Increment count if character matches
                    }
                }
                for (char ch : game_word)  // Counting the number of times character appears in the game word
                {
                    if (ch == player) 
                    {
                        game_word_number++; // Increment count if character matches
                    }
                }


                if (char_index == NULL && game_char_index == NULL) // If player input is neither in game word nor game result
                {
                    int counting_variable = 0; // This makes sure the user recieves only two letters as hint for every failed attempt
                    while (true){
                        if (game_result[anti_guess] == '_')
                        {
                            game_result[anti_guess] = game_word[anti_guess];
                            anti_guess++;
                            counting_variable = counting_variable + 1;
                        } else
                        {
                            anti_guess++;
                        }

                        if (counting_variable == 2 || anti_guess == word_length)  // condition to break while loop
                        {
                            break;
                        }
                    }
                    failed_attempts++;  // Increase number of attempts for every try
                    cout << "Hint: " << ">> " << game_result << endl;
                } else if ((char_index != NULL && game_char_index == NULL) || (game_word_number > game_result_number))  // For same letter in game word and game result, but that occurs multiple times in game word than in game result
                {
                    for (size_t i = 0; i < word_length; ++i) 
                    {
                        if (game_word[i] == player) 
                        {
                            game_result[i] = player; // Replace it with a the desired character.
                        }
                    }
                    failed_attempts++;  // Increase number of attempts for every try
                    cout << ">> " << game_result << endl;
                } else  // For game result already containing all instances of a character
                {
                    cout << "The above letter is no more found in another index of the word" << endl;
                    cout << ">> " << game_result << endl;
                    failed_attempts++;  // Increase number of attempts for every try
                }

                if (game_result != game_word && failed_attempts == word_length)  // Too many failed attempts with no success. This hardly occurs
                {
                    cout << "Too many failed attempts, the desired word is: >> " << game_word << endl;
                }

                if (game_result == game_word)  // Break for loop if we already have our desired word.
                {
                    break;
                }
            }
            cout << "Great, now lets move over to the next word" << endl;
        }

        carry_length = length(game_word.c_str());
        game_word.clear(); // Clearing our game word to permit for a new word to occupy it.
    }
    
    cout << "Oops, every word has been spelled. That was fun. Hope you enjoyed too." << endl;
    cout << "You can always go back to the code and change the words you wish to play with.";

    return 0;
}
