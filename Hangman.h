#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <fstream>
#include <cstdlib>
#include <limits>
using namespace std;


class Hangman
{
    public:
        /** Default constructor */
        Hangman();//:wordCount(0), livesRemaining(6);

        int gamesWon;

        void setRandomWord();
    /*------------------------------------------------------------------
    setRandomWord();



    ---------------------------------------------------------------------*/

        void run();
    /*------------------------------------------------------------------


    ---------------------------------------------------------------------*/


        void setGameMode();
    /*------------------------------------------------------------------


    ---------------------------------------------------------------------*/
    
    void splashScreen();
    /*------------------------------------------------------------------


    ---------------------------------------------------------------------*/

    private:
        ifstream wordBank;
        string wordArr[425];
        int livesRemaining;     // = six
        char userGuess;
        bool goodGuess;         // = false;
        int wordCount;          // = 0;
        unsigned seed;          // = time(0)
        string word;
        string hiddenWord;

};

#endif // HANGMAN_H

/**-- Ways to Improve and Other Ideas----------------------------------------------------------

1 - Use vector instead of array to read in file. This should then work for any size file.
2 - Allow the user to provide his/her own text file (optional).
3 - Clear and refresh screen after each guess.
4 - Create splash screen
5 - Create simple text graphic
6 - Create checker for already used words
7 - Provide a user mode, easy, medium, and difficult. This will control the number of tries.

-----------------------------------------------------------------------------------------------*/
