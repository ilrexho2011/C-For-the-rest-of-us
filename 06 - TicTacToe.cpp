/*
    TicTacTos Program in C++ using 2D array
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    cout << "*************** TIC TAC TOE *****************\n";
    // Use a 2D Array for display of the gameboard
    char gameboard[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int result = 0;
    // Declaring Players and giving them symbols
    const char  PLAYER_X = 'X', PLAYER_O ='O';
    cout << "\tPlayer 1 has the symbol of  X" << endl;
    cout << "\tPlayer 2 has the symbol of  O" << endl;
    // For fetching 9 inputs
    for (int i = 1; i <= 9; i++)
    {
        //system("cls");   // Clean the screen after every input

        // This displays initial GameBoard
        cout << "Current board state:" << endl;
        cout << "     0   1   2" << endl;
        cout << "   +---+---+---+" << endl;
        cout << " 0" << " | " << gameboard[0][0] << " | " << gameboard[0][1] << " | " << gameboard[0][2] << " | " << endl;
        cout << "   +---+---+---+" << endl;
        cout << " 1" << " | " << gameboard[1][0] << " | " << gameboard[1][1] << " | " << gameboard[1][2] << " | " << endl;
        cout << "   +---+---+---+" << endl;
        cout << " 2" << " | " << gameboard[2][0] << " | " << gameboard[2][1] << " | " << gameboard[2][2] << " | " << endl;
        cout << "   +---+---+---+" << endl;
        //Displays the requestion message
        cout << "Player 1 = " <<  PLAYER_X << "\nPlayer 2 = " << PLAYER_O << "\n\tEnter a number between 1 and 9:\n";
        int pos; // select the cell to enter value X or O
        // Fetching the Coordinates x and y
    static int turn = 1;
    static char comp[3][3];
    int x, y;
    //For Player-1
    if (turn % 2 == 1)
    {
        do
        {
            cout << "Player-X turn:";
            cin >> pos;
            // cout << "\tRow="; cin >> x; cout << "\t\tCol="; cin >> y;
            if (pos == 1) {x = 0; y = 0;}
            if (pos == 2) {x = 0; y = 1;}
            if (pos == 3) {x = 0; y = 2;}
            if (pos == 4) {x = 1; y = 0;}
            if (pos == 5) {x = 1; y = 1;}
            if (pos == 6) {x = 1; y = 2;}
            if (pos == 7) {x = 2; y = 0;}
            if (pos == 8) {x = 2; y = 1;}
            if (pos == 9) {x = 2; y = 2;}
            if (gameboard[x][y] == PLAYER_X || gameboard[x][y] == PLAYER_O || comp[x][y] == '.')
            cout << "Not a valid choice! Try again.\n";
        } while (pos < 1 || pos  > 9 || comp[x][y] == '.');
        comp[x][y] = '.';
        gameboard[x][y] =  PLAYER_X;
    }
    //For Player-2
    else
    {
        do
        {
            cout << "Player-O turn:";
            cin >> pos;
            // cout << "\tRow="; cin >> x; cout << "\t\tCol="; cin >> y;
            if (pos == 1) {x = 0; y = 0;}
            if (pos == 2) {x = 0; y = 1;}
            if (pos == 3) {x = 0; y = 2;}
            if (pos == 4) {x = 1; y = 0;}
            if (pos == 5) {x = 1; y = 1;}
            if (pos == 6) {x = 1; y = 2;}
            if (pos == 7) {x = 2; y = 0;}
            if (pos == 8) {x = 2; y = 1;}
            if (pos == 9) {x = 2; y = 2;}
            if (gameboard[x][y] == PLAYER_X || gameboard[x][y] == PLAYER_O || comp[x][y] == '.')
            cout << "Not a valid choice! Try again.\n";
        } while (pos < 1 || pos  > 9 || comp[x][y] == '.');
        comp[x][y] = '.';
        gameboard[x][y] = PLAYER_O;
    }
    turn++;
        // Check results
        if (i >= 5)     //for checking Game Result after 4 - first turns
            //For checking that either player-1 has won or not
    if (
        gameboard[0][0] ==  PLAYER_X && gameboard[0][0] == gameboard[0][1] && gameboard[0][1] == gameboard[0][2] ||
        gameboard[1][0] ==  PLAYER_X && gameboard[1][0] == gameboard[1][1] && gameboard[1][1] == gameboard[1][2] ||
        gameboard[2][0] ==  PLAYER_X && gameboard[2][0] == gameboard[2][1] && gameboard[2][1] == gameboard[2][2] ||
        gameboard[0][0] ==  PLAYER_X && gameboard[0][0] == gameboard[1][0] && gameboard[1][0] == gameboard[2][0] ||
        gameboard[0][1] ==  PLAYER_X && gameboard[0][1] == gameboard[1][1] && gameboard[1][1] == gameboard[2][1] ||
        gameboard[0][2] ==  PLAYER_X && gameboard[0][2] == gameboard[1][2] && gameboard[1][2] == gameboard[2][2] ||
        gameboard[0][0] ==  PLAYER_X && gameboard[0][0] == gameboard[1][1] && gameboard[1][1] == gameboard[2][2] ||
        gameboard[0][2] ==  PLAYER_X && gameboard[0][2] == gameboard[1][1] && gameboard[1][1] == gameboard[2][0]
        )
        result = 1;     //returns '1' if Player-1 Won
    //For checking that either player-2 has won or not if above conditions are false
    else if (
        gameboard[0][0] == PLAYER_O && gameboard[0][0] == gameboard[0][1] && gameboard[0][1] == gameboard[0][2] ||
        gameboard[1][0] == PLAYER_O && gameboard[1][0] == gameboard[1][1] && gameboard[1][1] == gameboard[1][2] ||
        gameboard[2][0] == PLAYER_O && gameboard[2][0] == gameboard[2][1] && gameboard[2][1] == gameboard[2][2] ||
        gameboard[0][0] == PLAYER_O && gameboard[0][0] == gameboard[1][0] && gameboard[1][0] == gameboard[2][0] ||
        gameboard[0][1] == PLAYER_O && gameboard[0][1] == gameboard[1][1] && gameboard[1][1] == gameboard[2][1] ||
        gameboard[0][2] == PLAYER_O && gameboard[0][2] == gameboard[1][2] && gameboard[1][2] == gameboard[2][2] ||
        gameboard[0][0] == PLAYER_O && gameboard[0][0] == gameboard[1][1] && gameboard[1][1] == gameboard[2][2] ||
        gameboard[0][2] == PLAYER_O && gameboard[0][2] == gameboard[1][1] && gameboard[1][1] == gameboard[2][0]
        )
        result = -1;    //returns '-1' if Player-2 Won
    else
        result = 0;     //returns '0' if GAME DRAW
        //For checking that either player-1 has won or not
        if (result == 1 || result == -1)
            break;
    }
    //for separating RESULT
    for (int i = 0; i < 80; i++)
        cout << "=";
    //Displays result
    cout << endl << setw(46) << "GAME RESULT\n";
    if (result == 1)
        cout << "\n" << setw(50) << "****Player-X WON****\n";
    else if (result == -1)
        cout << "\n" << setw(50) << "****Player-O WON****\n";
    else
        cout << "\n" << setw(50) << "********DRAW********\n";
    //Displays Final Game Board
    cout << endl;
        cout << "     0   1   2" << endl;
        cout << "   +---+---+---+" << endl;
        cout << " 0" << " | " << gameboard[0][0] << " | " << gameboard[0][1] << " | " << gameboard[0][2] << " | " << endl;
        cout << "   +---+---+---+" << endl;
        cout << " 1" << " | " << gameboard[1][0] << " | " << gameboard[1][1] << " | " << gameboard[1][2] << " | " << endl;
        cout << "   +---+---+---+" << endl;
        cout << " 2" << " | " << gameboard[2][0] << " | " << gameboard[2][1] << " | " << gameboard[2][2] << " | " << endl;
        cout << "   +---+---+---+" << endl;
    //For formatting output
    for (int i = 0; i < 80; i++)
        cout << "~";
    cout << endl;
    return 0;
}
