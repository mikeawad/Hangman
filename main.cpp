
#include "Hangman.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{

    int gamesWon = 0,
        gameCount = 0;
    char playAgain;
    bool showMenu = true;

    do
    {

    // Hangman class object creation
       Hangman game;

    // game difficulty set for all games played. to change difficulty exit and re-start
    if(showMenu)
    {

       game.splashScreen();
       game.setGameMode();
       showMenu = false;
    }


    // sets the random word from the text file for the user to guess
    game.setRandomWord();



    // runs the main portion of the game
    game.run();
    gameCount++;

    cout << "Would you like to play again? Enter (y/n): ";
    cin >> playAgain;
    cout << endl << endl;

    gamesWon += game.gamesWon;
    }while(playAgain == 'y');

    cout << endl << "You Won " << gamesWon << " out of " << gameCount << endl;
    cout << "Thank For Playing !!" << endl << endl;


    return 0;
}
