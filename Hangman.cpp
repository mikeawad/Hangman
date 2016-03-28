#include "Hangman.h"
#include <iostream>
#include <ctime>
#include <string>
#include <limits>


/** Default constructor */
Hangman::Hangman()
:wordCount(0), livesRemaining(6), gamesWon(0)
{
    wordBank.open("wordbank.txt");
    if(!wordBank)
    {
        cout << "Error opening file." << endl;
    }
    else
    {
        while(!wordBank.eof())
        {
            wordBank >> wordArr[wordCount];
            wordCount++;
        }
    }
    wordBank.close();
}

// function to set random word from previously read file.
void Hangman::setRandomWord()
{
    seed = time(0);
    srand(seed);

    word = wordArr[ 1 + rand() % 399]; // this results in a random value of between 1 and length of array
    hiddenWord.assign(word.length(), '*'); // turns words into asterisks

    cout << "Guess the following word" << endl;
    cout << hiddenWord << endl << endl;
}


// function to start the game
void Hangman::run()
{
    do
    {
        // get user guess limited to 1 character and ensures its lowercase
        cout << "Please enter a guess: \a\a\a\a";
        cin.get(userGuess);
        userGuess = tolower(userGuess);
        cin.ignore(numeric_limits<char>::max(),'\n');

        // reset goodGuess to false
        goodGuess = false;

        // scans the word to determine if the user guessed correctly. It will catch
        // every instance of the character if there are more than 1;
        for (unsigned short i = 0; i < word.length(); i++)
        {
            if (userGuess == word[i])
            {
                hiddenWord[i] = word[i];
                goodGuess = true;
            }
        }

        // compares the hidden word to the actual word. If there are no more asterisks
        // in the hidden word it means the two words are not equal. This raises a flag
        // for the user win state.
        if(!hiddenWord.compare(word))
        {
        	cout << hiddenWord << endl << endl;
        	cout << endl << "You Win! The Word was " << word << endl << endl;
        	gamesWon++;
        	break;
		}

        // if the user takes a bad guess, a warning on the screen shows up to indicate
        // the lives remaining.
        if(!goodGuess)
        {
            livesRemaining--;
            //goodGuess = false;
            cout << livesRemaining << "lives remaining" << endl;
        }

        // if the user runs out of lives this raises the flag for the losing condition.
        if(livesRemaining == 0)
        {
            cout << endl << "Game Over, You Lose. Word was \"" << word << "\"." << endl << endl;
            break;
        }

        cout << hiddenWord << endl << endl;
    }while (livesRemaining > 0);
}

void Hangman::setGameMode()
{
	cout << endl << "* * * * * * * * * * * * * Game Modes * * * * * * * * * * * * * * *" << endl << endl
		 << "1 - Easy:   10 Lives  (It\'s ok if you\'re scared)" << endl
		 << "2 - Normal:  6 Lives  (Just your average Joe)" << endl
		 << "3 - Beast:   3 Lives  (I eat the Oxford Dictionary for breakfast!!)" << endl << endl
		 << "* * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * *" << endl << endl;

	int mode;
	cout << "Choose difficult level: ";
	cin >> mode;
	cout << endl << endl;

	while (mode < 1 || mode > 3)
	{
		cout << "Please enter a value from the menu." << endl;
		cin >> mode;
		cout << endl << endl;
	}

	if (mode == 1)
		livesRemaining = 10;

	else if (mode == 2)
		livesRemaining = 6;

	else if (mode == 3)
		livesRemaining = 3;

	else
		livesRemaining = 6;

}

void Hangman::splashScreen()
{
	cout  << endl << "  =================================================================" << endl;
	cout<<	" 	 _____ _____ _____ _____ _____ _____ _____  " << endl
	<<"	|  |  |  _  |   | |   __|     |  _  |   | |"	<< endl
	<<"	|     |     | | | |  |  | | | |     | | | |"	<< endl
	<<"	|__|__|__|__|_|___|_____|_|_|_|__|__|_|___|" << endl;
	cout  << endl << "  =================================================================" << endl << endl;

}
