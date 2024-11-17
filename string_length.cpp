#include <iostream>
#include <string>
using namespace std;

int length(const char* thestring){
    int len = 0;
    while (*thestring != '\0'){
        len = len + 1;
        thestring++;
    }

    return len;

}

int main(){
    string thestring;
    cout << "Enter a word or string: ";
    getline(cin, thestring); // Prompting user to enter the string concerned

    const char* newstring = thestring.c_str(); // Converting our C++ string to a C-style string

    int len = length(newstring);
    cout << "The above string has " << len << " characters in it.";

    return 0;

}