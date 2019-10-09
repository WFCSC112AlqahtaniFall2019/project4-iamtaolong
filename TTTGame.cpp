/* Class: TicTacToe
 * Author: Tao Long
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
using namespace std;

int main() {

    // construct a TicTacToe object newGame
    TicTacToe newGame;

    // get the number of players from the user
    cout << endl << "*******************  Welcome to Long's TicTacToe!  ********************" << endl;
    cout << "One-player or Two-player (1 or 2): ";
    int numPlayers;
    cin >> numPlayers;

    // declare the variable of the target column and row
    int playerCol;
    int playerRow;

    // if the number of player is 1
    if (numPlayers == 1) {

        // intialize and print the board
        newGame.initializeBoard();
        newGame.printBoard();

        // get random number to find who will start
        srand(time(0));
        int whoStart = rand() % 2;

        // construct a while loop
        // if the system is false
        while (newGame.checkForWin() == false && newGame.isBoardFull() == false) {

            // ask the plater
            if (whoStart % 2 == 0) {
                //if (newGame.getCurrentPlayerNumber() == whoStart+1){
                cout << "Player: Enter row and column: ";
                cin >> playerRow;
                cin >> playerCol;

                // check if the input is out of range
                if ((playerRow != 1 && playerRow != 2 && playerRow != 3) ||(playerCol != 1 && playerCol != 2 && playerCol != 3)) {
                    cout << "Sorry! Your input is out of range." << endl;
                }

                    // check if the input is already taken
                else if (newGame.placeMark(playerRow - 1, playerCol - 1) == false) {
                    cout << "Sorry! Your input is hitting an already used point." << endl;
                }

                else {
                    newGame.placeMark(playerRow - 1, playerCol - 1);
                    newGame.printBoard();
                    newGame.changePlayer();
                    whoStart = whoStart + 1;
                }
            }

                // after that is the computer's turn
            else {
                cout << "Computer's turn:" << endl;
                // first get two random number
                playerRow = rand() % 3;
                playerCol = rand() % 3;

                // check if the random number is taken, if it is, than re-generate
                while (newGame.placeMark(playerRow, playerCol) == false) {
                    playerRow = rand() % 3;
                    playerCol = rand() % 3;
                }

                // after getting usable location, place and print and change
                // newGame.placeMark(playerRow + 1, playerCol + 1);
                newGame.printBoard();
                newGame.changePlayer();
                whoStart = whoStart + 1;
            }
            // finish a round and check if ALL the spots are taken
        }
    }


        // check if the number of players is 2
    else if (numPlayers == 2) {

            // initialize and print the board
            newGame.initializeBoard();
            newGame.printBoard();

            while (!newGame.isBoardFull() && !newGame.checkForWin()) {
                // ask player to enter
                cout << "Player: " << newGame.getCurrentPlayerNumber() << endl;
                cout << "Player: Enter row and column: ";
                cin >> playerRow;
                cin >> playerCol;

                //check bound of rows and columns
                if ((playerRow != 1 && playerRow != 2 && playerRow != 3) ||
                    (playerCol != 1 && playerCol != 2 && playerCol != 3)) {
                    cout << "Sorry! Your input is out of range." << endl;
                } else if (newGame.placeMark(playerRow - 1, playerCol - 1) == false) {
                    cout << "Sorry! Your input is hitting an already used point." << endl;
                }

                // place & print & change
                else {
                    newGame.placeMark(playerRow - 1, playerCol - 1);
                    newGame.printBoard();
                    newGame.changePlayer();
                }
            }
        }

        // user experience: if the typed number of players is not 1 or 2, then exit the game
        else {
            cout << "Sorry! Our game could only be played by 1 or 2 players.";
            exit(0);
        }

    // print the result message. it only has two situations: WIN OR TIE（draw）
    if (newGame.checkForWin() == true) {
        cout << "Congrats! There is a winner!" << endl;}
    else {
        cout << "Ooops! There is a tie/draw!" << endl;}
    // return 0 end the game

    cout << endl << "THANK YOU FOR PLAYING!!!!" << endl ;
    return 0;
    }

