/*
* GOOD OLD BUCKAROO WORDLE
*   - 5 guesses
*   - 5 letter words
*   - 5 times the amount of pain
*   - 5 times the "what the hell am I looking at?"
*   - 5 times "very original"
        - https://cplusplus.com/forum/general/9516/
        - I just learned from this instead.
        - Credits to the user who made this.
        - I changed the code to my style/format.
        - This is the 5th line.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cctype>
using namespace std;

//global variables
string word_answer,
       current_letters,
       wrong_letters;
int incorrect;

bool match(char letter, string word);
char askGuess(string usedLetterString);
bool restart();

int main()
{
    //rng start
    srand(time(0));

    //list of possible words
    vector<string>words;
    words.push_back("QUACK");                                   //just add more words if you want,
    words.push_back("JANKY");                                   //must be 5 letters long tho
    words.push_back("SCUFF");                                   //it is the standard length
    words.push_back("PAINS");                                   //for wordle afterall.
    words.push_back("LIVID");                                   //don't question my choice of words...
    words.push_back("AGONY");
    words.push_back("EMPTY");
    words.push_back("LAUGH");
    words.push_back("SMILE");
    words.push_back("JOKER");

    //its looping time
    bool done = false;
    do {
        //variable
        const int tries = 5;                                    //staying with the number 5 theme thing
        
        //shuffle between the word list
        random_shuffle(words.begin(), words.end());
        word_answer = words[0];                                 //chosen word

        current_letters = string(word_answer.size(), '-');      //letters guessed so far
        wrong_letters = "";                                     //letters already guessed

        //for the current word_answer
        while (incorrect < tries && current_letters != word_answer) {
            cout << "You have " << (tries - incorrect) << " guesses left.\n";
            cout << "Used Letters: " << wrong_letters << endl;
            cout << "The Word: " << current_letters << endl << endl;

            //call askGuess
            wrong_letters += askGuess(current_letters);
        }

        //if user guesses wrong word
        if (incorrect = tries && current_letters != word_answer) {
            cout << "You've failed to guess the Word.\n";
        }

        //give answer
        cout << "The Word : " << word_answer << endl;
    }   while (restart());
    return 0;                                                   //I haven't used this in awhile
}

//setting up for the hot mess below these 2 lines
inline bool match(char letter, string word)
{
       return (word.find(letter) != string::npos);
}

//start of the hot mess
char askGuess(string usedLetterString) {
    //variable
    char guess;

    //make user enter guess/letter
    cout << "Enter your guess: ";
    cin >> guess;

    //make any lowercase input to an uppercase input to match word_answer
    guess = toupper(guess);

    //if user input same letter
    while (match(guess, wrong_letters)) {
        cout << "You've used '" << guess << "' already.\n";
        cout << "Enter your guess: ";
        cin >> guess;
        guess = toupper(guess);
    }

    //if user guesses correctly
    if (match(guess, word_answer)) {
        cout << "'" << guess << "' is in the word.\n\n";

        //update current_letter within word_answer
        for (int i = 0; i < word_answer.length(); ++i)
            if (word_answer[i] == guess)
                current_letters[i] = guess;
    }

    //if user guesses incorrectly
    else {
        cout << "'" << guess << "' is not in the Word.\n\n";
        ++incorrect;
    }
    return guess;
}
//end of the hot mess

//asking to end or restart
bool restart() {
    //variable
    string again;

    cout << "Play again?\n"
         << "'y' or 'n'\n";
    cin >> again;

    //clear any previous input
    cin.clear();
    cin.ignore();

    if (again == "y") {
        return main();
    }
    else if (again == "n") {
        return 0;
    }
    else {
        return 0;
    }
}
