// Homework Assignment #8
// Structured TICTACTOE version 2

#include <iostream>

using namespace std;
// Declaring Players and giving them symbols
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

// Use a 2D Array for display of the gameboard
char board[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void displayBoard()
{
    cout << "Current board state:" << endl;
    cout << " " << endl;
    for(int x = 0; x < 3; x++) {
        cout << "    ";
        for(int y = 0; y < 3; y++) {
            cout << board[3 * x + y];
            if(y < 2) {
                cout << " | ";
            } else {
                cout << endl;
            }
        }
        if(x < 2) {
            cout << "    --+---+--" << endl;
        }
    }
    cout << "  " << endl;
}

bool checkForEndGame(int turnNumber, char player)
{
    bool retVal = false;
    // checking for a winner
    if(board[0] == player && board[1] == player && board[2] == player) {
        cout << "Player " << player << " wins on top row!" << endl;
        retVal = true;
    }
    if(board[3] == player && board[4] == player && board[5] == player) {
        cout << "Player " << player << " wins on middle row!" << endl;
        retVal = true;
    }
    if(board[6] == player && board[7] == player && board[8] == player) {
        cout << "Player " << player << " wins on bottom row!" << endl;
        retVal = true;
    }
    if(board[0] == player && board[3] == player && board[6] == player) {
        cout << "Player " << player << " wins on left column!" << endl;
        retVal = true;
    }
    if(board[1] == player && board[4] == player && board[7] == player) {
        cout << "Player " << player << " wins on middle column!" << endl;
        retVal = true;
    }
    if(board[2] == player && board[5] == player && board[8] == player) {
        cout << "Player " << player << " wins on right column!" << endl;
        retVal = true;
    }
    if(board[0] == player && board[4] == player && board[8] == player) {
        cout << "Player " << player << " wins on upward diagonal!" << endl;
        retVal = true;
    }
    if(board[2] == player && board[4] == player && board[6] == player) {
        cout << "Player " << player << " wins on downward diagonal!" << endl;
        retVal = true;
    }
    if(turnNumber == 9)
    {
        cout << "Draw. Nobody Wins" << endl;
        retVal = true;
    }

    return retVal;
}
void getPlayerChoice(char player)
{
    // Getting players input and validating it
    while (true) {
        int chosenSquare = -1;
        cout << "Player " << player << ", enter a number between 1 and 9: ";
        cin >> chosenSquare;
        chosenSquare--;
        // Validating the user input
        if(chosenSquare < 0 || chosenSquare > 8) {
            cout << "Not a valid choice! Try again.\n" << endl;
        } else if(board[chosenSquare] == PLAYER_O || board[chosenSquare] == PLAYER_X){
            cout << "Chosen square is not available. try again." << endl;
        } else {
            board[chosenSquare] = player;
            break;
        }
    }
}

int main()
{
    char lastPlayer = PLAYER_O;
    char actualPlayer = PLAYER_X;
    cout << "---------------------------------------------\n";
    cout << "*************** TIC TAC TOE *****************\n";
    cout << "---------------------------------------------\n";
    int len = sizeof(board) / sizeof(board[0]); // calculating the number of elements in the array.
    for(int a = 0; a <= len; a++) {
        cout << " " << endl;
        displayBoard();
        bool isGameOver = checkForEndGame(a, lastPlayer);
        if(isGameOver)
        {
            break;
        }
        getPlayerChoice(actualPlayer);
        swap(actualPlayer, lastPlayer);
    }
    cout << " " << endl;
    cout << " " << endl;
    return 0;
}
